#ifndef BOARDDRAW_H
#define BOARDDRAW_H
#include <SFML/Graphics.hpp>

class BoardDraw {
    int board_width;
    int board_height;
    int field_lenght;
    sf::VertexArray board_view;
public:
    BoardDraw(int w_board, int h_board, int lenght);
    void create_line(sf::RenderWindow &window);
    void board_draw(sf::RenderWindow & window);
};

#endif // BOARDDRAW_H
