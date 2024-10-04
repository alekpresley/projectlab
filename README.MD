READ.ME
Project 1 for CSC 1310
Group Members Tobin McGee, Alek Presley, Sujal Gohil, Tristen Martin

Program: Virtual Video Game Library

Details: This Project allows the user to have a library of video games. it provides functions that allow the use to add,remove,display,displaytitles only,change details of a video game, save to file, load from file, sort by year and sort by rating. The user is able to pick one of the options by a menu base program.

Important Classes
VideoGameLibrary: Holds Functions for the menu and manages all the video gamess
VideoGame: Holds the data for the functions. Setters and Getters.
Text: C++ string class
    

Functions:
        Main Menu - Allows the user to control the library
            Add Game - Manual entry of a game and it's details
            Remove Game - Allows deletion of a game from virtual library
            Change Details - Allows selection of a game to change detail
                Change Game menu - Allows selection of specific game to change
            Display Titles - Displays library in compact list of only titles with indexes
            Display all details - Displays expanded list off all games and details without indexes
            Save to File - Stores games and their details to a user specified file. Will overwrite exisitng lines or create new txt file
            Load from file - Imports Games and details from txt file in correct format. Example three_games.txt
            Sort Video Games by Year - Quick sort all games in virtual library by their release year
            Sort Video Games by Rating - Quick sort all games in virtual library by their IGN rating
            Delete Virtual Library and End Program - Release dynamically allocated memory and end program
Structure:
        Driver - Contains main menu logic
        Text object - Custom object that replaces the included string class.
        VideoGamelibrary object - Storage Class for the library. Handles the array of games. Holds most of the program's functions.
        VideoGame object - Data class for the Video Game objects. Handles the details of each game.