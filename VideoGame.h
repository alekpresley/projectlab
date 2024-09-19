#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "Text.h"
class VideoGame{
    private:
    Text* name;
    Text* author;
    Text* publisher;
    int year;
    int rating;

    public:
    VideoGame(Text*,Text*, Text*, int, int);
    ~VideoGame();
    string getName(Text*);
    string getAuthor(Text*);
    string getPublisher(Text*);
    int getYear(int);
    int getRating(int);


};


#endif