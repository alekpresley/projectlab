/*
    File name: Text.h
    Author: Tobin McGee, Alek Presley, Sujal Gohil, Tristen Martin
    Date: 9/15/24
    Purpose: header file for a Text class, which is my own version of the C++ String Class
*/
#ifndef TEXT_H
#define TEXT_H
#include <iostream>
#include <cstring>
using namespace std;

class Text
{
private:
    //Text class attributes
    const char* textArray;
    int textLength;

public:
    //public function prototypes
    Text(char*);
    ~Text();
    void displayText();
    const char* getText();
    int getLength();
};

#endif 