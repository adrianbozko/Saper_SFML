#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <SFML/Graphics.hpp>
#include "BoardDraw.h"
#include "OpenWindow.h"
#include <string>



int main()
{


    int board_width=20;
    int board_height=20;

    int x0 = 50;
    int y0 = 50;

    int field_size = 35;

    GameMode state;

    sf::Font font_text;
    font_text.loadFromFile("image/pixelated.ttf");

    int uruchomienie=0;
    if (uruchomienie==0)
    {
        uruchomienie++;
        OpenWindow okno;
        okno.create_openWindow(board_width,board_height,state);
    }

    int window_width = 2*x0+board_width*field_size;
    int window_heigt = 2*y0+board_height*field_size+200;


    MinesweeperBoard Saper(board_width,board_height,state);

    //                  CONSOLE MODE
    //    MSBoardTextView game_view (Saper);
    //    MSTextController control (Saper, game_view);
    //    control.play();
    //

            sf::RectangleShape restart(sf::Vector2f(120.f, 80.f));
            restart.setPosition(x0+(board_width*field_size/2)-130,y0+(board_height*field_size)+120);
            restart.setFillColor(sf::Color::Black);
            sf::Text reset;
            reset.setString("RESET");
            reset.setFont(font_text);
            reset.setPosition(x0+(board_width*field_size/2)-118,y0+(board_height*field_size)+133);
            reset.setCharacterSize(40);


            sf::RectangleShape quit(sf::Vector2f(120.f, 80.f));
            quit.setPosition(x0+(board_width*field_size/2)+10,y0+(board_height*field_size)+120);
            quit.setFillColor(sf::Color::Black);
            sf::Text quitt;
            quitt.setString("QUIT");
            quitt.setFont(font_text);
            quitt.setPosition(x0+(board_width*field_size/2)+29,y0+(board_height*field_size)+133);
            quitt.setCharacterSize(40);


    sf::RenderWindow window(sf::VideoMode(window_width, window_heigt), "SAPER");
    BoardDraw view(Saper,x0,y0,field_size);
    view.loadTextures();


    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        if (event.type == sf::Event::MouseButtonPressed)
        {

            if (event.mouseButton.button == sf::Mouse::Left)
            {
                int xpos=0;
                int ypos=0;

                if (event.mouseButton.x > x0 and event.mouseButton.x < x0+board_width*field_size and event.mouseButton.y > y0 and event.mouseButton.y < y0+board_height*field_size)
                {
                    for(int xi=0; xi<board_width;xi++)
                    {
                        if (event.mouseButton.x > x0+xi*field_size and event.mouseButton.x < x0+(xi+1)*field_size)
                            xpos=xi;
                    }
                    for(int yi=0; yi<board_width;yi++)
                    {
                        if (event.mouseButton.y > y0+yi*field_size and event.mouseButton.y < y0+(yi+1)*field_size)
                            ypos=yi;
                    }
                }
                Saper.revealField(xpos,ypos);

                    if (event.mouseButton.x > (x0+(board_width*field_size/2)-130) and event.mouseButton.x < (x0+(board_width*field_size/2)-10) and event.mouseButton.y > (y0+(board_height*field_size)+120) and event.mouseButton.y < (y0+(board_height*field_size)+200))
                    {
                        Saper.setBoard();
                        Saper.state=RUNNING;
                        Saper.moves=0;
                        clock.restart();
                    }
                    if (event.mouseButton.x > (x0+(board_width*field_size/2)+10) and event.mouseButton.x < (x0+(board_width*field_size/2)+10+120) and event.mouseButton.y > (y0+(board_height*field_size)+120) and event.mouseButton.y < (y0+(board_height*field_size)+120+80))
                    {
                        return 0;
                    }
            }


            if (event.mouseButton.button == sf::Mouse::Right)
            {
                int xpos=0;
                int ypos=0;

                if (event.mouseButton.x > x0 and event.mouseButton.x < x0+board_width*field_size and event.mouseButton.y > y0 and event.mouseButton.y < y0+board_height*field_size)
                {
                    for(int xi=0; xi<board_width;xi++)
                    {
                        if (event.mouseButton.x > x0+xi*field_size and event.mouseButton.x < x0+(xi+1)*field_size)
                            xpos=xi;
                    }
                    for(int yi=0; yi<board_width;yi++)
                    {
                        if (event.mouseButton.y > y0+yi*field_size and event.mouseButton.y < y0+(yi+1)*field_size)
                            ypos=yi;
                    }
                }
                Saper.toggleFlag(xpos,ypos);
            }
        }

        }
        window.clear(sf::Color(189,189,189));
        view.draw_board(window);


        sf::Time elapsed;
        if(Saper.moves>=1)
        {
        elapsed = clock.getElapsedTime();
        std::cout << elapsed.asSeconds() << std::endl;
        }


        if(Saper.getGameState()==RUNNING)
        {
            sf::RectangleShape runn_box(sf::Vector2f(300.f, 200.f));
            runn_box.setPosition(x0+(board_width*field_size/2)-150,y0+(board_height*field_size)+20);
            runn_box.setFillColor(sf::Color::Black);
            window.draw(runn_box);
            sf::RectangleShape runn_box1(sf::Vector2f(280.f, 180.f));
            runn_box1.setPosition(x0+(board_width*field_size/2)-150+10,y0+(board_height*field_size)+30);
            runn_box1.setFillColor(sf::Color(189,189,189));
            window.draw(runn_box1);

            window.draw(restart);
            window.draw(reset);
            window.draw(quit);
            window.draw(quitt);

            sf::Text stoper;
            int x = elapsed.asSeconds();
            x=x/1;
            stoper.setString(std::to_string(x));
            stoper.setFont(font_text);
            stoper.setFillColor(sf::Color::Black);
            stoper.setCharacterSize(50);
            stoper.setPosition(x0+(board_width*field_size/2)-150+40,y0+(board_height*field_size)+35);
            window.draw(stoper);

        }

        if(Saper.getGameState()==FINISHED_LOSS)
        {
            sf::RectangleShape loss_box(sf::Vector2f(300.f, 200.f));
            loss_box.setPosition(x0+(board_width*field_size/2)-150,y0+(board_height*field_size)+20);
            loss_box.setFillColor(sf::Color::Black);
            sf::RectangleShape loss_box1(sf::Vector2f(280.f, 180.f));
            loss_box1.setPosition(x0+(board_width*field_size/2)-150+10,y0+(board_height*field_size)+30);
            loss_box1.setFillColor(sf::Color(189,189,189));
            sf::Text loss_text;
            loss_text.setFont(font_text);
            loss_text.setString("YOU LOSE");
            loss_text.setPosition(x0+(board_width*field_size/2)-150+20,y0+(board_height*field_size)+35);
            loss_text.setFillColor(sf::Color::Black);
            loss_text.setCharacterSize(70);
            window.draw(loss_box);
            window.draw(loss_box1);
            window.draw(loss_text);


            window.draw(restart);
            window.draw(reset);
            window.draw(quit);
            window.draw(quitt);

        }
        if(Saper.getGameState()==FINISHED_WIN)
        {
            sf::RectangleShape win_box(sf::Vector2f(300.f, 200.f));
            win_box.setPosition(x0+(board_width*field_size/2)-150,y0+(board_height*field_size)+200);
            win_box.setFillColor(sf::Color::Black);
            sf::RectangleShape win_box1(sf::Vector2f(280.f, 180.f));
            win_box1.setPosition(x0+(board_width*field_size/2)-150+10,y0+(board_height*field_size)+30);
            win_box1.setFillColor(sf::Color(189,189,189));
            sf::Text win_text;
            win_text.setFont(font_text);
            win_text.setString("YOU WIN");
            win_text.setPosition(x0+(board_width*field_size/2)-150+30,y0+(board_height*field_size)+35);
            win_text.setFillColor(sf::Color::Black);
            win_text.setCharacterSize(70);
            window.draw(win_box);
            window.draw(win_text);


            window.draw(restart);
            window.draw(reset);
            window.draw(quit);
            window.draw(quitt);

        }
        window.display();
    }
    return 0;
}
