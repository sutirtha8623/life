#include"grid.hpp"

namespace life
{
    Grid::Grid()
    {
        Cell cell;
        cell_grid grid;
        grid.resize(60, std::vector<Cell>(60, cell));        
    }
    
    Grid::Grid(int r, int c)
    {
        rows = r;
        columns = c;
        Cell cell;
        grid.resize(r, std::vector<Cell>(c, cell));
    }
    
    Grid::~Grid()
    {
        
    }
    
    //writing a function for random() would call the below two constructors each time the loop runs and it increases execution time
    static std::random_device rd;
    static std::mt19937 generator(rd());
    void Grid::init()
    {
        for(int i=0; i < rows; ++i)
        {
            for(int j=0; j < columns; ++j)
            {
                std::uniform_int_distribution<int> distribution(0, 99);
                grid[i][j].set_alive_state((distribution(generator))%2);
                grid[i][j].set_grid_position(i, j);
            }
        }
    }
    
    /*in game of life, the grid is infinite. So, to handle the edge cells, the first cell of a row/column is considered to be adjacent
    to its last. Just like a toroid. */
    
    sf::Vector2i Grid::toroidal_index(int x, int y)
    {
        return sf::Vector2i(x % rows, y % columns);
    }
    
    int Grid::get_living_neighbours(Cell cell)
    {
        int neighbours = 0;
        
        //top cell
        sf::Vector2i toroidal_top_index = toroidal_index(cell.get_grid_position().x-1, cell.get_grid_position().y);
        Cell top = grid [toroidal_top_index.x] [toroidal_top_index.y];
        //bottom cell
        sf::Vector2i toroidal_bottom_index = toroidal_index(cell.get_grid_position().x+1, cell.get_grid_position().y);
        Cell bottom = grid [toroidal_bottom_index.x] [toroidal_bottom_index.y];
        //left cell
        sf::Vector2i toroidal_left_index = toroidal_index(cell.get_grid_position().x, cell.get_grid_position().y-1);
        Cell left = grid [toroidal_left_index.x] [toroidal_left_index.y];
        //right cell
        sf::Vector2i toroidal_right_index = toroidal_index(cell.get_grid_position().x, cell.get_grid_position().y+1);
        Cell right = grid [toroidal_right_index.x] [toroidal_right_index.y];
        //top-left
        sf::Vector2i toroidal_tl_index = toroidal_index(cell.get_grid_position().x-1, cell.get_grid_position().y-1);
        Cell tl = grid [toroidal_tl_index.x] [toroidal_tl_index.y];
        //top-right
        sf::Vector2i toroidal_tr_index = toroidal_index(cell.get_grid_position().x-1, cell.get_grid_position().y+1);
        Cell tr = grid [toroidal_tr_index.x] [toroidal_tr_index.y];
        //bottom-left
        sf::Vector2i toroidal_bl_index = toroidal_index(cell.get_grid_position().x+1, cell.get_grid_position().y-1);
        Cell bl = grid [toroidal_bl_index.x] [toroidal_bl_index.y];
        //bottom-right
        sf::Vector2i toroidal_br_index = toroidal_index(cell.get_grid_position().x+1, cell.get_grid_position().y+1);
        Cell br = grid [toroidal_br_index.x] [toroidal_br_index.y];
        
        if(top.get_living_state() == true) ++neighbours;
        if(bottom.get_living_state() == true) ++neighbours;
        if(left.get_living_state() == true) ++neighbours;
        if(right.get_living_state() == true) ++neighbours;
        if(tl.get_living_state() == true) ++neighbours;
        if(tr.get_living_state() == true) ++neighbours;
        if(bl.get_living_state() == true) ++neighbours;
        if(br.get_living_state() == true) ++neighbours;
        
        return neighbours;
    }
    
    void Grid::update()
    {
        Cell cell;
        cell_grid grid_copy;
        grid_copy.resize(rows, std::vector<Cell>(columns, cell));
        
        for(int i=0; i < rows; ++i)
        {
            for(int j=0; j < columns; ++j)
            {
                if(grid[i][j].get_living_state() == true && get_living_neighbours(grid[i][j]) < 2)
                {
                    grid_copy[i][j].kill();
                }
                else if(grid[i][j].get_living_state() == true && get_living_neighbours(grid[i][j]) > 3)
                {
                    grid_copy[i][j].kill();
                }
                else if(grid[i][j].get_living_state() == false && get_living_neighbours(grid[i][j]) == 3)
                {
                    grid_copy[i][j].generate();
                }
                else
                {
                    grid_copy[i][j].generate();
                }
            }
        }
        
        //swap the grids
        grid.swap(grid_copy);
        
    }
    
    void Grid::render(sf::RenderWindow& window, int block_size)
    {
        for(int i=0; i < rows; ++i)
        {
            for(int j=0; j < columns; ++j)
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
