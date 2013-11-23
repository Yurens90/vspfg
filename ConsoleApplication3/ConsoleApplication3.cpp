// ConsoleApplication3.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include "solomon.h"
#include "precogida.h"
#include "optimo.h"
using namespace std;


int main(int argc,      // Number of strings in array argv
	char *argv[],   // Array of command-line argument strings
	char *envp[])  // Array of environment variable strings
{
    cout << argv[1] << endl;
	solomon sol(argv[1]);
	sol.mostrarlistado();
	sol.calcularmatriz();
	mdistancia matriz;
	matriz = sol.convertir();
	optimo opt(matriz);
	opt.repetir(100, ';');
	cin.get();
}

