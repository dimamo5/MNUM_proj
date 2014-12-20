#include "constantes.h"
#include <utility>
#include <cmath>

using namespace std;

//metodo de euler
double metodoEuler(double(*f)(double x, double y), double xi, double xf, double y, double h) {
	
	unsigned n = (xf - xi) / h;

	for (size_t i = 0; i <= n; ++i) {
		y += h * f(xi, y);
		xi += h;
	}
	return y;
}

/*double metodoEuler_melhorado(double(*f)(double x, double y), double xi, double xf, double yi, double h) {

	/*unsigned n = (xf - xi) / h;
	double k1;
	double h2 = 0.5 * h;

	for (size_t i = 0; i <= n; ++i) {
	k1 = h2 * (*f)(xi, yi);
	yi += h * (*f)(xi + h2, yi + k1);
	xi += h;
	}

	return yi;
}*/

//metodo Runga - Kutta 2a ordem
double metodoRungaKutta2a(double f(double x, double y), double xi, double xf, double y, double h) {
	unsigned n = (xf - xi) / h;

	for (size_t i = 0; i <= n; ++i) {
		y += h * f(xi + h / 2, y + h / 2 * f(xi, y));
		xi += h;
	}
	return y;
}

//metodo Runga - Kutta 4a ordem
double metodoRungaKutta4a(double f(double x, double y), double xi, double xf, double y, double h) {
	unsigned n = (xf - xi) / h;
	double deltaY1, deltaY2, deltaY3, deltaY4;

	for (size_t i = 0; i <= n; ++i) {
		deltaY1 = h * f(xi, y);
		deltaY2 = h * f(xi + h / 2, y + deltaY1 / 2);
		deltaY3 = h * f(xi + h / 2, y + deltaY2 / 2);
		deltaY4 = h * f(xi + h, y + deltaY3);
		xi += h;
		y += (1.0 / 6) * deltaY1 + (1.0 / 3) * deltaY2 + (1.0 / 3) * deltaY3 + (1.0 / 6) * deltaY4;

		deltaY3 + (1.0 / 6) * deltaY4;
	}
	return y;
}

//resolve sistema eq difs
pair<double, double> sistemaEqDiferenciais1aOrd_RK(double f(double t, double mi, double mp, double ka), double f2(double t, double mi, double mp, double ka), double t, double ka, double mi, double mp, double h) {
	
	unsigned n = abs(t - 30*24*60) / h;
	pair<double, double> sol;

	double deltak1, deltak2, deltak3, deltak4, deltay1, deltay2, deltay3, deltay4;

	for (unsigned i = 0; i < n; i++)
	{
		deltay1 = h * f(t, mi, mp, ka);
		deltak1 = h * f2(t, mi,mp, ka);

		deltay2 = h * f(t + h / 2, mi + deltay1 / 2, mp + deltak1 / 2,ka);
		deltak2 = h * f2(t + h / 2, mi + deltay1 / 2, mp + deltak1 / 2, ka);

		deltay3 = h * f(t + h / 2, mi + deltay2 / 2, mp + deltak2 / 2, ka);
		deltak3 = h * f2(t + h / 2, mi + deltay2 / 2, mp + deltak2 / 2, ka);

		deltay4 = h * f(t + h, mi + deltay3, mp + deltak3, ka);
		deltak4 = h * f2(t + h, mi + deltay3, mp + deltak3, ka);

		t += h;
		mi += (1.0 / 6) * deltay1 + (1.0 / 3) * deltay2 + (1.0 / 3) * deltay3 + (1.0 / 6) * deltay4;
		mp += (1.0 / 6) * deltak1 + (1.0 / 3) * deltak2 + (1.0 / 3) * deltak3 + (1.0 / 6) * deltak4;

		sol.first = mi; 
		sol.second = mp;
	}
	return sol;
}

pair<double, double> sistemaEqDiferenciais1aOrd_EULER(double f(double t, double mi, double mp, double ka), double f2(double t, double mi, double mp, double ka), double t, double ka, double mi, double mp, double h){
	
	unsigned n = abs(t - 30 * 24 * 60) / h;
	pair<double, double> sol;

	double deltak1, deltak2, deltak3, deltak4, deltay1, deltay2, deltay3, deltay4;

	for (unsigned i = 0; i < n; i++)
	{
		t += h;
		mi += h * f(t,mi,mp,ka);
		mp += h* f2(t,mi,mp,ka);

		sol.first = mi;
		sol.second = mp;
	}
	return sol;
	

}