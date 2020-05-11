#include"game.hpp"


Game::Game()
: window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "trial", sf::Style::Default)
{
    life::Cell cell;
    cells.resize(80, std::vector<life::Cell>(60, cell));
    window.setVerticalSyncEnabled(true);
}

int random_generator(int min, int max){
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(min, max);
        
    return distribution(generator);
}

void Game::run()
{
    update();
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
    for(int i=0; i < (SCREEN_WIDTH/BLOCK_SIZE); ++i)
    {
        for(int j=0; j < (SCREEN_HEIGHT/BLOCK_SIZE); ++j)
        {
            auto random_number =  random_generator(7, 705975497);
            cells[i][j].set_alive_state(random_number%2);
        }
    }
}

void Game::render()
{
    window.clear(sf::Color::Black);
    for(int i=0; i < (SCREEN_WIDTH/BLOCK_SIZE); ++i)
    {
        for(int j=0; j < (SCREEN_HEIGHT/BLOCK_SIZE); ++j)
        {
            if(cells[i][j].get_living_state() == false)
            {
                cells[i][j].kill();
                cells[i][j].set_position(sf::Vector2f(i*BLOCK_SIZE, j*BLOCK_SIZE));
                cells[i][j].render(window);
            }
            if(cells[i][j].get_living_state() == true)
            {
                cells[i][j].generate();
                cells[i][j].set_position(sf::Vector2f(i*BLOCK_SIZE, j*BLOCK_SIZE));
                cells[i][j].render(window);
            }            
        }
    }
    window.display();
}
