#include "pch.h"
#include "io.h"

void read_input(std::string filename, Params &params) {
	std::ifstream input_file;
	input_file.open(filename, std::ios::in);
	if (input_file.is_open()) {
		std::string line;
		while (std::getline(input_file, line)) {
			std::vector<std::string> pair;
			boost::split(pair, line, boost::is_any_of("="));
			boost::algorithm::trim(pair[0]); //tag
			boost::algorithm::trim(pair[1]); //value
			params.set_param(pair[0], stod(pair[1]));
		}
	}
	input_file.close();
}

void read_mol(std::string filename, Atoms &atoms) {
	std::ifstream input_file;
	input_file.open(filename, std::ios::in);
	if (input_file.is_open()) {
		PeriodicTable pTable;
		std::string line;
		while (std::getline(input_file, line)) {
			std::vector<std::string> atomInfo;
			boost::split(atomInfo, line, boost::is_any_of("\t "));
			// trim
			std::for_each(
				atomInfo.begin(), 
				atomInfo.end(), 
				[](std::string str) {
				boost::algorithm::trim(str);
			}
			);
			std::array<double, 3> coords = { stod(atomInfo[1]), stod(atomInfo[2]), stod(atomInfo[3]) };
			Atom atom(pTable, atomInfo[0], coords);
			atoms.addAtom(atom);
		}
	}
}
