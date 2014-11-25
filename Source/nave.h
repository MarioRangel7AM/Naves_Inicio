#ifndef __NAVE_H__
#define __NAVE_H__
#include "objeto.h"

class Nave
{
	objeto * nave1;
	objeto * bala;
public:
	Nave(SDL_Surface * screen, char * rutaImagen,int x,int y,int modulo);
	void Pintar();
	void MoverArriba();
	void MoverAbajo();
	void MoverIsquierda();
	void MoverDerecha();
	objeto * GetNaveObjeto();
};

#endif