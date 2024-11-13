#ifndef MAZE_H
#define MAZE_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Maze {
public:
    Maze();
    void render(RenderWindow& window);
    bool isWalkable(int x, int y) const;
    Vector2f getStartPosition() const;
    Vector2f getEndPosition() const;
    Sprite & getPrincessSprite();

private:
    vector<vector<int>> maze;
    float cellSize;
    RectangleShape wallShape;
    RectangleShape pathShape;
    Texture princessTexture;
    Sprite princessSprite;
    Vector2f startPosition;
    Vector2f endPosition;
};

#endif // MAZE_H