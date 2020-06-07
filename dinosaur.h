#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Dinosaur {
public:
	Dinosaur();
	Dinosaur(const char*, const char*, const char*, const char*, const char*, const char*);
	Dinosaur(const Dinosaur& other);
	Dinosaur& operator= (const Dinosaur& other);
	~Dinosaur();


	char* getName() const;
	char* getEra() const;
	char* getCategory() const;
	char* getFood() const;

	void setName(const char* Name);
	void setGender(const char* Gender);
	void setEra(const char* Era);
	void setCategory(const char* Category);
	void setKind(const char* Kind);
	void setFood(const char* Food);

	void saveDinosaur(ostream&);

	void printInfo() const;

private:
	char* name;
	char* gender;
	char* era;
	char* category;
	char* kind;
	char* food;
	void copy(const Dinosaur&);
	void erase();
};

