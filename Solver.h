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

class Solver
{
private:
    std::vector<Body> bodies;
    double dt;
//    const double G = 6.674 * pow(10,-11);
	const double G = 2;

public:
	Solver(const double &dt);

    void addBody(Body &body);

    void step();

	void considerTwoBodies(Body &body1, Body &body2);

	void saveBodyPositions(std::fstream &file);
};


#endif //DOUBLESTAR_SOLVER_H
