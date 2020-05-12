#include"game.hpp"


Game::Game()
: window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "trial", sf::Style::Titlebar | sf::Style::Close)
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

// void Game::handle_player_input()
// {
//     if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
//     {
//         //std::cout<<std::to_string(sf::Mouse::getPosition().x)<<", "<<std::to_string(sf::Mouse::getPosition().y)<<"\n";
//         cell.set_position(sf::Mouse::getPosition(window));
//         cell.set_cells();
//     }
// }

void Game::process_events()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
//         if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//         {
//             
//         }
        
//         else if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
//         {
//             
//         }
        
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
