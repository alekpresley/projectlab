#include <iostream>
#include <fstream>
#include "Text.h"
#include "VideoGame.h"
using namespace std;

/*
    File Name: VideoGameLibrary.H
    Authors: Tobin McGee, Alek Presley, Sujal Gohil, Tristen Martin
    Date:9/24/24
    Purpose: Header File for Videogamelibrary.cpp
*/

#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H
class VideoGameLibrary{
    private:
        VideoGame** videoGamesArray;
        int maxGame;
        int numGame;

    public:
        //public function prototypes
        void resizeVideoGameArray();
        void addVideoGamesToArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void loadVideoGamesFromFile(char*);
        void removeVideoGameFromArray();
        void saveToFile(char*);
        void displayVideoGamePublishers();
        void changeVideoGameDetails();
        void sortVideoGameGenre();
        VideoGameLibrary(int maxGame);
        ~VideoGameLibrary();
};
#endif