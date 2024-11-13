#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Scene {
public:
    Scene(); 
    bool handleEvent(const Event& event); 
    void render(RenderWindow& window); 

private:
    Texture backgroundTexture;
    Sprite backgroundSprite;
    Font font;
    Text objectiveText;
    Text instructionsText;
    Text gameText;


    void loadAssets(); 
};

#endif

