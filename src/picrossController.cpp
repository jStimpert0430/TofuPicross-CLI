#include <iostream>
#include "picrossController.h"
#include "picrossEnums.h"

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
			//TODO: Poor construction of these checks, will change I just was working out how I wanted it to work logically. Instead of checking map puzzle val first, consider case checking the eMapEntry enum and reaction based off of that, since it is the current board state
				if(currentPuzzle.GetPuzzleMapVal(cursorPos.first, cursorPos.second) == true){
					if(currentPuzzle.GetGameBoardVal(cursorPos.first, cursorPos.second) != eMapEntryType::FILLED){
						MarkPuzzle(cursorPos.first, cursorPos.second, currentPuzzle);
                    	return "Correct Guess - Marking Spot";
					}
					else{
						return "Can't mark a spot again";
					}
				}
				else if(currentPuzzle.GetGameBoardVal(cursorPos.first, cursorPos.second) == eMapEntryType::EMPTY){
					currentPuzzle.addToCurrentMistakes(1);
					MarkMiss(cursorPos.first, cursorPos.second, currentPuzzle);
                    return "Incorrect Guess -- Adding Miss";
					// No match, so it must be a miss -- increment miss counter, check for limit and continue or end game depending.
				}
				else{
					return "Can't mark a spot again";
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
		currentPuzzle.SetGameBoard(x, y, eMapEntryType::FILLED);
	}

	void picrossController::MarkMiss(int x, int y, Puzzle &currentPuzzle){
		currentPuzzle.SetGameBoard(x, y, eMapEntryType::MISSED);
	}

	bool picrossController::CheckMove(int x, int y, Puzzle &currentPuzzle){
		return currentPuzzle.GetPuzzleMapVal(x, y);
	}
