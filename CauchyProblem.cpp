#include "CauchyProblem.h"
#include "NumerousMethod.h"
CauchyProblem::CauchyProblem()
{
	x = 3;
	y = -4;
	vx = 0;
	vy = 0;
	ax = 0;
	ay = 0;
	L = 5;
	time = 0;
	g = 9.81;// +0.05 * sin(2 * pi * time);
	T = 0;
	m = 1;
	timeExperiment = 100;
}

void CauchyProblem::solve(NumerousMethod& method)
{
	method.solve(*this);
}

double CauchyProblem::getG(double time)
{
	return 9.81 +0.05 * sin(2 * pi * time);
}

CauchyProblem::~CauchyProblem()
{

}