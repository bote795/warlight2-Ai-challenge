// stl
#include <iostream>
#include <string>

//project
#include "Moves.h"

Moves::Moves()
{}
Moves::~Moves()
{

}
/
int Moves::priority(Player status){
	int code;
	switch(status)
	{
		case ME: 
			code+="M";
				if (/* check if more than one army */)//contains 1
						//if enemy is bordering
							//sent reinforcments
				code= 0;
				else
				code= 1;  //more than one army and surrounding is owned
			break;
		case ENEMY: 
				  //if nieghbor is enemy
				    //if has higher armies than we do
						//ask to reinforce
					//else
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