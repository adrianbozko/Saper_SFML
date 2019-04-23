#ifndef SINGLEFIELD_H
#define SINGLEFIELD_H

#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"
#include "BoardDraw.h"

class SingleField
{
    public:
        SingleField(int x0, int y0, int field_lenght);
        void selectField(sf::RenderWindow &window, int idx_x, int idx_y, char type);
        void VsetMine(sf::RenderWindow &window, int idx_x, int idx_y);
    private:
        int x0;
        int y0;
        int field_lenght;
        sf::ConvexShape pole;
        void VsetFlag(sf::RenderWindow &window, int idx_x, int idx_y);
        void VsetReveal(sf::RenderWindow &window, int idx_x, int idx_y);

};

#endif // SINGLEFIELD_H
