#pragma once
#include <SFML/Graphics.hpp>
#include <thread>
#include "Material.hpp"
#include "Calculations.hpp"
#include "Simulation.hpp"
#include "const.hpp"
#include <iostream>
#include <chrono>


typedef std::shared_ptr<Material> s_mat_ptr;

class MainWindow {
private:
	sf::RenderWindow window;
	std::vector<s_mat_ptr> water;
	std::vector<s_mat_ptr> sand;
	std::vector<s_mat_ptr> materials;
	sf::Text label;
	sf::Font font;
	bool adding_water;
	bool adding_sand;
	void run();
	void handleEvents();
	void draw();
	void draw_sand();
	void draw_water();
	void update();
	void updateLabel();
	void setupLabel();
	void setupMaterials();
public:
	MainWindow();
};