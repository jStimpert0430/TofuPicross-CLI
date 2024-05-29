#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <vector>
#include "puzzle.h"
#define redNumber "\x1B[31m " + to_string((i)) + "\033[0m"
#define filledSpaceChar " ■"
#define emptySpaceChar " ◇"
using namespace std;

        Puzzle::Puzzle(){
        };

		void Puzzle::SetGameBoard(int x, int y, bool val){
			gameBoard[y][x] = val;
		}

		bool Puzzle::GetPuzzleMapVal(int x, int y){
			return puzzleMap[y][x]; 
		}

		void Puzzle::PrintBoard(int cursorX, int cursorY){
			system("clear");
			queue<queue<int>> rowKeyQueue = CalcRowKeys();
			vector<queue<int>> columnKeyQueue = CalcColumnKeys();
			PrintHeader();
			PrintTopRowCoords();
			for(int i = 0; i < sizeof(gameBoard[0]); i++){
				PrintLeadingKey(rowKeyQueue, i, cursorY);
				cout << redNumber;
				PrintGameBoardRow(i, cursorX, cursorY);
			}
			PrintBottomKeys(columnKeyQueue, cursorX);
			PrintFooter();
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
				cout << redNumber;
			}
		}

		void Puzzle::PrintLeadingKey(queue<queue<int>> &keyQueue, int selectedRow, int cursorY){
				int margin = 20;
                cout << "\n";
                string rowKeyString;
				if(selectedRow == cursorY){
					while(!keyQueue.front().empty()){
						rowKeyString += to_string(keyQueue.front().front()) + " ";
						keyQueue.front().pop();
					}
					cout << "\x1B[31m" <<  setw(margin) << rowKeyString + "   " << "\033[0m";
				}
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
			for(int i = 0; i < sizeof(gameBoard[selectedRow]); i++){
				//Color cursor space red
				if(selectedRow == cursorY && i == cursorX){
					if( gameBoard[selectedRow][i] == true){
						cout<< "\x1B[31m" << filledSpaceChar << "\033[0m";
					}
					else{
						cout << "\x1B[31m" << emptySpaceChar << "\033[0m";
					}
				}
				else{
					if( gameBoard[selectedRow][i] == true){
						cout<< filledSpaceChar;
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
					if(!keyQueue.at(j).empty()){
						//Color key of current heighlighted column based on cursor
						if(j == cursorX){
							cout << " " << "\x1B[31m" << keyQueue.at(j).front() << "\033[0m";
						}
						else{
							cout << " " << keyQueue.at(j).front();
						}
					keyQueue.at(j).pop();
					}
					else{
						cout << "  ";
					}
				}
			}
		}

		void Puzzle::PrintFooter(){
			int margin = 25;
			cout << "\n\n\n"; 
			cout << setw((margin)) << "";
			cout << "MISTAKES: 99\n\n";
		}

		queue<queue<int>> Puzzle::CalcRowKeys(){
			queue<queue<int>> rowKeyQueue;
			for(int i = 0; i < sizeof(puzzleMap[0]); i++){
				int consecutiveCount = 0;
				queue<int> puzzleKeyQueue;
				for(int j = 0; j < sizeof(puzzleMap[0]); j++){
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
			for(int i = 0; i < sizeof(puzzleMap[0]); i++){
				int consecutiveCount = 0;
				queue<int> puzzleKeyQueue;
				for(int j = 0; j < sizeof(puzzleMap[0]); j++){
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

