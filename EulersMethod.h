#pragma once
#include<math.h>
#include "NumerousMethod.h"
#include "CauchyProblem.h"
#include <fstream>
class EulersMethod:public NumerousMethod
{
public:
	EulersMethod();
	~EulersMethod();
	void solve(CauchyProblem&)override;
	double getTWithEnumeration(CauchyProblem& problem);
	double getTWithGradient(CauchyProblem& problem);
	void diff(double& x, double& y, double& vx, double& vy);
private:
	double timeStep;
	double TStep;
	double dT;
};
