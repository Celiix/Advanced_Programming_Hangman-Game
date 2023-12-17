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

// Main loop for game until game over (code returns true)
void NewHangmanGame::play() {
    char guess;
    while (!isGameOver()) {
        system("cls");
        StartScreen::display();
        displayGameStatus();
        displayHangman();

        NewPlayer player;
        guess = player.makeGuess();

        if (strchr(guessed, guess) != nullptr) {
            tries++;
        }

        bool flagFound = false;
        for (size_t i = 0; i < strlen(word); i++) {
            if (word[i] == guess && dispWord[i] == 'X') {
                dispWord[i] = guess;
                flagFound = true;
            }
        }

        if (!flagFound) {
            tries--;
        }

        strcat(guessed, &guess);
    }

system("cls");
    StartScreen::display();
    displayGameStatus();
    displayHangman();

    //Message to player if they win or lose
   if (strchr(dispWord, 'X') == nullptr) {
    cout << "\nCongratulations! You Win! The word was: " << word << "\n";
} else {
    cout << "\nGame Over! You Lose. The word was: " << word << "\n";
    cout << "Your Guessed Word: " << dispWord << "\n";
}
    
}

//Prints out the hangman when player guesses wrong
void NewHangmanGame::displayHangman() {
    cout << "\n  -----"
         << "\n  |   |"
         << "\n  |";
    if (tries < 5) cout << "   O    ";
    cout << "\n  |";
    if (tries <= 3) cout << "  /|\\   ";
    cout << "\n  |";
    if (tries <= 1) cout << "  / \\   ";
    cout << "\n  |"
         << "\n__|__\n";
}
