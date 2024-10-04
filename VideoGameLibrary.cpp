#include "VideoGameLibrary.h"
/*
    File Name: VideoGameLibrary.cpp
    Authors: Tobin McGee, Alek Presley, Sujal Gohil, Tristen Martin
    Date:9/24/24
    Purpose: driver file for the videogamelibrary object.
*/


/*
    Function Name: VideoGameLibrary (constructor)
    Purpose: Assigns the maxGame variable (set by the user when the program starts)
             and dynamically allocates a new VideoGame array
*/
VideoGameLibrary::VideoGameLibrary (int maxGame) {

    this->maxGame = maxGame;
    numGame = 0;
    videoGamesArray = new VideoGame*[maxGame];
    return;
};

/*
    Function Name: VideoGameLibrary (destructor)
    Purpose: deletes each index in the videoGamesArray
*/
VideoGameLibrary::~VideoGameLibrary() {
     for (int i = 0; i < numGame; i++) {
        delete videoGamesArray[i];
    }
    delete[] videoGamesArray;
    cout << "VideoGameLibrary was deleted";
    
};
/*
    Function Name: changeVideoGameDetails
    Purpose: Display game titles with display titles and use menu logic to select game.
        Then use a nested menu to change game attributes
*/

void VideoGameLibrary::changeVideoGameDetails(){
    //variable declaration
    int selection;
    int newSel;
    
    //check if the library is empty
    if(numGame < 1){
        cout << "\nThere must always be at least one game in the library to use this function.\n";
    }
    else{
        //Ask the user what game they want to remove after listing the game titles
        cout << "\nChoose from the following video games to modify:\n";
        displayVideoGameTitles(); //calls this function that will do as described
        cout << "\nChoose a video game between 1 & " << numGame << " (or 0 to cancel the operation): ";
        cin >> selection;
        //logic to see if the user chose a valid game to modify
        while(selection < 0 || selection > numGame){
            cout << "\nOops! You need to enter a valid selection: ";
            cin >> selection;
        }
        //exits function if user decides to cancel
        if(selection==0){
            return;
        }
        newSel = selection - 1;//newSel corrects the index of the choice to the games index in the array

        //Variable Declarations for nested menu
        int choice;
        Text* tempWord;
        char temp[100];
        int tempNum;
        //Menu Logic to choice what trait to change
        do{
            cout << endl << "1. Title: " << videoGamesArray[newSel]->getVideoGameName()->getText() << endl;
            cout << "2. Author: " << videoGamesArray[newSel]->getVideoGameAuthor()->getText() << endl;
            cout << "3. Publisher: " << videoGamesArray[newSel]->getVideoGamePublisher()->getText() << endl;
            cout << "4. Year: " << videoGamesArray[newSel]->getVideoGameYear() << endl;
            cout << "5. Rating: " << videoGamesArray[newSel]->getVideoGameRating() << endl;
            cout << "6. Exit" << endl;
            cout << "What would you like to change the Name, Author, Publisher, Year, or Rating, Exit (Using Nums 1-6)" << endl;

            cin >> choice;
            //Ensures the user enters a valid trait index
            while(choice < 1 || choice > 6){
                cout << "\nINVALID ENTRY. Please choose again: " << endl;
                cin >> choice;
            };
            
            //Nested Game menu logic that loops until the user exits
            switch(choice){  
                    
            case 1:
                cout << "\nEnter new Game Name: ";
                cin.ignore(); // clears cin to avoid issues with cin.getline
                cin.getline(temp, 100); // aquires the users input and sets the temp character array to this input
                tempWord = new Text(temp); //dynamically create a temp word object
                videoGamesArray[newSel]->setVideoGameName(tempWord); //
                break;
            case 2:
                cout << "\nEnter new Author Name: ";
                cin.ignore(); // clears cin to avoid issues with cin.getline
                cin.getline(temp, 100); // aquires the users input and sets the temp character array to this input
                tempWord = new Text(temp);
                videoGamesArray[newSel]->setVideoGameAuthor(tempWord);
                break;
            case 3:
                cout << "\nEnter new Publisher Name: ";
                cin.ignore(); // clears cin to avoid issues with cin.getline
                cin.getline(temp, 100); // aquires the users input and sets the temp character array to this input
                tempWord = new Text(temp);
                videoGamesArray[newSel]->setVideoGamePublisher(tempWord);
                break;
            case 4:
                cout << "\nEnter new Release Year: ";
                cin.ignore(); // clears cin to avoid issues with cin.getline
                cin >> tempNum;
                videoGamesArray[newSel]->setVideoGameYear(tempNum);
                break;
            case 5:
                cout << "\nEnter new IGN rating: (whole number 0-10)";
                cin.ignore(); // clears cin to avoid issues with cin.getline
                cin >> tempNum; // aquires the users input and sets the temp character array to this input
                videoGamesArray[newSel]->setVideoGameRating(tempNum);
                break;
            case 6:
                cout << "\nExiting Change Details.\n";
                break;
        }

        }while(choice!=6);
    }
    return;
};
/*
    Function Name: sortVideoGamesByRating
    Purpose: sorts each index within the videoGamesArray by its IGN rating
             checks if Library has games. If so, call quicksort for rating
*/
void VideoGameLibrary::sortVideoGamesByRating(){
    if(numGame < 1){
        cout << "\nThere must always be at least one game in the library to use this function.\n";
        return;
    }
    cout << "Starting to sort by Rating\n";
   	quickSortRating(videoGamesArray, 0, numGame-1);
    cout << "Finished sort.\n";
    return;
};
/*
    Function Name: quickSortRating
    Purpose: sorts each index within the videoGamesArray by its IGN rating
        Recursive Quicksort function definition
*/
void VideoGameLibrary::quickSortRating(VideoGame** inVideoGamesArray, int low, int high) {
  if (low < high) {
    int temp = partitionRating(videoGamesArray, low, high);
    quickSortRating(videoGamesArray, low, temp-1); 
    quickSortRating(videoGamesArray, temp+1, high);
  }
  return;
};
/*
    Function Name: partitionRating
    Purpose:  Quick sort partition fucntion definition
        
*/
int VideoGameLibrary::partitionRating(VideoGame** sortVideoGamesArray, int left, int right) {
  VideoGame* partition = sortVideoGamesArray[left]; 
  int temp = left; 
  VideoGame* tempArray;
  
  for (int i = left+1; i <= right; i++) { 
    if ((sortVideoGamesArray[i]->getVideoGameRating() < partition->getVideoGameRating()) || ((sortVideoGamesArray[i]->getVideoGameRating() == partition->getVideoGameRating()) && (rand()%2 == 0)))  {
      temp = temp +1;

	//swaps sortVideoGamesArray[i] and sortvideoGamesArray[temp]
	tempArray = sortVideoGamesArray[i];
	sortVideoGamesArray[i] = sortVideoGamesArray[temp];
	sortVideoGamesArray[temp] = tempArray;
    }
  }

  //swaps sortVideoGamesArray[left] and sortVideoGamesArray[temp]
  tempArray = sortVideoGamesArray[left];
  sortVideoGamesArray[left] = sortVideoGamesArray[temp];
  sortVideoGamesArray[temp] = tempArray;
  return temp;
};

/*
    Function Name: sortVideoGamesByYear
    Purpose: sorts each index within the videoGamesArray by the year it was released
*/
void VideoGameLibrary::sortVideoGamesByYear(){
    if(numGame < 1){
        cout << "\nThere must always be at least one game in the library to use this function.\n";
        return;
    }
   cout << "Starting to sort by Year.\n";
   	quickSortYear(videoGamesArray, 0, numGame-1);
    cout << "Finished sort.\n";
};

/*
    Function Name: quickSortYear
    Purpose: sorts each index within the videoGamesArray by the year it was released
*/
void VideoGameLibrary::quickSortYear(VideoGame** inVideoGamesArray, int low, int high) {
  if (low < high) {
    int temp = partitionYear(videoGamesArray, low, high);
    quickSortYear(videoGamesArray, low, temp-1); 
    quickSortYear(videoGamesArray, temp+1, high);
  }
};

/*
    Function Name: partitionYear
    Purpose: Quick sort partition function for year
*/
int VideoGameLibrary::partitionYear(VideoGame** sortVideoGamesArray, int left, int right) {
  VideoGame* partition = sortVideoGamesArray[left]; 
  int temp = left; 
  VideoGame* tempArray;
  
  for (int i = left+1; i <= right; ++i) { 
    if ((sortVideoGamesArray[i]->getVideoGameYear() < partition->getVideoGameYear()) || ((sortVideoGamesArray[i]->getVideoGameYear() == partition->getVideoGameYear()) && (rand()%2 == 0)))  {
        temp = temp +1;

	    //swaps sortVideoGamesArray[i] and sortvideoGamesArray[temp]
	    tempArray = sortVideoGamesArray[i];
	    sortVideoGamesArray[i] = sortVideoGamesArray[temp];
	    sortVideoGamesArray[temp] = tempArray;
    }
  }

  //swaps sortVideoGamesArray[left] and sortVideoGamesArray[temp]
  tempArray = sortVideoGamesArray[left];
  sortVideoGamesArray[left] = sortVideoGamesArray[temp];
  sortVideoGamesArray[temp] = tempArray;
  return temp;
};

/*
    Function Name: displayVideoGames
    Purpose: displays each index of the array (name,author,publisher,year,rating)
*/
void VideoGameLibrary::displayVideoGames(){
    Text* tmp;
    //ensures there are games to display
    if(numGame == 0){ 
            cout << "\nThere are no games in your Library!\n ";
    }
    else{
        //display video game details by calling them in the index with the text object display function
        for(int i =0; i < numGame; i++){
            cout << endl;
            videoGamesArray[i]->getVideoGameName()->displayText();
            cout << endl;
            videoGamesArray[i]->getVideoGameAuthor()->displayText();
            cout << endl;
            videoGamesArray[i]->getVideoGamePublisher()->displayText();
            cout << endl;
            cout << videoGamesArray[i]->getVideoGameYear() << endl;
            cout << videoGamesArray[i]->getVideoGameRating() << "/10 IGN Rating"<< endl;   
        }
    } 
    return;
};

/*
    Function Name: displayVideoGameTitles
    Purpose: displays the title of each game in the videoGamesArray
*/
void VideoGameLibrary::displayVideoGameTitles(){
    if(numGame == 0){ 
            cout << "\nThere are no games in your Library!\n ";
    }
    else{
        for(int i =0; i < numGame; i++){
            cout << "Game " << i+1 << ". ";
            cout << videoGamesArray[i]->getVideoGameName()->getText();
            cout << endl;

        }
    }
    return;
};

/*
    Function Name: saveToFile
    Purpose: goes through each index of the array and saves it to a file based on
             the user's choice
*/
 void VideoGameLibrary::saveToFile(char* fileName){
    ofstream outfile; //outputs to the file
    if(numGame < 1){
        cout << "\nThere must always be at least one game in the library to use this function.\n";
        return;
    }
    outfile.open(fileName);
	for(int i = 0; i < numGame; i++){ //loop goes through all games
        outfile << videoGamesArray[i]->getVideoGameName()->getText() << endl; 
        outfile << videoGamesArray[i]->getVideoGameAuthor()-> getText() << endl; 
        outfile << videoGamesArray[i]->getVideoGamePublisher()-> getText() << endl; 
        outfile << videoGamesArray[i]->getVideoGameYear() << endl;
        outfile << videoGamesArray[i]->getVideoGameRating() << endl;
    }
    outfile.close();
	cout << "\nAll video games in your library have been printed to " << fileName << endl;
	return;
};

//function definition meant to pull the data from the provided files
/*
    Function Name: loadVideoGamesFromFile
    Purpose: goes through the file of the user's choice and reads in the info
             and puts the info into an array (name,author,publisher,year,rating)
*/
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
    while(infile.getline(temp,10000))
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

/*
    Function Name: resizeVideoGameArray
    Purpose: creates an array of size being double the original, then copys the old array inro the new array that was double finally destory the array that did not get copyed.
*/
void VideoGameLibrary::resizeVideoGameArray(){
    cout << "\nResizing array from " << maxGame << " to " << maxGame *2;
    //creates a new array of size being double the original array
    VideoGame** tempArray; 
    maxGame = maxGame * 2;
    tempArray = new VideoGame* [maxGame];

    //copy all entries from the current libray to the new array
    for(int i = 0; i < maxGame; i++){
        tempArray[i] = videoGamesArray[i];
    };
    //destroys the old array and redefines it
    delete [] videoGamesArray;
    videoGamesArray = tempArray;
    return;
};

/*
    Function Name: removeVideoGameFromArray
    Purpose: displays all the video game titles and ask which one to remove then deletes the game then shifts the array then decrementing the numgames
*/
void VideoGameLibrary::removeVideoGameFromArray(){
    //variable declarations
    int selection;
    Text* tempTitle;
    int newSel;
    int num;
    //check if there is one game or 0. Will not let the user delete a game if this is true. Will let the user delete a game if it is false
    if(numGame <= 1){
        cout << "\nThere must always be at least one game in the library to use this function.\n";
    }
    else{
        //Ask the user what game they want to remove after listing the game titles
        cout << "\nChoose from the following video games to remove:\n";
        displayVideoGameTitles(); //calls this function that will do as described
        cout << "\nChoose a video game between 1 & " << numGame << "(or 0 to cancel the operation): ";
        cin >> selection;
        //logic to see if the user chose a valid game to delete
        while(selection < 0 || selection > numGame){
            cout << "\nOops! You need to enter a valid selection: ";
            cin >> selection;
        }
        //Exits remove game function if user enters 0
        if(selection == 0){
            return;
        }
        //define the temporary variables
        newSel = selection - 1;
        num = numGame - 1;
        tempTitle = videoGamesArray[newSel]->getVideoGameName();
        //Tell the user the game has been deleted, and call the destructors for the correct game
        cout << "\n\nThe video game \"";
        tempTitle->displayText();
        cout << "\" has been deleted.\n";
        delete videoGamesArray[newSel];
        //fix the array by moving the index of all the remaining games that are behind the deleted game
        for( int i = newSel; i < num; i++){
            videoGamesArray[i] = videoGamesArray[i+1];
        }
        //remove the invalid array position and decrements numGames
        videoGamesArray[num] = NULL;
        numGame--;
    }
    return;
};

/*
    Function Name: addVideoGamesToArray
    Purpose: ask the user all the new information for the new game and then takes in into the different dynamically allocated arrays 
        Then checks if the library is full, resizing if needed. Then adds the game to the next open spot in the array.
*/
void VideoGameLibrary::addVideoGamesToArray(){

    //creates variables needed to temporarily hold the information needed to call the VideoGame constructor
    char temp[100];
    Text* tempTitle;
    Text* tempDeveloper;
    Text* tempPublisher;
    int tempYear;
    int tempRating;

    //input logic
    cout << "\nVideo Game TITLE: ";
    cin.ignore(); // clears cin to avoid issues with cin.getline
    cin.getline(temp, 100); // aquires the users input and sets the temp character array to this input
    tempTitle = new Text(temp); //dynamically create a temporary text object to be sent to the VideoGame constructor
    cout << "\nVideo Game DEVELOPER: ";
    cin.getline(temp, 100);
    tempDeveloper = new Text(temp);
    cout << "\nVideo Game PUBLISHER: ";
    cin.getline(temp, 100);
    tempPublisher = new Text(temp);
    cout << "\nVideo Game YEAR: ";
    cin >> tempYear;
    cout << "\nVideo Game IGN rating: ";
    cin >> tempRating;
    cin.ignore(); // clears cin to avoid possble later conflicts

    //check if the library is full already, and resize of it is to accomodate for the new game entry
    if(numGame == maxGame){
        resizeVideoGameArray();
    }
    //call the VideoGame constructor using the temporary variables to create a new VideoGame object at position equal to numGames
    // which will place the game in the next open position of the videoGamesArray
    videoGamesArray[numGame] = new VideoGame(tempTitle, tempDeveloper, tempPublisher, tempYear, tempRating);
    numGame++;
    return;
};
