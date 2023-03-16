#include<iostream>
#include <iomanip>
#include <fstream>
#include "EulersMethod.h"
#include "CauchyProblem.h"

int main()
{
	EulersMethod method;
	CauchyProblem *equation = new CauchyProblem();
	equation->solve(method);

	return 0;
}