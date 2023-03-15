#include "MovieDatabase.h"
#include "Movie.h"

#include <string>
#include <vector>
#include <fstream>
using namespace std;

MovieDatabase::~MovieDatabase() {
    for (auto m : m_moviePointers)
        delete m;
}

bool MovieDatabase::load(const string& filename)
{
    // don't open file if we already loaded users
    if (m_loaded)
        return false;
    
    // open file
    ifstream infile(filename);
    if ( !infile ) {
        cerr << "Error: could not open file!" << endl;
        return false;
    }
    
    // variables to store data
    string id, name, release_year, director_string, actor_string, genre_string, temp;
    float rating;
    vector<string> directors, actors, genres;
    
    while (getline(infile, id)) {

        // read user data
        getline(infile, name);
        getline(infile, release_year);
        getline(infile, director_string);
        getline(infile, actor_string);
        getline(infile, genre_string);
        infile >> rating;
        infile.ignore(10000, '\n');
        
        // skip empty line
        getline(infile, temp);
    
        // process strings into vectors
        directors = processDataString(director_string);
        actors = processDataString(actor_string);
        genres = processDataString(genre_string);

        // create a new movie object
        Movie* movie = new Movie(id, name, release_year, directors, actors, genres, rating);
        
        // load tree multimaps with data
        m_id_tree.insert(id, movie); // id
        for (auto d : directors)
            m_director_tree.insert(d, movie);
        for (auto a : actors)
            m_actor_tree.insert(a, movie);
        for (auto g : genres)
            m_genre_tree.insert(g, movie);
        
        // add pointer to vector member (to handle destruction later)
        m_moviePointers.push_back(movie);
    
        // clear vectors for reuse
        directors.clear();
        actors.clear();
        genres.clear();
    }
    
    m_loaded = true;
    return true;
}

Movie* MovieDatabase::get_movie_from_id(const string& id) const
{
    auto i = m_id_tree.find(id);
    if (!i.is_valid())
        return nullptr;
    return i.get_value();
}

vector<Movie*> MovieDatabase::get_movies_with_director(const string& director) const
{
    auto i = m_director_tree.find(director);
    vector<Movie*> res;
    while (i.is_valid()) {
        res.push_back(i.get_value());
        i.advance();
    }
    return res;
}

vector<Movie*> MovieDatabase::get_movies_with_actor(const string& actor) const
{
    auto i = m_actor_tree.find(actor);
    vector<Movie*> res;
    while (i.is_valid()) {
        res.push_back(i.get_value());
        i.advance();
    }
    return res;}

vector<Movie*> MovieDatabase::get_movies_with_genre(const string& genre) const
{
    auto i = m_genre_tree.find(genre);
    vector<Movie*> res;
    while (i.is_valid()) {
        res.push_back(i.get_value());
        i.advance();
    }
    return res;
}

vector<string> processDataString(string s) {
    vector<string> res;
    string temp;
    for (auto c : s) {
        if (c == ',') {
            res.push_back(temp);
            temp = "";
        }
        else temp += c;
    }
    res.push_back(temp);
    return res;
}

