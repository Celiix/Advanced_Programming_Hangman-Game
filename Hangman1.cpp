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
