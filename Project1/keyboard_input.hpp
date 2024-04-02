#pragma once
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Bullet.hpp"
#include <vector>

void keyboard_input(Player& player, sf::RenderWindow& window, std::vector<Bullet>& bullets);
