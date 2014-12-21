#ifndef _EDO
#define _EDO
#include <utility>

using namespace std;

double metodoEuler(double (*f)(double x, double y), double xi, double xf,
		double y, double h);
double metodoRungaKutta2a(double f(double x, double y), double xi, double xf,
		double y, double h);
double metodoRungaKutta4a(double f(double x, double y), double xi, double xf,
		double y, double h);
double metodoEuler_melhorado(double (*f)(double x, double y), double xi,
		double xf, double yi, double h);

pair<double, double> sistemaEqDiferenciais1aOrd_RK(
		double f(double, double, double), double f2(double, double, double),
		double t, double mi, double mp, double h);

pair<double, double> sistemaEqDiferenciais1aOrd_Euler(
		double f(double, double, double), double f2(double, double, double),
		double t, double mi, double mp, double h);

#endif
