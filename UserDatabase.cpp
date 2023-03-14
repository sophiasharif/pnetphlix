#include "UserDatabase.h"
#include "User.h"

#include <string>
#include <vector>
#include <fstream>
using namespace std;

bool UserDatabase::load(const string& filename)
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
    string name, email, temp;
    int numMovies;
    vector<std::string> movies;
    
    
    while (getline(infile, name)) {
        
        // read user data
        getline(infile, email);
        infile >> numMovies;
        infile.ignore(10000, '\n');
        for (int i=0; i<numMovies; i++) {
            string movie;
            getline(infile, movie);
            movies.push_back(movie);
        }
        // skip empty line
        getline(infile, temp);
        
        // create a user, add to tree multimap
        User* u = new User(name, email, movies);
        m_data.insert(email, u);
        
        // clear movies vector for reuser
        movies.clear();
    }
    
    m_loaded = true;
    return true;
}

User* UserDatabase::get_user_from_email(const string& email) const
{
    auto i = m_data.find(email);
    if (!i.is_valid()) return nullptr;
    return i.get_value();  // Replace this line with correct code.
}
