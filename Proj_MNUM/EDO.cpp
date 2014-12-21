#include "constantes.h"
#include "EDO.h"
#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <fstream>

using namespace std;

//metodo de euler
double metodoEuler(double (*f)(double x, double y), double xi, double xf,
		double y, double h) {
	ofstream file;
	file.open("graphico_cp.txt");
	unsigned n = (xf - xi) / h;
	for (size_t i = 0; i <= n; ++i) {
		y += h * f(xi, y);
		file << setprecision(8) << fixed << y << endl;
		xi += h;
	}

	return y;
}

double metodoEuler_melhorado(double (*f)(double x, double y), double xi,
		double xf, double yi, double h) {

	double pn, dp, y_next, dy = f(xi, yi);
	double y_ant = yi;
	double y = metodoEuler(f, xi, xi + h, yi, h);
	std::cout << "\ncoco:" << y << std::endl;

	unsigned n = (xf - xi) / h;
	std::cout << "\n" << n << std::endl;

	for (size_t i = 0; i <= n; ++i) {

		pn = y_ant + 2 * h * dy;
		xi += h; //xn+1
		dp = f(xi, pn);

		y_next = y + (dp + dy) / 2;
		dy = f(xi, y_next);

		y_ant = y;
		y = y_next;
//		std::cout<<"valor"<<dy<<std::endl;
	}

	return y;
}

//metodo Runga - Kutta 2a ordem
double metodoRungaKutta2a(double f(double x, double y), double xi, double xf,
		double y, double h) {
	unsigned n = (xf - xi) / h;

	for (size_t i = 0; i <= n; ++i) {
		y += h * f(xi + h / 2, y + h / 2 * f(xi, y));
		xi += h;
	}
	return y;
}

//metodo Runga - Kutta 4a ordem
double metodoRungaKutta4a(double f(double x, double y), double xi, double xf,
		double y, double h) {
	unsigned n = (xf - xi) / h;
	double deltaY1, deltaY2, deltaY3, deltaY4;

	for (size_t i = 0; i <= n; ++i) {
		deltaY1 = h * f(xi, y);
		deltaY2 = h * f(xi + h / 2, y + deltaY1 / 2);
		deltaY3 = h * f(xi + h / 2, y + deltaY2 / 2);
		deltaY4 = h * f(xi + h, y + deltaY3);
		xi += h;
		y += (1.0 / 6) * deltaY1 + (1.0 / 3) * deltaY2 + (1.0 / 3) * deltaY3
				+ (1.0 / 6) * deltaY4;

	}
	return y;
}

pair<double, double> sistemaEqDiferenciais1aOrd_RK(
		double f(double, double, double), double f2(double, double, double),
		double t, double mi, double mp, double h) {
	ofstream file_mi, file_mp;
	file_mi.open("graphico_mi.txt");
	file_mp.open("graphico_mp.txt");

	unsigned n = abs(t - 24 * 60) / h;
	pair<double, double> sol;

	double deltak1, deltak2, deltak3, deltak4, deltay1, deltay2, deltay3,
			deltay4;

	for (unsigned i = 0; i < n; i++) {

		deltay1 = h * f(t, mi, mp);
		deltak1 = h * f2(t, mi, mp);

		deltay2 = h * f(t + h / 2, mi + deltay1 / 2, mp + deltak1 / 2);
		deltak2 = h * f2(t + h / 2, mi + deltay1 / 2, mp + deltak1 / 2);

		deltay3 = h * f(t + h / 2, mi + deltay2 / 2, mp + deltak2 / 2);
		deltak3 = h * f2(t + h / 2, mi + deltay2 / 2, mp + deltak2 / 2);

		deltay4 = h * f(t + h, mi + deltay3, mp + deltak3);
		deltak4 = h * f2(t + h, mi + deltay3, mp + deltak3);

		t += h;
		mi += (1.0 / 6) * deltay1 + (1.0 / 3) * deltay2 + (1.0 / 3) * deltay3
				+ (1.0 / 6) * deltay4;
		mp += (1.0 / 6) * deltak1 + (1.0 / 3) * deltak2 + (1.0 / 3) * deltak3
				+ (1.0 / 6) * deltak4;
		file_mi << setprecision(10) << fixed << mi << endl;
		file_mp << setprecision(10) << fixed << mp << endl;

		sol.first = mi;
		sol.second = mp;
//		cout<<i<<endl;
	}
	return sol;
}

pair<double, double> sistemaEqDiferenciais1aOrd_Euler(
		double f(double, double, double),
		double f2(double, double, double), double t, double mi,
		double mp, double h) {

	ofstream file_mi, file_mp;
	file_mi.open("graphico_mi.txt");
	file_mp.open("graphico_mp.txt");

	unsigned n = abs(t - 30 * 24 * 60) / h;
	pair<double, double> sol;

	for (unsigned i = 0; i < n; i++) {
		t += h;
		mi += h * f(t, mi, mp);
		mp += h * f2(t, mi, mp);
		sol.first = mi;
		sol.second = mp;
		cout << "\ncoco1:" << (ka) << endl;
		cout << "\ncoco2:" << (mi) << endl;
		file_mi << setprecision(10) << fixed << mi << endl;
		file_mp << setprecision(10) << fixed << mp << endl;
	}
	return sol;

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
