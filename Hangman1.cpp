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
    static void display();
};

class NewHangmanGame {}
public: 
    NewHangmanGame();
    ~NewHangmanGame();
    void play();
