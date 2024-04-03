/*
Author: Adam Aubry
UIN: 656353425
Date: 4/2/2024
Description: Keeps track of each store object in a vector. 
			 Useful for reading in all the stores info from the .txt file and 
			 anaylzing all of the stores information. 
*/

#ifndef STORES_H
#define STORES_H

#include <vector>
#include "Store.h"

class Stores {
public:
	void inputStoresInfo(std::string inputFileName);
	int getLargeStoreAmount() const;
	double getAvgSizeLargeStores() const;
	void printGeneralInfo();
	void printNeighborhoodsInfo() const;
	void printClosestStores(double latitude, double longitude) const;
	void printSearch(std::string storeName);
private:
	std::vector<Store> m_storesList;
};

#endif
