#pragma once
#include<math.h>
#include <iomanip>
#include <fstream>
#define pi 3.14159

class NumerousMethod;
class CauchyProblem
{
public:
	CauchyProblem();
	double getG(double time);
	~CauchyProblem();
	void solve(NumerousMethod& a);
	double time;
	double x;
	double y ;
	double vx;
	double vy;
	double ax;
	double ay;
	double g;
	double T;
	double L;
	double m;
	double timeExperiment;
private:
};