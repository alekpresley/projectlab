/*
    File Name: VideoGame.cpp
    Authors: Tobin McGee, Alek Presley, Sujal Gohil, Tristen Martin
    Date:9/24/24
    Purpose: driver file for the videogame object.
*/
#include "VideoGame.h"

//Constructor
VideoGame::VideoGame(Text* inName, Text* inAuthor, Text* inPublisher,int inYear,int inRating){
    name = inName;
    author = inAuthor;
    publisher = inPublisher;
    year = inYear;
    rating = inRating;

    
};
//Destructor
VideoGame::~VideoGame(){
    delete name;
    delete author;
    delete publisher;
    cout << "\n\nName, Author, Publisher was deleted!";
};
//getter for the name
Text* VideoGame::getVideoGameName(){
    return this->name;

};
//getter for the author
Text* VideoGame::getVideoGameAuthor(){
    return this->author;

};
//getter for publisher
Text* VideoGame::getVideoGamePublisher(){
    return this->publisher;

};
//getter for year
int VideoGame::getVideoGameYear(){
    return this->year;

};
//getter for rating 
int VideoGame::getVideoGameRating(){
    return this->rating;

};
//setter for name
void VideoGame::setVideoGameName(Text* newname){
    name = newname;
};
//setter for author
void VideoGame::setVideoGameAuthor(Text* newauthor){
    author = newauthor;
};
//setter for publisher
void VideoGame::setVideoGamePublisher(Text* newpublisher){
    publisher = newpublisher;
};
//setter for year
void VideoGame::setVideoGameYear(int newyear){
    year = newyear;
};
//setter for rating
void VideoGame::setVideoGameRating(int newrating){
    rating = newrating;
};







