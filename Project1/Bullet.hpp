#pragma once
#include <SFML/Graphics.hpp>

class Bullet {
public:
    sf::RectangleShape bulletent;
    sf::Vector2f position;
    float speed;

    Bullet(float initialSpeed);

    // Update bullet position based on its speed
    void update();
};
