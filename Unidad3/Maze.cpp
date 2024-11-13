#include "Maze.h"
using namespace sf;

Maze::Maze() {
    // Representación del laberinto: 1 = pared, 0 = camino
    maze = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
        {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    cellSize = 40.0f; // Tamaño de cada celda del laberinto

    wallShape.setSize(Vector2f(cellSize, cellSize));
    wallShape.setFillColor(Color(36, 119, 5));

    pathShape.setSize(Vector2f(cellSize, cellSize));
    pathShape.setFillColor(Color(147, 134, 85));

    // Posición de inicio y fin
    startPosition = Vector2f(1 * cellSize, 1 * cellSize); 
    endPosition = Vector2f(15 * cellSize, 13 * cellSize); 

    if (!princessTexture.loadFromFile("assets/princess.png")) {
        exit(EXIT_FAILURE);
    }
    princessSprite.setTexture(princessTexture);
    princessSprite.setScale(cellSize / princessSprite.getLocalBounds().width, cellSize / princessSprite.getLocalBounds().height);
    princessSprite.setPosition(endPosition);
}

void Maze::render(RenderWindow& window) {
    for (size_t y = 0; y < maze.size(); ++y) {
        for (size_t x = 0; x < maze[y].size(); ++x) {
            if (maze[y][x] == 1) {
                wallShape.setPosition(x * cellSize, y * cellSize);
                window.draw(wallShape);
            }
            else {
                pathShape.setPosition(x * cellSize, y * cellSize);
                window.draw(pathShape);
            }
        }
    }
    window.draw(princessSprite);
}

bool Maze::isWalkable(int x, int y) const {
    if (x < 0 || y < 0 || x >= maze[0].size() || y >= maze.size()) {
        return false;
    }
    return maze[y][x] == 0;
}

sf::Vector2f Maze::getStartPosition() const {
    return startPosition;
}

sf::Vector2f Maze::getEndPosition() const {
    return endPosition;
}

sf::Sprite& Maze::getPrincessSprite() {
    return princessSprite;
}