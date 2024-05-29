#include "game.h"
#include "puzzle.h"
#include "picrossController.h"

Game::Game(){
	score = 0;
}

void Game::initializeGame(){
	Puzzle currentPuzzle;
	picrossController controller;
	GameLoop(currentPuzzle, controller);
}

void Game::GameLoop(Puzzle &currentPuzzle, picrossController &controller){
	while(true){
		currentPuzzle.PrintBoard(controller.GetCursorPOSX(), controller.GetCursorPOSY());
		controller.GetCommand(currentPuzzle);
	}
}
