#include "Timer.h"
using namespace sf;
using namespace std;

Timer::Timer() {
    timeLimit = 20.0f;

    if (!font.loadFromFile("assets/arial.ttf")) {
        // Manejar error (aquí solo se termina el programa)
        exit(EXIT_FAILURE);
    }

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(Color::White);
    text.setPosition(10, 10);
}

void Timer::start() {
    clock.restart();
}

void Timer::update(float deltaTime) {
    float timeLeft = timeLimit - clock.getElapsedTime().asSeconds();
    if (timeLeft < 0) {
        timeLeft = 0;
    }
    text.setString("Time left: " + to_string(static_cast<int>(timeLeft)));
}

void Timer::render(RenderWindow& window) {
    window.draw(text);
}

bool Timer::isTimeUp() const {
    return clock.getElapsedTime().asSeconds() >= timeLimit;
}
