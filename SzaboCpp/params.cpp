#include "pch.h"
#include "params.h"

Params::Params() {
	//initialize all the parameters to default values
	//by reading a huge default incar
	map_params.insert(std::pair<std::string, double>("EDIFF", 0));
	map_params.insert(std::pair<std::string, double>("EDIFFG", 0));
}

double Params::get_param(std::string param_name) {
	if (map_params.find(param_name) == map_params.end()) {
		//not found, throw exception
		return NAN;
	}
	else {
		double value = map_params[param_name];
		return value;
	}

}

bool Params::set_param(std::string param_name, double value) {
	if (map_params.find(param_name) == map_params.end()) {
		//not found
		return false;
	}
	else {
		map_params[param_name] = value;
		return true;
	}
}

