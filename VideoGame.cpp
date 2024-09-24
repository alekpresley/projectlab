/*
    File Name: VideoGame.cpp
    Authors: Tobin McGee, Alek Presley, Sujal Hohil, Tristen Martin
*/
#include "VideoGame.h"

VideoGame::VideoGame(Text* name, Text* author, Text* publisher,int year,int rating){
    name = name;
    author = author;
    publisher = publisher;
    year = year;
    rating = rating;
};
VideoGame::~VideoGame(){
    delete name;
    delete author;
    delete publisher;
    cout << "\n\nName, Author, Publisher was deleted!";
};

Text* VideoGame::getVideoGameName(){
    return this->name;

};
Text* VideoGame::getVideoGameAuthor(){
    return this->author;

};
Text* VideoGame::getVideoGamePublisher(){
    return this->publisher;

};
int VideoGame::getVideoGameYear(){
    return this->year;

};

int VideoGame::getVideoGameRating(){
    return this->rating;

};
void VideoGame::setVideoGameName(Text* newname){
    name = newname;

};

void VideoGame::setVideoGameAuthor(Text* newauthor){
    author = newauthor;
};

void VideoGame::setVideoGamePublisher(Text* newpublisher){
    publisher = newpublisher;
};

void VideoGame::setVideoGameYear(int newyear){
    year = newyear;
};

void VideoGame::setVideoGameRating(int newrating){
    rating = newrating;
};







