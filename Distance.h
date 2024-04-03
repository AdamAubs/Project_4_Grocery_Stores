/*
Author: Adam Aubry
UIN: 656353425
Date: 4/2/2024
Description: Distance keeps track of each stores name, distance, address and size
			 which is later used in the distances class to determine and output the closest store.
*/

#ifndef DISTANCE_H
#define DISTANCE_H

#include <string>

class Distance {
public:
	Distance()
		: m_name{ "-- unknown --" }
		, m_distance{ 0.0 }
		, m_address{""}
		, m_size{""}
	{
	}

	Distance(std::string_view name, double distance, std::string_view address, std::string_view size)
		: m_name{ name }
		, m_distance{ distance }
		, m_address{ address }
		, m_size{ size }
	{
	}

	double getDist() const;
	std::string getName() const;
	std::string getAddress() const;
	std::string getSize();

private:
	std::string m_name{};
	double m_distance{};
	std::string m_address{};
	std::string m_size{};
};

#endif