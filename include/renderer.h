#ifndef RENDERER_H
#define RENDERER_H

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Shape.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>

class Renderer
{
  private:
    const int SHAPE_SIZE = 100;
    const float MOVE_STEP = 20.f;
    const int TIME_STEP_MS = 10;

    int _direction_x = 1;
    int _direction_y = 1;

    sf::Vector2f _window_size;
    sf::Vector2f _window_center;

    sf::RenderWindow *window;
    sf::Shape *shape;
    sf::Clock clock;

    void _move_shape(sf::Shape &, int);

  public:
    Renderer(sf::RenderWindow *window)
        : _window_size(window->getSize()), _window_center(_window_size.x / 2.f, _window_size.y / 2.f)
    {
        this->window = window;
        this->shape = new sf::RectangleShape(sf::Vector2f(SHAPE_SIZE, SHAPE_SIZE));
        this->shape->setPosition(_window_center.x, _window_center.y);
        this->shape->setFillColor(sf::Color::Blue);
    }

    ~Renderer();
    void render();
};

#endif
