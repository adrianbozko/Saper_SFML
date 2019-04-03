#include <iostream>
#include "MinesweeperBoard.h"
#include <string>
#include <stdlib.h>
#include <ctime>


MinesweeperBoard::MinesweeperBoard() {
    boardWidth=5;
    boardHeight=5;
    setBoard();
}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode g_mode) {
    boardWidth = width;
    boardHeight = height;
    mode = g_mode;
    state=RUNNING;
    mineBoardCounter=0;
    emptyField=0;
    setBoard();
}




void MinesweeperBoard::setField(int idx_x, int idx_y, bool hasMine, bool hasFlag, bool isRevealed) {
    board[idx_y][idx_x]={hasMine, hasFlag, isRevealed};
}

int MinesweeperBoard::gameFields(int width, int height) {
    int area = width*height;
    return area;
}

void MinesweeperBoard::setBoard() {
    if(mode==DEBUG)
    {
        for (int y=0, x=0; y<boardHeight and x<boardWidth ; y++, x++)
            setField(x,y,true,false,false);
        for (int y=0, x=0; x<boardWidth; x++)
            setField(x,y,true,false,false);
        for (int x=0, y=0; y<boardHeight; y++)
            if(y%2==0)
                setField(x,y,true,false,false);

    }
    if(mode==EASY)
    {
        {
        for (int idx_y = 0; idx_y < boardHeight; idx_y++) {
            for (int idx_x = 0; idx_x < boardWidth; idx_x++) {
                setField(idx_x, idx_y, false, false, false);
            }
        }
    }
        int difficulty = 0.1*gameFields(boardWidth,boardHeight);
        for (int counter=1; counter<=difficulty; ++counter)
        {
            int rand_x = (rand() % boardWidth)+ 0;
            int rand_y = (rand() % boardHeight) + 0;
            if (board[rand_y][rand_x].hasMine==0)
            {
                board[rand_y][rand_x].hasMine=true;
                mineBoardCounter++;
            }
            else
                counter--;
        }
        emptyField=gameFields(boardWidth,boardHeight)-mineBoardCounter;
    }

    if(mode==NORMAL)
    {
        {
            for (int idx_y = 0; idx_y < boardHeight; idx_y++) {
                for (int idx_x = 0; idx_x < boardWidth; idx_x++) {
                    setField(idx_x, idx_y, false, false, false);
                }
            }
        }
        int difficulty = 0.2*gameFields(boardWidth,boardHeight);
        for (int counter=1; counter<=difficulty; ++counter)
        {
            int rand_x = (rand() % boardWidth)+ 0;
            int rand_y = (rand() % boardHeight) + 0;
            if (board[rand_y][rand_x].hasMine==0)
            {
                board[rand_y][rand_x].hasMine=true;
                mineBoardCounter++;
            }
            else
                counter--;
        }
        emptyField=gameFields(boardWidth,boardHeight)-mineBoardCounter;
    }

    if(mode==HARD)
    {
        {
            for (int idx_y = 0; idx_y < boardHeight; idx_y++) {
                for (int idx_x = 0; idx_x < boardWidth; idx_x++) {
                    setField(idx_x, idx_y, false, false, false);
                }
            }
        }
        int difficulty = 0.3*gameFields(boardWidth,boardHeight);
        for (int counter=1; counter<=difficulty; ++counter)
        {
            int rand_x = (rand() % boardWidth)+ 0;
            int rand_y = (rand() % boardHeight) + 0;
            if (board[rand_y][rand_x].hasMine==0)
            {
                board[rand_y][rand_x].hasMine=true;
                mineBoardCounter++;
            }
            else
                counter--;
        }
        emptyField=gameFields(boardWidth,boardHeight)-mineBoardCounter;
    }
}

void MinesweeperBoard::debug_display() const {
    std::string display;
    for (int idx_y = 0; idx_y<boardHeight; idx_y++)
    {
        for (int idx_x = 0; idx_x<boardWidth; idx_x++) {
            display+="[";
            if (board[idx_y][idx_x].hasMine)
                display+="M";
            else
                display+=".";
            if (board[idx_y][idx_x].isRevealed)
                display+="o";
            else
                display+=".";
            if (board[idx_y][idx_x].hasFlag)
                display+="f";
            else
                display+=".";
            display+="] ";

        } display+= "\n";
    }
    std::cout << display;
}

int MinesweeperBoard::getBoardWidth() const {
    return boardWidth;
}

int MinesweeperBoard::getBoardHeight() const {
    return boardHeight;
}

int MinesweeperBoard::getMineCount() const {
    return mineBoardCounter;
}

int MinesweeperBoard::countMines(int idx_x, int idx_y) {
    mineFieldCounter=0;
//    if (board[idx_y][idx_x].isRevealed==0)
//        return -1;
    if (idx_x >= boardWidth or idx_y >= boardHeight or idx_x<0 or idx_y<0)
        return -1;
    else
    {
        for(int iy=idx_y-1; iy <=idx_y+1; iy++)
        {
            for (int ix=idx_x-1; ix<=idx_x+1 ; ix++)
                if (ix>=0 and ix<boardWidth and iy>=0 and iy<boardHeight)
                {
                    if (iy==idx_y and ix==idx_x)
                        mineFieldCounter+=0;
                    if(board[iy][ix].hasMine and (iy!=idx_y or ix!=idx_x))
                        mineFieldCounter+=1;
                }
        }
    }
    return mineFieldCounter;
}


bool MinesweeperBoard::hasMine(int idx_x, int idx_y) const {
    if (idx_x<0 or idx_x>=boardWidth or idx_y<0 or idx_y>=boardHeight)
        return false;
    if (board[idx_y][idx_x].hasMine==1)
        return true;
    else return false;
}

bool MinesweeperBoard::hasFlag(int idx_x, int idx_y) const {
    if (idx_x<0 or idx_x>=boardWidth or idx_y<0 or idx_y>=boardHeight)
        return false;
    if (board[idx_y][idx_x].isRevealed==1)
        return false;
    if (board[idx_y][idx_x].hasFlag==0)
        return false;
    if (board[idx_y][idx_x].hasFlag==1)
        return true;
}

bool MinesweeperBoard::isRevealed(int idx_x, int idx_y) const {
    if (idx_x<0 or idx_x>=boardWidth or idx_y<0 or idx_y>=boardHeight)
        return false;
    if (board[idx_y][idx_x].isRevealed==1)
        return true;
    else return false;
}

void MinesweeperBoard::toggleFlag(int idx_x, int idx_y) {
    ++moves;
    if (board[idx_y][idx_x].isRevealed==1)
        return;
    if (idx_x<0 or idx_x>=boardWidth or idx_y<0 or idx_y>=boardHeight)
        return;
    if (state==FINISHED_WIN or state==FINISHED_LOSS)
        return;
    if (board[idx_y][idx_x].isRevealed==0 and board[idx_y][idx_x].hasMine==1)
    {
        board[idx_y][idx_x].hasFlag=true;
        mineBoardCounter--;
    }
    else
        board[idx_y][idx_x].hasFlag=true;
    if (mineBoardCounter==0)
        state=FINISHED_WIN;
}

void MinesweeperBoard::revealField(int idx_x, int idx_y) {
    if (idx_x<0 or idx_x>=boardWidth or idx_y<0 or idx_y>=boardHeight)
        return;
    if (state==FINISHED_WIN or state==FINISHED_LOSS)
        return;
    if (board[idx_y][idx_x].hasFlag==1)
        return;


    if (moves!=0 and board[idx_y][idx_x].hasFlag==0 and board[idx_y][idx_x].hasMine==0)
    {

        if (board[idx_y][idx_x].isRevealed==0)
        {
            board[idx_y][idx_x].isRevealed=true;
            moves++;
            emptyField--;
        }
        recursionReveal(idx_x,idx_y);
    }
    if (emptyField==0)
        state=FINISHED_WIN;
    if (moves!=0 and board[idx_y][idx_x].hasMine==1 and mode!=DEBUG)
    {
        board[idx_y][idx_x].isRevealed=true;
        moves++;
        state=FINISHED_LOSS;
    }

    if (board[idx_y][idx_x].isRevealed==0 and moves==0)
    {
        if (board[idx_y][idx_x].hasMine==1 and mode==DEBUG)
        {
            board[idx_y][idx_x].isRevealed=true;
            moves++;
        }
        if (board[idx_y][idx_x].hasMine==1 and mode!=DEBUG)
        {
            for (int counter=1; counter<=1; ++counter)
            {
                int rand_x = (rand() % boardWidth)+ 0;
                int rand_y = (rand() % boardHeight) + 0;
                if (board[rand_y][rand_x].hasMine==0)
                {
                    board[idx_y][idx_x].hasMine=false;
                    board[rand_y][rand_x].hasMine=true;
                }
                else
                    counter--;
            }
            board[idx_y][idx_x].isRevealed=true;
            emptyField--;
        }
        if (board[idx_y][idx_x].hasMine==0 and mode!=DEBUG)
        {
            board[idx_y][idx_x].isRevealed=true;
            moves++;
            emptyField--;
        }
        recursionReveal(idx_x,idx_y);
    }
    if (emptyField==0)
        state=FINISHED_WIN;
}

GameState MinesweeperBoard::getGameState() const {
    return state;

}

char MinesweeperBoard::getFieldInfo(int idx_x, int idx_y) {
    char info;
    if (getGameState()==FINISHED_LOSS and board[idx_y][idx_x].hasMine==1)
    {
        info='X';
        return info;
    }
    if (idx_x<0 or idx_x>=boardWidth or idx_y<0 or idx_y>=boardHeight)
    {
        info='#';
        return info;
    }
    if (board[idx_y][idx_x].isRevealed==0 and board[idx_y][idx_x].hasFlag==1)
    {
        info='F';
        return info;
    }
    if (board[idx_y][idx_x].isRevealed==0 and board[idx_y][idx_x].hasFlag==0)
    {
        info='_';
        return info;
    }
    if (board[idx_y][idx_x].isRevealed==1 and board[idx_y][idx_x].hasMine==1)
    {
        info='x';
        return info;
    }
    if (board[idx_y][idx_x].isRevealed==1 and countMines(idx_x,idx_y)==0)
    {
            info=' ';
            return info;
    }
    if (board[idx_y][idx_x].isRevealed==1 and countMines(idx_x,idx_y)!=0)
    {
            int number = countMines(idx_x,idx_y);
            info='0'+number;
            return info;
    }
}

void MinesweeperBoard::recursionReveal(int idx_x, int idx_y) {
    if (countMines(idx_x,idx_y) == 0)
    {
        for (int i = idx_y - 1; i <= idx_y + 1; i++) {
            for (int j = idx_x - 1; j <= idx_x + 1; j++) {
                if (j>=0 and j<boardWidth and i>=0 and i<boardHeight and !board[i][j].isRevealed)
                {
                    if (countMines(j, i) == 0)
                    {
                        if (board[i][j].isRevealed==false)
                        {
                            board[i][j].isRevealed = true;
                            emptyField--;
                            revealField(j, i);
                        }

                    }

                    if (countMines(j, i) > 0)
                    {
                        if (board[i][j].isRevealed==false)
                        {
                            board[i][j].isRevealed = true;
                            emptyField--;
                        }
                    }
                }
            }
        }
    }
}
