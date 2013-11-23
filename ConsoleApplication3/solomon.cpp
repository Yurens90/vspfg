#include "stdafx.h"
#include "solomon.h"
#include <fstream>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;



solomon::solomon() {
	ncamiones = 0;
	nclientes = 0;
	capacidadcamiones = 0;
};

solomon::solomon(string nombre) {
	ifstream file(nombre.c_str());
	string aux;
	for (int i = 0; i < 4; i++) //saltamos las 4 primeras palabras
		file >> aux;
	file >> ncamiones;
	file >> capacidadcamiones;
	for (int i = 0; i < 12; i++)//saltamos las siguientes 12 palabras
		file >> aux;
	//empezamos a leer todos los numeros
	while (!file.eof()) { //saltamos las siguientes 12 palabras
		int num;
		punto_solomon p;
		file >> num;
		p.setid(num);
		file >> num;
		p.setx(num);
		file >> num;
		p.sety(num);
		file >> num;
		p.setdemanda(num);
		file >> num;
		p.setrtime(num);
		file >> num;
		p.setddate(num);
		file >> num;
		p.setservtime(num);
		listado.push_back(p);
	}
	file.close();
	vector <float> dummy;
	for (unsigned int i = 0; i < listado.size(); i++)
		dummy.push_back(-1);
	for (unsigned int i = 0; i < listado.size(); i++)
		matriz.push_back(dummy);
	nclientes = listado.size();

};

void solomon::mostrarmatriz() {
	cout << "Nclientes: " << nclientes << endl;
	cout << "matriz size: " << matriz.size() << endl;
	cout << "listado size: " << listado.size() << endl;
	for (unsigned int i = 0; i < matriz.size(); i++) {
		for (unsigned int j = 0; j < matriz.size(); j++)
			cout << matriz[i][j];
		cout << endl;
	}
}

void solomon::mostrarlistado() {
	cout << "Numero de camiones: " << ncamiones << endl;
	cout << "Capacidad de camiones: " << capacidadcamiones << endl;
	for (unsigned int i = 0; i < listado.size(); i++) {
		cout << "X: " << listado[i].getx() << ", Y: " << listado[i].gety() << endl;
	}

};

void solomon::mostrarpunto() {
	cout << "id: " << listado[1].getid() << endl;
	cout << "x: " << listado[1].getx() << endl;
	cout << "y: " << listado[1].gety() << endl;
};

void solomon::calcularmatriz() {
	for (unsigned int i = 0; i < listado.size(); i++) {
		for (unsigned int j = 0; j < listado.size(); j++) {
			matriz[i][j] = deuclidea(listado[j].getx(), listado[i].getx(), listado[j].gety(), listado[i].gety());
			//cout << "valor: " << matriz[i][j] << endl;
			//cin.get();
		}
	}
}

//calcular la distancia euclidea entre dos puntos
float solomon::deuclidea(int x1, int x2, int y1, int y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

mdistancia solomon::convertir() {
	vector<precogida> aux;
	vector <vector <precogida> > aux2;
	precogida dummy;
	for (int i = 0; i < nclientes; i++)
		aux.push_back(dummy);
	for (int i = 0; i < nclientes; i++)
		aux2.push_back(aux);
	//fin de la inicializacion de la matriz
	for (int i = 0; i < nclientes; i++)
	for (int j = 0; j < nclientes; j++) {
		aux2[i][j].setdistancia(matriz[i][j]);
		aux2[i][j].setid(j);
		aux2[i][j].setdemanda(listado[j].getdemanda());
		//cout << "getdemanda: " << listado[j].getdemanda() << endl;
		//cin.get();
		//aux2[i][j].setdemanda(matri);
	};
	/*
	cout << "Antes de pasar a mdistancia" << endl;
	cout << "nclientes: " << nclientes << endl;
	for (int i = 0; i < nclientes; i++) {
	for (int j = 0; j < nclientes; j++) {
	cout << aux2[i][j].getdemanda() << " ";
	};
	cout << endl;
	};

	//cout << "despues de crear mdistancia: " << endl;
	//ret.mostrar_demandas();
	//cin.get();
	//ret.imprimir();
	//cin.get();
	*/
	mdistancia ret(nclientes, aux2, ncamiones, capacidadcamiones);
	return ret;
}



solomon::~solomon()
{
}
