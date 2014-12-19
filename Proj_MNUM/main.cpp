#include <iostream>

#include "EDO.h"
#include "Zeros.h"
#include "Funcs_comp.h"
#include "constantes.h"

using namespace std;

//double f_bicomp_central(double t, double cp);

int main() {
	srand(1); //sempre que o programa executa gera os mesmos valores

	//	double h = 0.1;
	//
	//	cout << "metodoEuler: " << metodoEuler(f_comp_central, 0, 30 * 24 * 60, Cp0, h) << endl;
	//	cout << "Metodo Runga kutta 2a: " << metodoRungaKutta2a(f_comp_central, 0, 30 * 24 * 60, Cp0, h) << endl;
	//	cout << "Metodo Runga kutta 4a: " << metodoRungaKutta4a(f_comp_central, 0, 30 * 24 * 60, Cp0, h) << endl;
	//comp_central();

	cout << metodoBisseccao(funcao_ka, 0, 0.5);

	system("Pause");
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
		Qc = (double)(S2 - S1) / (S3 - S2);
		cout << "h:" << h;
		cout << "Qc: " << Qc << endl;
		h = h / 2;
	} while ((int)round(Qc) != 2);

	cout << "Qc: " << Qc;
	Erro = S2 - S1;
	cout << "\tErro: " << Erro;
	cout << "\tS: " << S1;

	h = 0.5;
	cout << "\nMetodo de Euler Modificado\t\n";
	do {
		//S1 = metodoEuler_melhorado(f_comp_central, 0, 30 * 24 * 60, Cp0, h);
		//S2 = metodoEuler_melhorado(f_comp_central, 0, 30 * 24 * 60, Cp0, h / 2);
		//S3 = metodoEuler_melhorado(f_comp_central, 0, 30 * 24 * 60, Cp0, h / 4);
		cout << S1 << "\t" << S2 << "\t" << S3 << "\t";
		Qc = (double)(S2 - S1) / (S3 - S2);
		cout << "h:" << h;
		cout << "Qc: " << Qc << endl;
		h = h / 2;
	} while ((int)round(Qc) != 2);

	cout << "Qc: " << Qc;
	Erro = S2 - S1;
	cout << "\tErro: " << Erro;
	cout << "\tS: " << S1;

	/*	cout << "\n\tMetodo de Runga Kutta 2 Ordem\t\n";
	
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
