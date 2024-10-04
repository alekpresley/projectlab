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
    VideoGameLibrary* library; //creates library object
    char fileName[1000]; //c-string to store filename
    cout << "\nHow many games do you wish for your virtual library to hold?\n";
    cin >> libSize; //size for the array
    library = new VideoGameLibrary(libSize);  //dynamically allocates the memory to library
    
    //Intro
    cout << " _ _ _     _                     " << endl;
    cout << "| | | |___| |___ ___ _____ ___   " << endl;
    cout << "| | | | -_| |  _| . |     | -_|  " << endl;
    cout << "|_____|___|_|___|___|_|_|_|___|  " << endl;
    cout << "                                 " << endl;

    do{
        //Main Menu Logic
        cout << "\nWELCOME TO THE VIDEOGAME LIBRARY!" << endl << endl;
        cout << "Please pick an option 1 to 10" << endl;
        cout << "1. Add a Game To Virtual Library" << endl;
        cout << "2. Remove a Game From Virtual Library" << endl;
        cout << "3. Change Video Game Details" << endl;
        cout << "4. Display Video Game Titles" << endl;
        cout << "5. Display All Video Game Details" << endl;
        cout << "6. Save Virtual Library To File" << endl;
        cout << "7. Load Video Games From File to Virtual Library" << endl;
        cout << "8. Sort Video Games By Year " << endl;
        cout << "9. Sort Video Games By Rating " << endl;
        cout << "10. Delete Virtual Library And Close Program" << endl;
        cin >> choice;

        //Makes sure you stay in bounds
        while(choice < 1 || choice > 10){
            cout << "\nINVALID ENTRY. Please choose again: ";
            cin >> choice;
        };

        switch (choice) {
            case 1:
                cout << "\nYou pick 1. " << endl;
                library->addVideoGamesToArray(); //calls add function
                break;
            case 2:
                cout << "\nYou pick 2. " << endl;
                library->removeVideoGameFromArray();//calls remove function
                break;
            case 3:
                cout << "\nYou pick 3. " << endl;
                library->changeVideoGameDetails();//calls to change any details 
                break;
            case 4:
                cout << "\nYou pick 4. " << endl;
                library->displayVideoGameTitles(); //call to displaytitle function
                break;
            case 5:
                cout << "\nYou pick 5. " << endl;
                library->displayVideoGames();//calls to displayvideogame function to print everyone
                break;
            case 6:
                cout << "\nYou pick 6. " << endl;
                cout << "Enter a file name to save the game: ";
                cin >> fileName; //takes in file
                library->saveToFile(fileName); //save the data into the file they input by calling save tofile function
                break;
            case 7:
                cout << "\nYou pick 7. " << endl;
                cout << "Enter a file name to save the game: ";
                cin >> fileName; //takes in file
                library->loadVideoGamesFromFile(fileName); //loads in the data from the file they input by calling save tofile function
                break;
            case 8:
                cout << "\nYou pick 8. " << endl;
                library->sortVideoGamesByYear();//calls the sort function to sort it by the year by using quicksort 
                break;
            case 9:
                cout << "\nYou pick 9. " << endl;
                library->sortVideoGamesByRating(); //calls the sort function to sort it by the rating by using quicksort
                break;
            case 10:
                cout << "Goodbye\n"; 
                break;

        }
    }while(choice!=10);

    delete library; //Calls the library destructor which calls all nested destructors, freeing all memory
    
    return 0;
}