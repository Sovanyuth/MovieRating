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
		Movie(int id, const string& title, const string& director, int runtime, double rating);
		int GetId() const;
		string GetTitle() const;
		string GetDirector() const;
		double GetRating() const;
		int GetRunTime() const;

		void PrintMoveData();
};

#endif // MOVIE_H