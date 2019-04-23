#include "Single_Field.h"
#include "MinesweeperBoard.h"
#include "BoardDraw.h"

SingleField::SingleField(int x_0, int y_0, int fieldLenght)
{

}



void SingleField::VsetMine(sf::RenderWindow &window, int idx_x, int idx_y)
{
    pole.setPointCount(4);
    pole.setFillColor(sf::Color(200,200,200));
    pole.setPoint(0, sf::Vector2f(x0+idx_x*field_lenght,y0+idx_y*field_lenght));
    pole.setPoint(1, sf::Vector2f(x0+field_lenght+idx_x*field_lenght,y0+idx_y*field_lenght));
    pole.setPoint(2, sf::Vector2f(x0+field_lenght+idx_x*field_lenght,y0+field_lenght+idx_y*field_lenght));
    pole.setPoint(3, sf::Vector2f(x0+idx_x*field_lenght,y0+field_lenght+idx_y*field_lenght));
}
