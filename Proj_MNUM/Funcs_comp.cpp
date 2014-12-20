#include "constantes.h"
#include <cmath>

double Dose(double t) {

	t = fmod(t, 60 * 24); //adaptacao para verificacao diaria

	if (t >= 0 && t <= 60) {   //1 ramo da funcao dt

		return (double)100 / 60;
	}

	else if (t > 60 && t <= 360) { //2 ramo da funcao dt

		return (double)400 / (horas_geradas * 60); //determinacao de 	uma hora aleatoria entre[4, 6]
	}
	else
		return 0;
}


double funcao_ka(double ka) {
	return (ka * exp(-ka * tmax)) - (Ket * exp(-Ket * tmax));
}

double funcao_ka_diff(double ka) {
	return exp(-ka * tmax) - ka * tmax * exp(-ka * tmax);
}

double funcao_ka_g(double ka)
{
	return Ket*exp(tmax*(ka - Ket));
}

double f_comp_central(double t, double cp) {

	return (Dose(t) - Ke * cp) / Vap;
}

double f_mi(double t, double mi, double mp, double ka){

	return (Dose(t) - ka*mi);
}

double f_mp(double t, double mi, double mp, double ka){
	
	return  (ka*mi - Ket*mp);
}

