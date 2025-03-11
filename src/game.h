#ifndef GAME_H
#define GAME_H
#include <string>
#include "puzzle.h"
#include "picrossController.h"
#include "picrossEnums.h"

//GAME CLASS - MANAGES GAME FLOW, PIECES, SCORE, AND TRACKS INFORMATION ABOUT THE CURRENT GAME
class Game{
	private:
		int score;
		std::string message = "";
	public:
        Game();
		void initializeGame();
		void GameLoop(Puzzle &currentPuzzle, picrossController &controller);
		void ResetGame(Puzzle &currentPuzzle, picrossController &controller);
};

#endif