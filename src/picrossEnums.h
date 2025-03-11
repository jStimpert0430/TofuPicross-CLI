#ifndef PICROSSENUMS_H
#define PICROSSENUMS_H

enum class eMapEntryType{
    EMPTY,
    FILLED,
    FLAGGED,
    FLAGGEDFILLED,
    WRONG,
    eMapEntryType_MAX
};

enum class eDifficultyType{
    EASY,
    MEDIUM,
    HARD,
    MASTER,
    GRANDMASTER,
    FUNSIES,
    eDifficultyType_MAX
};

enum class eGameState{
    INITIALIZING,
    ACTIVE,
    GAMEOVER,
    TITLE,
    LEVELSELECT,
    DIFFICULTYSELECT,
    MESSAGESCREEN,
    eGameState_MAX
};

#endif