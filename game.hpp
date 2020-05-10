#ifndef _GAME_H
#define _GAME_H

#include"cell.hpp"
#include<vector>

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
    
    std::vector<life::Cell> cells;
    
};
#endif
