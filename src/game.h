#ifndef GAME_H
#define GAME_H
#include "puzzle.h"
#include "picrossController.h"

//GAME CLASS - MANAGES GAME FLOW, PIECES, SCORE, AND TRACKS INFORMATION ABOUT THE CURRENT GAME
class Game{
	private:
		int score;
	public:
        Game();
		void initializeGame();
		void GameLoop(Puzzle &currentPuzzle, picrossController &controller);
};

#endif