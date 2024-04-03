/*
Author: Adam Aubry
UIN: 656353425
Date: 4/2/2024
Description: Stores the user choice (1,2,3,4,5) as well as the inputed latitidue, longitude and store name. 
*/

#ifndef MENU_H
#define MENU_H

#include <string>

struct Menu {
	int choice{};
	double latitude{};
	double longitude{};
	std::string storeName{};
};

#endif
