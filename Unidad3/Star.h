#ifndef STAR_H
#define STAR_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Star {
public:
    Star(float x, float y);
    void render(RenderWindow& window);
    bool isCollected() const;
    void collect();
    Sprite& getSprite();

private:
    Sprite sprite;
    Texture texture;
    bool collected;
};

#endif // STAR_H
