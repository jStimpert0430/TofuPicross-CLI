#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
#include <utility>
#include "puzzle.h"

class picrossController{
    private:
        std::pair<int, int> cursorPos; 
    public:
	    std::string GetCommand(Puzzle &currentPuzzle);
        int GetCursorPOSX();
        int GetCursorPOSY();
        void SetCursorPOS(int newX, int newY);
        void MoveCursor(int x, int y);
        void MarkPuzzle(int x, int y, Puzzle &currentPuzzle);
        bool CheckMove(int x, int y, Puzzle &currentPuzzle);
};

#endif
