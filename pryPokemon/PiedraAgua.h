#pragma once
#include "Pokemon.h";

class PiedraAgua : public Pokemon
{
private:

public:
	PiedraAgua(void);
	PiedraAgua(int px, int py);
	~PiedraAgua();

	void Mostrar(Graphics^ miGraphic);
};

PiedraAgua::PiedraAgua(void) { }

PiedraAgua::PiedraAgua(int px, int py) : Pokemon(px, py)
{
	ancho = 23;
	altura = 23;
	int R = rand() % 2;


	if (R)
	{
		dx = 5;
		dy = 5;
	}
	else
	{
		dx = -5;
		dy = 5;
	}

	tipo = 1;
}

PiedraAgua::~PiedraAgua() { }



void PiedraAgua::Mostrar(Graphics^ miGraphic) {
	Bitmap^ ImagenPiedraAgua = gcnew Bitmap("img/Piedra1.png");

	miGraphic->DrawImage(ImagenPiedraAgua, Rectangle(x, y, ancho, altura), Rectangle(0, 0, ancho, altura), GraphicsUnit::Pixel);
}