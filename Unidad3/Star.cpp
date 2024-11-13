#include "Star.h"
using namespace sf;

Star::Star(float x, float y) : collected(false) {
    texture.loadFromFile("assets/star.png");
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

void Star::render(RenderWindow& window) {
    if (!collected) {
        window.draw(sprite);
    }
}

void Star::collect() {
    collected = true;
}

bool Star::isCollected() const {
    return collected;
}

Sprite& Star::getSprite() {
    return sprite;
}
