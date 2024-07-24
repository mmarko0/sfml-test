#include "SFML/Graphics/RenderWindow.hpp"
#include "include/renderer.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Test SFML!");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    std::cout << "starting..." << std::endl;

    Renderer renderer(&window);

    // Events must be processed on the main thread
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        renderer.render();
    }

    return 0;
}
