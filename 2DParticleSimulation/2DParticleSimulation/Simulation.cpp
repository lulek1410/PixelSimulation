#include "Simulation.hpp"

Simulation::Simulation() {}

void Simulation::SimulateMaterials(std::vector<s_mat_ptr>& sand, std::vector<s_mat_ptr>& water, std::vector<s_mat_ptr>& materials)
{
	int index_it[3] = { 0, 1, -1 };
	for (s_mat_ptr s : sand) {
		sf::Vector2i position = sf::Vector2i(s->shape.getPosition());
		for (int i : index_it) {
			if (position.y < WIN_HEIGHT && materials.at(Calculations::XI(position.x + i, position.y + 1))->shape.getFillColor() == sf::Color(255, 255, 255)) {
				s->shape.setPosition(float(position.x + i), float(position.y + 1));
				materials.at(Calculations::XI(position.x, position.y)) = std::make_shared<Material>();
				materials.at(Calculations::XI(position.x + i, position.y + 1)) = s;
				break;
			}
		}

	}
}

//void Simulation::operator()(std::vector<s_mat_ptr> sand, std::vector<s_mat_ptr> water, std::vector<s_mat_ptr> materials)
//{
//	this->SimulateMaterials(sand, water, materials);
//}



