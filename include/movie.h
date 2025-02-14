#ifndef MOVIE_H
#define MOVIE_H
#include <string>

using namespace std;
// Creating a class movie 
class Movie {
	private:
		// Having these data that is unique to each movie as private data
		int id;

		string title;
		string director;
		int runtime;
		double rating;

	public:
		// Public Data: All of the methods that includes mutators and accessors.
		Movie(int id, string, string, int runtime, double rating);
		int GetId();
		string GetTitle();
		string GetDirector();
		double GetRating();
		int GetRunTime();

		void PrintMoveData();
};

#endif // MOVIE_H