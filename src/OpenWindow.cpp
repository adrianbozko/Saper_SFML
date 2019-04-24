#include "OpenWindow.h"
#include "BoardDraw.h"
#include "MinesweeperBoard.h"

OpenWindow::OpenWindow()
{

}

void OpenWindow::create_openWindow(int &board_width, int &board_height, GameMode &state)
{
    sf::Font font_text;
    font_text.loadFromFile("image/pixelated.ttf");

    sf::Text title;
    title.setString("SAPER");
    title.setFont(font_text);
    title.setCharacterSize(100);
    title.setPosition(125.f,3.f);
    title.setColor(sf::Color::Black);
//----------------------------------------------------------------------
    sf::RectangleShape size_options(sf::Vector2f(400.f, 80.f));
    size_options.setPosition(50,120);
    size_options.setFillColor(sf::Color::White);

    sf::RectangleShape size_options_1(sf::Vector2f(120.f, 60.f));
    size_options_1.setPosition(60,130);
    size_options_1.setFillColor(sf::Color::Black);
    sf::Text option1;
    option1.setFont(font_text);
    option1.setString("10x10");
    option1.setPosition(85,137);
    option1.setCharacterSize(30);

    sf::RectangleShape size_options_2(sf::Vector2f(120.f, 60.f));
    size_options_2.setPosition(190,130);
    size_options_2.setFillColor(sf::Color::Black);
    sf::Text option2;
    option2.setFont(font_text);
    option2.setString("15x15");
    option2.setPosition(215,137);
    option2.setCharacterSize(30);

    sf::RectangleShape size_options_3(sf::Vector2f(120.f, 60.f));
    size_options_3.setPosition(320,130);
    size_options_3.setFillColor(sf::Color::Black);
    sf::Text option3;
    option3.setFont(font_text);
    option3.setString("20x20");
    option3.setPosition(345,137);
    option3.setCharacterSize(30);

//-----------------------------------------------------------------------
    sf::RectangleShape level_options(sf::Vector2f(400.f, 80.f));
    level_options.setPosition(50,210);
    level_options.setFillColor(sf::Color::White);

    sf::RectangleShape level_options_1(sf::Vector2f(120.f, 60.f));
    level_options_1.setPosition(60,220);
    level_options_1.setFillColor(sf::Color::Black);
    sf::Text easy;
    easy.setFont(font_text);
    easy.setString("EASY");
    easy.setPosition(90,227);
    easy.setCharacterSize(30);

    sf::RectangleShape level_options_2(sf::Vector2f(120.f, 60.f));
    level_options_2.setPosition(190,220);
    level_options_2.setFillColor(sf::Color::Black);
    sf::Text medium;
    medium.setFont(font_text);
    medium.setString("MEDIUM");
    medium.setPosition(199,227);
    medium.setCharacterSize(30);

    sf::RectangleShape level_options_3(sf::Vector2f(120.f, 60.f));
    level_options_3.setPosition(320,220);
    level_options_3.setFillColor(sf::Color::Black);
    sf::Text hard;
    hard.setFont(font_text);
    hard.setString("HARD");
    hard.setPosition(355,227);
    hard.setCharacterSize(30);
//---------------------------------------------------------------------------------

    sf::RectangleShape start_box(sf::Vector2f(200.f, 80.f));
    start_box.setPosition(150,310);
    start_box.setFillColor(sf::Color::White);
    sf::Text start_text;
    start_text.setFont(font_text);
    start_text.setString("START");
    start_text.setPosition(180,307);
    start_text.setCharacterSize(60);
    start_text.setFillColor(sf::Color::Black);

//------------------------------------------------------------------------------------

    sf::RectangleShape quit_box(sf::Vector2f(200.f, 80.f));
    quit_box.setPosition(150,410);
    quit_box.setFillColor(sf::Color::White);
    sf::Text quit_text;
    quit_text.setFont(font_text);
    quit_text.setString("QUIT");
    quit_text.setPosition(184,415);
    quit_text.setCharacterSize(60);
    quit_text.setFillColor(sf::Color::Black);


    sf::RenderWindow window_open(sf::VideoMode(500, 510), "SAPER SETTINGS");
    while (window_open.isOpen())
    {
        sf::Event event;
        while (window_open.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window_open.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {

            if (event.mouseButton.button == sf::Mouse::Left)
            {
                if (event.mouseButton.x > 60 and event.mouseButton.x < 180 and event.mouseButton.y > 130 and event.mouseButton.y < 190)
                {
                    board_width=10;
                    board_height=10;
                    size_options_1.setFillColor(sf::Color::Green);
                    size_options_2.setFillColor(sf::Color::Black);
                    size_options_3.setFillColor(sf::Color::Black);
                }
                if (event.mouseButton.x > 190 and event.mouseButton.x < 310 and event.mouseButton.y > 130 and event.mouseButton.y < 190)
                {
                    board_width=15;
                    board_height=15;
                    size_options_2.setFillColor(sf::Color::Green);
                    size_options_1.setFillColor(sf::Color::Black);
                    size_options_3.setFillColor(sf::Color::Black);
                }
                if (event.mouseButton.x > 320 and event.mouseButton.x < 440 and event.mouseButton.y > 130 and event.mouseButton.y < 190)
                {
                    board_width=20;
                    board_height=20;
                    size_options_3.setFillColor(sf::Color::Green);
                    size_options_1.setFillColor(sf::Color::Black);
                    size_options_2.setFillColor(sf::Color::Black);
                }

//-------------------------------------------------------------------------------------------------------------------------------------
                if (event.mouseButton.x > 60 and event.mouseButton.x < 180 and event.mouseButton.y > 220 and event.mouseButton.y < 280)
                {
                    state=EASY;
                    level_options_1.setFillColor(sf::Color::Green);
                    level_options_2.setFillColor(sf::Color::Black);
                    level_options_3.setFillColor(sf::Color::Black);
                }
                if (event.mouseButton.x > 190 and event.mouseButton.x < 310 and event.mouseButton.y > 220 and event.mouseButton.y < 280)
                {
                    state=NORMAL;
                    level_options_2.setFillColor(sf::Color::Green);
                    level_options_1.setFillColor(sf::Color::Black);
                    level_options_3.setFillColor(sf::Color::Black);
                }
                if (event.mouseButton.x > 320 and event.mouseButton.x < 440 and event.mouseButton.y > 220 and event.mouseButton.y < 280)
                {
                    state=HARD;
                    level_options_3.setFillColor(sf::Color::Green);
                    level_options_1.setFillColor(sf::Color::Black);
                    level_options_2.setFillColor(sf::Color::Black);
                }
//------------------------------------------------------------------------------------------------------------
                if (event.mouseButton.x > 150 and event.mouseButton.x < 350 and event.mouseButton.y > 310 and event.mouseButton.y < 390)
                {
                    window_open.close();
                }

                if (event.mouseButton.x > 150 and event.mouseButton.x < 350 and event.mouseButton.y > 410 and event.mouseButton.y < 490)
                {
                    return;
                }
            }
        }

        }
        window_open.clear(sf::Color(189,189,189));
        window_open.draw(title);
        window_open.draw(size_options);
        window_open.draw(size_options_1);
        window_open.draw(option1);
        window_open.draw(size_options_2);
        window_open.draw(option2);
        window_open.draw(size_options_3);
        window_open.draw(option3);
        window_open.draw(level_options);
        window_open.draw(level_options_1);
        window_open.draw(easy);
        window_open.draw(level_options_2);
        window_open.draw(medium);
        window_open.draw(level_options_3);
        window_open.draw(hard);
        window_open.draw(start_box);
        window_open.draw(start_text);
        window_open.draw(quit_box);
        window_open.draw(quit_text);

        window_open.display();
    }
    }
