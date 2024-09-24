#include <iostream>
#include <fstream>
#include "Text.h"
#include "VideoGame.h"
using namespace std;

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