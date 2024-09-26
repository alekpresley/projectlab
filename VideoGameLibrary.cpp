#include "VideoGameLibrary.h"
/*
    File Name: VideoGameLibrary.cpp
    Authors: Tobin McGee, Alek Presley, Sujal Gohil, Tristen Martin
    Date:9/24/24
    Purpose: driver file for the videogamelibrary object.
*/

// Constructor
VideoGameLibrary::VideoGameLibrary (int maxGame) {

    this->maxGame = maxGame;
    numGame = 0;
    videoGamesArray = new VideoGame*[maxGame];
    return;
};

// Destructor
VideoGameLibrary::~VideoGameLibrary() {
     for (int i = 0; i < numGame; i++) {
        delete videoGamesArray[i];
    }
    delete[] videoGamesArray;
    cout << "VideoGameLibrary was deleted";
    
};

void VideoGameLibrary::displayVideoGames(){
    if(numGame == 0){ 
            cout << "\nThere are no games in your Library!\n ";
    }
    else{
        for(int i =0; i < numGame; i++){
            cout << videoGamesArray[i]->getVideoGameName() << endl;
            cout << videoGamesArray[i]->getVideoGameAuthor() << endl;
            cout << videoGamesArray[i]->getVideoGamePublisher() << endl;
            cout << videoGamesArray[i]->getVideoGameYear() << endl;
            cout << videoGamesArray[i]->getVideoGameRating() << endl;   
        }
    } 
};
void VideoGameLibrary::displayVideoGameTitles(){
    if(numGame == 0){ 
            cout << "\nThere are no games in your Library!\n ";
    }
    else{
        for(int i =0; i < numGame; i++){
            cout << videoGamesArray[i]->getVideoGameName();

        }
    }
};
void VideoGameLibrary::saveToFile(char* fileName){
    ofstream outfile; //outputs to the file
    outfile.open(fileName);
	for(int i = 0; i < numGame; ++i){ //loop goes through all games
        outfile << videoGamesArray[i]->getVideoGameName() << endl; 
        outfile << videoGamesArray[i]->getVideoGameAuthor() << endl; 
        outfile << videoGamesArray[i]->getVideoGamePublisher() << endl; 
        outfile << videoGamesArray[i]->getVideoGameYear() << endl;
        outfile << videoGamesArray[i]->getVideoGameRating() << endl;
    }
    outfile.close();
	cout << "\nAll video games in your library have been printed to " << fileName << endl;
	return;
};
//function definition meant to pull the data from the provided files
void VideoGameLibrary::loadVideoGamesFromFile(char* filename){

    //variable delcarations
    ifstream infile;
    char temp[10000]; //c-string to hold current line
    int year;
    int rating;
    int gamesAdded = 0;
    Text* outTitle;
    Text* outDev;
    Text* outPub;
    
    //uses the passed in c-string to open the file of the same name
    infile.open(filename);
    //if the file fails to open, prints a failure message
    if(!infile){
        cout << "\nSorry, I was unable to open the file.\n";
    }

    /* 
    attempts a getline from the file, trying to assign it to the temp c-string.
    Failure of the getline skips the while loop, terminating the function with no other output and returns the user to the menu 
    */
    while(infile.getline(temp,10000));
    {
        //check to see if the game library is full, if so, call the resizeVideoGameArray function to double the array's size
        if(numGame == maxGame){
            resizeVideoGameArray();
        }

        //creates(or overwritesin other iterations) a new Text object pointer of the data from the temp char array
        outTitle = new Text(temp);

        //assumes that a valid games details are to be read and begins pulling the remaining three lines of data
        infile.getline(temp,10000);
        outDev = new Text(temp);
        infile.getline(temp,10000);
        outPub = new Text(temp);
        infile >> year;
        infile >> rating;
        infile.ignore(); 

        //call the VideoGame constructor to make a new VideoGame object in the correct posisition of the videoGamesArray. Uses the temporary text object pointers
        videoGamesArray[numGame] = new VideoGame(outTitle, outDev, outPub, year, rating);
        numGame++; //increment the number of games
        gamesAdded++; //increment the count of games added
        cout << endl;
        outTitle->displayText();
        cout << " was added successfully";
    }
    cout << "\n" << gamesAdded << " video games were read from the file and added to your VideoGame library.\n";
    infile.close(); //close the ifstream to the file before exiting the function
    return;
};