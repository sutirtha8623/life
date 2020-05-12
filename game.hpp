#ifndef _GAME_H
#define _GAME_H

#include"cell.hpp"
#include"grid.hpp"

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const int BLOCK_SIZE = 10;


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
    
    life::Grid cells;
    
};
#endif
