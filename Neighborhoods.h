/*
Author: Adam Aubry
UIN: 656353425
Date: 4/2/2024
Description: Stores all the neighboord objects in a vector. Sorts the 
			 neighborhood in decending order with the most stores listed first.
			 The sorted vector is then outputed as a chart with the first column being 
			 the neighborhoods name and the second column being a string containing the number 
			 of Large "L" and Small "S" stores in that order. 
*/

#ifndef NEIGHBORHOODS_H
#define NEIGHBORHOODS_H

#include <vector>
#include "Neighborhood.h"

class Neighborhoods {
public:
	void setNeighborhood(Neighborhood neighborhood);
	void sortNeighborhoods();
	void printNeighborhoodsChart();
private:
	std::vector<Neighborhood> m_neighborhoodsList;
};

#endif
