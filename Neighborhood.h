/*
Author: Adam Aubry
UIN: 656353425
Date: 4/2/2024
Description: Stores each found neighorhood name along with the amount of stores in that neighborhood. 
			 The amount of stores is indicated by their size, either "L" for large or "S" for small.
			 This is useful for printing the neighboords chart. 
*/

#ifndef NEIGHBORHOOD_H
#define NEIGHBORHOOD_H

#include <string>

class Neighborhood
{
public:
	Neighborhood()
		: m_name{ "-- unknown --" }
		, m_size{ "-- unknown --" }
	{
	}
	Neighborhood(std::string_view name)
		: m_name{ name }
		, m_size{ "-- unknown --" }
	{
	}
	Neighborhood(std::string_view name, std::string_view size)
		: m_name{ name }
		, m_size{ size }
	{
	}
	std::string getName() const;
	void setName(std::string name);
	void addToLarge(char L);
	void addToSmall(char S);
	std::string getSizeL() const;
	std::string getSizeS() const;
	int getSize() const;

private:
	std::string m_name{};
	std::string m_size{};
	std::string m_sizeL{};
	std::string m_sizeS{};
};

#endif