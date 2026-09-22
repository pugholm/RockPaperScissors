#pragma once // Makes sure header file is only included once in compilations
#include <string> // for strings

// Header file

enum class HandType : unsigned int {
    Rock = 0,
    Paper = 1,
    Scissors = 2
};
// maps choices to 0, 1, 2. Also needed for the modular trick. 

enum class Difficulty {
    Standard = 1,
    Hard = 2
};// Class for the difficulty modes

class RockPaperScissorsGame {   

public:
    // Logic, and core game functions
    std::string handToString(HandType hand) const;
    int determineWinner(HandType player, HandType cpu) const;
    HandType getHandStandard() const;
    HandType getHandHard() const;
    bool Winner(unsigned int playerWins, unsigned int cpuWins, unsigned int totalRounds) const; 

    // for game setup and playing the game
    int rounds(); 
    Difficulty difficulty();
    void playGame(); 

private: // Match tracking variables. 
    unsigned int m_playerWins = 0; // Rounds won by player
    unsigned int m_cpuWins = 0; //Rounds won by CPU
    unsigned int m_currentRound = 1; // Current round
    unsigned int m_totalRounds = 0; // total rounds chosen by player
    Difficulty m_gameDifficulty = Difficulty::Standard; // Game difficulty

    // Variable for hard mode to work
    HandType m_playerLastHand = HandType::Rock; // players latest hand
    HandType m_cpuLastHand = HandType::Rock; // cpu latest hand
    int m_lastRoundResult = 0;  // result of latest round, needed for cpu to know what to do
    
};
