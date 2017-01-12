
#include <SFML/graphics.hpp>
#include <string>

class Game {
public:
    Game();
    ~Game() {};



    void run();

private:
    sf::RenderWindow window{};


};
