#ifndef _CELL_H
#define _CELL_H

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

namespace life
{
    class Cell
    {
        sf::Vector2f position;
        int block_size;
        bool is_alive;
        sf::RectangleShape cell_shape;
    public:
        Cell();
        ~Cell();
        
        void set_position(sf::Vector2f pos);
        sf::Vector2f get_position();
        
        bool get_living_state();
        void kill();
        void generate();
        
        void toggle_life();
        
//         void set_fillcolour(sf::Color);
        void render(sf::RenderWindow& window);
    };
}

#endif
