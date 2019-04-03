#include "BoardDraw.h"
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>

BoardDraw::BoardDraw(MinesweeperBoard &saper_board,int x_0, int y_0, int lenght) :board(saper_board) {
    board_width=board.getBoardWidth();
    board_height=board.getBoardHeight();
    field_lenght=lenght;
    fields_x=board_width/field_lenght;
    fields_y=board_height/field_lenght;
    x0 = x_0;
    y0 = y_0;
}

/*void BoardDraw::create_board(sf::RenderWindow &window,int xp,int yp, int xk, int yk)
{
    board_view.setPrimitiveType(sf::Lines);
    for (int i=0; i<=board.getBoardWidth();i++)
    {
    board_view.append(sf::Vertex(sf::Vector2f(xp+i*field_lenght,yp)));
    board_view.append(sf::Vertex(sf::Vector2f(xk+i*field_lenght,yk)));
    }
    for (int i=board.getBoardHeight(); i>=0;i--)
    {
    board_view.append(sf::Vertex(sf::Vector2f(xp,yp+i*field_lenght)));
    board_view.append(sf::Vertex(sf::Vector2f(xk+fields*field_lenght,yp+i*field_lenght)));
    }

    window.draw(board_view);
}*/

void BoardDraw::draw(sf::RenderWindow &window)
{
    board_view.setPrimitiveType(sf::Lines);
    for (int i=0; i<=board_width;i++)
    {
    board_view.append(sf::Vertex(sf::Vector2f(x0+i*field_lenght,y0)));
    board_view.append(sf::Vertex(sf::Vector2f(x0+i*field_lenght,y0+fields_y*field_lenght)));
    }
//    for (int i=board_height; i>=0;i--)
//    {
//    board_view.append(sf::Vertex(sf::Vector2f(xp,yp+i*field_lenght)));
//    board_view.append(sf::Vertex(sf::Vector2f(xk+fields*field_lenght,yp+i*field_lenght)));
//    }

    window.draw(board_view);
}
