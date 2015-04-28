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
std::vector<Region> getRegions(	std::vector<Region> regions)
{

}
