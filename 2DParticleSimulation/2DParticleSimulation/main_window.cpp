#include "main_window.hpp"


void MainWindow::run()
{
	auto previous_time = std::chrono::system_clock::now();
	double lag = 0.0;
	while (this->window.isOpen()) {
		auto current_time = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed = current_time - previous_time;
		previous_time = current_time;
		lag += elapsed.count();
		handleEvents();
		while (lag >= 1.f / FPS) {
			update();
			lag -= 1.f / FPS;
		}
		std::cout << lag << std::endl;
		draw();
	}
}

void MainWindow::handleEvents()
{
	sf::Event event;
	this->window.pollEvent(event);
	if (event.type == sf::Event::Closed) {
		window.close();
	}
	else if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::W) {
			this->adding_water = true;
			this->adding_sand = false;
		}
		else if (event.key.code == sf::Keyboard::S) {
			this->adding_water = false;
			this->adding_sand = true;
		}
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i mouse_position = sf::Mouse::getPosition(this->window);
		if (mouse_position.x >= 0 && mouse_position.x < WIN_WIDTH && mouse_position.y >= 0 && mouse_position.y < WIN_HEIGHT) {
			if (adding_sand && materials.at(Calculations::XI(mouse_position.x, mouse_position.y))->shape.getFillColor() != sf::Color(SAND[0], SAND[1], SAND[2])) {
				s_mat_ptr material = std::make_shared<Material>(mouse_position.x, mouse_position.y, 1);
				materials.at(Calculations::XI(mouse_position.x, mouse_position.y)) = material;
				sand.push_back(material);
			}
			else if (adding_water) {
				s_mat_ptr material = std::make_shared<Material>(mouse_position.x, mouse_position.y, 2);
				materials.at(Calculations::XI(mouse_position.x, mouse_position.y)) = material;
				water.push_back(material);
			}
		}
	}
}

void MainWindow::draw()
{
	this->window.clear();
	draw_sand();
	draw_water();
	this->window.draw(label);
	this->window.display();
}

void MainWindow::draw_sand()
{
	for (s_mat_ptr s : this->sand) {
		window.draw(s->shape);
	}
}

void MainWindow::draw_water()
{
	for (s_mat_ptr w : this->water) {
		window.draw(w->shape);
	}
}

void MainWindow::update()
{
	updateLabel();
	Simulation::SimulateMaterials(sand, water, materials);
}

void MainWindow::updateLabel()
{
	if (this->adding_sand) {
		this->label.setString("Sand");
	}
	else if (this->adding_water) {
		this->label.setString("Water");
	}
}

void MainWindow::setupLabel()
{
	try {
		this->font.loadFromFile("../resources/Arial.ttf");
		label.setFont(this->font);
	}
	catch (std::exception exc) {
		std::cout<<exc.what()<<std::endl;
	}

	label.setString("");
	label.setCharacterSize(12);
	label.setFillColor(sf::Color::White);
}

void MainWindow::setupMaterials()
{
	for (int i = 0; i < WIN_HEIGHT * WIN_WIDTH; i++) {
		materials.push_back(std::make_shared<Material>());
	}
}

MainWindow::MainWindow()
{
	this->window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Particle Simulation");
	this->adding_sand = false;
	this->adding_water = false;
	setupMaterials();
	setupLabel();
	this->run();
}
