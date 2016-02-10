#include "CFigure.h"
#include "CPoint.h"

class CRectangle final :public CFigure
{
public:
	CRectangle(CPoint p1, CPoint p2);
	~CRectangle();
	virtual double GetPerimeter() const override;
	virtual double GetArea() const override;
private:
	CPoint m_p1, m_p2;

};

