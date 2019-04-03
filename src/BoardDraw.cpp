#include "BoardDraw.h"
#include <SFML/Graphics.hpp>

BoardDraw::BoardDraw(int w_board, int h_board, int lenght) {
    board_width=w_board;
    board_height=h_board;
    field_lenght=lenght;
    fields=board_width/field_lenght;
}

void BoardDraw::create_board(sf::RenderWindow &window,int xp,int yp, int xk, int yk)
{
    board_view.setPrimitiveType(sf::Lines);
    for (int i=0; i<=fields;i++)
    {
    board_view.append(sf::Vertex(sf::Vector2f(xp+i*field_lenght,yp)));
    board_view.append(sf::Vertex(sf::Vector2f(xk+i*field_lenght,yk)));
    }
    for (int i=fields; i>=0;i--)
    {
    board_view.append(sf::Vertex(sf::Vector2f(xp,yp+i*field_lenght)));
    board_view.append(sf::Vertex(sf::Vector2f(xk+fields*field_lenght,yp+i*field_lenght)));
    }

    window.draw(board_view);


}

void BoardDraw::board_draw(sf::RenderWindow &window) {
    window.draw(board_view);

}

