#include "nave.h"
#include "Config.h"

<<<<<<< HEAD
nave::nave(SDL_Surface * screen, char * rutaImagen,int x, int y,int modulo){
	this ->modulo = modulo;
	sprite1 = new sprite(screen);
	sprite1->CargarImagen(rutaImagen);
	w = sprite1->WidthModule(this->modulo);
	h = sprite1->HeightModule(this->modulo);
=======
<<<<<<< HEAD
nave::nave(SDL_Surface * screen, char * rutaImagen,int x, int y){
	sprite1 = new sprite(screen);
	sprite1->CargarImagen(rutaImagen);
>>>>>>> origin/master
	this->x = x;
	this->y = y;
	//x = (WIDTH_SCREEN/2)-(sprite1->WidthModule(0)/2);
	//y= (HEIGHT_SCREEN-80)-(sprite1->HeightModule(0));
	automovimiento = false;
<<<<<<< HEAD
	pasoActual = 0;
	pasoLimite = -1;
=======
>>>>>>> origin/master
}
void nave::SetAutoMovimiento(bool automovimiento)
{
	this->automovimiento = automovimiento;
}
void nave::actualizar()
{
	if(automovimiento)
	{
<<<<<<< HEAD
		Moverx(1);
	}
	if(pasoLimite > 0)
	{
		//pasoActual++;
		if(pasoActual>=pasoLimite)
			pasoActual = 0;
	}
}

void nave::Pintar(){
   sprite1->PintarModulo(modulo,x,y);
}

void nave::Pintar(int modulo,int x,int y)
{
	sprite1->PintarModulo(modulo,x,y);
}

void nave::Moverx(int posicion){
	x += posicion;
}
void nave::Movery(int posicion){
	y += posicion;
}
int nave::Obtenerx()
{
	return x;
}
int nave::Obtenery()
{
	return y;
}
int nave::Obtenerw()
{
	return w;
}
int nave::Obtenerh()
{
	return h;
}
void nave::SetPasoLimite(int pasos)
{
	this ->pasoLimite = pasos;
}

int nave::ObtenerPasoActual()
{
	return pasoActual;
}

void nave::IncrementarPasoActual()
{
	pasoActual++;
}

bool nave::EstaColicionando(nave*b) //Tarea
{
	return false;
}
=======
		Mover(1);
	}
=======
nave::nave(SDL_Surface * screen, char * rutaImagen){
	sprite1 = new sprite(screen);
	sprite1->CargarImagen(rutaImagen);
	x = (WIDTH_SCREEN/2)-(sprite1->WidthModule(0)/2);
	y= (HEIGHT_SCREEN-80)-(sprite1->HeightModule(0));
>>>>>>> origin/master
}

void nave::Pintar(){
   sprite1->PintarModulo(0,x,y);
}

void nave::Mover(int posicion){
	x += posicion;
}
>>>>>>> origin/master
