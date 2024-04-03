#include <string>
#include <iostream>
#include "Neighborhood.h"

// Gets the neighborhoods name
std::string Neighborhood::getName() const
{
	return m_name;
}

// Gets neighborhood large store size as a string of "L's"
std::string Neighborhood::getSizeL() const
{
	return m_sizeL;
}

// Gets neighborhood small store size as a string of "S's"
std::string Neighborhood::getSizeS() const
{
	return m_sizeS;
}

// Get tot. amount of stores in neighboord
int Neighborhood::getSize() const
{
	return static_cast<int>(m_sizeS.size() + m_sizeL.size());
}

// Set the neighood name
void Neighborhood::setName(std::string name)
{
	m_name = name;
}

// Adds character "L" to neighborhood
void Neighborhood::addToLarge(char L) 
{
	m_sizeL += L;
}

// Adds character "S" to neighborhood
void Neighborhood::addToSmall(char S)
{
	m_sizeS += S;
}
