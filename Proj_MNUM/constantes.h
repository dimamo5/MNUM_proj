#ifndef _CONSTANTES

#include <cstdlib>

const double Vap = 3920; // mL
const double Cp0 = (100 / 60) / (Vap);  // mg/mL
const double Ket = 0.1155*60;
const double Ke = Ket / Vap;
const double tmax = 1.2*60;
const double horas_geradas = (rand() % 3 + 4); //valor aleatorio das horas
const double epsilon = 0.0001;

#endif