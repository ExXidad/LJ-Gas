//
// Created by mi on 08.10.2020.
//

#include "Solver.h"

void Solver::addBody(Body &body)
{
	bodies.emplace_back(body);
}

void Solver::step()
{
	for (auto &body : bodies) {
		body.setF(vec2d(0, 0));
	}

	for (int i = 0; i < bodies.size(); ++i) {
		for (int j = i + 1; j < bodies.size(); ++j) {
			if (i != j) {
				considerTwoBodies(bodies[i], bodies[j]);
			}
		}
	}

	for (auto &body : bodies) {
		body.move(dt);
	}
}

void Solver::considerTwoBodies(Body &body1, Body &body2)
{
	vec2d r = body2.r() - body1.r();
	if (r.norm() == 0) throw std::bad_function_call();
	vec2d f = G * body1.m() * body2.m() / pow(r.norm(), 3) * r;
	body1.setF(body1.f() + f);
	body2.setF(body2.f() - f);
}

Solver::Solver(const double &dt)
{
	this->dt = dt;
}

void Solver::saveBodyPositions(std::fstream &file)
{
	for (auto &body : bodies) {
		file << body.r()[0] << "\t" << body.r()[1] << "\t";
	}
	file << std::endl;
}
