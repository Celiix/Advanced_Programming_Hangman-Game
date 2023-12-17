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

// Implementation of NewHangmanGame
NewHangmanGame::NewHangmanGame() : tries(5), word(nullptr), guessed(nullptr), dispWord(nullptr) {
    initializeWord();
}

void NewHangmanGame::initializeWord() {
    NewWordManager wordManager;
    const string randomWord = wordManager.getRandomWord();

    // Allocate memory for the word and copy characters
    word = new char[randomWord.length() + 1];  // +1 for null terminator
    strcpy(word, randomWord.c_str());

    // Allocate memory for guessed and display word
    guessed = new char[randomWord.length() + 1];
    dispWord = new char[randomWord.length() + 1];
    fill(dispWord, dispWord + randomWord.length(), 'X');

    // Null terminate the strings
    guessed[randomWord.length()] = '\0';
    dispWord[randomWord.length()] = '\0';
}

void NewHangmanGame::cleanup() {
    // Free dynamically allocated memory
    delete[] word;
    delete[] guessed;
    delete[] dispWord;
}

NewHangmanGame::~NewHangmanGame() {
    cleanup();
}
