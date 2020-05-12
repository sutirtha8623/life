#include"cell.hpp"

namespace life
{
    Cell::Cell()
    {
        position = sf::Vector2f(0, 0);
        block_size = 10;
        is_alive = false;
        
        cell_shape.setFillColor(sf::Color::Black);
        cell_shape.setSize(sf::Vector2f(block_size, block_size));
        cell_shape.setOutlineThickness(2);
        cell_shape.setOutlineColor(sf::Color::Black);
    }
    
    Cell::~Cell()
    {
    }
    
    //positon and grid_position handling
    void Cell::set_position(sf::Vector2f pos)
    {
         cell_shape.setPosition(pos);
    }
    
    sf::Vector2f Cell::get_position()
    {
        return position;
    }
    
    sf::Vector2i Cell::get_grid_position()
    {
        return grid_position;
    }
    
    void Cell::set_grid_position(int x, int y)
    {
        grid_position = sf::Vector2i(x, y);
    }
    
    //killing and generating
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
    
    void Cell::set_alive_state(bool state)
    {
        is_alive = state;
    }        
    
    //rendering
    void Cell::render(sf::RenderWindow& window)
    {
        window.draw(cell_shape);
    }
    




}
