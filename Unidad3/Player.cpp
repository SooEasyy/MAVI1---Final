#include "Player.h"
using namespace sf;
using namespace std;

Player::Player(float startX, float startY) {
    if (!playerTexture.loadFromFile("assets/player.png")) {
        cerr << "Error al cargar la textura de jugador: assets/player.png" << endl;
        exit(EXIT_FAILURE);
    }

    // Ajustar el sprite a la textura correcta
    playerSprite.setTexture(playerTexture);

    // Configurar el tamaño del sprite
    playerSprite.setScale(40.0f / playerSprite.getLocalBounds().width,
                          40.0f / playerSprite.getLocalBounds().height);

    // Posicionar el sprite en las coordenadas iniciales
    playerSprite.setPosition(startX, startY);

    // Inicializar la velocidad de movimiento
    moveSpeed = 200.0f; // en píxeles por segundo
}

void Player::handleInput() {
    velocity = Vector2f(0, 0);
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        velocity.y -= moveSpeed;
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        velocity.y += moveSpeed;
    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        velocity.x -= moveSpeed;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        velocity.x += moveSpeed;
    }
}

void Player::update(float deltaTime) {
    if (mruaActive) {
        currentSpeed += acceleration * deltaTime; // Incrementa la velocidad usando MRUA
    }
    playerSprite.move(velocity * deltaTime);
}

void Player::render(RenderWindow& window) {
    window.draw(playerSprite);
}

sf::Vector2f Player::getPosition() const {
    return playerSprite.getPosition();
}

sf::Vector2f Player::getSize() const {
    return sf::Vector2f(playerSprite.getGlobalBounds().width, playerSprite.getGlobalBounds().height);
}

const sf::Sprite& Player::getPlayerSprite() const {
    return playerSprite; 
}

void Player::setPosition(float x, float y) {
    playerSprite.setPosition(x, y); 
}

// Métodos para activar y verificar MRUA
void Player::activateMRUA() {
    mruaActive = true;
}

bool Player::isMRUAActive() const {
    return mruaActive;
}