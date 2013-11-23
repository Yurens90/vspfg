#include "stdafx.h"
#include "mdistancia.h"
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;


mdistancia::mdistancia() {
	N = 0;
};

mdistancia::mdistancia(int n) {
	N = n;
	vector<precogida> aux;
	precogida dummy;
	for (int i = 0; i < N; i++)
		aux.push_back(dummy);
	for (int i = 0; i < N; i++)
		md.push_back(aux);
};

mdistancia::mdistancia(string nombre) {
	N = 0;
	ifstream fich(nombre.c_str());
	fich >> N;
	vector<precogida> aux;
	precogida dummy;
	for (int i = 0; i < N; i++)
		aux.push_back(dummy);
	for (int i = 0; i < N; i++)
		md.push_back(aux);
	//fin de la inicializacion de la matriz
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++) {
		float dist;
		fich >> dist;
		md[i][j].setdistancia(dist);
		md[i][j].setid(j);
	};
};

mdistancia::mdistancia(int n, vector <vector <precogida> > &vec, int nvec, int carga) {
	N = n;
	md = vec;
	nvehiculos = nvec;
	ucarga = carga;
}

int mdistancia::getsize() {
	return N;
};

precogida mdistancia::get(int i, int j) {
	return md[i][j];
};

void mdistancia::ordenar_matriz() {
	for (int i = 0; i < N; i++) {
		std::sort(md[i].begin(), md[i].end());
	}
};

void mdistancia::imprimir() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << md[i][j].getdistancia() << "	";
		cout << endl;
	}
	cout << "------------------" << endl;
};

void mdistancia::set_visitados(int i) {
	for (int j = 0; j < N; j++)
		md[i][j].setvisitado();
};

int mdistancia::getnvehiculos(){
	return nvehiculos;
};

int mdistancia::getcarga() {
	return ucarga;
};

void mdistancia::mostrar_demandas() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << md[i][j].getdemanda() << "-";
		cout << endl;
	}
	cout << "------------------" << endl;
};

mdistancia::~mdistancia()
{
}
