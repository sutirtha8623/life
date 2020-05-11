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
        int rows, columns;
        cell_grid grid;
    public:
        Grid();
        Grid(int, int);
        ~Grid();
        
        void init();
        
        void render(sf::RenderWindow& window, int);
    };
}

#endif
