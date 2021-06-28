#pragma once
#include "Material.hpp"
#include <vector>
#include <memory>
#include "Calculations.hpp"
#include "const.hpp"
typedef std::shared_ptr<Material> s_mat_ptr;


class Simulation
{
public:
	Simulation();
	static void SimulateMaterials(std::vector<s_mat_ptr>& sand, std::vector<s_mat_ptr>& water, std::vector<s_mat_ptr>& materials);

	//void operator()(std::vector<s_mat_ptr>sand, std::vector<s_mat_ptr> water, std::vector<s_mat_ptr> materials);
	//void SimulateSand(std::vector<s_mat_ptr> sand, std::vector<s_mat_ptr> materials);
	//void SimulateWater(std::vector<s_mat_ptr> water, std::vector<s_mat_ptr> materials);
};

