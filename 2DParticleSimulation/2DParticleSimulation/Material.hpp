#pragma once
#include <SFML/Graphics.hpp>
#include "const.hpp"

struct Material
{
	sf::RectangleShape shape;
	Material(int x, int y, int material);
	Material();
	Material& operator=(const Material& material);
};

