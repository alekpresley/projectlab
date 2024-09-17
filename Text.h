/*
    File name: Text.h
    Author: Tobin B. McGee
    Date: 9/15/24
    Purpose: header file for a Text class, which is my own version of the C++ String Class
*/

#include <iostream>
using namespace std;

#ifndef TEXT_H
#define TEXT_H
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