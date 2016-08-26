#include "Generator.h"
#include <ctime>

Generator::Generator(string id, int maxSize, int index, AbstractGeneratorState& state) : id(id), maxSize(maxSize), index(index), state(state)
{
	srand(time(NULL));
}

string Generator::getId() { return this->id; }

int Generator::getIndex() { return this->index; }

int Generator::getMaxSize() { return this->maxSize; }

AbstractGeneratorState& Generator::getState() { return this->state; }

bool Generator::hasNext() {	return index > 0; }

int Generator::next() {
	if (index == 0)
	{
		return state.get(index--);
	}
	int rndIdx = rand() % index;
	state.swap(rndIdx, index);
	int value = state.get(index--);
	return value;
}

bool Generator::release(int value)
{
	int curIndex = index + 1;
	int maxIndex = maxSize - 1;

	while (curIndex <= maxIndex && state.get(curIndex) != value)
	{
		++curIndex;
	}
	if (curIndex <= maxIndex)
	{
		state.swap(curIndex, ++index);
		return true;
	}
	return false;
}
