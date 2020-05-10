#include"game.hpp"
#include<iostream>

Game::Game()
: window(sf::VideoMode(800, 600), "trial", sf::Style::Default)
{
    std::vector<life::Cell> cells;
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
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            life::Cell cell;
            auto pos = sf::Vector2f(sf::Mouse::getPosition(window));
            cell.set_position(pos);
            cell.generate();
            cells.push_back(cell);
        }
        
        else if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
        {
            life::Cell cell;
            auto pos = sf::Vector2f(sf::Mouse::getPosition(window));
            cell.set_position(pos);
            cell.kill();
            cells.push_back(cell);
        }
        
        else if(event.type == sf::Event::Closed)
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
    for(auto& c : cells)
    {
        c.render(window);
    }
    window.display();
}






