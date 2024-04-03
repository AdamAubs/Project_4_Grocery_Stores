/*
Author: Adam Aubry
UIN: 656353425
Date: 4/2/2024
Description: This program allows users to search for specific grocery stores, 
			 find the nearest grocery store to a given location, and analyze the number of 
			 and size of grocery stores in each neighborhood. The data is based on neighborhoods 
			 in Chicago and can be used to determine where food deserts are based on
			 inputed location (latitude and longitude). 
*/

#include <iostream>
#include <string>

#include "Menu.h"
#include "Store.h"
#include "Stores.h"
#include "Neighborhood.h"
#include "Neighborhoods.h"

// Asks user to input file name
// Returns inputed file name
std::string getFileName()
{
	std::string inputFileName;
	std::cout << "Enter the file name: ";
	std::cin >> inputFileName;

	return inputFileName;
}

// Displays the 5 different menu options
// Determines if selected option needs additional input
// Returns Menu object containing users selection
Menu getMenuOptions()
{
	std::cout << '\n';
	Menu options{};
	std::cout << "Select a menu option: \n";
	std::cout << "	1. Display general grocery stores information\n";
	std::cout << "	2. Display neighborhood charts\n";
	std::cout << "	3. Find closest stores\n";
	std::cout << "	4. Search for store by name\n";
	std::cout << "	5. Exit\n";

	std::cout << "Your choice: ";
	std::cin >> options.choice;

	// Ask for latitude and longitude to find closest store
	if (options.choice == 3)
	{

		std::cout << "Enter latitude: ";
		std::cin >> options.latitude;
		
		std::cout << "Enter longitude: ";
		std::cin >> options.longitude;
	}
	// Ask for the store to be searched
	if (options.choice == 4)
	{
		std::cout << "Enter store to search for: ";
		std::getline(std::cin >> std::ws, options.storeName);
	}

	return options;
}

int main()
{

	// get store info from .txt file
	std::string inputFileName{ getFileName() };

	// Create Stores object to hold all the stores information
	Stores allStores{};
	allStores.inputStoresInfo(inputFileName);

	// Display menu after each selection untill 
	// user selects the option to exit the program
	while (true)
	{
		// store users input in a menu struct
		Menu menuOptions{ getMenuOptions() };
		

		if (menuOptions.choice == 1)
		{
			allStores.printGeneralInfo();

		}
		else if (menuOptions.choice == 2)
		{
			allStores.printNeighborhoodsInfo();
		}
		else if (menuOptions.choice == 3)
		{
			allStores.printClosestStores(menuOptions.latitude,menuOptions.longitude);

		}
		else if (menuOptions.choice == 4)
		{
			allStores.printSearch(menuOptions.storeName);

		}
		else if (menuOptions.choice == 5)
		{
			std::exit(EXIT_SUCCESS);
		}
	}

	return 0;

}