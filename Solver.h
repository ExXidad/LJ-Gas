//
// Created by mi on 08.10.2020.
//

#ifndef DOUBLESTAR_SOLVER_H
#define DOUBLESTAR_SOLVER_H

#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include "Body.h"
#include "BoundingRect.h"

class Solver
{
private:
	BoundingRect *boundingRect;
	std::vector<Body> bodies;
	double dt;
	double sigma, eps;
	double rCrit;

	double P;

private:
	inline double bodyToBodyDistance(Body &body1, Body &body2);

	void considerTwoBodies(Body &body1, Body &body2);

public:
	Solver(BoundingRect &boundingRect, const double &dt,const double &sigma, const double &eps, const double &rCrit = 2.5);

	void addBody(const Body &body);

	void step();

	void saveBodyPositions(std::fstream &file);

	void saveBodies(std::fstream &file);

	double computeEnergy();
};


#endif //DOUBLESTAR_SOLVER_H
