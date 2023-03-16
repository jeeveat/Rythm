#pragma once

class CauchyProblem;
class NumerousMethod
{
public:
	NumerousMethod();
	~NumerousMethod();
	virtual void solve(CauchyProblem&) = 0;
private:

};