#include "AbstractGeneratorState.h"

void AbstractGeneratorState::init(AbstractGeneratorState &state, int size)
{
	for (int i = 0; i < size; i++)
	{
		put(i, state.get(i));
	}
}

bool AbstractGeneratorState::swap(int index1, int index2)
{
	int a = get(index1);
	int b = get(index2);
	put(index1, b);
	put(index2, a);
	return true;
}
