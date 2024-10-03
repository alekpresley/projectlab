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
        //Private
        VideoGame** videoGamesArray;
        int maxGame;
        int numGame;

    public:
        //Public function prototypes
        void resizeVideoGameArray();
        void addVideoGamesToArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void loadVideoGamesFromFile(char*);
        void removeVideoGameFromArray();
        void saveToFile(char*);
        void displayVideoGamePublishers();
        void changeVideoGameDetails();
        void sortVideoGamesByRating();
        void sortVideoGamesByYear();
        void quickSortYear(VideoGame**, int, int);
        int partitionYear(VideoGame**, int, int);
        void quickSortRating(VideoGame**, int, int);
        int partitionRating(VideoGame**, int, int);
        VideoGameLibrary(int maxGame);
        ~VideoGameLibrary();
};
#endif