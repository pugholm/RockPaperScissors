#include <iostream>
#include <cassert>
#include "../GameBuild/RPS.h"

// Test file

void testGameLogic() {
RockPaperScissorsGame game;

    // Loops all possible hand combinations. 
    for (unsigned int p = 0; p < 3; ++p) {
        for (unsigned int c = 0; c < 3; ++c) { 
            HandType playerHand = static_cast<HandType>(p);
            HandType cpuHand = static_cast<HandType>(c);
            
            // Calculates the expected outcome with a formula that is never negative, then maps to expected result 
            int expectedResult = 0;
            unsigned int formula = (3 + p - c) % 3;
            
            if (formula == 1) expectedResult = 1;       // Player Win
            else if (formula == 2) expectedResult = -1;  // CPU Win
            else expectedResult = 0;                     // Tie

            // forces program to crash if game logic returns wrong. 
            assert(game.determineWinner(playerHand, cpuHand) == expectedResult);
        }
    }
    std::cout << "[PASS] testGameLogic" << std::endl;

}


void testHandStringMapping() {
    RockPaperScissorsGame game;

    // Makes sure a hand type is mapped to the correct string

    struct MapCase { HandType hand; std::string expected; };

    // Array of test cases. 
    MapCase cases[] = {
        {HandType::Rock, "Rock"},
        {HandType::Paper, "Paper"},
        {HandType::Scissors, "Scissors"},
        {static_cast<HandType>(99), "Have you never played rock paper scissors????"}
    };
    // Loops through all test cases. 
    for (const auto& tc : cases) {
        // compares actual game output to test output
        assert(game.handToString(tc.hand) == tc.expected);
    }
    std::cout << "[PASS] testHandStringMapping " << std::endl;
}
    
void testMatchOverConditions() {
    RockPaperScissorsGame game;

    // Loops through match sizes up to best of 21

    for (unsigned int total = 3; total <= 21; total += 2) {
        unsigned int majorityThreshold = (total / 2) + 1;
        // Calculate what is needed to win. 

        assert(game.Winner(majorityThreshold, 0, total) == true);
        assert(game.Winner(0, majorityThreshold, total) == true);
        // Makes sure game ends, when either player or cpu hits majority

        assert(game.Winner(majorityThreshold - 1, majorityThreshold - 1, total) == false);
    }   // Makes sure the game is still on in a tie-breaker scenario. 

    std::cout << "[PASS] testMatchOverConditions: " << std::endl;
}

int main() {
    std::cout << "Testing\n" << std::endl;
    
    testGameLogic();
    testHandStringMapping();
    testMatchOverConditions();

    // Runs the functions 
    
    std::cout << "\n SUCCESS: 100% " << std::endl;
    return 0;
}



