#include <iostream>
#include "picrossController.h"

	std::string picrossController::GetCommand(Puzzle &currentPuzzle){
		char input;
		std::cin.get();
		std::cout <<"Current POS: X-" <<cursorPos.first <<" Y-"<<cursorPos.second << std::endl <<  "Enter Command:\n[(R)eveal Space, (C)over space, (M)ark space, (D)elete mark, (Q)uit] \n-> ";
		std::cin.get(input);
		switch(tolower(input)){
			case 'u':
				MoveCursor(0, -1, currentPuzzle.getSize());
				return "   Moved Up";
			case 'd':
				MoveCursor(0, 1, currentPuzzle.getSize());
				return "   Moved Down";
			case 'l':
				MoveCursor(-1, 0, currentPuzzle.getSize());
				return "   Moved Left";
			case 'r':
				MoveCursor(1, 0, currentPuzzle.getSize());
                return "   Moved Right";
			case 'm':
				if(currentPuzzle.GetPuzzleMapVal(cursorPos.first, cursorPos.second) == true){
					if(currentPuzzle.GetGameBoardVal(cursorPos.first, cursorPos.second) != true){
						MarkPuzzle(cursorPos.first, cursorPos.second, currentPuzzle);
                    	return "Correct Guess - Marking Spot";
					}
					else{
						return "Can't mark a spot again";
					}
				}
				else{
					currentPuzzle.addToCurrentMistakes(1);
                    return "Incorrect Guess -- Adding Miss";
					// No match, so it must be a miss -- increment miss counter, check for limit and continue or end game depending.
				}
			default: 
				return "Error: Not a supported command";
		}
	};

	int picrossController::GetCursorPOSX(){
		return cursorPos.first;
	}

	int picrossController::GetCursorPOSY(){
		return cursorPos.second;
	}

	void picrossController::SetCursorPOS(int newX, int newY){
		cursorPos.first = newX;
		cursorPos.second = newY;
	}

	void picrossController::MoveCursor(int x, int y, int puzzleBounds){
		if(cursorPos.first + x >= 0 && cursorPos.first + x < puzzleBounds){
			cursorPos.first += x;
		}
		if((cursorPos.second + y) >= 0 && (cursorPos.second + y) < puzzleBounds){
			cursorPos.second += y;
		}
	}

	void picrossController::MarkPuzzle(int x, int y, Puzzle &currentPuzzle){
		currentPuzzle.SetGameBoard(x, y, true);
	}

	bool picrossController::CheckMove(int x, int y, Puzzle &currentPuzzle){
		return currentPuzzle.GetPuzzleMapVal(x, y);
	}
