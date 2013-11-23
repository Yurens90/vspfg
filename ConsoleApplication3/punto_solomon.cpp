#include "stdafx.h"
#include "punto_solomon.h"


punto_solomon::punto_solomon() {
	id = 0;
	x = 0;
	y = 0;
	demanda = 0;
	rtime = 0;
	ddate = 0;
	servtime = 0;
};

punto_solomon::punto_solomon(int aid, int ax, int ay, int ademanda, int artime, int addate, int aservtime) {
	id = aid;
	x = ax;
	y = ay;
	demanda = ademanda;
	rtime = artime;
	ddate = addate;
	servtime = aservtime;
};

void punto_solomon::setid(int i) {
	id = i;
};

void punto_solomon::setx(int i) {
	x = i;
};

void punto_solomon::sety(int i) {
	y = i;
};

void punto_solomon::setdemanda(int i) {
	demanda = i;
};

void punto_solomon::setrtime(int i) {
	rtime = i;
};

void punto_solomon::setddate(int i) {
	ddate = i;
};

void punto_solomon::setservtime(int i) {
	servtime = i;
};

int punto_solomon::getid() {
	return id;
};

int punto_solomon::getx() {
	return x;
};

int punto_solomon::gety() {
	return y;
};

int punto_solomon::getdemanda() {
	return demanda;
};

int punto_solomon::getrtime() {
	return rtime;
};

int punto_solomon::getddate() {
	return ddate;
};

int punto_solomon::setservtime() {
	return servtime;
};

punto_solomon::~punto_solomon()
{
};
