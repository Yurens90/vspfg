#pragma once
#include "mdistancia.h"
#include "tvehiculo.h"
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
class ruta {
private:
	mdistancia mraw; //matriz de distancias sin modificar
	mdistancia mord; //matriz de distancias ordenada
	list <int> visitados; //clientes visitados
public:
	ruta();
	~ruta();
	ruta(mdistancia &mat); //constructor con una matriz ya inicializada desde fuera
	ruta(string nombre);
	vector<precogida> ordenar_fila(int i);
	precogida candidatos(int i);
	bool buscar(tvehiculo &v, int media);
	void insertar_visitado(int i);
	bool comprobar_visitado(int i);
	bool fin_visitas();
	float getdistanciaij(int i, int j);
	list <int> get_visitados();
};

