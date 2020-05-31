#pragma once
#include "cage.h"

class LargeCage : public Cage {
private:
	Dinosaur* dinosaur;
	size_t count;
	size_t capacity;
	char* category;
	char* era;
	char* climate;
	void copy(const LargeCage&);
	void erase();

public:
	LargeCage(const char* climate);
	LargeCage(const LargeCage&);
	LargeCage& operator=(const LargeCage&);
	~LargeCage();

	bool isEqual(const char*, const char*);

	string getCageType() const;
	char* getClimate() const;
	char* getEra() const;
	char* getCategory() const;
	int getCount() const;
	Dinosaur getDinosaurFromIndex(int index);

	void saveCage(ostream&);

	void saveDinosaurs(ostream&);


	void setClimate(const char*);
	void setEra(const char*);
	void setCategory(const char*);

	bool isEmpty();
	bool freeSpace();

	void removeDinosaurFromCage(const char*);
	void addNewDinosaur(const Dinosaur&);
	void printInfo()const;
};