#ifndef _EDO
#define _EDO
#include <utility>

using namespace std;

double metodoEuler(double(*f)(double x, double y), double xi, double xf, double y, double h);
double metodoRungaKutta2a(double f(double x, double y), double xi, double xf, double y, double h);
double metodoRungaKutta4a(double f(double x, double y), double xi, double xf, double y, double h);
pair<double, double> sistemaEqDiferenciais1aOrd_RK(double f(double t, double mi,double mp, double ka), double f2(double y, double mi, double mp, double ka), double t, double ka, double mi, double mp, double h);
pair<double, double> sistemaEqDiferenciais1aOrd_EULER(double f(double t, double mi, double mp, double ka), double f2(double t, double mi, double mp, double ka), double t, double ka, double mi, double mp, double h);
#endif