#include "MSTextController.h"
#include "iostream"

MSTextController::MSTextController(MinesweeperBoard &board_act, MSBoardTextView &board_vi) : board_action(board_act), board_view(board_vi) {

}

void MSTextController::play()
{
while (board_action.getGameState()==RUNNING)
    {
    board_view.game_display();
    std::cout << std::endl;
    std::cout << "#########################" << std::endl;
    std::cout << "#                       #" << std::endl;
    std::cout << "#    1. REVEAL FIELD    #" << std::endl;
    std::cout << "#      2. SET FLAG      #" << std::endl;
    std::cout << "#        3. EXIT        #" << std::endl;
    std::cout << "#                       #" << std::endl;
    std::cout << "#########################" << std::endl;
    std::cin >> switcher;
    if (switcher ==3)
    {
        return;
    }
    std::cin >> x >> y;
    switch (switcher)
    {
        case 1: {
            board_action.revealField(x, y);
            break;
        }
        case 2: {
            board_action.toggleFlag(x, y);
            break;
        }
    }
    }
    if (board_action.getGameState()==FINISHED_LOSS)
    {
        board_view.game_display();
        std::cout << std::endl;
        std::cout << "#########################" << std::endl;
        std::cout << "#                       #" << std::endl;
        std::cout << "#        YOU LOSE       #" << std::endl;
        std::cout << "#                       #" << std::endl;
        std::cout << "#########################" << std::endl;
        std::cout << std::endl;
    }
    if (board_action.getGameState()==FINISHED_WIN)
    {
        board_view.game_display();
        std::cout << std::endl;
        std::cout << "#########################" << std::endl;
        std::cout << "#                       #" << std::endl;
        std::cout << "#        YOU WIN        #" << std::endl;
        std::cout << "#                       #" << std::endl;
        std::cout << "#########################" << std::endl;
        std::cout << std::endl;
    }
}
