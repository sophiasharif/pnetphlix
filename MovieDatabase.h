#ifndef MOVIEDATABASE_INCLUDED
#define MOVIEDATABASE_INCLUDED

#include <string>
#include <vector>
#include "treemm.h"

class Movie;

class MovieDatabase
{
  public:
    MovieDatabase(): m_loaded(false) {}
    ~MovieDatabase();
    bool load(const std::string& filename);
    Movie* get_movie_from_id(const std::string& id) const;
    std::vector<Movie*> get_movies_with_director(const std::string& director) const;
    std::vector<Movie*> get_movies_with_actor(const std::string& actor) const;
    std::vector<Movie*> get_movies_with_genre(const std::string& genre) const;

  private:
    bool m_loaded;
    std::vector<Movie*> m_moviePointers;
    TreeMultimap<std::string, Movie*> m_id_tree;
    TreeMultimap<std::string, Movie*> m_director_tree;
    TreeMultimap<std::string, Movie*> m_actor_tree;
    TreeMultimap<std::string, Movie*> m_genre_tree;
};

std::vector<std::string> processDataString(std::string s);

#endif // MOVIEDATABASE_INCLUDED
