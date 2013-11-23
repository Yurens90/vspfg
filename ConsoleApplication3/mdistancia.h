#pragma once
#include "precogida.h"
#include <iostream>
#include <vector>
using namespace std;
class mdistancia {
	int N; //numero de putnos de recogida
	vector <vector <precogida> > md;
	int nvehiculos; //numero de vehiculos que realizaran las rutas
	int ucarga; //unidades de carga maxima de dichos vehiculos
public:
	mdistancia();
	~mdistancia();
	mdistancia(int n);
	mdistancia(string nombre);
	mdistancia(int n, vector <vector <precogida> > &vec, int nvec, int carga);
	int getsize();
	precogida get(int i, int j);
	void ordenar_matriz();
	void imprimir();
	void set_visitados(int i);
	int getnvehiculos();
	int getcarga();
	void mostrar_demandas();
};

