#include "include/renderer.h"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Vector2.hpp"

void Renderer::render()
{
    window->clear(sf::Color::Black);
    
    int elapsed = clock.getElapsedTime().asMilliseconds();

    _move_shape(*shape, elapsed);
    window->draw(*shape);
    this->window->display();

    if (elapsed >= Renderer::TIME_STEP_MS)
    {
        clock.restart();
    }
}

Renderer::~Renderer()
{
    delete shape;
}

void Renderer::_move_shape(sf::Shape &shape, int elapsed_time)
{
    if (elapsed_time < Renderer::TIME_STEP_MS)
    {
        return;
    }

    sf::Vector2f prev_pos(shape.getPosition().x, shape.getPosition().y);

    sf::Vector2f new_pos(prev_pos.x + Renderer::MOVE_STEP * this->_direction_x,
                         prev_pos.y + Renderer::MOVE_STEP * this->_direction_y);

    if (new_pos.x + Renderer::SHAPE_SIZE > this->_window_size.x)
    {
        this->_direction_x = -1;
    }

    if (new_pos.x < 0)
    {
        this->_direction_x = 1;
    }

    if (new_pos.y + Renderer::SHAPE_SIZE > this->_window_size.y)
    {
        this->_direction_y = -1;
    }

    if (new_pos.y < 0)
    {
        this->_direction_y = 1;
    }

    shape.move(Renderer::MOVE_STEP * this->_direction_x, Renderer::MOVE_STEP * this->_direction_y);
}
