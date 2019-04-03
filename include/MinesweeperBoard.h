#ifndef MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_H

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};


class MinesweeperBoard {
    Field board[100][100];
    int boardWidth;
    int boardHeight;
    void setBoard();
    GameMode mode;
    GameState state;
    int mineFieldCounter;
    int mineBoardCounter;
    int emptyField;
    int gameFields (int width, int height);
    int moves=0;
    void setField(int idx_x, int idx_y, bool hasMine, bool hasFlag, bool isRevealed);



    public:
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int x, int y);
    bool hasFlag(int x, int y) const;
    bool isRevealed(int x, int y) const;
    bool hasMine (int x, int y) const;
    void toggleFlag(int x, int y);
    void revealField(int x, int y);
    void recursionReveal (int x, int y);
    GameState getGameState() const;
    char getFieldInfo(int x, int y);
};

#endif // MINESWEEPERBOARD_H
