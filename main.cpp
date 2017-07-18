//Author: Elizabeth (Liz) Boyle
//Title: Final Project: Game of WAR!


#include "Classes.h"
using namespace std;
#include <fstream>

int main() {
	srand(time(0));
    bool playing = 1;
    string name;
    do {
        Game game;

        std::ofstream scoreCard;
        scoreCard.open("HighScores.txt", std::ios_base::app);
        if (scoreCard.fail()) {
            cerr << "Error opening input file";
            exit(1);
        }

        cout << "Enter your name to add your score to the High Scores List: ";
        cin >> name;
        scoreCard << name << "              " << game.GetScore() << "                " << game.GetRounds() << endl;
        scoreCard.close();
        do {
            cout << "Enter 0 to Exit or 1 to Play Again: ";
            cin >> playing;
        } while (playing != true && playing != false);



    } while (playing == 1);
    return EXIT_SUCCESS;
}
