#pragma once
#include "cage.h"

void Cage::removeDinosaur(const vector<Cage*> cages, const char* name) {

	for (int i = 0; i < cages.size(); i++) {
		cages[i]->removeDinosaurFromCage(name);
	}
}

Cage::~Cage() {

}
