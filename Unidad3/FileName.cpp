#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Escaleras y Piso");

    sf::Texture platformTexture;
    if (!platformTexture.loadFromFile("plataforma.jpg"))
    {
        return 1; // Manejar errores si no se puede cargar la textura
    }

    sf::Sprite stairPlatform(platformTexture);
    stairPlatform.setScale(0.5f, 0.5f); // Escala para ajustar el tamaño
    stairPlatform.setPosition(200, 500); // Posición inicial

    sf::Sprite topPlatform(platformTexture);
    topPlatform.setScale(0.5f, 0.5f); // Escala para ajustar el tamaño
    topPlatform.setPosition(200, 100); // Posición inicial

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Dibuja las plataformas en forma de escaleras
        for (int i = 0; i < 5; i++)
        {
            window.draw(stairPlatform);
            stairPlatform.move(100, -100); // Mover hacia arriba y a la derecha
        }

        // Dibuja el piso superior
        window.draw(topPlatform);

        window.display();
    }

    return 0;
}