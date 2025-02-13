#include "movie.h"
#include "movie_factory.h"
#include <vector>
#include <limits>
#include <string>
#include <iostream>

Movie* FindHighestRateMovie(const vector<Movie*>& movies) 
{
	if (movies.empty())
	{
		throw invalid_argument("The Movie Vector is Empty!");
	}

	Movie* highestRated = movies[0];
	size_t numMovies = movies.size();
	double maxRating = movies[0]->GetRating();

	for (size_t i = 0; i < numMovies; i++) 
	{
		double currentMovieRatings = movies[i]->GetRating();
		if (currentMovieRatings > maxRating)
		{
			maxRating = movies[i]->GetRating();
			highestRated = movies[i];
		}
	}

	return highestRated;
}

size_t CalculateAverageRuntime(const vector<Movie*>& movies)
{
	size_t numMovies = movies.size();
	size_t totalRuntime = 0;
	int averageRuntime = 0;

	for (auto& movie : movies)
	{
		int currentMovieRuntime = movie->GetRunTime();
		averageRuntime += currentMovieRuntime;
	}

	totalRuntime = averageRuntime / numMovies;

	return totalRuntime;
}

int main() 
{
	std::vector<std::string> titles{ "John Wick 4", "Dune:Part Two", "La la land", "StarWars: Episode III - Revenge of the Sith", "Oppenheimer" };
	std::vector<std::string> directors{ "Director 1", "Director 2", "Director 3", "Director 4", "Director 5" };
	std::vector<int> runtimes{ 169, 166, 128, 140, 180 };
	std::vector<int> ids{ 1, 2, 3, 4, 5 };
	std::vector<double> ratings{ 9.4, 9.2, 9.1, 8.0, 9.3 };

	std::vector<Movie*> movies = CreateMovies(ids, titles, directors, runtimes, ratings); 

	Movie* bestMovie = FindHighestRateMovie(movies);

	if (bestMovie != nullptr) {
		std::cout << "Highest Rated Movie: " << bestMovie->GetTitle() << std::endl; // Use -> here as well!
	}
	else {
		std::cout << "No movies found." << std::endl;
	}

	deallocateNewPtrs(movies);

	return 0;
}