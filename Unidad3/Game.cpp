#include "Game.h"
#include <iostream>
using namespace sf;

Game::Game()
    : window(VideoMode(800, 600), "Maze Game"),
    player(maze.getStartPosition().x, maze.getStartPosition().y), 
    isGameOver(false),
    hasWon(false),
    inStartScreen(true),
    star1(6 * 40, 5 * 40),
    star2(15 * 40, 1 * 40),
    star3(12 * 40, 9 * 40),
    star4(1 * 40, 11 * 40)
{
    if (!font.loadFromFile("assets/arial.ttf")) {
        cerr << "Error al cargar la fuente" << endl;
    }

    // Ajusta la posición del jugador después de crearlo
    float nuevaPosX = maze.getStartPosition().x;
    float nuevaPosY = maze.getStartPosition().y;
    player.setPosition(nuevaPosX, nuevaPosY);
}

void Game::run() {
    Clock clock;

    while (window.isOpen()) {
        Time deltaTime = clock.restart();
        processEvents();

        if (!inStartScreen && !isGameOver) {
            update(deltaTime);
        }

        render();
    }
}

void Game::processEvents() {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }

        if (inStartScreen) {
            if (startScene.handleEvent(event)) {
                inStartScreen = false;  // Salimos de la pantalla de inicio
                timer.start();          // Iniciar el temporizador
            }
        }
        else {
            player.handleInput();
        }
    }
}


void Game::update(Time deltaTime) {
    player.update(deltaTime.asSeconds());
    timer.update(deltaTime.asSeconds());

    if (timer.isTimeUp() && !hasWon) {
        isGameOver = true;
    }

    Vector2f playerPos = player.getPosition();
    Vector2f playerSize = player.getSize();

    if (!maze.isWalkable((playerPos.x + playerSize.x / 2) / 40, (playerPos.y + playerSize.y / 2) / 40)) {
        player.update(-deltaTime.asSeconds());
    }

    if (playerPos.x / 40 == maze.getEndPosition().x / 40 &&
        playerPos.y / 40 == maze.getEndPosition().y / 40 &&
        allStarsCollected())
    {
        isGameOver = true; // Puede mostrar mensaje de victoria
    }

    // Verificar recolección de estrellas y activar MRUA en la primera recolección
    if (!star1.isCollected() && player.getPlayerSprite().getGlobalBounds().intersects(star1.getSprite().getGlobalBounds())) {
        star1.collect();
        if (!player.isMRUAActive()) {
            player.activateMRUA(); // Activar MRUA
        }
    }

    // Verificar el resto de estrellas
    if (!star2.isCollected() && player.getPlayerSprite().getGlobalBounds().intersects(star2.getSprite().getGlobalBounds())) {
        star2.collect();
    }
    if (!star3.isCollected() && player.getPlayerSprite().getGlobalBounds().intersects(star3.getSprite().getGlobalBounds())) {
        star3.collect();
    }
    if (!star4.isCollected() && player.getPlayerSprite().getGlobalBounds().intersects(star4.getSprite().getGlobalBounds())) {
        star4.collect();
    }

    // Verificar si el jugador ha recolectado todas las estrellas y está en la posición de la princesa
    if (allStarsCollected() && player.getPlayerSprite().getGlobalBounds().intersects(maze.getPrincessSprite().getGlobalBounds())) {
        hasWon = true;  // Marcamos como victoria
    }

}

bool Game::allStarsCollected() const {
    return star1.isCollected() && star2.isCollected() && star3.isCollected() && star4.isCollected();
}

void Game::render() {
    window.clear();


    if (inStartScreen) {
        startScene.render(window);
    }else if (isGameOver && !hasWon) {
        Text gameOverText;
        gameOverText.setFont(font);
        gameOverText.setString("Game Over");
        gameOverText.setCharacterSize(50);
        gameOverText.setFillColor(Color::Red);
        gameOverText.setPosition(250, 250);
        window.draw(gameOverText);
    }
    else if (hasWon) {
        Text winText;
        winText.setFont(font);
        winText.setString("Has rescatado a la Princesa con éxito");
        winText.setCharacterSize(40);
        winText.setFillColor(Color::Green);
        winText.setPosition(100, 250);
        window.draw(winText);
    }
    else {
        maze.render(window);
        timer.render(window);
        player.render(window);

        // Renderizar las estrellas
        star1.render(window);
        star2.render(window);
        star3.render(window);
        star4.render(window);

        window.draw(maze.getPrincessSprite());
    }

    window.display();
}