#ifndef Moves_H
#define Moves_H

// stl
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>

// project
#include "Region.h"
#include "SuperRegion.h"
#include "main.h"
class Moves
{
public:
	Moves();
	~Moves();
	/*
		@param status of current region
		different codes 
	*/
	int priority(Player status);

};
#endif // Moves Helper