#include "stdafx.h"
#include "optimo.h"


optimo::optimo()
{
}

optimo::optimo(mdistancia &mat) {
	inicial = new resolver(mat);
	menor = new resolver(mat);
	matr = mat;
}



//implementar salida
void optimo::repetir(int n, char delimitador) {
	menor->ejecutar();
    //struct timeval inicio, fin;
	//struct
	clock_t t1;
	clock_t t2;
	//double tiempo;
	unsigned int mejorit = 0;
	double mejortiempo = 0.0;
	stringstream ss;
	ofstream out("salida.txt");
	for (int i = 0; i < n; i++) {
		//gettimeofday(&inicio, NULL);
		t1 = clock();
		//cout << endl << endl << endl;
		resolver *sol = new resolver(matr);
		sol->ejecutar();
		//cout << "Sol->getcoste... " << sol->get_coste_total() << " VS " << menor->get_coste_total() << endl;
		//gettimeofday(&fin, NULL);
		t2 = clock();
		double tiempo = (double)(t2 - t1) / CLOCKS_PER_SEC;
		//float tiempo = ((fin.tv_sec + (float)fin.tv_usec / 1000000) - (inicio.tv_sec + (float)inicio.tv_usec / 1000000));
		//loat tiempo = 0;
		if (sol->get_coste_total() < menor->get_coste_total()) {
			//cout << "---> Se ha encontrado una mejor" << endl;
			menor = sol;
			mejorit = i;
			mejortiempo = tiempo;
		}

		ss << i << delimitador << tiempo << delimitador << sol->get_ruta() << delimitador << sol->get_coste_total() << endl;
	};
	out << "Iteracion mejor solucion" << delimitador << "tiempo" << delimitador << "ruta" << delimitador << "coste" << endl;
	out << mejorit << delimitador << mejortiempo << delimitador << menor->get_ruta() << delimitador << menor->get_coste_total() << endl;
	out << "Numero_iteracion" << delimitador << "tiempo" << delimitador << "ruta" << delimitador << "coste" << endl;
	out << ss.str();
	out.close();
	cout << "Iteracion del mejor: " << mejorit << endl;
	cout << "El mejor: " << menor->get_coste_total() << endl;
	cout << "ruta: " << menor->get_ruta() << endl;
};

optimo::~optimo()
{
}
