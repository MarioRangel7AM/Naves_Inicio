#include "nave.h"
Nave::Nave(SDL_Surface * screen, char * rutaImagen,int x,int y,int modulo)
{
	nave1 = new objeto(screen, rutaImagen, x , y , modulo);
}
void Nave::Pintar()
{
	nave1->Pintar();
}

void Nave::MoverAbajo()
{
	nave1->Movery(8);
}
void Nave::MoverArriba()
{
	nave1->Movery(-8);
}
void Nave::MoverDerecha()
{
	nave1->Moverx(8);
}
void Nave::MoverIsquierda()
{
	nave1->Moverx(-8);
}

objeto*Nave::GetNaveObjeto()
{
	return nave1;
}