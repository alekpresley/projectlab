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
        cout << "Please pick an option" << endl;
        cout << "1. Adds Games" << endl;
        cout << "2. Removing Games" << endl;
        cout << "3. Displays" << endl;
        cout << "4. save" << endl;
        cout << "5. Load" << endl;
        cout << "6. Close program" << endl;
        cin >> choice;
        //cout << endl << endl;
        switch (choice) {
            case 1:
                cout << "You pick 1." << endl;
                library->addVideoGamesToArray();
                break;
            case 2:
                cout << "You pick 2. " << endl;
                library->removeVideoGameFromArray();
                break;
            case 3:
                cout << "You pick 3. " << endl;
                library-> displayVideoGames();
                break;
            case 4:
                cout << "Your pick 4. " << endl;
                cout << "Enter a file name to save the game ";
                cin >> fileName;
                library-> saveToFile(fileName);
                break;
            case 5:
                cout << "Your pick 5. " << endl;
                cout << "Enter a file name to save the game ";
                cin >> fileName;
                library-> loadVideoGamesFromFile(fileName);
                break;
            case 6:
                cout << "Goodbye\n";
                break;
        }
    }while(choice!=6);
    
	
	
    return 0;
}