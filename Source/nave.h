#ifndef __NAVE_H__
#define __NAVE_H__
#include "objeto.h"
#include "config.h"
class Nave
{
	objeto * nave1;
	objeto * bala[MAXIMO_DE_BALAS];
	int balasVisisbles;
	bool visible;
	bool colision;
public:
	Nave(SDL_Surface * screen, char * rutaImagen,int x,int y,int modulo);
	void Pintar(int tiponave);

	void MoverArriba(int velocidad);
	void MoverAbajo(int velocidad);
	void MoverIsquierda(int velocidad);
	void MoverDerecha(int velocidad);
	void Disparar(int tiponave, int balas);

	void AutoDisparar(int balas);
	objeto * GetNaveObjeto();
	bool EstadoColicionandoConBala(Nave* nave);
	void SetVisible(bool visible);
	void simularColicion(bool colision);
	void CrearNuevo();
};

#endif