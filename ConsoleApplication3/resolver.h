#pragma once
#include <vector>
#include <iostream>
#include "tvehiculo.h"
#include "ruta.h"
#include <sstream>
using namespace std;
class resolver {
private:
	vector <tvehiculo> vehiculos; //contiene una lista con los vehiculos que van a realizar las recogidas
	ruta * rt; //se encarga de buscar las rutas para los camiones
	float coste_total;
	int cmed; //carga media de los contenedores
public:
	resolver();
	resolver(mdistancia mat);
	~resolver();
	void ejecutar();
	int get_coste_total();
	string get_ruta();
};
