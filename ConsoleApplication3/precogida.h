#pragma once
class precogida
{
public:
	//String nombre;
	int id; //numero identificador
	float distancia; //distancia
	bool visitado;
	int demanda;
public:
	precogida();
	precogida(int x, float d);
	int getid(); //indice original de cada fila en la matriz de distancias
	float getdistancia();
	precogida(const precogida &p);
	void setid(int iid);
	void setdistancia(float o);
	void setvisitado();
	bool check_visitado();
	bool operator < (precogida p) const;
	int getdemanda();
	void setdemanda(int dmd);
	~precogida();
};

