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
	Moves(std::vector<Region> r,std::vector<int> o);
	~Moves();
	/*
		return vector of indexs of owned areas need assitance
	*/
	std::vector<int> NeedReinforcments();
	/*
		@param index of region
		return true if there is enemy around
	*/
	bool EnemyAround(int index);
	bool FriendlyFullAround(int index);
	
	/*
		@param status of current region
		different codes 
	*/
	int priority(Player status, int regionIndex);

private:
	std::vector<Region> regions;
	std::vector<int> ownedRegions;

};
#endif // Moves Helper