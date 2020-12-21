#include <iostream>
#include <fstream>
#include "Body.h"
#include "Solver.h"
#include "MyTypedefs.h"

int main()
{
	Body body1(DYNAMIC, 1, vec2d(-1, 0), vec2d(0.5, 0.5));
	Body body2(DYNAMIC, 1, vec2d(1, 0), vec2d(-0.5, -0.5));

	Solver solver(0.01);
	solver.addBody(body1);
	solver.addBody(body2);

	std::fstream file;

	file.open("data.txt", std::ios::out);

	file << 1 << "\t" << 1 << "\t" << std::endl;
	solver.saveBodyPositions(file);

	for (int i = 0; i < 1000; ++i) {
		solver.step();
		solver.saveBodyPositions(file);
	}

	file.close();

	return 0;
}