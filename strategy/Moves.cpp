// stl
#include <iostream>
#include <string>

//project
#include "Moves.h"

Moves::Moves(std::vector<Region> r,std::vector<int> o)
: regions(r),ownedRegions(o)
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
int Moves::priority(Player status, int regionIndex){
	int code;
	switch(status)
	{
		case ME: 
				if(FriendlyFullAround(regionIndex))
				{
					//more than one army and surrounding is owned
					//move armies from here
					return code= 1;  
				}
			break;
		case ENEMY: 
				  //if nieghbor is enemy
				    //if isnt higher armies than we do
						//attack it
			break;
		case NEUTRAL: 
					//more than one army and neighboring is neutral
						//is nighbor a wasteland?
						//if so ignore
						//else take over if lower than our armies
			break; 
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