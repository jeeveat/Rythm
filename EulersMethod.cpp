#include "EulersMethod.h"

EulersMethod::EulersMethod()
{
	timeStep = pow(10, -3);
	TStep = pow(10, -3);
	dT = 0.2;
}


void EulersMethod::diff(double& x, double& y, double& vx, double& vy)
{

}

void EulersMethod::solve(CauchyProblem& problem)
{
	std::ofstream fout;
	fout.open("file.txt");

	double x_temp;
	double y_temp;
	double vx_temp;
	double vy_temp;
	double g;
	dT = problem.m * (problem.g + problem.vx * problem.vx / problem.L);
	//problem.T = getTWithEnumeration(problem);
	problem.T = getTWithGradient(problem);
	dT = 0.1;
	for (double t = 0; t < problem.timeExperiment; t += timeStep)
	{
		x_temp = problem.x;
		y_temp = problem.y;
		vx_temp = problem.vx;
		vy_temp = problem.vy;
		problem.g = problem.getG(t);

		//Choose beetwen methods to find T in iteration
		//problem.T = getTWithEnumeration(problem);
		problem.T = getTWithGradient(problem);

		problem.ax = -problem.x / problem.L * problem.T / problem.m;
		problem.ay = -problem.y / problem.L * problem.T / problem.m - problem.g;

		problem.vy += problem.ay * timeStep;
		problem.vx += problem.ax * timeStep;

		problem.x += problem.vx * timeStep;
		problem.y += problem.vy * timeStep;
		fout << problem.x << " " << problem.y << " "<<t<< std::endl;
	}
	fout.close();
}

double EulersMethod::getTWithEnumeration(CauchyProblem& problem)
{
	double x_temp;
	double y_temp;
	double vx_temp;
	double vy_temp;
	double ax;
	double ay;
	double min_ = 1000;
	double T_best = problem.T;
	for (double T_temp = problem.T-dT; T_temp < problem.T+ dT; T_temp += TStep)
	{
		x_temp = problem.x;
		y_temp = problem.y;
		vx_temp = problem.vx;
		vy_temp = problem.vy;
		ax = -x_temp / problem.L * T_temp / problem.m;
		ay = -y_temp / problem.L * T_temp / problem.m - problem.g;

		vy_temp += ay * timeStep;
		vx_temp += ax * timeStep;

		x_temp += vx_temp * timeStep;
		y_temp += vy_temp * timeStep;

		if (min_ > abs(problem.L * problem.L - x_temp * x_temp - y_temp * y_temp))
		{
			T_best = T_temp;
			min_ = abs(problem.L * problem.L - x_temp * x_temp - y_temp * y_temp);
		}
		//std::cout << L * L - x_temp * x_temp - y_temp * y_temp << " " << T_temp << std::endl;
	}
	return T_best;
}

double EulersMethod::getTWithGradient(CauchyProblem& problem)
{

	double T1 = problem.T, T_temp = T1 + 0.05;
	double F1, F2 = abs(problem.L * problem.L - problem.x * problem.x - problem.y * problem.y);
	double x_temp;
	double y_temp;
	double vx_temp;
	double vy_temp;
	double ax;
	double ay;
	double lambda = pow(10, 2);
	double T_help;
	double proiz;
	bool flag = false;
	int i = 1;
	double T_past = problem.T;
	while (abs(T_temp - T1) > pow(10, -4) )
	{
		F1 = F2;
		x_temp = problem.x;
		y_temp = problem.y;
		vx_temp = problem.vx;
		vy_temp = problem.vy;
		ax = -x_temp / problem.L * T_temp / problem.m;
		ay = -y_temp / problem.L * T_temp / problem.m - problem.g;

		vy_temp += ay * timeStep;
		vx_temp += ax * timeStep;

		x_temp += vx_temp * timeStep;
		y_temp += vy_temp * timeStep;

		F2 = abs(problem.L * problem.L - x_temp * x_temp - y_temp * y_temp);
		//std::cout << F2<<" "<<T2 << std::endl;
		T_help = T_temp;
		proiz = (F2 - F1) / (T_temp - T1);
		T_temp = T_temp - lambda * proiz;
		if (i % 10 == 0)
		{
			if (abs(T_temp - T_past) < 2*pow(10, -3))
				break;
			T_past = T_temp;
		}
		i++;
		T1 = T_help;
	}
	return T_temp;
}

EulersMethod::~EulersMethod()
{

}