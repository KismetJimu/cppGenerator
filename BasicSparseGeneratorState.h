#ifndef __BASICSPARSEGENERATORSTATE_H__
#define __BASICSPARSEGENERATORSTATE_H__

#include <map>
#include <unordered_map>
#include "AbstractGeneratorState.h"
using namespace std;

class BasicSparseGeneratorState : public AbstractGeneratorState
{
	//map<int, int> map;
	unordered_map<int, int> map;
public:
	BasicSparseGeneratorState(int size);
	//BasicSparseGeneratorState(AbstractGeneratorState state, int size);

	int get(int index);
	int put(int index, int value);
};

#endif