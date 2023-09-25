#pragma once

#include "Pokemon.h";

class PiedraFuego : public Pokemon
{
public:
	PiedraFuego(void);
	PiedraFuego(int px, int py);
	~PiedraFuego();

	void Mostrar(Graphics^ miGraphic);
};

PiedraFuego::PiedraFuego(void) { }

PiedraFuego::PiedraFuego(int px, int py) : Pokemon(px, py)
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
	tipo = 2;
}

PiedraFuego::~PiedraFuego() { }

void PiedraFuego::Mostrar(Graphics^ miGraphic)
{
	Bitmap^ ImagenPiedraFuego = gcnew Bitmap("img/Piedra2.png");

	miGraphic->DrawImage(ImagenPiedraFuego, Rectangle(x, y, ancho, altura), Rectangle(0, 0, ancho, altura), GraphicsUnit::Pixel);
}