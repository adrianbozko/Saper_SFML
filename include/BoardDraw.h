#ifndef BOARDDRAW_H
#define BOARDDRAW_H
#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"

class BoardDraw {
    MinesweeperBoard &board;
    int board_width;
    int board_height;
    int field_lenght;
    int x0;
    int y0;
    sf::VertexArray board_view;
    sf::VertexArray board_view2;

public:
    BoardDraw(MinesweeperBoard &Saper, int x0, int y0, int lenght);
    void draw_board(sf::RenderWindow &window);
    void setField(int x, int y);
};

#endif // BOARDDRAW_H
