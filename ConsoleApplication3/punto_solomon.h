#pragma once

class punto_solomon {
private:
	int id;
	int x;
	int y;
	int demanda;
	int rtime;
	int ddate;
	int servtime;
public:
	//constructor normal y con los parámetros
	punto_solomon();
	~punto_solomon();
	punto_solomon(int aid, int ax, int ay, int ademanda, int artime, int addate, int aservtime);
	//getter y setter para todos
	void setid(int i);
	void setx(int i);
	void sety(int i);
	void setdemanda(int i);
	void setrtime(int i);
	void setddate(int i);
	void setservtime(int i);
	int getid();
	int getx();
	int gety();
	int getdemanda();
	int getrtime();
	int getddate();
	int setservtime();
};

