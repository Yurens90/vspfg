#include "stdafx.h"
#include "precogida.h"

precogida::precogida() {
	id = -1;
	distancia = -1;
	visitado = false;
};

precogida::precogida(int x, float d) {
	visitado = NULL;
	id = x;
	distancia = d;
};

int precogida::getid() {
	return id;
};

float precogida::getdistancia() {
	return distancia;
};

precogida::precogida(const precogida &p) {
	visitado = NULL;
	id = p.id;
	distancia = p.distancia;
	demanda = p.demanda;
};

void precogida::setid(int iid) {
	id = iid;
};

void precogida::setdistancia(float o) {
	distancia = o;
};

void precogida::setvisitado() {
	visitado = true;
};

bool precogida::check_visitado() {
	return visitado;
};

bool precogida :: operator < (precogida p) const {
	if (distancia < p.getdistancia())
		return true;
	return false;
};

int precogida::getdemanda() {
	return demanda;
}

void precogida::setdemanda(int dmd) {
	demanda = dmd;
}

precogida::~precogida()
{
}
