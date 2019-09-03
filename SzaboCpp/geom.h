#pragma once
#include "pch.h"

class Atoms {
public:
	void add_atom(Atom atom);
	void remove_atom(int atom_index);
private:
	std::vector<Atom> atoms;
	std::vector<std::vector<double>> unit_cell;
};

class Atom {
private:
	std::string symbol;
	std::vector<double> coords;
};