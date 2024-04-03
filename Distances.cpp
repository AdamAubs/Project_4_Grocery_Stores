#include <iostream>
#include <cmath>

#include "Distances.h"

// Adds distance objects that contains a store name, distance from inputed lat. and long. in miles, address, and size
// to a Distances vector object. 
void Distances::setDistances(Distance currDist)
{
	m_distancesList.push_back(currDist);
}

// Iterates through all the stores distances info
// to determine which store is closest to the inputed latitude and longitude.
// The closest store and the closest largest store along with their distances and addresses will be outputed. 
// Only if the closest store is the largest than only that store will be outputed.
// Additional checks such as not having a store within 0.5 miles and not having
// a large store within 1 mile determines if a store is a food desert.
void Distances::printClosest()
{
	// Initialize closestStore object and closestLargeStore object to stores
	// really far away to prevent stores being same distance from given location
	Distance closestStore{ "unknown", 80000, "unknown", "unknown"};
	Distance closestLargeStore{ "unknown", 80000, "unknown", "unknown" };
	
	// loop through all the stores distances info
	for (unsigned i = 0; i < m_distancesList.size(); ++i)
	{
		Distance currDist{ m_distancesList.at(i) };
		
		// determine if the stores distance is less than the already found closest store.
		if (closestStore.getDist() > currDist.getDist())
		{
			closestStore = currDist;
		}

		// determine if the stores distance is less the already found closest store and it is also a large store
		if (closestLargeStore.getDist() > currDist.getDist() && currDist.getSize() == "Large")
		{
			closestLargeStore = currDist;
		}
	}
	
	// Determine if the closest small store found is more than 0.5 miles and the closest large store found is greater than 1 mile
	if (closestStore.getAddress() == closestLargeStore.getAddress() && closestStore.getDist() > 0.5 && closestLargeStore.getDist() > 1.0)
	{
		std::cout << "The closest store is " << round(closestStore.getDist() * 10) / 10 << " miles away." << '\n';
		std::cout << '\t' << closestStore.getName() << " is at " << closestStore.getAddress() << '\n';
		std::cout << "That is a large store." << '\n';
		std::cout << "This location is a food desert." << '\n';

	}
	// Closest store is a large store
	else if (closestStore.getAddress() == closestLargeStore.getAddress())
	{
		std::cout << "The closest store is " << round(closestStore.getDist() * 10) / 10 << " miles away." << '\n';
		std::cout << '\t' << closestStore.getName() << " is at " << closestStore.getAddress() << '\n';
		std::cout << "That is a large store." << '\n';
	}
	// Closest store is not a large store
	else
	{
		std::cout << "The closest store is " << round(closestStore.getDist() * 10) / 10 << " miles away." << '\n';
		std::cout << '\t' << closestStore.getName() << " is at " << closestStore.getAddress() << '\n';
		std::cout << "The closest large store is " << round(closestLargeStore.getDist() * 10) / 10 << " miles away." << '\n';
		std::cout << '\t' << closestLargeStore.getName() << " is at " << closestLargeStore.getAddress() << '\n';
	}
}