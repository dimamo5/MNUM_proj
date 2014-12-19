#include "constantes.h"
#include <cmath>

double metodoCorda(double f(double x), double x, double y){

	double w, xn, yn;

	if (f(x)*f(y) > 0) return -1;

	do {
		xn = x;
		yn = y;

		w = (x*f(y) - y*f(x)) / (f(y) - f(x));

		if (f(xn)*f(w) < 0){
			y = w;
		}
		else x = w;

	} while (abs(x - y) > epsilon);

	return x;
}

double metodoNewton(double f(double x), double diff(double x), double x){

	double xn;

	do {
		xn = x;

		if (diff(x) == 0) return -1;

		x += f(x) / diff(x);

	} while (abs(xn - x > epsilon));
}

double metodoBisseccao(double f(double), double a, double b) {

	if (f(a) * f(b) < 0) {

		while (abs(f(a) - f(b)) < epsilon) {

			double m = (a + b) / 2;

			if (f(a) * f(m) < 0) {
				b = m;
			}
			else {
				a = m;
			}
		}
	}
	return a;
}

double metodo_picardPeano(double f(double k), double f_diff(double x), double guess)
{
	double xn_;
	double anterior;
	do
	{
		xn_ = f(guess);
		anterior = guess;
		guess = xn_;

	} while (abs(xn_ - anterior) > epsilon);
	return xn_;
}
