#pragma once
#include<list>
#include <iostream>
using namespace std;
class tvehiculo {
	int id; //identificador del vehiculo
	int ut; // unidades de carga total
	int ua; //unidades de carga actual
	float coste; //coste de la ruta
	list <int> visitados;
public:
	tvehiculo();
	~tvehiculo();
	tvehiculo(int i, int uut);
	void insertar(int i);
	void impr_recorrido();
	int getid();
	int getcarga_actual();
	int getcarga_max();
	void sumar_carga(int cg);
	void sumar_coste(float cost);
	float get_coste();
};

