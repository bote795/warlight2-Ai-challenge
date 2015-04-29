// stl
#include <iostream>
#include <string>

//project
#include "HelperRegions.h"

HelperRegions::HelperRegions()
{}
HelperRegions::~HelperRegions()
{

}
std::vector<SuperRegion> HelperRegions::getSortedSuperRegions(std::vector<SuperRegion> SuperRegions,std::vector<int> Wastelands)
{

	// First choose the SuperRegions with armiesReward > 0 
	std::vector<SuperRegion> out;
	std::vector<SuperRegion> zeroReward;
	std::vector<SuperRegion> SuperRegionsWithReward;
	for (int i = 0; i < SuperRegions.size(); ++i)
	{
		SuperRegions[i].calcWastelands(Wastelands);
		if (SuperRegions[i].getReward() > 0)
		{
			SuperRegionsWithReward.push_back(SuperRegions[i]);
		}
		else
		{
			zeroReward.push_back(SuperRegions[i]);
		}
	}
	//then least amount of neutrals
	while(!SuperRegionsWithReward.empty())
	{
		int minNeutrals = 10000;
		int index=0;
		//find smallestNeutrals
		for (int i = 0; i < SuperRegionsWithReward.size(); ++i)
		{
			if (SuperRegionsWithReward[i].getNeutrals() < minNeutrals)
			{
				minNeutrals = SuperRegionsWithReward[i].getNeutrals();
				index=i;
			}
		}

		out.push_back(SuperRegionsWithReward[index]); // add SuperRegion with least amount of neutral Enemies

		SuperRegionsWithReward.erase(SuperRegionsWithReward.begin()+index);
	}
	//then add the superREgions with armies reward of 0
	out.insert(out.end(), zeroReward.begin(), zeroReward.end());
}
std::vector<int> HelperRegions::getSortedStartingRegions (std::vector<int> startingRegionsreceived, std::vector<Region> regions)
{
	std::vector<int> minEdges;
	int index=0;
	
	while(!startingRegionsreceived.empty())
	{
		int min=1000;
		for (int i = 0; i < startingRegionsreceived.size(); ++i)
		{
			if(regions[startingRegionsreceived[i]].getNbNeighbors() < min)
			{
				min=regions[startingRegionsreceived[i]].getNbNeighbors();
				index=i;
			}
		}
		minEdges.push_back(startingRegionsreceived[index]);
		startingRegionsreceived.erase(startingRegionsreceived.begin()+index-1);
		break;
	}
	return minEdges;
}

int HelperRegions::getsmallestStartingRegions (std::vector<int> startingRegionsreceived, std::vector<Region> regions)
{
	int min=1000;
	int index;
		for (int i = 0; i < startingRegionsreceived.size(); ++i)
		{
			if(regions[startingRegionsreceived[i]].getNbNeighbors() < min)
			{
				min=regions[startingRegionsreceived[i]].getNbNeighbors();
				index=i;
			}
		}
		return startingRegionsreceived[index];
}
