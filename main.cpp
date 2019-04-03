#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <SFML/Graphics.hpp>
#include "BoardDraw.h"

int main()
{
    int board_width = 10;
    int board_height = 10;

    int x0 = 50;
    int y0 = 50;

    int field_size = 60;

    int window_width = 2*x0+board_width*field_size;
    int window_heigt = 2*y0+board_height*field_size;

    MinesweeperBoard Saper(board_width,board_height,DEBUG);
    //                  CONSOLE MODE
    //    MSBoardTextView game_view (Saper);
    //    MSTextController control (Saper, game_view);
    //    control.play();
    //
    sf::RenderWindow window(sf::VideoMode(window_width, window_heigt), "SAPER");
    BoardDraw view(Saper,x0,y0,field_size);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        view.draw_board(window);
        window.display();
    }

    return 0;
}
