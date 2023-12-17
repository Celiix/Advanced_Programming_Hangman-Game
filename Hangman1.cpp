#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cstring>  

using namespace std;

class NewWordManager {
public:
    NewWordManager();
    string getRandomWord();

private:
    vector<string> wordList;
};

class NewPlayer {
public:
    char makeGuess();
};

class StartScreen {
public:
    static void display();
};

class NewHangmanGame {
public:
    NewHangmanGame();
    ~NewHangmanGame();
    void play();

private:
    int tries;      // Number of tries the user has until game over
    char* word;     // Use dynamic array for the word chosen for hangman
    char* guessed;  // Use dynamic array for guessed letters that user has input
    char* dispWord; // Use dynamic array for the displayed word in the game

    void initializeWord();
    void displayHangman();
    void displayGameStatus();
    bool isGameOver();
    void cleanup();
};

// Implementation of NewWordManager
NewWordManager::NewWordManager() {
    wordList = {"india", "korea", "mexico", "france", "jamaica", "australia", "ghana", "canada", "norway", "iraq"}; // List of countries, player must guess the correct country when playing
}

string NewWordManager::getRandomWord() {
    return wordList[rand() % wordList.size()];
}

// Implementation of NewPlayer
char NewPlayer::makeGuess() {
    char guess;
    cout << "Guess a Letter: ";
    cin >> guess;

   

    return guess;
}

// Implementation of StartScreen for game
void StartScreen::display() {
    // Set console colors
    system("color 0B");  

//Creating border for console output of game
    cout << "\n";
    for (int i = 0; i < 40; i++) {
        cout << "*";
    }
    cout << "\n";

    
    for (int i = 0; i < 10; i++) {
        cout << "**********                            **********\n";
    }

    // Print options for player to choose
    cout << "*            1. New Game             *\n";
    cout << "*            2. Rules                *\n";
    cout << "*            3. Exit                 *\n";

    // Print colored background for output
    for (int i = 0; i < 10; i++) {
        cout << "**********                            **********\n";
    }

    // Print colored border
    for (int i = 0; i < 40; i++) {
        cout << "*";
    }
    cout << "\n\n";
}
