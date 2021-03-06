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
void comp_central();
void calculo_zeros();

int main() {
	srand(1); //sempre que o programa executa gera os mesmos valores
	/**
	 * ------------------------------
	 * Descomentar funcao a mostrar
	 *-------------------------------
	 */
	comp_central();
	//	calculo_zeros();
	//	comp_bi

	return 0;
}

void comp_central() {
	double S1, S2, S3, Erro, Qc;
	double h = 1;
	cout << "\nMetodo de Euler\n";
	clock_t b = clock();
	S1 = metodoEuler(f_comp_central, 0, 30 * 24 * 60, 0, h);

	S2 = metodoEuler(f_comp_central, 0, 30 * 24 * 60, 0, h / 2);
	S3 = metodoEuler(f_comp_central, 0, 30 * 24 * 60, 0, h / 4);
	clock_t e = clock();
	double elapsed_secs = (double) (e - b) / CLOCKS_PER_SEC;
	cout << "tempo: " << elapsed_secs << endl;
	cout << S1 << "\t" << S2 << "\t" << S3 << "\t";
	Qc = (double) (S2 - S1) / (S3 - S2);
	cout << "h:" << h;
	cout << "\tQc: " << Qc;
	Erro = abs(S2 - S1);
	cout << "\tErro: " << Erro << endl;
	/**
	 * Metodo N�o funciona correctamente
	 *
	 * Apenas coerente no calculo da primeira Solucao
	 */
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
	S2 = metodoRungaKutta2a(f_comp_central, 0, 30 * 24 * 60, 0, h / 2);
	S3 = metodoRungaKutta2a(f_comp_central, 0, 30 * 24 * 60, 0, h / 4);

	e = clock();
	elapsed_secs = (double) (e - b) / CLOCKS_PER_SEC;

	cout << "tempo: " << elapsed_secs << endl;
	cout << S1 << "\t" << S2 << "\t" << S3 << "\t";
	Qc = (double) (S2 - S1) / (S3 - S2);
	cout << "h:" << h;
	cout << "\tQc: " << Qc;
	Erro = abs(S2 - S1);
	cout << "\tErro: " << Erro << endl;

	cout << "\nMetodo de Runga Kutta 4 Ordem\n";

	b = clock();
	S1 = metodoRungaKutta4a(f_comp_central, 0, 30 * 24 * 60, 0, h);
	S2 = metodoRungaKutta4a(f_comp_central, 0, 30 * 24 * 60, 0, h / 2);
	S3 = metodoRungaKutta4a(f_comp_central, 0, 30 * 24 * 60, 0, h / 4);
	e = clock();
	elapsed_secs = (double) (e - b) / CLOCKS_PER_SEC;

	cout << "tempo: " << elapsed_secs << endl;
	cout << S1 << "\t" << S2 << "\t" << S3 << "\t";
	Qc = (double) (S2 - S1) / (S3 - S2);
	cout << "h:" << h;
	cout << "\tQc: " << Qc;
	Erro = abs(S2 - S1);
	cout << "\tErro: " << Erro << endl;

}

void comp_bi() {

	double h = 1;

	/**
	 * METODO RK
	 */

	cout << "\nMetodo RK\n" << endl;

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
	/**
	 * METODO EULER
	 */
	cout << "\nMetodo Euler\n" << endl;

	b = clock();
	h1_y = sistemaEqDiferenciais1aOrd_Euler(f_mi, f_mp, 0, 0, 0, h).first;
	h2_y = sistemaEqDiferenciais1aOrd_Euler(f_mi, f_mp, 0, 0, 0, h / 2).first;
	h3_y = sistemaEqDiferenciais1aOrd_Euler(f_mi, f_mp, 0, 0, 0, h / 4).first;
	h1_z = sistemaEqDiferenciais1aOrd_Euler(f_mi, f_mp, 0, 0, 0, h).second;
	h2_z = sistemaEqDiferenciais1aOrd_Euler(f_mi, f_mp, 0, 0, 0, h / 2).second;
	h3_z = sistemaEqDiferenciais1aOrd_Euler(f_mi, f_mp, 0, 0, 0, h / 4).second;

	qc_y = (h2_y - h1_y) / (h3_y - h2_y);
	qc_z = (h2_z - h1_z) / (h3_z - h2_z);
	e_y = (h3_y - h2_y) / 15;
	e_z = (h3_y - h2_y) / 15;

	e = clock();
	elapsed_secs = (double) (e - b) / CLOCKS_PER_SEC;
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

void calculo_zeros() {
	cout << "\n NEWTON\n";
	cout << "1� zero: " << metodoNewton(funcao_ka, funcao_ka_diff, 0.001)
			<< endl;
	cout << "2� zero: " << metodoNewton(funcao_ka, funcao_ka_diff, 0.05)
			<< endl;

	cout << "\n BISSECAO\n";
	cout << "1� zero: " << metodoBisseccao(funcao_ka, 0, 0.05) << endl;
	cout << "2� zero: " << metodoBisseccao(funcao_ka, 0.03, 0.06) << endl;

	cout << "\n CORDA\n";
	cout << "1� zero: " << metodoCorda(funcao_ka, 0, 0.005) << endl;
	cout << "2� zero: " << metodoCorda(funcao_ka, 0.03, 0.06) << endl;

}
