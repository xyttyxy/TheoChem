#pragma once
#include "pch.h"
#include "params.h"
#include "geom.h"

void read_input(std::string filename, Params &params);
void read_mol(std::string filename, Atoms &atoms);
//static inline void ltrim(std::string &s);
//static inline void rtrim(std::string &s);
//static inline void trim(std::string &s);