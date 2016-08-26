// main.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Generator.h"
#include "BasicSparseGeneratorState.h"
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int main(int argc, char* argv[])
{
	int maxSize = (int) pow(36, 5);
	BasicSparseGeneratorState state(maxSize);
	Generator gen("thisone", maxSize, maxSize - 1, &state);
	const int codesToGenerate = 1000000;
	vector<int> v(codesToGenerate);
	auto start = high_resolution_clock::now();
	for (int i = 0; i < codesToGenerate; ++i)
	{
		v[i] = gen.next();
	}
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start).count();
	cout << v[codesToGenerate - 1] << endl;
	cout << "Done! Rate of: " << codesToGenerate / ( duration / 1000.0) << " Codes/sec"<< endl;
	return 0;
}

