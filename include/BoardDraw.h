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
    sf::ConvexShape pole;
    sf::Font font;
    sf::Texture bombTexture;
    sf::Texture flagTexture;
    sf::Texture revealTexture;
    sf::Texture fieldTexture;
    void VsetMine(sf::RenderWindow &window, int idx_x, int idx_y);
    void VsetFlag(sf::RenderWindow &window, int idx_x, int idx_y);
    void VsetReveal(sf::RenderWindow &window, int idx_x, int idx_y);
    void VsetNumber(sf::RenderWindow &window, int idx_x, int idx_y);
    void VsetField(sf::RenderWindow &window, int idx_x, int idx_y);

public:
    BoardDraw(MinesweeperBoard &Saper, int x0, int y0, int lenght);
    void draw_board(sf::RenderWindow &window);
    void setField(int x, int y);
    void loadTextures();
};

#endif // BOARDDRAW_H
