//
// Created by mi on 08.10.2020.
//

#include "Solver.h"

void Solver::addBody(const Body &body)
{
	bodies.emplace_back(body);
}

void Solver::step()
{
	for (auto &body : bodies)
	{
		body.setF(vec2d(0, 0));
	}

	P = 0;

	for (int i = 0; i < bodies.size(); ++i)
	{
		for (int j = i + 1; j < bodies.size(); ++j)
		{
			if (i != j && bodyToBodyDistance(bodies[i], bodies[j]) <= rCrit)
			{
				considerTwoBodies(bodies[i], bodies[j]);
			}
		}
	}

	for (auto &body : bodies)
	{
		body.move(dt);
		vec2d r = body.r();
		if (r[0] > boundingRect->getXSize() || r[0] < 0)
		{
			body.inverseXVelocity();
		}
		if (r[1] > boundingRect->getYSize() || r[1] < 0)
		{
			body.inverseYVelocity();
		}
	}
}

void Solver::considerTwoBodies(Body &body1, Body &body2)
{
	// U(r) = 4 eps ((sigma/r)^12 - (sigma/r)^6)
	// r'= r / sigma
	// U(r') = 4 eps ((1/r')^12 - (1/r')^6)
	// F(r) = - grad F(r)
	// F(r') = 24 eps / sigma (2 / r'^13 - 1 / r'^7)
	double r = bodyToBodyDistance(body1, body2);
	if (r == 0)
	{
		return;
	}
	vec2d f = (24 * eps / sigma * (2 / pow(r, 13) - 1 / pow(r, 7))) * (body2.r() - body1.r());
	body1.addF(f);
	body2.addF(-f);
	P += 4 * eps * (1 / pow(r, 12) - 1 / pow(r, 6));
}

Solver::Solver(BoundingRect &boundingRect, const double &dt, const double &sigma, const double &eps,
			   const double &rCrit)
{
	this->dt = dt;
	this->eps = eps;
	this->rCrit = rCrit;
	this->sigma = sigma;
	this->boundingRect = &boundingRect;
}

void Solver::saveBodyPositions(std::fstream &file)
{
	for (auto &body : bodies)
	{
		file << body.r()[0] << "\t" << body.r()[1] << "\t";
	}
	file << std::endl;
}

double Solver::bodyToBodyDistance(Body &body1, Body &body2)
{
	return (body1.r() - body2.r()).norm();
}

void Solver::saveBodies(std::fstream &file)
{
	for (auto &body : bodies)
	{
		file << body.r()[0] << "\t" << body.r()[1] << "\t" << body.v()[0] << "\t" << body.v()[1] << std::endl;;
	}
}

double Solver::computeEnergy()
{
	double K = 0;
	for (auto &body : bodies)
	{
		K += body.m() * pow(body.v().norm(), 2) / 2;
	}

	return P + K;
}

