#include "movie.h"
#include <string>
#include <iostream>
#include <exception>
using namespace std;

Movie::Movie(string title, string director, int id, int runtime, double rating)
{
	// Error 1: Throw an exception when the movie constructor is given at least 1 empty vectors
	if (title.empty() || director.empty())
	{
		throw invalid_argument("Error (Invalid Movie): The title and director should not be empty!");
	}

	if (id < 0)
	{
		throw invalid_argument("Error (Invalid ID): Id must not be negative!");
	}

	if (runtime < 0)
	{
		throw invalid_argument("Error (Invalid Runtime): Runtime must not be negative! Also funfact: the longest movie ever made is 857 hours or 51420 minutes");
	}

	if (rating < 0 || rating > 10) 
	{
		throw invalid_argument("Ratings must be from 0-10");
	}

	this->title = title;
	this->director = director;
	this->id = id;
	this->runtime = runtime;
	this->rating = rating;
}

int Movie::GetId() 
{
	return id;
}

string Movie::GetTitle() 
{
	return title;
}

string Movie::GetDirector() 
{
	return director;
}

double Movie::GetRating() 
{
	return rating;
}

int Movie::GetRuntime() 
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