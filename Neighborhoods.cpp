#include "Neighborhood.h"
#include "Neighborhoods.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

// Passes in each Neighborhood object that contains its name, amount of stores, amount of large stores,
// and amount of small stores. 
// The info is than inputed into a Neighborhoods vector object.
void Neighborhoods::setNeighborhood(Neighborhood neighborhood)
{
	m_neighborhoodsList.push_back(neighborhood);
}

// Correctly formats chart into two columns
// Column 1: neighboorhood name
// Column 2: amount of large and small stores indicates by a string of "L's" and "S's"
// The chart is displayed in decending order. Neighboorhod with most stores to least.
void Neighborhoods::printNeighborhoodsChart()
{
	// intializes the current neighborhood object
	Neighborhood currNeighborhood;

	// loop through all the neighborhoods
	for (unsigned i = 0; i < m_neighborhoodsList.size(); ++i)
	{
		// get the current neighborhood
		currNeighborhood = m_neighborhoodsList.at(i);
		
		std::cout << currNeighborhood.getName() << "\t\t" << currNeighborhood.getSizeL() + currNeighborhood.getSizeS() << '\n';
		
	}
}

// Sorts the neighborhoods list in decending order (most stores to least) 
void Neighborhoods::sortNeighborhoods()
{
	// Sort neighborhoods using the < operator defined for Neighborhood
	std::sort(m_neighborhoodsList.begin(), m_neighborhoodsList.end());
}

// Overload the < operator for Neighborhood class
bool operator<(const Neighborhood& lhs, const Neighborhood& rhs) 
{
	if (rhs.getSize() < lhs.getSize()) {
		return true;
	}
	else if (rhs.getSize() > lhs.getSize()) {
		return false;
	}

	// If sizeS is also equal, compare names alphabetically
	return lhs.getName() < rhs.getName();
} 

