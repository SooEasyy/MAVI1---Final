#include "Scene.h"
#include <iostream>
using namespace sf;
using namespace std;

Scene::Scene() {
    loadAssets();

    gameText.setFont(font);
    gameText.setString("MAZE GAME.");
    gameText.setCharacterSize(50);
    gameText.setFillColor(Color(31, 206, 116));
    gameText.setPosition(250, 50);


    // Configuración del texto de objetivo
    objectiveText.setFont(font);
    objectiveText.setString("Recolecta las 4 estrellas y rescata a la princesa");
    objectiveText.setCharacterSize(24);
    objectiveText.setFillColor(Color::White);
    objectiveText.setPosition(150, 150);

    // Configuración del texto de instrucciones
    instructionsText.setFont(font);
    instructionsText.setString("Usa las teclas de direccion para moverte.\n\nPresiona cualquier tecla para comenzar.");
    instructionsText.setCharacterSize(24);
    instructionsText.setFillColor(Color::White);
    instructionsText.setPosition(180, 200);
}

void Scene::loadAssets() {
    // Cargar la textura de fondo
    if (!backgroundTexture.loadFromFile("assets/start_screen.png")) {
        cerr << "Error al cargar el fondo" << endl;
    }
    backgroundSprite.setTexture(backgroundTexture);

    // Cargar la fuente
    if (!font.loadFromFile("assets/arial.ttf")) {
        cerr << "Error al cargar la fuente" << endl;
    }
}

bool Scene::handleEvent(const Event& event) {
    if (event.type == Event::KeyPressed) {
        return true; // Indica que se debe cerrar la pantalla de inicio
    }
    return false;
}

void Scene::render(RenderWindow& window) {
    window.draw(backgroundSprite);
    window.draw(gameText);
    window.draw(objectiveText);
    window.draw(instructionsText);
}
