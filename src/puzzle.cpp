#include <iostream>
#include <iomanip>
#include "puzzle.h"
#define redNumber "\x1B[31m " + to_string((i)) + "\033[0m"
#define grayNumber "\x1B[90m " + to_string((i)) + "\033[0m"
//need leading spaces on game characters for alignment purposes so the grid remains square
#define filledSpaceChar " ■"
#define emptySpaceChar " ◇"
#define clearScr system("clear");
using namespace std;

//Puzzle class handles the state of the current puzzle and associated gameboard -- should I move gameboard to the game manager or controller class?

        Puzzle::Puzzle(){
        };

		void Puzzle::SetGameBoard(int x, int y, enum eMapEntryType val){
			enumGameBoard[y][x] = val;
		}

		enum eMapEntryType Puzzle::GetGameBoardVal(int x, int y){
			return enumGameBoard[y][x];
		}

		bool Puzzle::GetPuzzleMapVal(int x, int y){
			return puzzleMap[y][x]; 
		}

		//SCREEN DRAW FUNCTIONS

		void Puzzle::PrintBoard(int cursorX, int cursorY, string message){
			clearScr;
			queue<queue<int>> rowKeyQueue = CalcRowKeys();
			vector<queue<int>> columnKeyQueue = CalcColumnKeys();
			PrintHeader();
			PrintTopRowCoords();
			for(int i = 0; i < (int)size(enumGameBoard[0]); i++){
				PrintLeadingKey(rowKeyQueue, i, cursorY);
				cout << grayNumber;
				PrintGameBoardRow(i, cursorX, cursorY);
			}
			PrintBottomKeys(columnKeyQueue, cursorX);
			PrintFooter(message);
		};

		void Puzzle::PrintHeader(){
			int margin = 10;
			cout << setw(margin) << "";
			cout << "Level 'test' | Difficulty: * | Size: 10x10\n\n\n";

		}

		void Puzzle::PrintTopRowCoords(){
			int margin = 20;
			cout << setw(margin) << right << "";
            cout << "  ";
			for (int i = 0; i < SIZE; i++){
				cout << grayNumber;
			}
		}

		void Puzzle::PrintLeadingKey(queue<queue<int>> &keyQueue, int selectedRow, int cursorY){
				int margin = 20;
                cout << "\n";
                string rowKeyString;
				//Print leading key red if in the selected row
				if(selectedRow == cursorY){
					while(!keyQueue.front().empty()){
						rowKeyString += to_string(keyQueue.front().front()) + " ";
						keyQueue.front().pop();
					}
					cout << "\x1B[31m" <<  setw(margin) << rowKeyString + "   " << "\033[0m";
				}
				//
				else{
					while(!keyQueue.front().empty()){
						rowKeyString += to_string(keyQueue.front().front()) + " ";
						keyQueue.front().pop();
					};
					cout << setw(margin) << rowKeyString + "   ";
				}
				keyQueue.pop();
		}

		void Puzzle::PrintGameBoardRow(int selectedRow, int cursorX, int cursorY){
			for(int i = 0; i < (int)size(enumGameBoard[selectedRow]); i++){
				//Color cursor space red when printing character at cursor coordinates
				if(selectedRow == cursorY && i == cursorX){
					if( enumGameBoard[selectedRow][i] == eMapEntryType::FILLED){
						cout<< "\x1B[31m" << filledSpaceChar << "\033[0m";
					}
					else if(enumGameBoard[selectedRow][i] == eMapEntryType::MISSED){
						cout << "\x1b[38;5;90m" << emptySpaceChar << "\033[0m";
					}
					else{
						cout << "\x1B[31m" << emptySpaceChar << "\033[0m";
					}
				}
				//
				else{
					if( enumGameBoard[selectedRow][i] == eMapEntryType::FILLED){
						cout<< filledSpaceChar;
					}
					else if(enumGameBoard[selectedRow][i] == eMapEntryType::MISSED){
						cout << "\x1B[90m" << emptySpaceChar << "\033[0m";
					}
					else{
						cout << emptySpaceChar;
					}
				}
			}
		}

		void Puzzle::PrintBottomKeys(vector<queue<int>> &keyQueue, int cursorX){
			int margin = 20;
			cout << "\n";
			for(int i = 0; i < 6; i++){
				cout << "\n";
				cout << setw(margin) << right << " ";
            	cout << "  ";
				for(int j = 0; j < SIZE; j++){
					//Print bottom key red if is the the same column the cursor is currently in
					if(!keyQueue.at(j).empty()){
						if(j == cursorX){
							cout << " " << "\x1B[31m" << keyQueue.at(j).front() << "\033[0m";
						}
						else{
							cout << " " << keyQueue.at(j).front();
						}
					keyQueue.at(j).pop();
					}
					//

					else{
						cout << "  ";
					}
				}
			}
		}

		void Puzzle::PrintFooter(string message){
			int margin = 27;
			cout << "\n\n";
			if(message != ""){ 
				if(message.length() > 10){
				// in order to align output for long strings, I need to add an offset based on string length
				cout << setw((margin) - (message.length()/4)) << "";
            	cout << message << "\n";
				}
				else{
					cout << setw((margin)) << "";
					cout << message << "\n";
				}
			}
			else{}
            cout << setw((margin)) << "";
			cout << "MISSES: " << getCurrentMistakes() << "/" << getMaxMistakes() << "\n\n";
		}

		// END SCREEN DRAW FUNCTIONS

		int Puzzle::getCurrentMistakes(){
			return currentMistakes;
		}

		int Puzzle::getMaxMistakes(){
			return MAX_MISTAKES;
		}

		int Puzzle::getSize(){
			return SIZE;
		}

		void Puzzle::addToCurrentMistakes(int value){
			currentMistakes += value;
		}

		void Puzzle::resetGameBoard(){
			std::fill(std::begin(enumGameBoard[0]), std::end(enumGameBoard[10]), eMapEntryType::EMPTY);
			currentMistakes = 0;
		}

		//TODO: I don't like how similar these functions are, It's just the way I pop items off of the stack to print the keys makes it so I need fifo for the row keys and lifo for the column keys.
		//Will work further on this as there is likely a much smarter way to go about it.
		queue<queue<int>> Puzzle::CalcRowKeys(){
			queue<queue<int>> rowKeyQueue;
			for(int i = 0; i < (int)size(puzzleMap[0]); i++){
				int consecutiveCount = 0;
				queue<int> puzzleKeyQueue;
				for(int j = 0; j < (int)size(puzzleMap[0]); j++){
					if(puzzleMap[i][j]){
						consecutiveCount++;
					}
					else{
						if(consecutiveCount != 0){
							puzzleKeyQueue.push(consecutiveCount);
						}
						consecutiveCount = 0;
					}
				}
				if(consecutiveCount != 0){
					puzzleKeyQueue.push(consecutiveCount);
				}
				if(puzzleKeyQueue.empty()){
					puzzleKeyQueue.push(0);
				}
				rowKeyQueue.push(puzzleKeyQueue);
			}
			return rowKeyQueue;
		}

		vector<queue<int>> Puzzle::CalcColumnKeys(){
			vector<queue<int>> columnKeyQueue;
			for(int i = 0; i < (int)size(puzzleMap[0]); i++){
				int consecutiveCount = 0;
				queue<int> puzzleKeyQueue;
				for(int j = 0; j < (int)size(puzzleMap[0]); j++){
					if(puzzleMap[j][i]){
						consecutiveCount++;
					}
					else{
						if(consecutiveCount != 0){
							puzzleKeyQueue.push(consecutiveCount);
						}
						consecutiveCount = 0;
					}
				}
				if(consecutiveCount != 0){
					puzzleKeyQueue.push(consecutiveCount);
				}
				if(puzzleKeyQueue.empty()){
					puzzleKeyQueue.push(0);
				}
				columnKeyQueue.push_back(puzzleKeyQueue);
			}
			return columnKeyQueue;
		}

