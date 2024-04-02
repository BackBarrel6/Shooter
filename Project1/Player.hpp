#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
    sf::CircleShape playerent;
    sf::Text posx, posy;
    sf::Vector2f position;
    float movespeed = 0.1f;
    float bulletspeed = 0.5f;
    sf::Clock fireClock;
    sf::Time fireRate = sf::milliseconds(1000);
};
