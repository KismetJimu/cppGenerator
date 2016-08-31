#include "BasicSparseGeneratorState.h"
#include "AbstractGeneratorState.h"
#include <map>

using namespace std;

BasicSparseGeneratorState::BasicSparseGeneratorState(int size) {

}

/*BasicSparseGeneratorState::BasicSparseGeneratorState(AbstractGeneratorState state, int size)
{
init(state, size);
}*/

int BasicSparseGeneratorState::get(int index) {
	auto i = map.find(index);
	if (i != map.end()) {
		return i->second;
	} else {
		return index;
	}
}

int BasicSparseGeneratorState::put(int index, int value) {
	int existing;
	/*auto i = map.find(index);
	if (i != map.end()) {
		existing = i->second;
		map.erase(i);
	} else {
		existing = index;
	}

	if (index != value) {
		map[index] = value;
	} else if (index == value && index != existing) {
		map.erase(index);
	}

	return existing;*/
	auto i = map.find(index);
	if (i != map.end()) {
		existing = i->second;
		if (index != value) {
			i->second = value;
		} else {
			map.erase(i);
		}
	} else {
		existing = index;
		if (index != value)
			map.insert(std::make_pair(index, value));
	}

	return existing;
}