#include <iostream>
#include <string>
#include "puzzle.h"
#include "picrossController.h"

	void picrossController::GetCommand(Puzzle &currentPuzzle){
		char input;
		std::cout <<"Current POS: X-" <<cursorPos.first <<" Y-"<<cursorPos.second << std::endl <<  "Enter Command:\n[(R)eveal Space, (C)over space, (M)ark space, (D)elete mark, (Q)uit] \n-> ";
		// cases - > needs to be an int, needs to not be more than x size, needs to not be less than x min
		std::cin.get(input);
		switch(tolower(input)){
			case 'u':
				MoveCursor(0, -1);
				break;
			case 'd':
				MoveCursor(0, 1);
				break;
			case 'l':
				MoveCursor(-1, 0);
				break;
			case 'r':
				MoveCursor(1, 0);
				break;
			case 'm':
				if(currentPuzzle.GetPuzzleMapVal(cursorPos.first, cursorPos.second) == true){
					MarkPuzzle(cursorPos.first, cursorPos.second, currentPuzzle);
				}
				else{
					// No match, so it must be a miss -- increment miss counter, check for limit and continue or end game depending.
				}
				break;
		}
	};

	int picrossController::GetCursorPOSX(){
		return cursorPos.first;
	}

	int picrossController::GetCursorPOSY(){
		return cursorPos.second;
	}

	void picrossController::SetCursorPOS(){

	}

	void picrossController::MoveCursor(int x, int y){
		if(cursorPos.first + x >= 0 && cursorPos.first + x < 10){
			cursorPos.first += x;
		}
		if((cursorPos.second + y) >= 0 && (cursorPos.second + y) < 10 ){
			cursorPos.second += y;
		}
	}

	void picrossController::MarkPuzzle(int x, int y, Puzzle &currentPuzzle){
		currentPuzzle.SetGameBoard(x, y, true);
	}

	bool picrossController::CheckMove(int x, int y, Puzzle &currentPuzzle){
		return currentPuzzle.GetPuzzleMapVal(x, y);
	}
