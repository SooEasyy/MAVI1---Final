#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Maze.h"
#include "Timer.h"
#include "Star.h"
#include "Scene.h"
#include "iostream"
using namespace sf;
using namespace std;

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(Time deltaTime);
    void render();

    RenderWindow window;
    Player player;
    Maze maze;
    Timer timer;
    Font font;
    bool isGameOver;
    bool hasWon;

    Star star1;
    Star star2;
    Star star3;
    Star star4;
    bool allStarsCollected() const;

    Scene startScene;
    bool inStartScreen;
};

#endif // GAME_H
