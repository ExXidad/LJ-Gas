//
// Created by mi on 08.10.2020.
//

#include "Body.h"


Body::Body(const BodyTypes &bodyType, const double &m, const vec2d &r0, const vec2d &v0)
{
	m_bodyType = bodyType;
	m_m = m;
	m_r = r0;
	m_v = v0;
	m_f = vec2d(0, 0);
}

BodyTypes Body::bodyType() const
{
	return m_bodyType;
}

void Body::setBodyType(BodyTypes bodyType)
{
	Body::m_bodyType = bodyType;
}

double Body::m() const
{
	return m_m;
}

void Body::setM(double mM)
{
	m_m = mM;
}

const vec2d &Body::r() const
{
	return m_r;
}

void Body::setR(const vec2d &mR)
{
	m_r = mR;
}

const vec2d &Body::v() const
{
	return m_v;
}

void Body::setV(const vec2d &mV)
{
	m_v = mV;
}

const vec2d &Body::f() const
{
	return m_f;
}

void Body::setF(const vec2d &mF)
{
	m_f = mF;
}

void Body::move(const double &dt)
{
	m_v += m_f * dt;
	m_r += m_v * dt;
}

void Body::addF(const vec2d &dF)
{
	m_f += dF;
}

void Body::inverseXVelocity()
{
	m_v = vec2d(-m_v[0], m_v[1]);
}

void Body::inverseYVelocity()
{
	m_v = vec2d(m_v[0], -m_v[1]);
}