#pragma once
#include <iostream>
#include "resolver.h"
#include <stdlib.h>
#include <time.h>
//#include <sys/time.h>
#include <winsock2.h>
#include <fstream>
using namespace std;
class optimo {
private:
	resolver * inicial;
	resolver * menor;
	mdistancia matr;
public:
	optimo();
	optimo(mdistancia &mat);
	~optimo();
	void repetir(int i, char delimitador);
};

