#pragma once

#include "Pokemon.h";

class Charizard : public Pokemon
{
private:

public:
	Charizard(void);
	Charizard(int px, int py);
	~Charizard();

	void Mostrar(Graphics^ miGraphic);
};

Charizard::Charizard(void) { }

Charizard::Charizard(int px, int py) : Pokemon(px, py)
{
	ancho = 105;
	altura = 80;

	dx = 3;
	dy = 3;

	tipo = 4;
}

Charizard::~Charizard() { }

void Charizard::Mostrar(Graphics^ miGraphic)
{
	Bitmap^ imagenCharizard = gcnew Bitmap("img/Charizard.png");

	miGraphic->DrawImage(imagenCharizard, Rectangle(x, y, ancho, altura), Rectangle(0, 0, ancho, altura), GraphicsUnit::Pixel);
}