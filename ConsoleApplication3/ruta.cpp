#include "stdafx.h"
#include "ruta.h"
//#include <iostream>
//using namespace std;


ruta::ruta(mdistancia &mat) {
	mraw = mat;
	mord = mat;    //nn
	//mord.ordenar_matriz();
	insertar_visitado(0);
}

ruta::ruta(string nombre) {
	mdistancia aux(nombre.c_str());
	mraw = aux;
	mord = aux;
	insertar_visitado(0);
}

vector<precogida> ruta::ordenar_fila(int i) {
	vector<precogida> candidatos;
	int j = 0;
	while (j < mord.getsize() && !fin_visitas()) {
		if (!comprobar_visitado(mord.get(i, j).getid()) && mord.get(i, j).getdistancia() != 0)
			candidatos.push_back(mord.get(i, j));
		j++;
	}
	std::sort(candidatos.begin(), candidatos.end());
	return candidatos;
};

precogida ruta::candidatos(int i) { // dado un punto buscamos los 3 mas cercanos que no hayan sido visitados ya, para poder seleccionar uno de forma aleatoria
	vector <precogida> candidatos = ordenar_fila(i);
	int indice = 0;
	if (candidatos.size() >= 3)
		indice = rand() % 3;
	else
		indice = rand() % candidatos.size(); // puede ser que en vez de 3 puntos tengamos dos o 1
	//cout << "indice original: " << i << "," << candidatos[indice].getid() << endl;
	// cout << "distancia: " << candidatos[indice].getdistancia() << endl;
	insertar_visitado(candidatos[indice].getid());
	return candidatos[indice];
};

bool ruta::buscar(tvehiculo &v, int media) { //ruta parcial
	cout << "fin de visitas? " << fin_visitas() << endl;
	if (!fin_visitas()) {
		int cont = 0;
		int siguiente = 0;
		//float coste = 0.0;
		precogida ret;
		int demanda = 0;
		while (cont < mraw.getsize() && v.getcarga_actual() + demanda <= v.getcarga_max() && !fin_visitas()) {
			ret = candidatos(siguiente);
			cout << "----------->siguiente: " << ret.getid() << endl;
			demanda = ret.getdemanda();
			cout << "Demanda: " << demanda << endl;
			//cin.get();
			cont++;
			v.sumar_coste(ret.getdistancia());
			siguiente = ret.getid();
			v.insertar(siguiente);
			v.sumar_carga(demanda);
		}
		v.sumar_coste(getdistanciaij(ret.getid(), 0)); //añadimos el coste de ir desde el ultimo punto hasta el origen
		v.insertar(0); //añadimos al recorrido del vehiculo la vuelta al origen
		v.impr_recorrido();
		//cin.get();
		//cout << "distancia del ultimo punto al origen: " << getdistanciaij(ret.getid(),0) << endl
		cout << "ultimo punto visitado: " << ret.getid() << endl;
		//cout << "cuenta: " << cont << endl;
		cout << "coste total del vehiculo: " << v.get_coste() << endl;
		return true;
	}
	else {
		cout << "Ya todos los puntos estan visitados" << endl;
		return false;
	}
	cout << "Puntos totales visitados hasta el momento: " << endl;
	for (list<int> ::iterator it = visitados.begin(); it != visitados.end(); it++)
		cout << " " << (*it);
	cout << " Son: " << visitados.size() << endl << "----------------" << endl;
};


void ruta::insertar_visitado(int i) {
	visitados.push_back(i);
};

bool ruta::comprobar_visitado(int i) {
	for (list<int> ::iterator it = visitados.begin(); it != visitados.end(); it++)
	if (i == (*it))
		return true;
	return false;
};

bool ruta::fin_visitas() {
	if (visitados.size() == mraw.getsize())
		return true;
	return false;
};

float ruta::getdistanciaij(int i, int j) {
	precogida ret = mraw.get(i, j); //recuperamos el punto ij de la matriz sin alterar
	return ret.getdistancia(); //devolvemos la distancia de un punto a otro
};

list <int> ruta::get_visitados() {
	return visitados;
};


ruta::~ruta()
{
}
