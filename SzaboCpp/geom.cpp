#include "pch.h"
#include "geom.h"

Element::Element() {
	this->symbol_ = "";
	this->elemIndex_ = 0;
	this->mass_ = 0;
	this->valence_ = 0;
}

Element::Element(std::string symbol, unsigned int elemIndex, double mass, unsigned int valence) {
	this->symbol_ = symbol;
	this->elemIndex_ = elemIndex;
	this->mass_ = mass;
	this->valence_ = valence;
}

PeriodicTable::PeriodicTable() {
	std::ifstream storedTable;
	storedTable.open("Table.csv", std::ios::in);
	if (storedTable.is_open()) {
		std::string lineStr;
		std::getline(storedTable, lineStr); //skip first line
		while (std::getline(storedTable, lineStr)) {
			std::vector<std::string> lineVec;
			boost::split(lineVec, lineStr, boost::is_any_of(","));
			std::for_each(
				lineVec.begin(),
				lineVec.end(),
				[](std::string str) {
				boost::algorithm::trim(str);
			}
			);
			std::string symbol = lineVec[0];
			unsigned int elemIndex = stoi(lineVec[1]);
			double mass = stod(lineVec[2]);
			unsigned int valence = stoi(lineVec[3]);
			table_.insert(std::pair<std::string, Element>(symbol, Element(symbol, elemIndex, mass, valence)));
		}
	}
}

unsigned int PeriodicTable::symbolToIndex(std::string symbol) {
	return this->table_[symbol].getElemIndex();
}

Element PeriodicTable::getElement(std::string symbol) {
	return this->table_[symbol];
}

Atom::Atom(PeriodicTable &ptable, std::string symbol, std::array<double, 3> coords, std::array<double, 3> forces){
	Element elem = ptable.getElement(symbol);
	this->setSymbol(symbol);
	this->setElemIndex(elem.getElemIndex());
	this->setMass(elem.getMass());
	this->setValence(elem.getValence());
	this->coords_ = coords;
	this->forces_ = forces;
}

Atoms::Atoms() {
	this->isPBC = false;
}

void Atoms::addAtom(Atom atom) {
	atoms_.push_back(atom);
}

void Atoms::removeAtom(int atom_index) {
	if (atom_index < atoms_.size()) {
		atoms_.erase(atoms_.begin() + atom_index);
	}
	else {
		// throw exception
	}
}

void Atoms::setUnitCell(double xAxis, double yAxis, double zAxis) {
	this->unitCell_[0] = { xAxis, 0, 0 };
	this->unitCell_[1] = { 0, yAxis, 0 };
	this->unitCell_[0] = { 0, 0, zAxis };
}
