#ifndef _CELL_H
#define _CELL_H

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

namespace life
{
    class Cell
    {
        sf::Vector2f position;
        
        sf::Vector2i grid_position;
        
        int block_size;
        bool is_alive;
        sf::RectangleShape cell_shape;
    public:
        Cell();
        ~Cell();
        
        //position handlers
        void set_position(sf::Vector2f);
        sf::Vector2f get_position();
        
        void set_grid_position(int x, int y);
        sf::Vector2i get_grid_position();
        
        //life state handlers
        bool get_living_state();
        void kill();
        void generate();
        void set_alive_state(bool);
        
        //render
        void render(sf::RenderWindow& window);
    };
}

#endif
