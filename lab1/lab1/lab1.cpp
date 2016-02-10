#include "stdafx.h"
#include <algorithm>
#include <memory>

#include "CFigure.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"

using namespace std;

shared_ptr<CFigure> AddFigure();
vector<shared_ptr<CFigure>> Figure;

typedef shared_ptr<CFigure> CFigurePointer;

CPoint ParserPoint(string &paramsStr)
{
	vector<int> args;
	CPoint p;
	const string symbols = " ,:;CR=P";
	size_t e, b;
	e = 0;
	while ((b = paramsStr.find_first_not_of(symbols, e)) != paramsStr.npos)
	{
		e = paramsStr.find_first_of(symbols, b);
		args.push_back(stoi(paramsStr.substr(b, e - b)));
		b = e;
	}
	if (args.size() == 3)
	{
		p.x = args[1];
		p.y = args[2];
	}
	else if (args.size() == 2)
	{
		p.x = args[0];
		p.y = args[1];
	}
	else if (args.size() == 1)
	{
		p.radius = args[0];
	}
	return p;
}

shared_ptr<CFigure> CreateTriangle(ifstream &file)
{
	vector<CPoint> points;
	while (points.size() != 3)
	{
		string paramsStr;
		file >> paramsStr;
		points.push_back(ParserPoint(paramsStr));
	}
	return make_shared<CTriangle>(points[0], points[1], points[2]);
}

shared_ptr<CFigure> CreateRectangle(ifstream &file)
{
	vector<CPoint> points;
	while (points.size() != 2)
	{
		string paramsStr;
		file >> paramsStr;
		points.push_back(ParserPoint(paramsStr));
	}
	return make_shared<CRectangle>(points[0], points[1]);
}

shared_ptr<CFigure> CreateCircle(ifstream &file)
{
	vector<CPoint> points;
	double radius;
	while (points.size() != 2)
	{
		string paramsStr;
		file >> paramsStr;
		points.push_back(ParserPoint(paramsStr));
	}
	return make_shared<CCircle>(points[0], points[1].radius);
}



shared_ptr<CFigure> AddBody(string const & typeBody, ifstream &file)
{
	shared_ptr<CFigure> body;

	if (typeBody == "TRIANGLE:")
	{
		body = CreateTriangle(file);
	}
	else if (typeBody == "RECTANGLE:")
	{
		body = CreateRectangle(file);
	}
	else if (typeBody == "CIRCLE:")
	{
		body = CreateCircle(file);
	}

	return body;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string inFile = "input.txt";
	string outputStr = "output.txt";
	ifstream file(inFile);
	ofstream outFile(outputStr);

	shared_ptr<CFigure> body;

	if (!file)
	{
		return false;
	}
	while (!file.eof())
	{
		string typeBody;
		file >> typeBody;
		body = AddBody(typeBody, file);
		outFile << typeBody << " P = " << body->GetPerimeter() << "; S = " << body->GetArea() << endl;
	}

	return 0;
}

