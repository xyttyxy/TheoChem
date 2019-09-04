#pragma once
#include "pch.h"

class Element {
public:
	Element();
	Element(std::string symbol, unsigned int elemIndex, double mass, unsigned int valence);
	//Modifiers
	void setSymbol(std::string symbol) { this->symbol_ = symbol; }
	void setElemIndex(unsigned int elemIndex) { this->elemIndex_ = elemIndex; }
	void setMass(double mass) { this->mass_ = mass; }
	void setValence(unsigned int valence) { this->valence_ = valence; }
	//Accessors
	std::string getSymbol() { return symbol_; }
	unsigned int getElemIndex() { return elemIndex_; }
	double getMass() { return mass_; }
	unsigned int getValence() { return valence_; }

private:
	std::string symbol_;
	unsigned int elemIndex_;
	double mass_;
	unsigned int valence_;
};

class PeriodicTable {
public:
	PeriodicTable();
	unsigned int symbolToIndex(std::string symbol);
	Element getElement(std::string symbol);
private:
	std::map<std::string, Element> table_;
	void sym2idx_init();
	void table_init();
};

class Atom : public Element {
public:
	Atom() {
		coords_ = { 0,0,0 };
		forces_ = { 0,0,0 };
	}
	Atom(PeriodicTable &ptable, std::string symbol, std::array<double, 3> coords, std::array<double, 3> forces = std::array<double, 3>{0, 0, 0});
private:
	std::array<double, 3> coords_;
	std::array<double, 3> forces_;

};

class Atoms {
public:
	Atoms();
	void addAtom(Atom atom);
	void removeAtom(int atom_index);
	void setUnitCell(double xAxis, double yAxis, double zAxis);
	//stubs
	void setUnitCell(std::array<std::array<double, 3>, 3> unitCell) {}
	void setUnitCell(double unitCell[3][3]) {}
	void setUnitCell(double unitCell[3]) {}
	int getAtomCount() { return this->atoms_.size(); }
	Atom getAtom(int atom_index) { return atoms_[atom_index]; }

private:
	std::vector<Atom> atoms_;
	std::array<std::array<double, 3>, 3> unitCell_;
	bool isPBC;
};



