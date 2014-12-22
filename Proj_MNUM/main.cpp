#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <utility>
#include "EDO.h"
#include "Zeros.h"
#include "Funcs_comp.h"
#include "constantes.h"

using namespace std;

//double f_bicomp_central(double t, double cp);
void comp_bi();

int main() {
	srand(1); //sempre que o programa executa gera os mesmos valores

	//	double h = 0.1;
	//
	//	cout << "metodoEuler: " << metodoEuler(f_comp_central, 0, 30 * 24 * 60, Cp0, h) << endl;
	//	cout << "Metodo Runga kutta 2a: " << metodoRungaKutta2a(f_comp_central, 0, 30 * 24 * 60, Cp0, h) << endl;
	//	cout << "Metodo Runga kutta 4a: " << metodoRungaKutta4a(f_comp_central, 0, 30 * 24 * 60, Cp0, h) << endl;
//	comp_central();
//	cout << funcao_ka(0)<<endl;
//	cout << funcao_ka(5)<<endl;
//	clock_t b = clock();
//	cout << setprecision(20) << metodoBisseccao(funcao_ka, 0.02, 0.06) << endl;
//	clock_t e = clock();
//	double elapsed_secs = (double) (e - b) / CLOCKS_PER_SEC;
//	cout << "tempo: " << elapsed_secs << endl;
//	 e = clock();
//	cout << setprecision(20) << metodoCorda(funcao_ka, 0, 0.009) << endl;
//	 e = clock();
//	 elapsed_secs = (double) (e - b) / CLOCKS_PER_SEC;
//	cout << "tempo: " << elapsed_secs << endl;
//	 e = clock();
//	cout << setprecision(20) << metodoNewton(funcao_ka, funcao_ka_diff, 0.07);
//			<< endl;
//	 e = clock();
//	 elapsed_secs = (double) (e - b) / CLOCKS_PER_SEC;
//	cout << "tempo: " << elapsed_secs << endl;
//	cout<<metodoEuler_melhorado(f_comp_central, 0, 30 * 24 * 60, 0, 1);
//	comp_bi();
	cout << metodoNewton(funcao_ka, funcao_ka_diff, 0.05) << endl;
//	metodoEuler(f_comp_central,0,30*24*60,0,1);
//	sistemaEqDiferenciais1aOrd_RK(f_mi, f_mp, 0, 0, 0, 2);
//	sistemaEqDiferenciais1aOrd_Euler(f_mi, f_mp, 0, 0, 0, 1);
//	comp_bi();
	system("Pause");
}

void comp_central() {
	double S1, S2, S3, Erro, Qc;
	double h = 1;
	cout << "\nMetodo de Euler\n";
	clock_t b = clock();
	S1 = metodoEuler(f_comp_central, 0, 30 * 24 * 60, 0, h);
	clock_t e = clock();
	double elapsed_secs = (double) (e - b) / CLOCKS_PER_SEC;

	cout << "tempo: " << elapsed_secs << endl;
	S2 = metodoEuler(f_comp_central, 0, 30 * 24 * 60, 0, h / 2);
	S3 = metodoEuler(f_comp_central, 0, 30 * 24 * 60, 0, h / 4);
	cout << S1 << "\t" << S2 << "\t" << S3 << "\t";
	Qc = (double) (S2 - S1) / (S3 - S2);
	cout << "h:" << h;
	cout << "\tQc: " << Qc;
	Erro = abs(S2 - S1);
	cout << "\tErro: " << Erro << endl;

	/*	cout << "\nMetodo de Euler Modificado\n";
	 S1 = metodoEuler_melhorado(f_comp_central, 0, 30 * 24 * 60, 0, h);
	 S2 = metodoEuler_melhorado(f_comp_central, 0, 30 * 24 * 60, 0, h / 2);
	 S3 = metodoEuler_melhorado(f_comp_central, 0, 30 * 24 * 60, 0, h / 4);
	 cout << S1 << "\t" << S2 << "\t" << S3 << "\t";
	 Qc = (double) (S2 - S1) / (S3 - S2);
	 cout << "h:" << h;
	 cout << "\tQc: " << Qc;
	 Erro = abs(S2 - S1);
	 cout << "\tErro: " << Erro<<endl;*/

	cout << "\nMetodo de Runga Kutta 2 Ordem\n";
	b = clock();
	S1 = metodoRungaKutta2a(f_comp_central, 0, 30 * 24 * 60, 0, h);
	e = clock();
	elapsed_secs = (double) (e - b) / CLOCKS_PER_SEC;

	cout << "tempo: " << elapsed_secs << endl;

	S2 = metodoRungaKutta2a(f_comp_central, 0, 30 * 24 * 60, 0, h / 2);
	S3 = metodoRungaKutta2a(f_comp_central, 0, 30 * 24 * 60, 0, h / 4);
	cout << S1 << "\t" << S2 << "\t" << S3 << "\t";
	Qc = (double) (S2 - S1) / (S3 - S2);
	cout << "h:" << h;
	cout << "\tQc: " << Qc;
	Erro = abs(S2 - S1);
	cout << "\tErro: " << Erro << endl;

	cout << "\nMetodo de Runga Kutta 4 Ordem\n";

	b = clock();
	S1 = metodoRungaKutta4a(f_comp_central, 0, 30 * 24 * 60, 0, h);
	e = clock();
	elapsed_secs = (double) (e - b) / CLOCKS_PER_SEC;

	cout << "tempo: " << elapsed_secs << endl;
	S2 = metodoRungaKutta4a(f_comp_central, 0, 30 * 24 * 60, 0, h / 2);
	S3 = metodoRungaKutta4a(f_comp_central, 0, 30 * 24 * 60, 0, h / 4);
	cout << S1 << "\t" << S2 << "\t" << S3 << "\t";
	Qc = (double) (S2 - S1) / (S3 - S2);
	cout << "h:" << h;
	cout << "\tQc: " << Qc;
	Erro = abs(S2 - S1);
	cout << "\tErro: " << Erro << endl;

}

void comp_bi() {

	double h = 1;
	clock_t b = clock();
	double h1_y = sistemaEqDiferenciais1aOrd_RK(f_mi, f_mp, 0, 0, 0, h).first;
	double h2_y =
			sistemaEqDiferenciais1aOrd_RK(f_mi, f_mp, 0, 0, 0, h / 2).first;
	double h3_y =
			sistemaEqDiferenciais1aOrd_RK(f_mi, f_mp, 0, 0, 0, h / 4).first;
	double h1_z = sistemaEqDiferenciais1aOrd_RK(f_mi, f_mp, 0, 0, 0, h).second;
	double h2_z =
			sistemaEqDiferenciais1aOrd_RK(f_mi, f_mp, 0, 0, 0, h / 2).second;
	double h3_z =
			sistemaEqDiferenciais1aOrd_RK(f_mi, f_mp, 0, 0, 0, h / 4).second;

	double qc_y = (h2_y - h1_y) / (h3_y - h2_y);
	double qc_z = (h2_z - h1_z) / (h3_z - h2_z);
	double e_y = (h3_y - h2_y) / 15;
	double e_z = (h3_y - h2_y) / 15;

	clock_t e = clock();
	double elapsed_secs = (double) (e - b) / CLOCKS_PER_SEC;
	cout << "\ntempo: " << elapsed_secs << endl;

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
}
