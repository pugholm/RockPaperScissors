#include  <iostream>  //Standard input outputs
#include "RPS.h" // Link to my header file

// file for game logic. 


int RockPaperScissorsGame::determineWinner(HandType player, HandType cpu) const{
    if (player == cpu) {  // Equal hands result in a tie
        return 0; 
    } 
        
        // I use modular arithmetic to evaluate who won the round. 
        //  Returns 1 if player wins, -1 if CPU wins.
      else if ((static_cast<unsigned int>(player) + 1) % 3 == static_cast<unsigned int>(cpu)) {
        return -1; 
    } else {
        return 1; 
    }
} 
bool RockPaperScissorsGame::Winner(unsigned int playerWins, unsigned int cpuWins, unsigned int totalRounds) const {
    unsigned int winsNeeded = (totalRounds / 2) + 1; 
    if (playerWins >= winsNeeded || cpuWins >= winsNeeded) {
        return true;
    } else {
        return false;
    } // This function determines the winner of the whole Game, first player to win a majority of the n rounds. 
}


std::string RockPaperScissorsGame::handToString(HandType hand) const{
    switch (hand) {
        case HandType::Rock: return "Rock";
        case HandType::Paper: return "Paper";
        case HandType::Scissors: return "Scissors";

        // Safety bound to catch invalid inputs 
        default:    return "Have you never played rock paper scissors????";      
    }
}

