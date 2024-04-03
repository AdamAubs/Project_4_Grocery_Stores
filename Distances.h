/*
Author: Adam Aubry
UIN: 656353425
Date: 4/2/2024
Description: Distances class is used to store, anaylze and output the closest store
			 to the user inputed location. 
*/

#ifndef DISTANCES_H
#define DISTANCES_H

#include <vector>
#include <string>

#include "Distance.h"

class Distances
{
public:
	void setDistances(Distance currDist);
	void printClosest();
private:
	std::vector<Distance> m_distancesList;
};

#endif