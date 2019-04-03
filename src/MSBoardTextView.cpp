#include <iostream>
#include "MSBoardTextView.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard &gameboard) : board_view(gameboard) {
}

void MSBoardTextView::game_display() {
    std::string display;
    int boardHeight=board_view.getBoardHeight();
    int boardWidth=board_view.getBoardWidth();
    for (int idx_y = 0; idx_y<boardHeight; idx_y++)
    {
        for (int idx_x = 0; idx_x<boardWidth; idx_x++) {
            display+="[";
            display+=board_view.getFieldInfo(idx_x,idx_y);
            display+="]";
        } display+= "\n";
    }
    std::cout << display;
}
