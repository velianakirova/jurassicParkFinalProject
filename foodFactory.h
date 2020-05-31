#pragma once
#include "cage.h"
#include "smallCage.h"
#include "mediumCage.h"
#include "largeCage.h"
using namespace std;
#ifndef FOODFACTORY_H
#define FOODFACTORY_H

class Warehouse {
public:
	void storeFood(const char*);
	bool isEqual(const char*, const char*);
	Warehouse() : grass(0), meat(0), fish(0) {};
	void printInfo() const;

private:
	int grass;
	int meat;
	int fish;
};

#endif // !FOODFACTORY_H