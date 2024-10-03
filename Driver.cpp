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
    cout << "\nHow many games do you wish for your virtual library to hold?\n";
    cin >> libSize;
    library = new VideoGameLibrary(libSize);

    cout << " _ _ _     _                     " << endl;
    cout << "| | | |___| |___ ___ _____ ___   " << endl;
    cout << "| | | | -_| |  _| . |     | -_|  " << endl;
    cout << "|_____|___|_|___|___|_|_|_|___|  " << endl;
    cout << "                                 " << endl;

    do{
        cout << "\nWELCOME TO THE VIDEOGAME LIBRARY!" << endl << endl;
        cout << "Please pick an option 1 to 10" << endl;
        cout << "1. Adds Game To Virtual Library" << endl;
        cout << "2. Removing Games From Virtual Library" << endl;
        cout << "3. Change Video Game Details" << endl;
        cout << "4. Display Video Game Titles" << endl;
        cout << "5. Display All Video Game Details" << endl;
        cout << "6. Save Virtual Library To File" << endl;
        cout << "7. Load Video Games From File to Virtual Library" << endl;
        cout << "8. Sort Video Games By Year " << endl;
        cout << "9. Sort Video Games By Rating " << endl;
        cout << "10. Delete Virtual Library And Close Program" << endl;
        cin >> choice;
        while(choice < 1 || choice > 10){
        cout << "\nINVALID ENTRY. Please choose again: ";
        cin >> choice;
        };
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
                break;
            case 4:
                cout << "\nYou pick 4. " << endl;
                library-> displayVideoGameTitles();
                break;
            case 5:
                cout << "\nYou pick 5. " << endl;
                library-> displayVideoGames();
                break;
            case 6:
                cout << "\nYou pick 6. " << endl;
                cout << "Enter a file name to save the game: ";
                cin >> fileName;
                library-> saveToFile(fileName);
                break;
            case 7:
                cout << "\nYou pick 7. " << endl;
                cout << "Enter a file name to save the game: ";
                cin >> fileName;
                library-> loadVideoGamesFromFile(fileName);
                break;
            case 8:
                cout << "\nYou pick 8. " << endl;
                break;
            case 9:
                cout << "\nYou pick 9. " << endl;
                break;
            case 10:
                cout << "Goodbye\n";
                break;

        }
    }while(choice!=10);

    delete library;
    
    return 0;
}