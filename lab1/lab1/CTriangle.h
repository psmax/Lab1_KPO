#include "CFigure.h"
#include "CPoint.h"

class CTriangle final : public CFigure
{
public:
	CTriangle(CPoint p1, CPoint p2, CPoint p3);
	~CTriangle();

	virtual double GetPerimeter() const override;
	virtual double GetArea() const override;
private:
	CPoint m_p1, m_p2, m_p3;
	static double GetLineLength(CPoint p1, CPoint p2);
};