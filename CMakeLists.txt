cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(MovieRating)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(MovieRating src/movie.cpp src/movie_factory.cpp src/main.cpp)

add_executable(my_test src/movie.cpp src/movie_factory.cpp test/test.cpp)

target_include_directories(my_test PRIVATE ${PROJECT_SOURCE_DIR}/include)

enable_testing()