#pragma once
#include <vector>
#include <iostream>
#include "punto_solomon.h"
#include "mdistancia.h"
#include <sstream>
using namespace std;
class solomon {
private:
	int ncamiones;
	int nclientes;
	int capacidadcamiones;
	vector <punto_solomon> listado;
	// int xmin, xmax;
	//int ymin, ymax;
	vector <vector <float> > matriz;
public:
	solomon(); //inicializar a 0 los totales y los max y a 999 los mínimos
	~solomon();
	//leer de fichero
	solomon(string nombre);
	//calcular distancia entre dos puntos

	//generar matriz de distancias -> pasar de vector de puntos_solomon a mdistancia

	//getter y setter de xmin,xmax,nclientes

	//mostrar todos los puntos
	void mostrarlistado();
	//mostrar un punto
	void mostrarpunto();
	//mostrar matriz de distancias de solomon
	void mostrarmatriz();
	//calcular la matriz de distancias
	void calcularmatriz();
	//calcular la distancia euclidea entre dos puntos
	float deuclidea(int x1, int x2, int y1, int y2);
	//convertir a mdistancia
	mdistancia convertir();


};

