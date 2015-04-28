#ifndef HelperRegions_H
#define HelperRegions_H

// stl
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>

// project
#include "Region.h"
#include "SuperRegion.h"

class HelperRegions
{
public:
	HelperRegions();
	~HelperRegions();

	/*
		find sorted order of superRegion
		@param superRegion List
		returns vector of super Regions ordered
	*/
	std::vector<SuperRegion> getSortedSuperRegions(std::vector<SuperRegion>);
	
	/*
		find Regions belonging to x superRegion 
		@param regions
		return vector of Region ids
	*/
	std::vector<Region> getRegions(	std::vector<Region> regions);
};
#endif // HelperRHelper