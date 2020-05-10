#include"cell.hpp"

namespace life
{
    Cell::Cell()
    {
        position = sf::Vector2f(10.f, 10.f);
        block_size = 10;
        is_alive = false;
        cell_shape.setFillColor(sf::Color::Black);
        cell_shape.setSize(sf::Vector2f(block_size-1, block_size-1));
    }
    
    Cell::~Cell()
    {
    }

    
    sf::Vector2f Cell::get_position()
    {
        return position;
    }
    
    bool Cell::get_living_state()
    {
        return is_alive;
    }
    
    void Cell::kill()
    {
        is_alive = false;
        cell_shape.setFillColor(sf::Color::Black);
    }
    
    void Cell::generate()
    {
        is_alive = true;
        cell_shape.setFillColor(sf::Color::White);
    }
    
    void Cell::set_position(sf::Vector2f pos)
    {
        cell_shape.setPosition(pos);
    }
    
    void Cell::render(sf::RenderWindow& window)
    {
        window.draw(cell_shape);
    }
    
//     void Cell::set_fillcolour(sf::Color color)
//     {
//         cell_shape.setFillColor(color);
//     }


    void Cell::toggle_life()
    {
        if(is_alive == true)
        {
            kill();
        }
        else
        {
            generate();
        }
    }


}
