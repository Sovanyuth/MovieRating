#include "movie_factory.h"
#include <iostream>
// I've initialized the parameters with const and reference so that I could just 
vector<Movie*> CreateMovies(vector<string> titles, vector<string> directors,
    vector<int> runtimes, vector<int> ids, vector<double> ratings)
{
	// Check for errors, only proceed if all of the vectors have the same size
	if (directors.size() != titles.size() || runtimes.size() != directors.size() ||
		ids.size() != directors.size() || ratings.size() != directors.size())
	{
		throw invalid_argument("Input Vectors must have the same size!");
	}

	if (ids.empty() || titles.empty() || directors.empty() || runtimes.empty() || ratings.empty())
	{
		throw invalid_argument("Vectors must not be empty!");
	}
	// Intializing vector of pointers to return
	vector<Movie*> movieList;
	// Loop through every element in the arrays 
	// For every element, create an object that gets the data from each of the array elements 
	// at that index
	for (size_t i = 0; i < directors.size(); i++)
	{
		Movie* uniqueMoviePtr = new Movie(titles[i], directors[i], ids[i], runtimes[i], ratings[i]);
		movieList.push_back(uniqueMoviePtr);
	}
	// Return vector of pointers of those movie objects
	return movieList;
}

void deallocateNewPtrs(const vector<Movie*>& movies)
{
	// For loop that deallocates memory for the objects
	for (auto& obj : movies) 
	{	
		delete obj;
	}
}