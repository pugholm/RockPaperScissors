#include "RPS.h" // header file
#include <iostream> // input, outputs

// This document runs the game. 

void RockPaperScissorsGame::playGame() {
    unsigned int winsNeeded = (m_totalRounds / 2) + 1;
    // Calculates number of wins needed to win, which is just more than 50% of total rounds. 
    std::cout << "\n The Game is afoot, first to " << winsNeeded << " Is VICTORIOUS!\n" << std::endl;

    unsigned int playerInput = 0;
    // Loop keeps going till a winner is found .
    while (m_playerWins < winsNeeded && m_cpuWins < winsNeeded) {
        std::cout << "\nRound " << m_currentRound << " of " << m_totalRounds << std::endl;

        // Handles user input, keeps going until valid input, and a cheeky remark..
        while (true) {
            std::cout << "What is your move? (0 = Rock, 1 = Paper, 2 = Scissors)\n";
            if (std::cin >> playerInput) {
                if (playerInput <= 2) {
                    break; // breaks at a correct input
                }else {
                    std::cout << "Invalid!! you should know better.\n";
                }
                } else {
                std::cout << "Letters are not allowed! Please enter digits only.\n";
                // Fixes a stream failure, resets error flags, and flushes bad characters
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }

        // Maps the validated integer to the enum class HandType
        HandType playerHand = static_cast<HandType>(playerInput);

        // On round 1 , hard mode = standard mode, as there is no previous hand data
        HandType cpuHand = (m_gameDifficulty == Difficulty::Standard || m_currentRound==1)
        ? getHandStandard() : getHandHard();

        std::cout << "\nYou threw: " << handToString(playerHand) << std::endl;
        std::cout << "\nCPU Threw: " << handToString(cpuHand) << std::endl;

        int result = determineWinner(playerHand, cpuHand);
        // Checks who won using the modular formula

        if (result == 1) { 
                std::cout << "\nYou won...this time" << std::endl;
                m_playerWins++;
                m_currentRound++; // player wins
            }
            else if (result == -1){ 
                std::cout << "\nHehe I won YOU LOST" << std::endl;
                m_cpuWins++;
                m_currentRound++; // cpu wins
            }
            else { 
                std::cout << "\nTIE!!, replay the round" << std::endl;
            }// tie, replay the round
            
            std::cout << "Your Score: " << m_playerWins << "\nMy Score(CPU):" << m_cpuWins << std::endl; 

            // Saves, hand data, for hard mode to work.
            m_playerLastHand = playerHand;
            m_cpuLastHand = cpuHand;
            m_lastRoundResult = result;
    }
     // prints final game outcome. 
    std::cout << "\n_______________________" << std::endl;
    if (m_playerWins > m_cpuWins) {
        std::cout << "\nCongratulations you won!!!!, now get back to work!!" << std::endl;
    }
    else {
        std::cout << "\nYou lost. better luck next time... you should get back to work" << std::endl;
    }
    std::cout << "_______________________" << std::endl;


}



