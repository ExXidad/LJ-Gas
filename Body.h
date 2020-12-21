//
// Created by mi on 08.10.2020.
//

#ifndef DOUBLESTAR_BODY_H
#define DOUBLESTAR_BODY_H

#include "MyTypedefs.h"

using namespace myTypedefs;

enum BodyTypes
{
	STATIC, DYNAMIC
};

class Body
{
private:
	BodyTypes m_bodyType;
	double m_m;
	vec2d m_r, m_v, m_f;
public:
	BodyTypes bodyType() const;

	void setBodyType(BodyTypes bodyType);

	double m() const;

	void setM(double mM);

	const vec2d &r() const;

	void setR(const vec2d &mR);

	const vec2d &v() const;

	void setV(const vec2d &mV);

	const vec2d &f() const;

	void setF(const vec2d &mF);

public:
	Body(const BodyTypes &bodyType, const double &m = 1, const vec2d &r0 = vec2d(0, 0), const vec2d &v0 = vec2d(0, 0));

	void move(const double &dt);
};


#endif //DOUBLESTAR_BODY_H
