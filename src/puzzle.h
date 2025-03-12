#ifndef PUZZLE_H
#define PUZZLE_H
#include <queue>
#include <vector>
#include <string>
#include "picrossEnums.h"


class Puzzle{
	private:
		const static int SIZE = 10;
		int DIFFICULTY = 2;
		int MAX_MISTAKES = 10;
		int currentMistakes = 0;
		//DEBUG DEFINITION - IN FULL VERSION THIS WILL BE POPULATED EXTERNALLY

		//A bool is used for the puzzle map and the custom enum for the gameboard because the map needs only 2 states whereas the gameboard will have many.
		bool puzzleMap[SIZE][SIZE] = { 
		{false, false, false, false, false, false, false, false, false , false},
		{false, false, true, true, true, true, true, true, true, false},
		{false, false, false, true, true, true, true, true, false, false},
		{false, false, false, true, true, true, true, true, false, false},
		{false, false, false, true, true, true, true, true, false, false},
		{false, false, true, true, true, true, true, true, true, false},
		{false, false, false, false, false, true, false, false, false , false},
		{true, false, true, true, true, true, true, true, true, true},
		{false, true, true, true, true, true, true, true, true , false},
		{false, false, true, true, true, true, true, true, true, false} };

		enum eMapEntryType enumGameBoard[SIZE][SIZE] = {};

	public:
        Puzzle();
		void SetGameBoard(int x, int y, enum eMapEntryType val);
		enum eMapEntryType GetGameBoardVal(int x, int y);
		bool GetPuzzleMapVal(int x, int y);
		void PrintHeader();
		void PrintTopRowCoords();
		void PrintBoard(int cursorX, int cursorY, std::string message);
		void PrintLeadingKey(std::queue<std::queue<int>> &keyQueue, std::queue<std::queue<int>> &rowKeyQueueEnum, int selectedRow, int cursorY);
		void PrintGameBoardRow(int selectedRow, int cursorX, int cursorY);
		void PrintBottomKeys(std::vector<std::queue<int>> &keyQueue, int cursorX);
		void PrintFooter(std::string message);
		void addToCurrentMistakes(int value);
		int getMaxMistakes();
		int getCurrentMistakes();
		int getSize();
		void resetGameBoard();
		std::queue<std::queue<int>> CalcRowKeys();
		std::vector<std::queue<int>> CalcColumnKeys();
		std::queue<std::queue<int>> CalcRowKeysEnum();
		std::vector<std::queue<int>> CalcColumnKeysEnum();
};

#endif
