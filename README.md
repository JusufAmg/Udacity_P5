# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.
_________________________________________________________________________________________________________________________________________________________________________________
## Project Rubric

### Loops, Functions, I/O

CRITERIA|SPECIFICATIONS
---|---
The project demonstrates an understanding of C++ functions and control structures.|In main.cpp, there are many control structures that use different functions to ensure that the game is handling input from the user correctly.
The project reads data from a file and process the data, or the program writes data to a file.|The project creates a file highscore.txt and reads the names and scores from it and then writes the new score in it.
The project accepts user input and processes the input.|In main.cpp , the project accepts user’s name to save it with the game score in highscore.txt.

### Object Oriented Programming

CRITERIA|SPECIFICATIONS
---|---
The project uses Object Oriented Programming techniques.|I have created Score class that handles creating the high score file, sorts the scores and prints them.
Classes use appropriate access specifiers for class members.|All class data members are explicitly specified as public, protected, or private.
Class constructors utilize member initialization lists.|Score constructor utilizes the private member File_Name .
Classes abstract implementation details from their interfaces.|All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.
Classes follow an appropriate inheritance hierarchy.|Inheritance was not logical in this program and I couldn’t implement it.

### Memory Management
CRITERIA|SPECIFICATIONS
---|---
The project makes use of references in function declarations.|In score.cpp, the function Sort accepts scores as a reference to make the changes directly on the vector.

### Concurrency
CRITERIA|SPECIFICATIONS
---|---
The project uses multithreading|The member function Score::Data runs in a thread, to allow the program to load the required data while the player is playing the game.

