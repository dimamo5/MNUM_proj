#ifndef _EDO

double metodoEuler(double(*f)(double x, double y), double xi, double xf, double y, double h);
double metodoRungaKutta2a(double f(double x, double y), double xi, double xf, double y, double h);
double metodoRungaKutta4a(double f(double x, double y), double xi, double xf, double y, double h);

#endif