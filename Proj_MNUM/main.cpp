#include <iostream>
#include <cmath>
#include <cstdlib>
#include "constantes.h"

using namespace std;

double Dose(unsigned int t);
double metodoEuler(double (*f)(double x, double y), double xi, double xf,double y, double h);
double metodoRungaKutta2a(double f(double x, double y), double xi, double xf,double y, double h);
double metodoRungaKutta4a(double f(double x, double y), double xi, double xf,double y, double h);
double sistemaEqDiferenciais1aOrd(double f(double x), double f2(double y), double x, double xf, double h);
double metodoCorda(double f(double x), double x, double y);
double metodoNewton(double f(double x), double diff(double x), double x, double y);

void comp_central();
double f_comp_central(double t, double cp);
double f_bicomp_central(double t, double cp);

int main() {
	srand(1); //sempre que o programa executa gera os mesmos valores

//	double h = 0.1;
//
//	cout << "metodoEuler: " << metodoEuler(f_comp_central, 0, 30 * 24 * 60, Cp0, h) << endl;
//	cout << "Metodo Runga kutta 2a: " << metodoRungaKutta2a(f_comp_central, 0, 30 * 24 * 60, Cp0, h) << endl;
//	cout << "Metodo Runga kutta 4a: " << metodoRungaKutta4a(f_comp_central, 0, 30 * 24 * 60, Cp0, h) << endl;
	comp_central();

	system("Pause");
}

double f_comp_central(double t, double cp) {

	return (Dose(t) - Ke * cp) / Vap;
}

/*
 { 100/60 ,  0 << t << 60
 D(t) {
 { 400/((rand % 3 + 4)*60) ,  60 < t << 360  -> 6h -> 360 minutos : tempo maximo possivel
 t = minutos
 */

double Dose(unsigned int t) {
	t = t % (60 * 24); //adaptacao para verificacao diaria

	if (t >= 0 && t <= 60) {   //1 ramo da funcao dt

		return (double) 100 / 60;
	}

	else if (t > 60 && t <= 360) { //2 ramo da funcao dt

		return (double) 400 / (horas_geradas * 60); //determinacao de 	uma hora aleatoria entre[4, 6]
	} else
		return 0;
}

//metodo de euler
double metodoEuler(double (*f)(double x, double y), double xi, double xf,double y, double h) {
	unsigned n = (xf - xi) / h;

	for (size_t i = 0; i <= n; ++i) {
		y += h * f(xi, y);
		xi += h;
	}
	return y;
}

double metodoEuler_melhorado(double (*f)(double x, double y), double xi,double xf, double yi, double h) {

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
	     yf = yi + f(xi,yi)*(xf-yi);
	     yf = yi + (f(xi,yi)+f(xf,yf))*0.5*(xf-xi);
	   return yf;
}

//metodo Runga - Kutta 2a ordem
double metodoRungaKutta2a(double f(double x, double y), double xi, double xf,double y, double h) {
	unsigned n = (xf - xi) / h;

	for (size_t i = 0; i <= n; ++i) {
		y += h * f(xi + h / 2, y + h / 2 * f(xi, y));
		xi += h;
	}
	return y;
}

//metodo Runga - Kutta 4a ordem
double metodoRungaKutta4a(double f(double x, double y), double xi, double xf,double y, double h) {
	unsigned n = (xf - xi) / h;
	double deltaY1, deltaY2, deltaY3, deltaY4;

	for (size_t i = 0; i <= n; ++i) {
		deltaY1 = h * f(xi, y);
		deltaY2 = h * f(xi + h / 2, y + deltaY1 / 2);
		deltaY3 = h * f(xi + h / 2, y + deltaY2 / 2);
		deltaY4 = h * f(xi + h, y + deltaY3);
		xi += h;
		y += (1.0 / 6) * deltaY1 + (1.0 / 3) * deltaY2 + (1.0 / 3) *

		deltaY3 + (1.0 / 6) * deltaY4;
	}
	return y;
}

//resolve sistema eq difs
double sistemaEqDiferenciais1aOrd(double f(double x), double f2(double y), double x, double xf, double h)
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
}

//=====================

double metodoCorda(double f(double x), double x, double y){

	double w, xn, yn;

	if (f(x)*f(y) > 0) return -1;

	do {
		xn = x;
		yn = y;

		w = (x*f(y) - y*f(x)) / (f(y) - f(x));				if (f(xn)*f(w) < 0){			y = w;		}		else x = w;


	} while (abs(xn - x) > 0.0001);

	return x;
}

double metodoNewton(double f(double x), double diff(double x), double x){

	double xn;

	do {
		xn = x;

		if (diff(x) == 0) return -1;

		x += f(x) / diff(x);

	} while (abs(xn - x > 0.0001));
}

void comp_central() {
	double S1, S2, S3, Erro, Qc;
	double h = 0.5;
	cout << "\tMetodo de Euler\t\n";
	do {
		S1 = metodoEuler(f_comp_central, 0, 30 * 24 * 60, Cp0, h);
		S2 = metodoEuler(f_comp_central, 0, 30 * 24 * 60, Cp0, h / 2);
		S3 = metodoEuler(f_comp_central, 0, 30 * 24 * 60, Cp0, h / 4);
		cout << S1 << "\t" << S2 << "\t" << S3 << "\t";
		Qc = (double) (S2 - S1) / (S3 - S2);
		cout << "h:" << h;
		cout << "Qc: " << Qc << endl;
		h = h / 2;
	} while ((int) round(Qc) != 2);

	cout << "Qc: " << Qc;
	Erro = S2 - S1;
	cout << "\tErro: " << Erro;
	cout << "\tS: " << S1;

	h = 0.5;
	cout << "\nMetodo de Euler Modificado\t\n";
	do {
		S1 = metodoEuler_melhorado(f_comp_central, 0, 30 * 24 * 60, Cp0, h);
		S2 = metodoEuler_melhorado(f_comp_central, 0, 30 * 24 * 60, Cp0, h / 2);
		S3 = metodoEuler_melhorado(f_comp_central, 0, 30 * 24 * 60, Cp0, h / 4);
		cout << S1 << "\t" << S2 << "\t" << S3 << "\t";
		Qc = (double) (S2 - S1) / (S3 - S2);
		cout << "h:" << h;
		cout << "Qc: " << Qc << endl;
		h = h / 2;
	} while ((int) round(Qc) != 2);

	cout << "Qc: " << Qc;
	Erro = S2 - S1;
	cout << "\tErro: " << Erro;
	cout << "\tS: " << S1;

	/*	cout << "\n\tMetodo de Runga Kutta 2 Ordem\t\n";
	 h=1;
	 do {
	 S1 = metodoRungaKutta2a(f_comp_central, 0, 30 * 24 * 60, Cp0, h);
	 S2 = metodoRungaKutta2a(f_comp_central, 0, 30 * 24 * 60, Cp0, h / 2);
	 S3 = metodoRungaKutta2a(f_comp_central, 0, 30 * 24 * 60, Cp0, h / 4);
	 cout << S1 << "\t" << S2 << "\t" << S3 << "\t";
	 Qc = (double) (S2 - S1) / (S3 - S2);
	 cout << "h:" << h;
	 cout << "Qc: " << Qc << endl;
	 h = h / 2;
	 } while ((int) round(Qc) != 4);

	 cout << "Qc: " << Qc;
	 Erro = (S2 - S1) / 3;
	 cout << "\tErro: " << Erro;
	 cout << "\tS: " << S1;
	 */
	/*	cout << "\n\tMetodo de Runga Kutta 4 Ordem\t\n";
	 h = 1;
	 do {
	 S1 = metodoRungaKutta4a(f_comp_central, 0, 30 * 24 * 60, Cp0, h);
	 S2 = metodoRungaKutta4a(f_comp_central, 0, 30 * 24 * 60, Cp0, h / 2);
	 S3 = metodoRungaKutta4a(f_comp_central, 0, 30 * 24 * 60, Cp0, h / 4);
	 cout << S1 << "\t" << S2 << "\t" << S3 << "\t";
	 Qc = (double) (S2 - S1) / (S3 - S2);
	 cout << "h:" << h;
	 cout << "Qc: " << Qc << endl;
	 h = h / 2;
	 } while ((int) round(Qc) != 16);

	 cout << "Qc: " << Qc;
	 Erro = (S2 - S1) / 15;
	 cout << "\tErro: " << Erro;
	 cout << "\tS: " << S1;
	 */
}

