#pragma once

#include "PiedraAgua.h";
#include "PiedraFuego.h";
#include "Charizard.h";
#include "Blastoise.h";

class ArrPokemon
{
private:
	Pokemon** arreglo;
	int cantidad;
	int contBlastoise;
	int contCharizard;
	int combx;
	int comby;

public:
	ArrPokemon(void);
	~ArrPokemon(void);

	int GET_cantidad();
	int GET_contBlastoise();
	int GET_contCharizard();

	void Insertar(int tipo);

	void Eliminar(int posEnArreglo);
	void VerificarColisiones(Graphics^ miGraphic);
	void MoverTodo(Graphics^ miGraphic);
};

ArrPokemon::ArrPokemon(void)
{
	contBlastoise = 0;
	contCharizard = 0;
	cantidad = 0;
	arreglo = NULL;
}

ArrPokemon::~ArrPokemon(void)
{
	for (int i = 0; i < cantidad; i++)
		delete arreglo[i];
}

int ArrPokemon::GET_cantidad() { return cantidad; }
int ArrPokemon::GET_contBlastoise() { return contBlastoise; }
int ArrPokemon::GET_contCharizard() { return contCharizard; }

void ArrPokemon::Insertar(int tipo)
{

	Pokemon** auxiliar = new Pokemon * [cantidad + 1];

	if (auxiliar != NULL)
	{
		for (int i = 0; i < cantidad; i++)
			auxiliar[i] = arreglo[i];


		/* CREACIÓN DE OBJETOS SEGÚN TIPO */
		// Tipo 1 -> Piedra Agua 
		// Tipo 2 -> Piedra Fuego 
		// Tipo 3 -> Blastoise
		// Tipo 4 -> Charizard

		if (tipo == 1) { auxiliar[cantidad] = new PiedraAgua(rand() % 635, rand() % 335); }
		if (tipo == 2) { auxiliar[cantidad] = new PiedraFuego(rand() % 635, rand() % 335); }
		if (tipo == 3) { auxiliar[cantidad] = new Blastoise(rand() % 635, rand() % 335); }
		if (tipo == 4) { auxiliar[cantidad] = new Charizard(rand() % 635, rand() % 335); }

		cantidad++;

		if (arreglo != NULL)
			delete arreglo;

		arreglo = auxiliar;
	}
}


void ArrPokemon::Eliminar(int posEnArreglo)
{
	Pokemon** auxiliar = new Pokemon * [cantidad - 1];

	if (auxiliar != NULL)
	{

		for (int i = 0; i <= posEnArreglo - 1; i++)
			auxiliar[i] = arreglo[i];

		for (int i = posEnArreglo + 1; i < cantidad; i++)
			auxiliar[i - 1] = arreglo[i];

		cantidad--;

		if (arreglo != NULL)
			delete arreglo;

		arreglo = auxiliar;
	}
}

void ArrPokemon::VerificarColisiones(Graphics^ miGraphic)
{

	/* 1- TRIPLE COLISIÓN */

	for (int i = 0; i < cantidad - 2; i++)
		for (int j = i + 1; j < cantidad - 1; j++)
			for (int h = j + 1; h < cantidad - 0; h++)
			{
				//Creamos 3 Rectangulos es decir 3 objetos (METODO CRAYON)				
				Rectangle obj1 = Rectangle(arreglo[i]->GET_x(), arreglo[i]->GET_y(), arreglo[i]->GET_ancho(), arreglo[i]->GET_altura());
				Rectangle obj2 = Rectangle(arreglo[j]->GET_x(), arreglo[j]->GET_y(), arreglo[j]->GET_ancho(), arreglo[j]->GET_altura());
				Rectangle obj3 = Rectangle(arreglo[h]->GET_x(), arreglo[h]->GET_y(), arreglo[h]->GET_ancho(), arreglo[h]->GET_altura());


				// Verificamos Triple colision
				if (!(obj1.IntersectsWith(obj2)) || !(obj2.IntersectsWith(obj3)) || !(obj3.IntersectsWith(obj1)))
					;//No Hacemos Nada

				// Triple colision : OK 
				else
				{
					// CASO 1: 1 piedra agua y 2 piedras fuego  (Charizard)
					if ((arreglo[i]->GET_tipo() == 2 && arreglo[j]->GET_tipo() == 1 && arreglo[h]->GET_tipo() == 1) ||
						(arreglo[j]->GET_tipo() == 2 && arreglo[i]->GET_tipo() == 1 && arreglo[h]->GET_tipo() == 1) ||
						(arreglo[h]->GET_tipo() == 2 && arreglo[i]->GET_tipo() == 1 && arreglo[j]->GET_tipo() == 1))
					{

						//Coordenada de partida de la nueva combinacion
						combx = (arreglo[i]->GET_x() + arreglo[j]->GET_x() + arreglo[h]->GET_x()) / 3;
						comby = (arreglo[i]->GET_y() + arreglo[j]->GET_y() + arreglo[h]->GET_y()) / 3;

						Insertar(4); //Inserta Charizard
						contCharizard++; // +1 Charizard

					} //end if

					// CASO 2: 1 piedra fuego y 2 piedras agua (Blastoise)
					if ((arreglo[i]->GET_tipo() == 1 && arreglo[j]->GET_tipo() == 2 && arreglo[h]->GET_tipo() == 2) ||
						(arreglo[j]->GET_tipo() == 1 && arreglo[i]->GET_tipo() == 2 && arreglo[h]->GET_tipo() == 2) ||
						(arreglo[h]->GET_tipo() == 1 && arreglo[i]->GET_tipo() == 2 && arreglo[j]->GET_tipo() == 2))
					{

						//Coordenada de partida de la nueva combinacion
						combx = (arreglo[i]->GET_x() + arreglo[j]->GET_x() + arreglo[h]->GET_x()) / 3;
						comby = (arreglo[i]->GET_y() + arreglo[j]->GET_y() + arreglo[h]->GET_y()) / 3;

						Insertar(3); //Inserta Blastoise
						contBlastoise++; // +1 Blastoise
					}  //end if


				}

			}

	/* 2- REBOTE : Colision Pokemon-Pared (recorrido de elementos)	*/
	for (int i = 0; i < cantidad; i++)
	{

		if (arreglo[i]->GET_tipo() == 3 || arreglo[i]->GET_tipo() == 4)
		{
			/* EJE X */
			//Si choca con la pared izquierda o si choca con la pared derecha...
			if (arreglo[i]->GET_x() + arreglo[i]->GET_dx() < 0 || arreglo[i]->GET_x() + arreglo[i]->GET_dx() + arreglo[i]->GET_ancho() > miGraphic->VisibleClipBounds.Width)
				arreglo[i]->InvertirDx();//Cambiamos el sentido en el que se mueve horizontalmente

			/* EJE Y */
			//Si es que choca con la pared de arriba o si choca con la pared abajo
			if (arreglo[i]->GET_y() + arreglo[i]->GET_dy() < 0 || arreglo[i]->GET_y() + arreglo[i]->GET_dy() + arreglo[i]->GET_altura() > miGraphic->VisibleClipBounds.Height)
				arreglo[i]->InvertirDy();//Cambiamos el sentido en el que se mueve verticalmente
		}
	}

}

void ArrPokemon::MoverTodo(Graphics^ miGraphic)
{
	VerificarColisiones(miGraphic);

	for (int i = 0; i < cantidad; i++)
	{
		arreglo[i]->Mover();
		arreglo[i]->Mostrar(miGraphic);
	}
}

