# Rock, Paper, Scissors Game

Console based rock paper scissors game with a standard mode, and a hard mode


How to Build and Run

You can compile and run both the game and the test script using any standard C++ compiler (g++). I use g++

# Running the Game
```bash
g++ main.cpp GameBuild/GameMode.cpp GameBuild/GameLogic.cpp GameBuild/GameEngine.cpp -o rps_game.exe

```
 run `rps_game.exe`


# Running the Test Suite
```bash
g++ tests/test.cpp GameBuild/GameMode.cpp GameBuild/GameLogic.cpp -o run_tests.exe

```
 run `run_tests.exe`

---

# Choices i made

I intentionally used only native C++ standard headers (`<iostream>`, `<cstdlib>`, `<ctime>`, `<cassert>`, and `<string>`).

For a game like rock paper scissors, i think adding a bunch of frameworkds and libraries adds complexity, just to add complexity.
I found that the native library was enough to make a good simple game, that works very well with easy to maintain, alter, and extend code.  

---

# Key Features

*Input Validation*: Safely clears input stream failures (`std::cin.clear()`) to prevent infinite terminal loops when letters are typed.

*Hard Mode*:I created hard mode, by playing a bit of rock, paper, scissors with some buddies at school, and my family. I found that most of them would stay when they won, and shift when the lost. Funnily enough in the loop the game implies. Rock, Paper and then scissors. 

*Modular Math Logic:* I found that this made the code alot simpler, instead of a long if/else

*Automated Unit Tests:* Made a test file, thats independently test the values it gets, and compares to the game values, to make sure the game gets the correct values. 

---

# Project Architecture

 `main.cpp` - Entry point, play the game
 `RPS.h` - Global header 
 `tests/test.cpp` - Independent testing 
 `GameBuild/GameEngine.cpp` - Driving match loop controller.
 `GameBuild/GameLogic.cpp` - Win/loss evaluations
 `GameBuild/GameMode.cpp` - Setting up the game 
