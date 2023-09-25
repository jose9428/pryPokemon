#pragma once

#include<stdlib.h>

using namespace System;
using namespace System::Drawing;

class Pokemon
{
protected:
	int x;
	int y;

	int dx;
	int dy;
	int ancho;
	int altura;
	int tipo;//1 = Piedra de Agua, 2 = Piedra de Fuego, 3 = Blastoise, 4 = Charizard , 
public:
	Pokemon(void);
	Pokemon(int px, int py);
	~Pokemon(void);

	int GET_x();
	int GET_y();
	int GET_ancho();
	int GET_altura();
	int GET_tipo();
	int GET_dx();
	int GET_dy();


	void InvertirDx();
	void InvertirDy();

	void Mover();
	virtual void Mostrar(Graphics^ miGraphic) abstract;
};


Pokemon::Pokemon(void) {}
Pokemon::Pokemon(int px, int py)
{
	x = px;
	y = py;

}

Pokemon::~Pokemon(void) {}

int Pokemon::GET_x() { return x; }
int Pokemon::GET_y() { return y; }
int Pokemon::GET_ancho() { return ancho; }
int Pokemon::GET_altura() { return altura; }
int Pokemon::GET_tipo() { return tipo; }
int Pokemon::GET_dx() { return dx; }
int Pokemon::GET_dy() { return dy; }

void Pokemon::InvertirDx()
{
	dx *= -1;
}

void Pokemon::InvertirDy()
{
	dy *= -1;
}

void Pokemon::Mover()
{
	x += dx;
	y += dy;
}