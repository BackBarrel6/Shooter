#include "Bullet.hpp"

Bullet::Bullet(float initialSpeed) : speed(initialSpeed) {
    bulletent.setSize(sf::Vector2f(25, 25)); // Set size of bullet
    bulletent.setFillColor(sf::Color::Red); // Set color of bullet
}

void Bullet::update() {
    position += sf::Vector2f(0, -speed); // Assuming bullets move upwards
    bulletent.setPosition(position);
}
