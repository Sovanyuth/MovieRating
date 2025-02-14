//movie_factory.h
#include <vector>
#include "movie.h"
using namespace std;
/*
Write function declaration CreateMovies() that
accepts (attributes in the below order)
  vector of titles,
  vector of directors,
  vector of runtimes,
  vector of ids,
  vector of ratings and
return
  vector of pointers of Movie objects
*/
vector<Movie*> CreateMovies(vector<int> ids, vector<string> titles, vector<string> directors,
    vector<int> runtimes, vector<double> ratings);

void deallocateNewPtrs(const vector<Movie*>& movies);