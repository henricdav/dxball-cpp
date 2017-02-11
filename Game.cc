
#include "Game.h"
#include "globaldefines.h"

Game::Game()
    : window(sf::VideoMode(WIDTH,HEIGHT), "DxBall")
{
    window.setFramerateLimit(50);
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
        ball.update(paddle);
        movePaddle();





        window.clear(sf::Color::Black);
        showShapes();


        window.display();
    }
}

void Game::showShapes()
{
    window.draw(paddle.getShape());
    window.draw(ball.getShape());
}

void Game::movePaddle()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        paddle.move(true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        paddle.move(false);
    }
}
