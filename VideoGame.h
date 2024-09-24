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
    //getters
    Text* getVideoGameName();
    Text* getVideoGameAuthor();
    Text* getVideoGamePublisher();
    int getVideoGameYear();
    int getVideoGameRating();
    //setters
    void setVideoGameName(Text*);
    void setVideoGameAuthor(Text*);
    void setVideoGamePublisher(Text*);
    void setVideoGameYear(int);
    void setVideoGameRating(int);


};


#endif