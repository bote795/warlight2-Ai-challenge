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
		@param wasteland List of ids
		returns vector of super Regions ordered
		the ordering being the easiest to conquered based on 
		neutrals needed to defeat in battle and how much it is worth 
		in points to the ones not worth any points
	*/
	std::vector<SuperRegion> getSortedSuperRegions(std::vector<SuperRegion> SuperRegions, std::vector<int> Wastelands);
	/*
		sort starting regions from least neighbored to most
		@param startingRegionsrecieved
		@param regions vector
	*/
	std::vector<int> getSortedStartingRegions (std::vector<int> startingRegionsreceived, 	std::vector<Region> regions);
	/*
		returns smallest amount of neighbors region
		@param startingRegionsrecieved
		@param regions vector
	*/
	int getsmallestStartingRegions (std::vector<int> startingRegionsreceived, 	std::vector<Region> regions);

};
#endif // HelperRHelper