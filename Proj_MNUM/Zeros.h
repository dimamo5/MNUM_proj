#ifndef _ZEROS
#define _ZEROS

double metodoBisseccao(double f(double), double a, double b);
double metodoCorda(double f(double), double x1, double x2);
double metodoNewton(double f(double ka), double diff(double ka), double x);

#endif
