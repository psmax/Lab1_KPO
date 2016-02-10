#pragma once

#include "CFigure.h"
#include "CPoint.h"

class CCircle final : public CFigure
{
public:
	CCircle(CPoint p, double radius);
	~CCircle();

	virtual double GetPerimeter() const override;
	virtual double GetArea() const override;
private:
	double m_radius;
	CPoint m_p;
	const double PI = 3.14159265;
};