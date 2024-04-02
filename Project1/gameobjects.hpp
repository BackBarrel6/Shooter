#pragma once
#include<SFML/Graphics.hpp>
class Player {
public:
    sf::CircleShape playerent;
    sf::Text posx, posy;
    sf::Vector2f position;
    float movespeed = 0.1f;
};
class Bullet {
public:
    sf::RectangleShape bulletent;
    sf::Vector2f position;
    float speed;

    Bullet(float initialSpeed) : speed(initialSpeed) {
        bulletent.setSize(sf::Vector2f(5, 5)); // Set size of bullet
        bulletent.setFillColor(sf::Color::Red); // Set color of bullet
    }

    void update() {
        position += sf::Vector2f(0, -speed);
        bulletent.setPosition(position);
    }
};