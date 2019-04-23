#include "BoardDraw.h"
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>
#include "Single_Field.h"


BoardDraw::BoardDraw(MinesweeperBoard &saper_board,int x_0, int y_0, int lenght) :board(saper_board) {
    board_width=board.getBoardWidth();
    board_height=board.getBoardHeight();
    field_lenght=lenght;
    x0 = x_0;
    y0 = y_0;
}

void BoardDraw::loadTextures()
{
    bombTexture.loadFromFile("image/bomb.png");
    flagTexture.loadFromFile("image/flag.png");
    revealTexture.loadFromFile("image/revealed.png");
    font.loadFromFile("image/pixelated.ttf");
    fieldTexture.loadFromFile("image/field.png");
}

void BoardDraw::VsetMine(sf::RenderWindow &window, int idx_x, int idx_y)
{
    pole.setPointCount(4);
 //   pole.setFillColor(sf::Color(100,200,150));
    pole.setPoint(0, sf::Vector2f(x0+idx_x*field_lenght,y0+idx_y*field_lenght));
    pole.setPoint(1, sf::Vector2f(x0+field_lenght+idx_x*field_lenght-1,y0+idx_y*field_lenght));
    pole.setPoint(2, sf::Vector2f(x0+field_lenght+idx_x*field_lenght-1,y0+field_lenght+idx_y*field_lenght-1));
    pole.setPoint(3, sf::Vector2f(x0+idx_x*field_lenght,y0+field_lenght+idx_y*field_lenght-1));
    pole.setTexture(&bombTexture);
    window.draw(pole);
}

void BoardDraw::VsetFlag(sf::RenderWindow &window, int idx_x, int idx_y)
{
    pole.setPointCount(4);
//    pole.setFillColor(sf::Color(200,50,150));
    pole.setPoint(0, sf::Vector2f(x0+idx_x*field_lenght,y0+idx_y*field_lenght));
    pole.setPoint(1, sf::Vector2f(x0+field_lenght+idx_x*field_lenght-1,y0+idx_y*field_lenght));
    pole.setPoint(2, sf::Vector2f(x0+field_lenght+idx_x*field_lenght-1,y0+field_lenght+idx_y*field_lenght-1));
    pole.setPoint(3, sf::Vector2f(x0+idx_x*field_lenght,y0+field_lenght+idx_y*field_lenght-1));
    pole.setTexture(&flagTexture);
    window.draw(pole);
}

void BoardDraw::VsetReveal(sf::RenderWindow &window, int idx_x, int idx_y)
{
    pole.setPointCount(4);
//    pole.setFillColor(sf::Color(229, 229, 229));
    pole.setPoint(0, sf::Vector2f(x0+idx_x*field_lenght,y0+idx_y*field_lenght));
    pole.setPoint(1, sf::Vector2f(x0+field_lenght+idx_x*field_lenght-1,y0+idx_y*field_lenght));
    pole.setPoint(2, sf::Vector2f(x0+field_lenght+idx_x*field_lenght-1,y0+field_lenght+idx_y*field_lenght-1));
    pole.setPoint(3, sf::Vector2f(x0+idx_x*field_lenght,y0+field_lenght+idx_y*field_lenght-1));
    pole.setTexture(&revealTexture);
    window.draw(pole);
}

void BoardDraw::VsetField(sf::RenderWindow &window, int idx_x, int idx_y)
{
    pole.setPointCount(4);
 //   pole.setFillColor(sf::Color(100,200,150));
    pole.setPoint(0, sf::Vector2f(x0+idx_x*field_lenght,y0+idx_y*field_lenght));
    pole.setPoint(1, sf::Vector2f(x0+field_lenght+idx_x*field_lenght-1,y0+idx_y*field_lenght));
    pole.setPoint(2, sf::Vector2f(x0+field_lenght+idx_x*field_lenght-1,y0+field_lenght+idx_y*field_lenght-1));
    pole.setPoint(3, sf::Vector2f(x0+idx_x*field_lenght,y0+field_lenght+idx_y*field_lenght-1));
    pole.setTexture(&fieldTexture);
    window.draw(pole);
}

void BoardDraw::VsetNumber(sf::RenderWindow &window, int idx_x, int idx_y)
{
    int mines = board.countMines(idx_x,idx_y);
    sf::Text number;
    number.setFont(font);


    if(mines==1)
        {
        number.setString("1");
        number.setFillColor(sf::Color(51, 105, 30));
        }
    if(mines==2)
        {
        number.setString("2");
        number.setFillColor(sf::Color(130, 119, 23));
        }
    if(mines==3)
    {
        number.setString("3");
        number.setFillColor(sf::Color(245, 127, 23));
    }
    if(mines==4)
    {
        number.setString("4");
        number.setFillColor(sf::Color(255, 111, 00));
    }
    if(mines==5)
    {
        number.setString("5");
        number.setFillColor(sf::Color(230, 81, 0));
    }
    if(mines==6)
    {
        number.setString("6");
        number.setFillColor(sf::Color(191, 54, 12));
    }
    if(mines==7)
    {
        number.setString("7");
        number.setFillColor(sf::Color(183, 28, 28));
    }
    if(mines==8)
    {
        number.setString("8");
        number.setFillColor(sf::Color(213, 0, 0));
    }


    number.setCharacterSize(field_lenght*0.8);
    number.setPosition(x0+idx_x*field_lenght+12,y0+idx_y*field_lenght);

    window.draw(number);

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



    for (int idx_y = 0; idx_y<board_height; idx_y++)
    {
        for (int idx_x = 0; idx_x<board_width; idx_x++) {
            if(board.isRevealed(idx_x,idx_y)==0)
            {
                VsetField(window,idx_x,idx_y);
            }

            if(board.isRevealed(idx_x,idx_y)==1 and board.hasFlag(idx_x,idx_y)==0)
            {
                VsetReveal(window,idx_x,idx_y);
                VsetNumber(window,idx_x,idx_y);
            }
            if(board.hasFlag(idx_x,idx_y)==1)
            {
                VsetFlag(window,idx_x,idx_y);
            }
            if(board.hasMine(idx_x,idx_y)==1 and board.getGameState()==FINISHED_LOSS)
            {
                VsetMine(window,idx_x,idx_y);
            }

        }
    }



}

