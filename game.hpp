#ifndef _GAME_H
#define _GAME_H

#include"cell.hpp"
#include"grid.hpp"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int BLOCK_SIZE = 10;

typedef std::vector<std::vector<life::Cell>> cell_grid;

class Game{
public:
    Game();
    void run();
    
    void process_events();
    void update();
    void render();
    
    void handle_player_input();
    
    
private:
    sf::RenderWindow window;
    
    cell_grid cells;
    
};
#endif
