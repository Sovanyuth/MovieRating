#include "movie.h"
#include <string>
#include <iostream>
using namespace std;

Movie::Movie(int id, string title, string director, int runtime, double rating) 
	:id(id), title(title), director(director), runtime(runtime), rating(rating) {}

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

int Movie::GetRunTime()
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