#include <iostream>
#include <cmath>
#include <cstdlib>
#include "constantes.h"

using namespace std;

double Dose(unsigned int t);
double metodoEuler(double(*f)(double x, double y), double xi, double xf, double y, double h);
double metodoEuler_melhorado(double(*f)(double x, double y), double xi, double yi, double xn, double yn, double xf, double h);
double metodoRungaKutta2a(double f(double x, double y), double xi, double xf, double y, double h);
double metodoRungaKutta4a(double f(double x, double y), double xi, double xf, double y, double h);

void comp_central();
double f_comp_central(double t, double cp);
double f_bicomp_central(double t, double cp);

int main() {
	srand(1); //sempre que o programa executa gera os mesmos valores

		double h = 0.1;
	//
	//	cout << "metodoEuler: " << metodoEuler(f_comp_central, 0, 30 * 24 * 60, Cp0, h) << endl;
	//	cout << "Metodo Runga kutta 2a: " << metodoRungaKutta2a(f_comp_central, 0, 30 * 24 * 60, Cp0, h) << endl;
	//	cout << "Metodo Runga kutta 4a: " << metodoRungaKutta4a(f_comp_central, 0, 30 * 24 * 60, Cp0, h) << endl;
	//comp_central();
	cout << metodoEuler_melhorado(f_comp_central, 0, Cp0, 1, Cp0, 30 * 24 * 60, h) << endl;
	system("Pause");
}

double f_comp_central(double t, double cp) {

	return (Dose(t) - Ke * cp) / Vap;
}

double f_bicomp_central(double t, double cp){




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

		return (double)100 / 60;
	}

	else if (t > 60 && t <= 360) { //2 ramo da funcao dt

		return (double)400 / (horas_geradas * 60); //determinacao de 	uma hora aleatoria entre[4, 6]
	}
	else
		return 0;
}

//metodo de euler
double metodoEuler(double(*f)(double x, double y), double xi, double xf, double y, double h) {

	unsigned n = (xf - xi) / h;

	for (size_t i = 0; i <= n; ++i) {
		y += h * f(xi, y);
		xi += h;
	}
	return y;
}

/*
double metodoEuler_melhorado(double(*f)(double x, double y), double xi, double yi, double xn, double yn, double xf, double h)
{
	double pn1, pn1_tang, xn_, yn_;
	unsigned n = (xf - xi) / h;
		
	for (size_t i = 0; i <= n; ++i){

		xn_ = xn; //preserva valores
		yn_ = yn;

		yi = yn; //yn-1
		xn += h; //xn+1

		pn1 = yi + 2 * h*f(xn, yn);  //valor previsto
		pn1_tang = f(xn, pn1);  //sua tangente

		yn += h / 2 * (f(xn, pn1) + f(xn_, yn_)); //valor corrigido para yn+1
	}	
	return yn;
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
		y += (1.0 / 6) * deltaY1 + (1.0 / 3) * deltaY2 + (1.0 / 3) *

			deltaY3 + (1.0 / 6) * deltaY4;
	}
	return y;
}

void comp_central() {

	double S1, S2, S3, Erro, Qc;
	double h = 0.1;

	do {
		S1 = metodoEuler(f_comp_central, 0, 30 * 24 * 60, Cp0, h);
		S2 = metodoEuler(f_comp_central, 0, 30 * 24 * 60, Cp0, h / 2);
		S3 = metodoEuler(f_comp_central, 0, 30 * 24 * 60, Cp0, h / 4);

		cout << S1 << "\t" << S2 << "\t" << S3 << "\t";

		Qc = (S2 - S1) / (S3 - S2);
		cout << "h: " << h << endl;
		cout << "Qc: " << Qc << endl;
		h = h / 2;

	} while ((int)round(Qc) != 2);

	Erro = S2 - S1;
	cout << "Erro: " << Erro << endl;
}

