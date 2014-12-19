#include "constantes.h"


//metodo de euler
double metodoEuler(double(*f)(double x, double y), double xi, double xf, double y, double h) {
	unsigned n = (xf - xi) / h;

	for (size_t i = 0; i <= n; ++i) {
		y += h * f(xi, y);
		xi += h;
	}
	return y;
}

double metodoEuler_melhorado(double(*f)(double x, double y), double xi, double xf, double yi, double h) {

	/*unsigned n = (xf - xi) / h;
	double k1;
	double h2 = 0.5 * h;

	for (size_t i = 0; i <= n; ++i) {
	k1 = h2 * (*f)(xi, yi);
	yi += h * (*f)(xi + h2, yi + k1);
	xi += h;
	}

	return yi;*/

	double yf;
	yf = yi + f(xi, yi) * (xf - yi);
	yf = yi + (f(xi, yi) + f(xf, yf)) * 0.5 * (xf - xi);
	return yf;
}

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
/*double sistemaEqDiferenciais1aOrd(double f(double t, double mi), double f2(double mi, double mp), double mi, double mf, double h)
{
unsigned n = (xf - x) / h;

double deltak1, deltak2, deltak3, deltak4, deltay1, deltay2, deltay3, deltay4;

for (unsigned i = 0; i < n; i++)
{
deltay1 = h * f(x);
deltak1 = h * f2(x);

deltay2 = h * f(x + h / 2, y + deltay1 / 2, z + deltak1 / 2);
deltak2 = h * f2(x + h / 2, y + deltay1 / 2, z + deltak1 / 2);

deltay3 = h * f(x + h / 2, y + deltay2 / 2, z + deltak2 / 2);
deltak3 = h * f2(x + h / 2, y + deltay2 / 2, z + deltak2 / 2);

deltay4 = h * f(x + h, y + deltay3, z + deltak3);
deltak4 = h * f2(x + h, y + deltay3, z + deltak3);

x += h;
y += (1.0 / 6) * deltay1 + (1.0 / 3) * deltay2 + (1.0 / 3) * deltay3 + (1.0 / 6) * deltay4;
z += (1.0 / 6) * deltak1 + (1.0 / 3) * deltak2 + (1.0 / 3) * deltak3 + (1.0 / 6) * deltak4;
}

return 0;
}*/
