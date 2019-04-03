#include <iostream>
#include <SFML/Graphics.hpp>
#include "BoardDraw.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    BoardDraw bord(600,600,100);
    bord.create_line(window);





    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...

        // end the current frame
        window.display();
    }

    return 0;
}
