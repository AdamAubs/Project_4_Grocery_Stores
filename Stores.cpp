#include <vector>
#include <string>
#include <fstream>

#include "Stores.h"
#include "Neighborhoods.h"
#include "Neighborhood.h"
#include "Utils.h"
#include "Distance.h"
#include "Distances.h"
#include "Menu.h"

// Parses file data containing store info, 
// then creates indivual store objects which are put into a vector containing
// all the store objects.
// inputFileName is a .txt file that contains each stores info.
// Each store in the file is seperated onto newlines and the 
// info of each store is seperated by commas on that line.
// Each stores info includes its (name, square feet, size, address, neighborhood, latitude, and longitude) in that order
void Stores::inputStoresInfo(std::string inputFileName) {

	// set up the file to be read from
	std::ifstream fileIn{ inputFileName };

	// check if file can be opened
	if (!fileIn) {
		std::cout << "Error opening file!";
		std::exit(-1);
	}

	// while there's still stores to be read
	while (!fileIn.eof()) {

		// set up variables to store parsed input
		std::string name;
		std::string strSqFeet;
		std::string size;
		std::string address;
		std::string neighborhood;
		std::string strLatitude;
		std::string strLongitude;

		// extract parsed text seperated by commas 
		std::getline(fileIn, name, ',');
		std::getline(fileIn, strSqFeet, ',');
		std::getline(fileIn, size, ',');
		std::getline(fileIn, address, ',');
		std::getline(fileIn, neighborhood, ',');
		std::getline(fileIn, strLatitude, ',');
		std::getline(fileIn, strLongitude);

		// convert the numeric units to correct numeric types
		int sqFeet{ std::stoi(strSqFeet) };
		double latitude{ std::stod(strLatitude) };
		double longitude{ std::stod(strLongitude) };

		// initialize store class with information read from file
		Store store(name, sqFeet, size, address, neighborhood, latitude, longitude);

		// put the store information in an array of all the stores
		m_storesList.push_back(store);
	}

	// explicitly close the file after reaching the end of the file
	fileIn.close();
}

// Displays the general info about all of the stores
// Uses predefined storesList object from Stores class to get total amount of grocery stores in the given file.
// Calls getLargeStoreAmount() member function that calculates # of large stores in the given file.
// Calls getAvgSizeLargeStores() member function that calculates the avg. size of ONLY the large stores in the given file.
void Stores::printGeneralInfo() {
	std::cout << "Number of grocery stores: " << m_storesList.size() << '\n';
	std::cout << "Number of large grocery stores: " << getLargeStoreAmount() << '\n';
	std::cout << "Average size of large grocery stores: " << getAvgSizeLargeStores() << '\n';
}

// Calculates # of large stores in the given file
// returns the total amount of large stores
int Stores::getLargeStoreAmount() const {
	int largeStoreCount{ 0 };

	// iterate through all the stores
	for (unsigned i = 0; i < m_storesList.size(); ++i)
	{
		// get the current store in the list
		Store currStore = m_storesList.at(i);

		// determine if the store is large
		if (currStore.getSize() == "Large")
		{
			++largeStoreCount;
		}
	}

	return largeStoreCount;
}

// Calculates the avg size of the only the large stores
// returns the avg size of the large stores
double Stores::getAvgSizeLargeStores() const {
	double largeStoreSizeSum{ 0 };
	int largeStoreCount{ 0 };
	double avgSize{};

	// iterate through all the stores
	for (unsigned i = 0; i < m_storesList.size(); ++i)
	{
		// get the current store in the list
		Store currStore = m_storesList.at(i);
		// check to see if the store is large and the square feet of the store is not 0
		if (currStore.getSize() == "Large" && currStore.getSqFeet() != 0)
		{
			largeStoreSizeSum += currStore.getSqFeet();
			++largeStoreCount;
		}
	}
	// calculate the avg using only the large stores with a square feet that is not 0
	avgSize = largeStoreSizeSum / largeStoreCount;

	return avgSize;
}

// Displays chart of stores where the first column is
// the neighborhood that the store is located and the 
// second column is a list of "L's" and "S's" indicating
// the size of each store in that neighborhood.
// The chart is sorted in decreasing order where the neighborhood with
// most amount stores is at the top and the least amount of stores
// is at the bottom.
void Stores::printNeighborhoodsInfo() const 
{
	// setup category for each neighborhood
	std::vector<std::string> neighborhoods{};
	
	// instantiate store object with first store in file
	Store currStore = m_storesList.at(0);

	// since its not in the neighboorhoods array yet, have it be the first element
	neighborhoods.push_back(currStore.getNeighborhood());

	// iterate through all the stores to find names of different neighborhoods in the file
	// skip duplicates because only one is needed to set up the different neighborhood categories
	for (unsigned i = 0; i < m_storesList.size(); ++i)
	{
		// initial condition (first neighborhood name is already found)
		if (i == 0)
		{
			continue;
		}
		// follow loop index to find the rest of neighborhoods
		else
		{
			currStore = m_storesList.at(i);
		}
		// keep track of already found neighborhoods
		bool inFile{ false };
		// check for duplicate neighborhoods
		for (unsigned j = 0; j < neighborhoods.size(); ++j)
		{
			// if a duplicate occurs set flag and end loop
			if (currStore.getNeighborhood() == neighborhoods.at(j))
			{
				inFile = true;
				break;
			}
		}

		// if neighboordhood is not in the list
		if (!inFile)
		{
			// put it in the neighborhoods list
			neighborhoods.push_back(currStore.getNeighborhood());
			// create new neighborhood object
			Neighborhood neighborhood(currStore.getNeighborhood(), currStore.getSize());
		}
	}

	// set up  neighborhoods object to store all the different neighborhoods 
	Neighborhoods neighborhood{};

	// go through neighborhoods list created in prev loop
	for (unsigned i = 0; i < neighborhoods.size(); ++i)
	{
		// create new Neighborhood chart object for each neighborhood
		Neighborhood chart{ neighborhoods.at(i), ""};

		// find all stores that match the current neighborhood in the file
		for (unsigned j = 0; j < m_storesList.size(); ++j)
		{
			// get the current store in the list
			Store newCurrStore = m_storesList.at(j);

			// check to see if the store matches the neighborhood and get its size (small or large).
			if (neighborhoods.at(i) == newCurrStore.getNeighborhood() && newCurrStore.getSize() == "Large")
			{
				// add "L" to the Neighborhood chart object (defined in Neighborhood.cpp file)
				chart.addToLarge('L');
			}
			else if (neighborhoods.at(i) == newCurrStore.getNeighborhood() && newCurrStore.getSize() == "Small")
			{
				// add "S" to the Neighborhood chart object (defined in Neighborhood.cpp file)
				chart.addToSmall('S');
			}
		}
		// put updated neighborhood chart object into a neighborhoods vector object (defined in Neighborhoods.cpp file)
		neighborhood.setNeighborhood(chart);
	
	}

	// sort the neighborhoods in decending order with most stores at top (defined in Neighborhoods.cpp file)
	neighborhood.sortNeighborhoods();
    // print out the chart (defined in Neighborhoods.cpp file)
	neighborhood.printNeighborhoodsChart();
}

// Using the user inputed latitude and longitude, printClosestStores prints
// the closest store and the closest large store. Additional information, such as, the distance away (in miles), if the closest
// store is large, and if the given location is a food desert (not within 0.5 mile of a store and not within 1 mile of large store) is also provided. 
// The parameters latitude and longitude are the user inputed values.
void Stores::printClosestStores(double latitude,double longitude) const
{
	// initialize distances object that will be used to set and anaylze all the stores distances
	Distances distances;

	// loop through all the stores
	for (unsigned i = 0; i < m_storesList.size(); ++i)
	{
		Store currStore{ m_storesList.at(i) };

		// get the distance away from user inputed latitude and longitude in miles using distance function (located in Utils.h)
		double dist = distance(latitude, longitude, currStore.getLatitude(), currStore.getLongitude());

		// Create a Distance object that stores the name, distance, address, and size of the store
		Distance currDist{ currStore.getName(), dist, currStore.getAddress(), currStore.getSize() };

		// add the newly created Distance object to a Distances object that is a vector containing info regarding
		// all the stores distances. (located in Distances.cpp file)
		distances.setDistances(currDist);
	}
	// determines closest store and prints results along with additional info about store
	distances.printClosest();
}

// Uses the user inputed search query to retrieve info about stores in file
// storeName is the store name the user is trying to find
void Stores::printSearch(std::string storeName)
{
	// captialize inputed store name to match store names in file
	for (char& c: storeName)
	{
		c = static_cast<char>(std::toupper(c));
	}
	
	// Flag if the input matches any of the stores name
	bool storeFound{ false };
	// loop through the list of all the stores
	for (unsigned i = 0; i < m_storesList.size(); ++i)
	{
		Store currStore{ m_storesList.at(i) };

		// Check if inputed store name is a substring of a store name in the file
		if (currStore.getName().find(storeName) != std::string::npos)
		{
			// display the stores info
			std::cout << "Store: " << currStore.getName() << '\n';
			std::cout << "Address: " << currStore.getAddress() << '\n';
			std::cout << "Community: " << currStore.getNeighborhood() << '\n';
			std::cout << "Size: " << currStore.getSize() << '\n';
			std::cout << "Square Feet: " << currStore.getSqFeet() << '\n';
			std::cout << '\n';
			// indicate the store was found
			storeFound = true;
		}
	}

	// store was not found
	if (!storeFound)
	{
		std::cout << "No stores found.";
	}
}
