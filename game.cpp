#include"game.hpp"


Game::Game()
: window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "trial", sf::Style::Default)
, cells(SCREEN_HEIGHT/BLOCK_SIZE, SCREEN_WIDTH/BLOCK_SIZE)
{
    window.setVerticalSyncEnabled(true);
}

void Game::run()
{
    cells.init();
    while(window.isOpen())
    {
        process_events();
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
}

void Game::render()
{
    window.clear(sf::Color::Black);
    cells.render(window, BLOCK_SIZE);
    window.display();
}
