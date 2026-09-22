#include <iostream> // Input/output
#include <cstdlib> // for srand
#include <ctime> // to seed a random number generator
#include "GameBuild/RPS.h"  // header file link

int main() {
    // seeds random number, using current system time
    // ensures cpu is different every time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "Dear Player\n" << std::endl;

    
    RockPaperScissorsGame game;
    // starts the game
    
    game.rounds();
    game.difficulty();
    // triggers the loops to set up the game

    
    game.playGame();
    // runs the game

    return 0;
}// signals game is over, and program stops running
