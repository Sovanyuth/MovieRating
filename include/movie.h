#ifndef MOVIE_H
#define MOVIE_H
#include <string>

using namespace std;

class Movie {
	private:
		int id;

		string title;
		string director;
		int runtime;
		double rating;

	public:
		Movie(int id, string title, string director, int runtime, double rating);

		string GetTitle();
		string GetDirector();
		double GetRating();
		int GetRunTime();

		void PrintMoveData();
};

#endif // MOVIE_H