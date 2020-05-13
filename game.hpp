#ifndef _GAME_H
#define _GAME_H

#include"cell.hpp"
#include"grid.hpp"

const int SCREEN_WIDTH = 1370;
const int SCREEN_HEIGHT = 700;
const int BLOCK_SIZE = 5;


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
    sf::Clock clock;
    
    life::Grid cells;
    
};
#endif
