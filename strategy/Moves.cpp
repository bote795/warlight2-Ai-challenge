// stl
#include <iostream>
#include <string>

//project
#include "Moves.h"

Moves::Moves(std::vector<Region> r,std::vector<int> o, std::vector<int> w)
: regions(r),ownedRegions(o),wastelands(w)
{}
Moves::~Moves()
{

}
std::vector<int> Moves::NeedReinforcments()
{
	std::vector<int> needReinforcments;
	for (int i = 0; i < ownedRegions.size(); ++i)
	{
		if(EnemyAround(ownedRegions[i]))
		{
			needReinforcments.push_back(ownedRegions[i]);	//send reinforcments
		}
	}
	return needReinforcments;
	
}
string Moves::priority(int regionIndex){
	string code="";
	if (regions[regionIndex].getArmies() > 1)
		if(FriendlyFullAround(regionIndex))
		{
			//more than one army and surrounding is owned
			//move armies from here
			code = "transfer";  
			return code;
		}
	else
		return "0"; 
	if (EnemyAround(regionIndex))
	{
		for (int i = 0; i < regions[regionIndex].getNbNeighbors(); ++i)
		{
			if (regions[regions[regionIndex].getNeighbor(i)].getOwner() != ME)
			{
				//if isnt higher armies than we do
				if (regions[regions[regionIndex].getNeighbor(i)].getArmies() < regions[regionIndex].getArmies())
				{
					//attack it
					code="attack "+regions[regionIndex].getNeighbor(i);
					return code;
				}
			}
		}
	}
	 
	  //more than 3 army and neighboring is neutral
		//is nighbor a wasteland?
		//if so ignore
		//else take over if lower than our armies
	for (int i = 0; i < regions[regionIndex].getNbNeighbors(); ++i)
	{
		if (regions[regions[regionIndex].getNeighbor(i)].getOwner() != NEUTRAL)
		{
			//if isnt higher armies than we do
			if (regionsregions[regionIndex].getArmies() > 3 &&
				!wasteland(regions[regionIndex].getNeighbor(i)))
			{
				code="move "+regions[regionIndex].getNeighbor(i);
				return code;
			}
		}
	}
	 
	
}
 
bool Moves::EnemyAround(int index)
{
	for (int i = 0; i < regions[index].getNbNeighbors(); ++i)
	{
		if (regions[regions[index].getNeighbor(i)].getOwner() == ENEMY)
		{
			return true;
		}
	}
	return false;
}
bool Moves::FriendlyFullAround(int index)
{
	for (int i = 0; i < regions[index].getNbNeighbors(); ++i)
	{
		if (regions[regions[index].getNeighbor(i)].getOwner() != ME)
		{
			return false;
		}
	}
	return true;
}
bool Moves::wasteland(int index)
{
	for (int i = 0; i < wastelands.size(); ++i)
	{
		if(wastelands[i] == index)
		{
			return true;
		}
	}
	retrun false;
}