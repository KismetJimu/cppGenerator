#ifndef __ABSTRACTGENERATORSTATE_H__
#define __ABSTRACTGENERATORSTATE_H__

class AbstractGeneratorState
{
public:
	void init(AbstractGeneratorState &state, int size);
	bool swap(int index1, int index2);

	virtual int get(int index) { return 0; };
	virtual int put(int index, int value) { return 0; };
};

#endif