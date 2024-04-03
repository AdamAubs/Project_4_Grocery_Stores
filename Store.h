/*
Author: Adam Aubry
UIN: 656353425
Date: 4/2/2024
Description: Used to intialize each store object after being read from file. 
			 The information of each store includes its
			 name, square feet, size (Large or Small), address, neighborhood, latitude and longitude.
*/

#include <iostream>
#include <string>

#ifndef STORE_H
#define STORE_H

class Store {
public:
	Store();
	Store(std::string_view name, int sqFeet, std::string_view size, std::string_view address, std::string_view neighborhood, double latitude, double longitude);
	std::string getName();
	int getSqFeet();
	std::string getSize();
	std::string getAddress();
	std::string getNeighborhood();
	double getLatitude();
	double getLongitude();

private:
	std::string m_name;
	int m_sqFeet;
	std::string m_size;
	std::string m_address;
	std::string m_neighborhood;
	double m_latitude;
	double m_longitude;
};



#endif