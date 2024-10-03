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
void VideoGameLibrary::changeVideoGameDetails(){
    //variable declaration
    int selection;
    Text* tempTitle;
    int newSel;
    int num;
    //check if there is one game or 0
    if(numGame <= 1){
        cout << "\nThere must always be at least one game in the library to use this function.\n";
    }
    else{
        //Ask the user what game they want to remove after listing the game titles
        cout << "\nChoose from the following video games to modify:\n";
        displayVideoGameTitles(); //calls this function that will do as described
        cout << "\nChoose a video game between 1 & " << numGame << ": ";
        cin >> selection;
        //logic to see if the user chose a valid game to modify
        while(selection < 1 || selection > numGame){
            cout << "\nOops! You need to enter a valid selection: ";
            cin >> selection;
        }
        newSel = selection - 1;

        //Display details of the game using getters and provide an indexed menu to select which detail to modify
        //switch cases for each detail using the setters
        // Ask if done or would like to continue?
    }
    return;
};

void VideoGameLibrary::sortVideoGamesByRating(){
    if(numGame <= 1){
        cout << "\nThere must always be at least one game in the library to use this function.\n";
        return;
    }
    cout << "startint to sort\n";
   	quickSortRating(videoGamesArray, 0, numGame-1);
    cout << "Finished sort.\n";

};
void VideoGameLibrary::quickSortRating(VideoGame** inVideoGamesArray, int low, int high) {
  if (low < high) {
    int temp = partitionRating(videoGamesArray, low, high);
    quickSortRating(videoGamesArray, low, temp-1); 
    quickSortRating(videoGamesArray, temp+1, high);
  }
};
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
void VideoGameLibrary::sortVideoGamesByYear(){
    if(numGame <= 1){
        cout << "\nThere must always be at least one game in the library to use this function.\n";
        return;
    }
   cout << "Starting to sort.\n";
   	quickSortYear(videoGamesArray, 0, numGame-1);
    cout << "Finished sort.\n";
};
void VideoGameLibrary::quickSortYear(VideoGame** inVideoGamesArray, int low, int high) {
  if (low < high) {
    int temp = partitionYear(videoGamesArray, low, high);
    quickSortYear(videoGamesArray, low, temp-1); 
    quickSortYear(videoGamesArray, temp+1, high);
  }
};
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

void VideoGameLibrary::displayVideoGames(){
    Text* tmp;
    if(numGame == 0){ 
            cout << "\nThere are no games in your Library!\n ";
    }
    else{
        for(int i =0; i < numGame; i++){
            videoGamesArray[i]->getVideoGameName()->displayText();
            cout << endl;
            videoGamesArray[i]->getVideoGameAuthor()->displayText();
            cout << endl;
            videoGamesArray[i]->getVideoGamePublisher()->displayText();
            cout << endl;
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
            cout << "Game " << i+1 << ". ";
            cout << videoGamesArray[i]->getVideoGameName()->getText();
            cout << endl;

        }
    }
};
void VideoGameLibrary::saveToFile(char* fileName){
    ofstream outfile; //outputs to the file
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

//function definition of resizeVideoGameArray(). Is designed to double the size of the videoGameArray if there is an attempt to add a game to a full library
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

//void VideoGameLibrary::changeVideoGameDetails(int select){
   // int selection = select;
    //switch(selection){
    //    case 1:

   // }
//};

//function definition to remove a particular game from the videoGamesArray
void VideoGameLibrary::removeVideoGameFromArray(){
    //variable declaration
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
        cout << "\nChoose a video game between 1 & " << numGame << ": ";
        cin >> selection;
        //logic to see if the user chose a valid game to delete
        while(selection < 1 || selection > numGame){
            cout << "\nOops! You need to enter a valid selection: ";
            cin >> selection;
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

//function definition that is meant to allow the user to manually add a new game to the current library
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
