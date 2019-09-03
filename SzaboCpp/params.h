#pragma once
#include "pch.h"

class Params {
public:
	Params();
	double get_param(std::string param_name);
	bool set_param(std::string param_name, double value);
private: 
	std::map<std::string, double> map_params;
};