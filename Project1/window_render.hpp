#pragma once
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Bullet.hpp"
void window_render(sf::RenderWindow& window, Player& player, std::vector<Bullet>& bullets, sf::Event& event);
