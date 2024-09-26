#include "VideoGameLibrary.h"
/*
    File Name: VideoGameLibrary.cpp
    Authors: Tobin McGee, Alek Presley, Sujal Gohil, Tristen Martin
    Date:9/24/24
    Purpose: driver file for the videogamelibrary object.
*/

// Constructor
VideoGameLibrary::VideoGameLibrary (int maxGame) {
    this->maxGame = maxGame;
    numGame = 0;

    videoGamesArray = new VideoGame*[maxGame];
    for (int i = 0; i < maxGame; ++i) {
        videoGamesArray[i] = nullptr;
    }
}

// Destructor
VideoGameLibrary::~VideoGameLibrary() {
    for (int i = 0; i < numGame; ++i) {
        delete videoGamesArray[i];
    }
    delete[] videogameArray;
    cout << "VideoGameLi"
}