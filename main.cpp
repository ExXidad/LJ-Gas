#include <iostream>
#include <fstream>
#include "Body.h"
#include "Solver.h"
#include "MyTypedefs.h"
#include "BoundingRect.h"
#include <random>
#include <ctime>
#include <string>

int main()
{
	// All distance vars are dimensionless r' = r / sigma
	double eps = 100;
	double sigma = 1;
	double dt = 0.005;

	int NX = 50, NY = 50;
	double xSize = 500, ySize = 500;
	double hx = xSize / (NX + 1), hy = ySize / (NY + 1);

	BoundingRect boundingRect(0, xSize, 0, ySize);

	Solver solver(boundingRect, dt, sigma, eps);

	std::mt19937 gen(time(nullptr));
	std::uniform_real_distribution<> randomPhi(0, 2 * M_PI);
	double v0 = 1;

	for (int j = 1; j < NY + 1; ++j)
	{
		for (int i = 1; i < NX + 1; ++i)
		{
			double phi = randomPhi(gen);
			solver.addBody(
					Body(
							DYNAMIC,
							1,
							vec2d(i * hx, j * hy),
							v0 * vec2d(cos(phi), sin(phi))
					)
			);
		}
	}

	std::fstream file;

	for (int i = 0; i <= 200000; ++i)
	{
		if (i % 200 == 0)
		{
			file.open(std::to_string(i), std::ios::out);
			solver.saveBodies(file);
			file.close();
			std::cout << solver.computeEnergy() << std::endl;
		}
		solver.step();
	}

	return 0;
}