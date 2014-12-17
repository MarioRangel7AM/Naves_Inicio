#include "nave.h"
#include "config.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen,int x,int y,int modulo)
{
	nave1 = new objeto(screen, rutaImagen, x , y , modulo);
	for(int i = 0;i<MAXIMO_DE_BALAS;i++)
	{
	bala[i] = new objeto(screen,"../Data/balas.bmp",0,0,MODULO_BALAS_BALA);
	bala[i]->SetVisible(false);
	}
	balasVisisbles = 0;
	visible = true;
	colision = false;
}
void Nave::CrearNuevo()
{
	balasVisisbles = 0;
	visible = true;
	colision = false;
	for(int i = 0;i<MAXIMO_DE_BALAS;i++)
	{
	bala[i]->SetVisible(false);
	}
	nave1->ponerEn(0,0);
}
void Nave::Pintar(int tiponave)
{
	if(visible)
	{
	nave1->Pintar();
	for(int i = 0;i<MAXIMO_DE_BALAS;i++)
	{
	bala[i]->Pintar();
	switch(tiponave)
	{
	case NAVE_PROPIA:
		bala[i]->Movery(-8);
		break;
	case NAVE_ENEMIGO:
			bala[i]->Movery(8);
			break;
	   }
	  }
	}
}

void Nave::Disparar(int tiponave, int balas)
{
	if(visible)
	{
	bala[balasVisisbles]->SetVisible(true);
	switch(tiponave)
	{
	case NAVE_PROPIA:
		bala[balasVisisbles]->ponerEn(nave1->Obtenerx()+nave1->Obtenerw()/2,nave1->Obtenery());
		break;
	case NAVE_ENEMIGO:
		bala[balasVisisbles]->ponerEn(nave1->Obtenerx()+nave1->Obtenerw()/2,nave1->Obtenery()+nave1->Obtenerh());
			break;
	}
	balasVisisbles++;
	if(balasVisisbles >= balas)
		balasVisisbles = 0;
	}
}
void Nave::AutoDisparar(int balas)
{
	if((rand() % 100)<2)
	Disparar(NAVE_ENEMIGO,balas);
}

void Nave::MoverAbajo(int velocidad)
{
	nave1->Movery(velocidad);
}
void Nave::MoverArriba(int velocidad)
{
	nave1->Movery(-velocidad);
}
void Nave::MoverDerecha(int velocidad)
{
	nave1->Moverx(velocidad);
}
void Nave::MoverIsquierda(int velocidad)
{
	nave1->Moverx(-velocidad);
}

objeto*Nave::GetNaveObjeto()
{
	return nave1;
}

void Nave::SetVisible(bool visible)
{
	this->visible = visible;

}

bool Nave::EstadoColicionandoConBala(Nave * nave)
{
	return colision;
}

void Nave::simularColicion(bool colision)
{
	this->colision = colision;
}