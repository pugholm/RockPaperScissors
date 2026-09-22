#include <iostream>  // standard input outputs 
#include <cstdlib>  // for srand
#include "RPS.h" // Included header file


// Game modes, rules, setup functions. 

int RockPaperScissorsGame::rounds() {    
    
    int totalInput = 0; // Temporary variable before users input is validated.

    while (true) {  // While loop, loops until the user gives valid input. 
         std::cout << "Enter the amount of round you wish to play(must be odd an number)" << std::endl;
        if (std::cin >> totalInput) {
            if (totalInput > 0 && totalInput % 2 !=0) {
                m_totalRounds = static_cast<unsigned int>(totalInput);
                break;
                
        } // Makes sure the rounds is of standards like best of 3, best of 5....
            else { 
            std::cout<< "Please enter a odd and positive number" << std::endl;
        }
     } else { 
            
            std::cout << "Thats not even a number, try again i believe in you" << std::endl;
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
        }
            // Prevents infinite looping (stream failure)
        }
        return totalInput;
    }



Difficulty RockPaperScissorsGame::difficulty() {

    int choice = 0; 

    while (true) {
        std::cout << "Select difficulty level (1 for Standard, 2 for Hard): ";
        if (std::cin >> choice) {
            if (choice == 1 || choice == 2) {
                m_gameDifficulty = static_cast<Difficulty>(choice);
                break; 
            } else {
                std::cout << "Please enter 1 for Standard or 2 for Hard." << std::endl;
            }
        } 
        else { 
           
            std::cout << "NO LETTERS... Please enter digits only." << std::endl;
            // the code above , forces the user to pick either 1 or 2 and will loop until that happens.

            std::cin.clear();             
            std::cin.ignore(10000, '\n');
        } //  (stream failure)
}
return m_gameDifficulty;
}

HandType RockPaperScissorsGame::getHandStandard() const {
    return static_cast<HandType>(std::rand() % 3); 
    // Selects a random hand. 
}

HandType RockPaperScissorsGame::getHandHard() const {
    if (m_lastRoundResult == 1) { // player won
        return static_cast<HandType>((static_cast<unsigned int>(m_playerLastHand) + 1) % 3); 
    } else if (m_lastRoundResult == -1) { 
        return static_cast<HandType>((static_cast<unsigned int>(m_cpuLastHand) + 1) % 3); 
    } else { // tie
        return static_cast<HandType>(std::rand() % 3); 
    } // for a bit harder version this code, uses my own experience of rock paper scissors, (played with my family before this)
    // Where they would use the same hand if they won, and swich if the lost, usually in the ROck, paper, scissors loop. t
    // this code tries to counteract that by inversing it. so if player wins on rock, cpu expects rock next time and throws paper. 
}

