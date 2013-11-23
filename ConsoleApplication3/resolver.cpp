#include "stdafx.h"
#include "resolver.h"


resolver::resolver()
{
}

resolver::resolver(mdistancia mat) { //corregir
	rt = new ruta(mat);
	cout << "numero de vehiculos: " << mat.getnvehiculos() << endl;
	cout << "carga de los vehiculos: " << mat.getcarga() << endl;
	for (int i = 0; i < mat.getnvehiculos(); i++) {
		tvehiculo vec(i, mat.getcarga());
		vehiculos.push_back(vec);
	}
	coste_total = 0;
	cmed = 30; //carga media de los contenedores, hay que cambiarlo para que cada uno tenga su carga
	//cmed = mat.getnvehiculos();
};

void resolver::ejecutar() {
	bool existe = true;
	unsigned int i = 0;
	while ((i < vehiculos.size()) && (existe)){
		existe = rt->buscar(vehiculos[i], cmed);
		coste_total += vehiculos[i].get_coste();
		cout << "Iteracion : " << i << endl;
		i++;
	}
	if (i == vehiculos.size())
		cout << "Ha sido necesario usar todos los vehiculos" << endl;
	if (!existe)
		cout << "Se han visitado todos los puntos sin usar el total de vehiculos" << endl;
};

int resolver::get_coste_total() {
	return coste_total;
};

string resolver::get_ruta() {
	list <int> ret = rt->get_visitados();
	stringstream ss;
	for (list<int> ::iterator it = ret.begin(); it != ret.end(); it++) {
		ss << (*it) << " ";
	}
	return ss.str();
};


resolver::~resolver()
{
}
