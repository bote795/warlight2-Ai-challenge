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
std::vector<SuperRegion> getSortedSuperRegions(std::vector<SuperRegion> SuperRegions,std::vector<int> Wastelands)
{

	// First choose the SuperRegions with armiesReward > 0 
	std::vector<SuperRegion> out;
	std::vector<SuperRegion> zeroReward;
	std::vector<SuperRegion> SuperRegionsWithReward;
	for (int i = 0; i < SuperRegions.size(); ++i)
	{
		SuperRegions.calcWastelands(Wastelands);
		if (SuperRegions[i].getReward > 0)
		{
			SuperRegionsWithReward.push_back(SuperRegions[i]);
		}
		else
		{
			zeroReward.push_back(SuperRegions[i]);
		}
	}
	//then least amount of neutrals
	while(!SuperRegionsWithReward.isEmpty())
	{
		int minNeutrals = 10000;
		int index=0;
		//find smallestNeutrals
		for (int i = 0; i < SuperRegionsWithReward.size(); ++i)
		{
			if (SuperRegionsWithReward.getNeutrals() < minNeutrals)
			{
				minNeutrals = SuperRegionsWithReward.getNeutrals();
				index=i;
			}
		}

		out.push_back(SuperRegionsWithReward[i]); // add SuperRegion with least amount of neutral Enemies

		SuperRegionsWithReward.erase(index);
	}
	//then add the superREgions with armies reward of 0
	out.insert(out.end(), zeroReward.being(), zeroReward.end());
}
std::vector<Region> getRegions(	std::vector<Region> regions)
{

}
