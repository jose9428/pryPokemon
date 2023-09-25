#pragma once
#include "Pokemon.h";

/*** BLASTOISE CLASS (3)***/
// - Hija de Pokemon class
class Blastoise : public Pokemon
{
private:

public:
	Blastoise(void);
	Blastoise(int px, int py);
	~Blastoise();

	void Mostrar(Graphics^ miGraphic);
};

Blastoise::Blastoise(void) { }

Blastoise::Blastoise(int px, int py) : Pokemon(px, py)
{
	ancho = 71;
	altura = 67;

	dx = 3;
	dy = 3;

	tipo = 3;
}

Blastoise::~Blastoise() { }

void Blastoise::Mostrar(Graphics^ miGraphic)
{
	Bitmap^ imagenBlastoise = gcnew Bitmap("img/Blastoise.png");

	miGraphic->DrawImage(imagenBlastoise, Rectangle(x, y, ancho, altura), Rectangle(0, 0, ancho, altura), GraphicsUnit::Pixel);
}