#include"grid.hpp"

namespace life
{
    int random_generator(int min, int max)
    {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(min, max);
        
        return distribution(generator);
    }
    
    Grid::Grid()
    {
        Cell cell;
        cell_grid grid;
        grid.resize(80, std::vector<Cell>(60, cell));        
    }
    
    Grid::Grid(int r, int c)
    {
        rows = r;
        columns = c;
        Cell cell;
        grid.resize(c, std::vector<Cell>(60, cell));
    }
    
    Grid::~Grid()
    {
        
    }
    
    void Grid::init()
    {
        for(int i=0; i < columns; ++i)
        {
            for(int j=0; j < rows; ++j)
            {
                auto random_number =  random_generator(7, 705975497);
                grid[i][j].set_alive_state(random_number%2);
            }
        }
    }
    
    void Grid::render(sf::RenderWindow& window, int block_size)
    {
        for(int i=0; i < columns; ++i)
        {
            for(int j=0; j < rows; ++j)
            {
                if(grid[i][j].get_living_state() == false)
                {
                    grid[i][j].kill();
                    grid[i][j].set_position(sf::Vector2f(i*block_size, j*block_size));
                    grid[i][j].render(window);
                }
                else if(grid[i][j].get_living_state() == true)
                {
                    grid[i][j].generate();
                    grid[i][j].set_position(sf::Vector2f(i*block_size, j*block_size));
                    grid[i][j].render(window);
                }            
            }
        }
    }
}
