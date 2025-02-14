#include "movie_factory.h"
#include <iostream>
// I've initialized the parameters with const and reference so that I could just 
vector<Movie*> CreateMovies(const vector<int>& ids, const vector<string>& titles, const vector<string>& directors, 
	const vector<int>& runtimes, const vector<double>& ratings)
{
	size_t numMovies = titles.size();
	// Check for errors, only proceed if all of the vectors have the same size
	if (directors.size() != numMovies || runtimes.size() != numMovies ||
		ids.size() != numMovies || ratings.size() != numMovies)
	{
		throw invalid_argument("Input Vectors must have the same size!");
	}
	else if (ids.empty() || titles.empty() || directors.empty() || runtimes.empty() || ratings.empty())
	{
		throw invalid_argument("Input Vectors must have the same size!");
	}
	// Intializing vector of pointers to return
	vector<Movie*> movieList;
	// Loop through every element in the arrays 
	// For every element, create an object that gets the data from each of the array elements 
	// at that index
	for (size_t i = 0; i < numMovies; i++)
	{
		Movie* uniqueMoviePtr = new Movie(ids[i], titles[i], directors[i], runtimes[i], ratings[i]);
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