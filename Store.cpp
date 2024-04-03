#include <string>
#include <iostream>

#include "Store.h"

// Default contructor for store
Store::Store()
	: m_name{ "- unknown -" }
	, m_sqFeet{ 0 }
	, m_size{ "- unknown -" }
	, m_address{ "- unknown -" }
	, m_neighborhood{ "- unknown -" }
	, m_latitude{ 0.0 }
	, m_longitude{ 0.0 }
{
}

// Intializes data members for Store object
Store::Store(std::string_view name, int sqFeet, std::string_view size, std::string_view address, std::string_view neighborhood, double latitude, double longitude)
	: m_name{ name }
	, m_sqFeet{ sqFeet }
	, m_size{ size }
	, m_address{ address }
	, m_neighborhood{ neighborhood }
	, m_latitude{ latitude }
	, m_longitude{ longitude }
{
}

// Gets store name
std::string Store::getName() {
	return m_name;
}

// Gets store square feet
int Store::getSqFeet() {
	return m_sqFeet;
}

// Gets store size
std::string Store::getSize() {
	return m_size;
}

// Gets store address
std::string Store::getAddress() {
	return m_address;
}

// Gets store neighborhood
std::string Store::getNeighborhood() {
	return m_neighborhood;
}

// Gets stores latitude
double Store::getLatitude() {
	return m_latitude;
}

// gets store longitude
double Store::getLongitude() {
	return m_longitude;
}

