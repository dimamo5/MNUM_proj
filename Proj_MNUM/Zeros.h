#ifndef _ZEROS

double metodoBisseccao(double f(double), double a, double b);
double metodoCorda(double f(double x), double x, double y);
double metodoNewton(double f(double x), double diff(double x), double x);
double metodo_picardPeano(double f(double k), double f_diff(double x), double guess);

#endif