#include"game.hpp"


Game::Game()
: window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "trial", /*sf::Style::Titlebar | sf::Style::Close*/ sf::Style::Default)
, cells(SCREEN_WIDTH/BLOCK_SIZE, SCREEN_HEIGHT/BLOCK_SIZE)
{
    clock.restart();
    cells.init();
    
    window.setVerticalSyncEnabled(true);
}

void Game::run()
{
    while(window.isOpen())
    {
        process_events();
        update();
        render();
    }
}

void Game::process_events()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        
        if(event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void Game::update()
{
    float timestep = 300;
    if(clock.getElapsedTime().asMilliseconds() >= timestep)
    {
        cells.update();
        clock.restart();
    }
}

void Game::render()
{
    window.clear(sf::Color::Black);
    cells.render(window, BLOCK_SIZE);
    window.display();
}
