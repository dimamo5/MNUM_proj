#include <cmath>
#include <cstdlib>
#include "constantes.h"

using namespace std;

double Dose(unsigned int t);
double metodoEuler(double(*f)(double x, double y), double xi, double xf, double
	y, double h);
double metodoRungaKutta2a(double f(double x, double y), double xi, double xf,
	double y, double h);
double metodoRungaKutta4a(double f(double x, double y), double xi, double xf,
	double y, double h);

double f_central(double t, double cp);


int main() {
	srand(1); //sempre que o programa executa gera os mesmos valores

	double h = 0.1;

	cout << "metodoEuler: " << metodoEuler(f_central, 0, 30 * 24 * 60, Cp0, h) <<
		endl;
	system("Pause");
}

double f_central(double t, double cp){

	return (Dose(t) - Ke*cp) / Vap;
}


/*
{ 100/60 ,  0 << t << 60
D(t) {
{ 400/((rand % 3 + 4)*60) ,  60 < t << 360  -> 6h -> 360 minutos : tempo
maximo possivel
t = minutos
*/
double Dose(unsigned int t) {

	t = t % (60 * 24);

	if (t >= 0 && t <= 60) {   //1 ramo da funcao dt

		return (double)100 / 60;
	}

	else if (t > 60 && t <= 360) { //2 ramo da funcao dt

		return (double)400 / ((rand() % 3 + 4) * 60);   //determinacao de 
		uma hora aleatoria entre[4, 6]
	}
	else
		return 0;
}

//metodo de euler
double metodoEuler(double(*f)(double x, double y), double xi, double xf, double
	y, double h)
{
	unsigned n = (xf - xi) / h;

	for (size_t i = 0; i <= n; ++i)
	{
		y += h * f(xi, y);
		xi += h;
	}
	return y;
}

//metodo Runga - Kutta 2a ordem
double metodoRungaKutta2a(double f(double x, double y), double xi, double xf,
	double y, double h)
{
	unsigned n = (xf - xi) / h;

	for (size_t i = 0; i <= n; ++i)
	{
		y += h * f(xi + h / 2, y + h / 2 * f(xi, y));
		xi += h;
	}
	return y;
}

//metodo Runga - Kutta 4a ordem
double metodoRungaKutta4a(double f(double x, double y), double xi, double xf,
	double y, double h)
{
	unsigned n = (xf - xi) / h;
	double deltaY1, deltaY2, deltaY3, deltaY4;

	for (size_t i = 0; i <= n; ++i)
	{
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



/*
double metodoEuler_melhorado(double(*f)(double x, double y), double xi, double
xf, double y, double h)
{

return f(xi, y);
}*/
