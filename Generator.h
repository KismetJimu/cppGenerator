#ifndef __GENERATOR_H__
#define __GENERATOR_H__

#include <string>
#include "BasicSparseGeneratorState.h"

using namespace std;

class Generator {
	string id;
	int index;
	int maxSize;
	AbstractGeneratorState& state;

public:
	Generator(string id, int maxSize, int index, AbstractGeneratorState& state);

	string getId();

	int getIndex();

	int getMaxSize();

	AbstractGeneratorState& getState();

	bool hasNext();

	int next();

	bool release(int value);
};

#endif