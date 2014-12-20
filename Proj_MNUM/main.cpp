#include <iostream>
#include <iomanip>

#include "EDO.h"
#include "Zeros.h"
#include "Funcs_comp.h"
#include "constantes.h"
#include <utility>

using namespace std;

//double f_bicomp_central(double t, double cp);

int main() {
	srand(1); //sempre que o programa executa gera os mesmos valores

	double h = 1;
	//
	//	cout << "metodoEuler: " << metodoEuler(f_comp_central, 0, 30 * 24 * 60, Cp0, h) << endl;
	//	cout << "Metodo Runga kutta 2a: " << metodoRungaKutta2a(f_comp_central, 0, 30 * 24 * 60, Cp0, h) << endl;
	//	cout << "Metodo Runga kutta 4a: " << metodoRungaKutta4a(f_comp_central, 0, 30 * 24 * 60, Cp0, h) << endl;
	//comp_central();

	//cout <<setprecision(20) << metodoCorda(funcao_ka, 6.5, 7) <<endl;
	pair<double, double> resultado = sistemaEqDiferenciais1aOrd_EULER(f_mi, f_mp, 0, 0, 0, 6.92, h);
	cout << resultado.first << endl;
	cout << resultado.second << endl;

	double ka = 0.046;

	double h1_y = sistemaEqDiferenciais1aOrd_RK(f_mi, f_mp, 0, 0, 0, ka, h).first;
	double h2_y = sistemaEqDiferenciais1aOrd_RK(f_mi, f_mp, 0, 0, 0, ka, h / 2).first;
	double h3_y = sistemaEqDiferenciais1aOrd_RK(f_mi, f_mp, 0, 0, 0, ka, h / 4).first;
	double h1_z = sistemaEqDiferenciais1aOrd_RK(f_mi, f_mp, 0, 0, 0, ka, h).second;
	double h2_z = sistemaEqDiferenciais1aOrd_RK(f_mi, f_mp, 0, 0, 0, ka, h / 2).second;
	double h3_z = sistemaEqDiferenciais1aOrd_RK(f_mi, f_mp, 0, 0, 0, ka, h / 4).second;
	double qc_y = (h2_y - h1_y) / (h3_y - h2_y);
	double qc_z = (h2_z - h1_z) / (h3_z - h2_z);
	double e_y = (h3_y - h2_y) / 15;
	double e_z = (h3_y - h2_y) / 15;

	cout << "S mi = " << setprecision(10) << h1_y << endl;
	cout << "S' mi = " << setprecision(10) << h2_y << endl;
	cout << "S''mi = " << setprecision(10) << h3_y << endl;
	cout << "S mp = " << setprecision(30) << h1_z << endl;
	cout << "S' mp = " << setprecision(30) << h2_z << endl;
	cout << "S''mp = " << setprecision(30) << h3_z << endl;
	cout << "Qc mi =" << setprecision(10) << qc_y << endl;
	cout << "Qc mp =" << setprecision(10) << qc_z << endl;
	cout << "E'' mi =" << setprecision(10) << abs(e_y) << endl;
	cout << "E'' mp =" << setprecision(10) << abs(e_z) << endl;
	
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
