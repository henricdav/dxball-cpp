
#include "Game.h"

Game::Game()
    : window(sf::VideoMode(1024,768), "DxBall")
{
    window.setFramerateLimit(60);
}

void Game::run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                    break;
                }
                default: break;
            }
        }

        window.clear(sf::Color::Black);
        window.display();
    }
}
