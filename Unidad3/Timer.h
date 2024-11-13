#ifndef TIMER_H
#define TIMER_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Timer {
public:
    Timer();
    void start();
    void update(float deltaTime);
    void render(RenderWindow& window);
    bool isTimeUp() const;

private:
    Clock clock;
    float timeLimit; 
    Font font;
    Text text;
};

#endif // TIMER_H

