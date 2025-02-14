#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "movie.h"
#include "movie_factory.h"
#include "vector"

TEST_CASE("Movie class fuctions", "[Movie][valid]")
{
    Movie* uniqueMoviePtr = new Movie(1, "Avengers:Infinity War", "Anthony/Joe Russo", 149, 8.4);
    // Test 1: Teting all of the member variables of my class
    REQUIRE(uniqueMoviePtr->GetDirector() == "Anthony/Joe Russo");
    REQUIRE(uniqueMoviePtr->GetId() == 1);
    REQUIRE(uniqueMoviePtr->GetTitle() == "Avengers:Infinity War");
    REQUIRE(uniqueMoviePtr->GetRunTime() == 149);
    REQUIRE(uniqueMoviePtr->GetRating() == 8.4);

    delete uniqueMoviePtr;
}

TEST_CASE("Movie class fuctions invalid cases", "[Movie][invalid]")
{
    // Test 2: Teting all of the exceptions that must be thrown by the errors caused in the constructor
    // Case 1: Invalid Id: ID is negative
    REQUIRE_THROWS_AS(Movie(-1, "Avengers:Infinity War", "Anthony/Joe Russo", 149, 8.4), invalid_argument);

    // Case 2: Movie title or director is empty
    REQUIRE_THROWS_AS(Movie(4, "", "", 149, 8.4), invalid_argument);

    // Case 3: Invalid Movie runtime
    REQUIRE_THROWS_AS(Movie(4, "Wall-E", "Andrew Stanton", -13, 8.4), invalid_argument);

    // Case 4: Rating exceeds limit
    REQUIRE_THROWS_AS(Movie(4, "Wall-E", "Andrew Stanton", 133, 12), invalid_argument);
}

TEST_CASE("Vector of Movies, [CreateMovies][valid]") 
{
    std::vector<std::string> titles{ "John Wick 4", "Dune:Part Two", "La la land", "StarWars: Episode III - Revenge of the Sith", "Oppenheimer" };
    std::vector<std::string> directors{ "Director 1", "Director 2", "Director 3", "Director 4", "Director 5" };
    std::vector<int> runtimes{ 169, 166, 128, 140, 180 };
    std::vector<int> ids{ 1, 2, 3, 4, 5 };
    std::vector<double> ratings{ 9.4, 9.2, 9.1, 8.0, 9.3 };

    std::vector<Movie*> movies = CreateMovies(ids, titles, directors, runtimes, ratings);
    REQUIRE(movies.size() == 5);
    REQUIRE(movies[0]->GetTitle() == "John Wick 4");
    REQUIRE(movies[1]->GetTitle() == "Dune:Part Two");
    REQUIRE(movies[4]->GetTitle() == "Oppenheimer");

    REQUIRE(movies[2]->GetRunTime() == 128);
    REQUIRE(movies[3]->GetRating() == 8.0);

    deallocateNewPtrs(movies);
}

TEST_CASE("Empty Input Vectors", "[CreateMovies][invalid]") 
{
    SECTION("Empty Vectors") 
    {
        std::vector<std::string> titles;
        std::vector<std::string> directors;
        std::vector<int> runtimes;
        std::vector<int> ids;
        std::vector<double> ratings;

        // ... (Assertions to check if an exception is thrown or an empty vector is returned)
        REQUIRE_THROWS_AS(CreateMovies(ids, titles, directors, runtimes, ratings), invalid_argument);
    }

    SECTION("Different Sizes Vectors")
    {
        std::vector<std::string> titles{"Cinderella", "The Notebook", "Parasite"};
        std::vector<std::string> directors{"Director 1", "Director 2"};
        std::vector<int> runtimes{76, 121, 132};
        std::vector<int> ids{1, 2, 3};
        std::vector<double> ratings{7.8, 8.4, 9.2, 7.4};

        // ... (Assertions to check if an exception is thrown or an empty vector is returned)
        REQUIRE_THROWS_AS(CreateMovies(ids, titles, directors, runtimes, ratings), invalid_argument);
    }

    SECTION("1 Movie has an invalid runtime")
    {
        std::vector<std::string> titles{ "Cinderella", "The Notebook", "Parasite" };
        std::vector<std::string> directors{ "Director 1", "Director 2", "Director 3"};
        std::vector<int> runtimes{ 76, 121, -1 };
        std::vector<int> ids{ 1, 2, 3 };
        std::vector<double> ratings{ 7.8, 8.4, 9.2};

        // ... (Assertions to check if an exception is thrown or an empty vector is returned)
        REQUIRE_THROWS_AS(CreateMovies(ids, titles, directors, runtimes, ratings), invalid_argument);
    }
}