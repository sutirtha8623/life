#ifndef _GRID_H
#define _GRID_H

#include<SFML/Window.hpp>
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
        cell_grid grid_copy;
        
    public:
        
        Grid();
        Grid(int, int);
        ~Grid();
        
        void init();
        
        sf::Vector2i toroidal_index(int, int);
        int get_living_neighbours(Cell);
        
        void update();
        
        void render(sf::RenderWindow& window, int);
    };
}

#endif
