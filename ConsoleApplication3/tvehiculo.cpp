#include "stdafx.h"
#include "tvehiculo.h"

tvehiculo::tvehiculo() {
	id = -1;
	ut = 0;
	ua = 0;
	coste = 0.0;
	visitados.push_back(0);
};

tvehiculo::tvehiculo(int i, int uut) {
	//coste = 0;
	id = i;
	ut = uut;
	ua = 0;
	visitados.push_back(0);
};

void tvehiculo::insertar(int i) {
	visitados.push_back(i);
};

void tvehiculo::impr_recorrido() {
	cout << "Recorrido del vehiculo " << id << ": " << endl;
	for (list<int> ::iterator it = visitados.begin(); it != visitados.end(); it++)
		cout << "-" << (*it);
	cout << endl << endl;
};

int tvehiculo::getid() {
	return id;
};

int tvehiculo::getcarga_actual() {
	return ua;
};

int tvehiculo::getcarga_max() {
	return ut;
};

void tvehiculo::sumar_carga(int cg) {
	ua += cg;
};

void tvehiculo::sumar_coste(float cost) {
	coste += cost;
};

float tvehiculo::get_coste() {
	return coste;
};

tvehiculo::~tvehiculo()
{
}
