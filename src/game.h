#ifndef GAME_H
#define GAME_H
#include <string>
#include "puzzle.h"
#include "picrossController.h"

//GAME CLASS - MANAGES GAME FLOW, PIECES, SCORE, AND TRACKS INFORMATION ABOUT THE CURRENT GAME
class Game{
	private:
		int score;
		std::string message = "";
	public:
		enum eGameState{
			INITIALIZING,
			ACTIVE,
			GAMEOVER,
			LEVELSELECT,
			DIFFICULTYSELECT,
			MESSAGESCREEN,
			eGameState_MAX
		};
        Game();
		void initializeGame();
		void GameLoop(Puzzle &currentPuzzle, picrossController &controller);
};

#endif