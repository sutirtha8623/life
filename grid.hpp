#ifndef _GRID_H
#define _GRID_H

#include"cell.hpp"
#include<vector>
#include<random>

typedef std::vector<std::vector<life::Cell>> cell_grid;

namespace life
{
    class Grid
    {
        cell_grid grid;
    public:
        Grid();
        ~Grid();
        
        cell_grid init();
        
        void render(sf::RenderWindow& window, int);
    };
}

#endif
