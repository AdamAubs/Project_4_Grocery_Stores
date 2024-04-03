#include "Distance.h"

// Gets the distance of the store from inputed location
double Distance::getDist() const
{
	return m_distance;
}

// Gets the name of the store
std::string Distance::getName() const
{
	return m_name;
}

// Gets the address of the store
std::string Distance::getAddress() const
{
	return m_address;
}

// Gets the size of the store
std::string Distance::getSize()
{
	return m_size;
}