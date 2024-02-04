#include "Grid.h"


Grid::Grid() : Xplay(true)
{
    for (int i = 0; i < gridSize; ++i)
    {
        for (int j = 0; j < gridSize; ++j)
        {
            grid[i][j] = Case();
        }
    }
}

void Grid::handleEvent(sf::Event event) 
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
    {
        int x = (event.mouseButton.x / 100);
        int y = ((event.mouseButton.y - 50) / 100);

        if (grid[x][y].getValue() == ' ' && !checkWin('X') && !checkWin('O'))
        {
            if (Xplay) {
                grid[x][y].setValue('X');
            }
            else {
                grid[x][y].setValue('O');
            }

            Xplay = !Xplay;
        }
    }
}

void Grid::draw(sf::RenderWindow& window)
{
    sf::Font font;
    font.loadFromFile("font/arial.ttf");

    whoPlay.setFont(font);
    whoPlay.setCharacterSize(20);
    whoPlay.setString(Xplay ? "Tour de X" : "Tour de O");
    whoPlay.setPosition(110, 10);

    window.draw(whoPlay);

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            sf::RectangleShape cellRect(sf::Vector2f(100.0f, 100.0f));
            cellRect.setPosition(i * 100, j * 100 + 50); // Ajoutez un d�calage vertical pour �viter la superposition
            cellRect.setOutlineColor(sf::Color::Black);
            cellRect.setOutlineThickness(2.0f);

            window.draw(cellRect);
            grid[i][j].draw(window, i, j);
        }
    }
}

bool Grid::checkWin(char player) 
{
    // V�rification des lignes
    for (int i = 0; i < gridSize; ++i)
    {
        if (grid[i][0].getValue() == player && grid[i][1].getValue() == player && grid[i][2].getValue() == player)
        {
            return true;
        }
    }

    // V�rification des colonnes
    for (int j = 0; j < gridSize; ++j)
    {
        if (grid[0][j].getValue() == player && grid[1][j].getValue() == player && grid[2][j].getValue() == player)
        {
            return true;
        }
    }

    // V�rification des diagonales
    if (grid[0][0].getValue() == player && grid[1][1].getValue() == player && grid[2][2].getValue() == player)
    {
        return true;
    }

    if (grid[0][2].getValue() == player && grid[1][1].getValue() == player && grid[2][0].getValue() == player)
    {
        return true;
    }

    return false;
}

bool Grid::isFull() 
{
    for (int i = 0; i < gridSize; ++i)
    {
        for (int j = 0; j < gridSize; ++j)
        {
            if (grid[i][j].getValue() == ' ')
            {
                return false;
            }
        }
    }
    return true;
}