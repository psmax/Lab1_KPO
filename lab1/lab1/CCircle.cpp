#include "stdafx.h"
#include "CCircle.h"



CCircle::CCircle(CPoint p, double radius)
	: m_radius(radius)
	, m_p(p)
{
}


CCircle::~CCircle()
{
}

double CCircle::GetPerimeter() const
{
	return 2 * m_radius * PI;
}

double CCircle::GetArea() const
{
	return PI * pow(m_radius, 2);
}
