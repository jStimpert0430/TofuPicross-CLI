#include <iostream>
#include <string>
#include <climits>
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
		currentPuzzle.PrintBoard(controller.GetCursorPOSX(), controller.GetCursorPOSY(), message);
		message = controller.GetCommand(currentPuzzle); //Get user command and populate message variable with the corrosponding success, movement, or error messages.
		if(currentPuzzle.getCurrentMistakes() >= currentPuzzle.getMaxMistakes()){
			message = "Too many mistakes - Please try again";
			std::cin.get();
			currentPuzzle.resetGameBoard();
			controller.SetCursorPOS(0, 0);
		}
	}
}

