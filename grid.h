#include "Case.h"
const int gridSize = 3;

class Grid {
public:
    Grid();
    void handleEvent(sf::Event event);
    void draw(sf::RenderWindow& window);
    bool checkWin(char player);
    bool isFull();
    sf::Text whoPlay;

private:
    Case grid[gridSize][gridSize];
    bool Xplay;
};

