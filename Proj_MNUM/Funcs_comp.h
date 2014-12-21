#ifndef _FUNCS

/*
 { 100/60 ,  0 << t << 60
 D(t) {
 { 400/((rand % 3 + 4)*60) ,  60 < t << 360  -> 6h -> 360 minutos : tempo maximo possivel
 t = minutos
 */

double Dose(unsigned int t);
double funcao_ka(double ka);
void comp_central();
double f_comp_central(double t, double cp);
double funcao_ka_diff(double ka);
double f_mi(double t, double mi,double mp);
double f_mp(double t, double mi, double mp);
#endif
