#include "Material.hpp"
#include <math.h>
#include <iostream>

Material::Material(int x, int y, int material)
{
	this->shape.setPosition(float(x), float(y));
	switch (material) {
	case 1: this->shape.setFillColor(sf::Color(SAND[0], SAND[1], SAND[2])); break; //sand
	case 2: this->shape.setFillColor(sf::Color(WATER[0], WATER[1], WATER[2])); break; //water
	}
	this->shape.setSize(sf::Vector2f(1, 1));
}
Material::Material() {}

Material& Material::operator=(const Material& material)
{
	if (this == &material)
		return *this;
	this->shape.setPosition(material.shape.getPosition());
	this->shape.setFillColor(material.shape.getFillColor());
	return *this;
}
