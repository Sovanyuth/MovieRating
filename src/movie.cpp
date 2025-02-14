#include "movie.h"
#include <string>
#include <iostream>
#include <exception>
using namespace std;

Movie::Movie(int id, const string& title, const string& director, int runtime, double rating)
	:id(id), title(title), director(director), runtime(runtime), rating(rating)
{
	// Error 1: Throw an exception when the movie constructor is given at least 1 empty vectors
	if (title.empty() || director.empty())
	{
		throw invalid_argument("Error (Invalid Movie): The title and director should not be empty!");
	}

	if (id < 0 || id > 10000)
	{
		throw invalid_argument("Error (Invalid ID): Id must not be negative!");
	}

	if (runtime < 0 || runtime > 51420)
	{
		throw invalid_argument("Error (Invalid Runtime): Runtime must not be negative! Also funfact: the longest movie ever made is 857 hours or 51420 minutes");
	}

	if (rating < 0 || rating > 10) 
	{
		throw invalid_argument("Ratings must be from 0-10");
	}
}

int Movie::GetId() const
{
	return id;
}

string Movie::GetTitle() const
{
	return title;
}

string Movie::GetDirector() const
{
	return director;
}

double Movie::GetRating() const
{
	return rating;
}

int Movie::GetRunTime() const
{
	return runtime;
}

void Movie::PrintMoveData()
{
	cout << "This Current Movie has an id of: " << id << endl;
	cout << "This Title of the Movie is: " << title << endl;
	cout << "This Movie was directed by: " << director << endl;
	cout << "It has an runtime of: " << runtime << endl;
	cout << "This Movie has a rating of: " << rating << endl;
}