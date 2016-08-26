// main.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Generator.h"
#include "BasicSparseGeneratorState.h"
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

unsigned long generate(int quantity, int maxSize)
{
	BasicSparseGeneratorState state(maxSize);
	Generator gen("thisone", maxSize, maxSize - 1, state);
	const int codesToGenerate = 1000000;
	vector<int> v(codesToGenerate);
	auto start = high_resolution_clock::now();
	for (int i = 0; i < codesToGenerate; ++i)
	{
		v[i] = gen.next();
	}
	auto end = high_resolution_clock::now();
	return duration_cast<milliseconds>(end - start).count();
}

int main(int argc, char* argv[])
{
	int maxSize = (int) pow(36, 5);
	const int codesToGenerate = 1000000;
	unsigned long durations = 0;
	int repeats = 10;
	for (int i = 0; i < repeats; ++i)
	{
		durations += generate(codesToGenerate, maxSize);
	}
	cout << "Done! Rate of: " << (repeats * codesToGenerate) / ( durations / 1000.0) << " Codes/sec"<< endl;
	return 0;
}

