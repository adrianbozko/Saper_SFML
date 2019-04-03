#ifndef BOARDDRAW_H
#define BOARDDRAW_H
#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"

class BoardDraw {
    MinesweeperBoard &board;
    int board_width;
    int board_height;
    int field_lenght;
    int fields_x;
    int fields_y;
    int x0;
    int y0;
    sf::VertexArray board_view;
public:
    BoardDraw(MinesweeperBoard &Saper, int x0, int y0, int lenght);
    void create_board(sf::RenderWindow &window,int xp,int yp, int xk, int yk);
    void draw(sf::RenderWindow &window);
};

#endif // BOARDDRAW_H
