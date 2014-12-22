#ifndef _ZEROS
#define _ZEROS

double metodoBisseccao(double f(double), double a, double b);
double metodoCorda(double f(double), double x1, double x2);
double metodoNewton(double f(double ka), double diff(double ka), double x);
/**
 * Metodo picard Peano só se pode aplica r no primeiro zero
 */
double metodo_picardPeano(double f(double k), double f_diff(double x),	double guess);
#endif
