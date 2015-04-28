//project
#include "SuperRegion.h"

SuperRegion::SuperRegion()
	: reward(0), Counterwastelands(0), neutrals(0), WASTESIZE(6)
{
}

SuperRegion::SuperRegion(int i, const int& pReward)
	: reward(pReward), id(i), Counterwastelands(0), neutrals(0), WASTESIZE(6)
{
}

SuperRegion::~SuperRegion()
{
}

void SuperRegion::addRegion(const int& region)
{
	regions.push_back(region);
}
void SuperRegion::calcWastelands(std::vector<int> Wastelands)
{
  for(int j=0; j < Wastelands.size(); ++j)
	for (int i = 0; i < regions.size(); ++i)
	{
		if (regions[i] == Wastelands[j])
		{
			Counterwastelands = Wastelands;
			break;
		}
	}
  calcNeutrals();	
}
void SuperRegion::calcNeutrals()
{
	neutrals = regions.size()*2;
	neutrals += Counterwastelands* WASTESIZE;
}