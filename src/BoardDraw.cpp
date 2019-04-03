#include "BoardDraw.h"
#include <SFML/Graphics.hpp>

BoardDraw::BoardDraw(int w_board, int h_board, int lenght) {
    board_width=w_board;
    board_height=h_board;
    field_lenght=lenght;
}


void BoardDraw::create_line(sf::RenderWindow &window) {
  //  board_view.clear();
   // board_view.setPrimitiveType(sf::Lines);
  //  board_view.append(sf::Vertex(sf::Vector2f(0,0)));
  //  board_view.append(sf::Vertex(sf::Vector2f(100,200)));
  //  window.draw(board_view);



    sf::VertexArray kreska(sf::Lines,2);
    kreska[0].position =sf::Vector2f(10,10);
    kreska[1].position = sf::Vector2f(50,50);
    window.draw(kreska);

}

void BoardDraw::board_draw(sf::RenderWindow &window) {
    window.draw(board_view);

}

