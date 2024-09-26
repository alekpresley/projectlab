/*
    File name: Text.cpp
    Author: Tobin McGee, Alek Presley, Sujal Gohil, Tristen Martin
    Date: 9/17/24
    Purpose: source file conaining function definitions required for the Text class
*/
#include "Text.h"

//Text object constructor. Creates a pointer to an array of characters from the passed in c-string
Text::Text(char* input){
    int k = 0;
    textLength = strlen(input);
    char* tempArray;
    tempArray =  new char [textLength+1]; //dynamically allocate an array of characters of the length of the input plus a space for a null terminator
    strcpy(tempArray, input); //copy contents of the input to the created temporary array
    textArray = tempArray; //assign text array to tempArray
};
//Text destructor. Releases memory that was allocated for the textArray
Text::~Text(){
    delete [] textArray;
    cout << "\nText destructor: Released memory for textArray.";
};
//function that prints the c-string stored within the Text object
void Text::displayText(){

    cout << textArray;
    return;
};
//function that retun=rns the c-string within the Text object
const char* Text::getText(){
    
    return textArray;
};
//returns the stored text length
int Text::getLength(){
    return textLength;
};