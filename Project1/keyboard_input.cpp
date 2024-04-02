#include "keyboard_input.hpp"
#include <iostream>

void keyboard_input(Player& player, sf::RenderWindow& window, std::vector<Bullet>& bullets)
{
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= player.movespeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y -= player.movespeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += player.movespeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        movement.y += player.movespeed;

    // Normalize movement vector
    float magnitude = std::sqrt(movement.x * movement.x + movement.y * movement.y);
    if (magnitude > 0) {
        movement.x /= magnitude;
        movement.y /= magnitude;
    }

    sf::Vector2f newPosition = player.playerent.getPosition() + movement * player.movespeed;

    // Check if the new position is within the window bounds
    if (newPosition.x < 0)
        newPosition.x = 0;
    if (newPosition.y < 0)
        newPosition.y = 0;
    if (newPosition.x + player.playerent.getRadius() * 2 > window.getSize().x)
        newPosition.x = window.getSize().x - player.playerent.getRadius() * 2;
    if (newPosition.y + player.playerent.getRadius() * 2 > window.getSize().y)
        newPosition.y = window.getSize().y - player.playerent.getRadius() * 2;

    player.playerent.setPosition(newPosition);

    if(player.fireClock.getElapsedTime() >= player.fireRate && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Bullet bullet(player.bulletspeed); // Speed of the bullet
        bullet.position = player.playerent.getPosition();
        bullets.push_back(bullet);

        // Restart the timer
        player.fireClock.restart();
    }
}
