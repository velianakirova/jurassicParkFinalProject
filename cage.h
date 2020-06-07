#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
#include "dinosaur.h"
using namespace std;
#ifndef CAGE_H
#define CAGE_H


class Cage {
public:

	virtual void addNewDinosaur(const Dinosaur&) = 0;
	virtual void removeDinosaurFromCage(const char*) = 0;

	virtual bool isEmpty() = 0;
	virtual bool freeSpace() = 0;

	virtual string getCageType() const = 0;
	virtual char* getEra() const = 0;
	virtual char* getCategory() const = 0;

	virtual void setClimate(const char*) = 0;

	virtual void saveCage(ostream& out) = 0;
	virtual void saveDinosaurs(ostream& out) = 0;

	virtual void printInfo() const = 0;
	virtual int getCount() const = 0;
	virtual Dinosaur getDinosaurFromIndex(int index) = 0;

	static void removeDinosaur(const vector<Cage*>, const char*);
	virtual ~Cage();

};


#endif // !CAGE_H
