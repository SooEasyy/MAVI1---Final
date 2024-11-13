#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Player {
public:
    Player(float startX, float startY);
    void handleInput();
    void update(float deltaTime);
    void render(RenderWindow& window);
    Vector2f getPosition() const;
    Vector2f getSize() const;
    const Sprite& getPlayerSprite() const;
    void setPosition(float x, float y);

    // Métodos para activar MRUA
    void activateMRUA();
    bool isMRUAActive() const;

private:
    float moveSpeed;
    float acceleration = 50.0f; // Aceleración en píxeles por segundo²
    float currentSpeed; // Velocidad actual
    bool mruaActive = false; // Bandera para activar MRUA

    Texture playerTexture;
    Sprite playerSprite;
    Vector2f velocity;
};

#endif // PLAYER_H
