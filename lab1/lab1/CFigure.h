#pragma once
#include "stdafx.h"

class CFigure
{
public:
	CFigure();
	virtual ~CFigure();
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
};