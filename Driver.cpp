#include "VideoGame.h"
#include "VideoGameLibrary.h"
/*
    File name: Driver.cpp
    Author: Tobin McGee, Alek Presley, Sujal Gohil, Tristen Martin
    Date: 9/17/24
    Purpose: Main 
*/
int main(){
    int choice;
    int libSize;
    VideoGameLibrary* library;
    char fileName[1000];
    cout << "\nHow many games do you wish to play?\n";
    cin >> libSize;
    library = new VideoGameLibrary(libSize);
    do{
        cout << " _ _ _     _                     " << endl;
        cout << "| | | |___| |___ ___ _____ ___   " << endl;
        cout << "| | | | -_| |  _| . |     | -_|  " << endl;
        cout << "|_____|___|_|___|___|_|_|_|___|  " << endl;
        cout << "                                 " << endl;
        cout << "WELCOME TO THE VIDEOGAME LIBRARY!" << endl << endl;
        cout << "Please pick an option" << endl;
        cout << "1. Adds Games" << endl;
        cout << "2. Removing Games" << endl;
        cout << "3. Display Title Only" << endl;
        cout << "4. Displays" << endl;
        cout << "5. Save" << endl;
        cout << "6. Load" << endl;
        cout << "7. Sort by year " << endl;
        cout << "8. Close Program" << endl;
        cin >> choice;
        //cout << endl << endl;
        switch (choice) {
            case 1:
                cout << "\nYou pick 1. " << endl;
                library->addVideoGamesToArray();
                break;
            case 2:
                cout << "\nYou pick 2. " << endl;
                library->removeVideoGameFromArray();
                break;
            case 3:
                cout << "\nYou pick 3. " << endl;
                library-> displayVideoGameTitles();
                break;
            case 4:
                cout << "\nYou pick 4. " << endl;
                library-> displayVideoGames();
                break;
            case 5:
                cout << "\nYou pick 5. " << endl;
                cout << "Enter a file name to save the game: ";
                cin >> fileName;
                library-> saveToFile(fileName);
                break;
            case 6:
                cout << "\nYou pick 6. " << endl;
                cout << "Enter a file name to save the game: ";
                cin >> fileName;
                library-> loadVideoGamesFromFile(fileName);
                break;
            case 7:
                cout << "\nYou pick 7. " << endl;
                //sorting
            case 8:
                cout << "Goodbye\n";
                break;

        }
    }while(choice!=8);
    
	
	
    return 0;
}