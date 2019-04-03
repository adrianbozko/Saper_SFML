#include "BoardDraw.h"
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>

BoardDraw::BoardDraw(MinesweeperBoard &saper_board,int x_0, int y_0, int lenght) :board(saper_board) {
    board_width=board.getBoardWidth();
    board_height=board.getBoardHeight();
    field_lenght=lenght;
    x0 = x_0;
    y0 = y_0;
}

void BoardDraw::setField(int idx_x, int idx_y)
{
    board_view2.append(sf::Vertex(sf::Vector2f(x0+idx_x*field_lenght,y0+idx_y*field_lenght)));
    board_view2.append(sf::Vertex(sf::Vector2f(x0+field_lenght+idx_x*field_lenght,y0+idx_y*field_lenght)));
    board_view2.append(sf::Vertex(sf::Vector2f(x0+field_lenght+idx_x*field_lenght,y0+field_lenght+idx_y*field_lenght)));
    board_view2.append(sf::Vertex(sf::Vector2f(x0+idx_x*field_lenght,y0+field_lenght+idx_y*field_lenght)));
}

void BoardDraw::draw_board(sf::RenderWindow &window)
{


    board_view.setPrimitiveType(sf::Lines);
    for (int i=0; i<=board_width;i++)
    {
    board_view.append(sf::Vertex(sf::Vector2f(x0+i*field_lenght,y0)));
    board_view.append(sf::Vertex(sf::Vector2f(x0+i*field_lenght,y0+board_height*field_lenght)));
    }
    for (int i=board_height; i>=0;i--)
    {
    board_view.append(sf::Vertex(sf::Vector2f(x0,y0+i*field_lenght)));
    board_view.append(sf::Vertex(sf::Vector2f(x0+board_width*field_lenght,y0+i*field_lenght)));
    }

    window.draw(board_view);



    board_view2.setPrimitiveType(sf::Quads);

    for (int idx_y = 0; idx_y<board_height; idx_y++)
    {
        for (int idx_x = 0; idx_x<board_width; idx_x++) {
            if(board.hasMine(idx_x,idx_y)==1)
            {
                    setField(idx_x,idx_y);
            }
        }
    }

    window.draw(board_view2);
}

