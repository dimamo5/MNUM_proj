#include "constantes.h"
#include <cmath>
#include <iostream>
#include<iomanip>

using namespace std;

double metodoCorda(double f(double), double x1, double x2) {
	double h = 0, x_temp = 0;

	while (h < 20) {
		double w = (x1 * f(x2) - x2 * f(x1) / (f(x2) - f(x1)));
		if (f(x1) * f(w) < 0)
			x2 = w;
		else {
			x1 = w;
		}

		if (x_temp == x2) {
			h++;
		} else {
			h = 0;
		}
		x_temp = x2;
	}

	return x2;
}

double metodoNewton(double f(double ka), double diff(double ka), double x) {

	double xn;

	do {
		xn = x;
		cout << x << endl;
		if (diff(x) == 0.0)
			return -1;

		x -= f(x) / diff(x);
	} while (abs(xn - x) > epsilon);

	return x;
}

double metodoBisseccao(double f(double), double a, double b) {
	double m = 0;

	while (abs(a - b) > epsilon) {

		m = (a + b) / 2;

		if (f(a) * f(m) < 0) {
			b = m;
		} else {
			a = m;
		}
	}
	return a;
}

double metodo_picardPeano(double f(double k), double f_diff(double x),
		double guess) {
	double xn_;
	double anterior;
	do {
		xn_ = f(guess);
		anterior = guess;
		guess = xn_;

	} while (abs(xn_ - anterior) > epsilon);
	return xn_;
}
