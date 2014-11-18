#include "nave.h"
#include "Config.h"

nave::nave(SDL_Surface * screen, char * rutaImagen,int x, int y,int modulo){
	this ->modulo = modulo;
	sprite1 = new sprite(screen);
	sprite1->CargarImagen(rutaImagen);
	w = sprite1->WidthModule(this->modulo);
	h = sprite1->HeightModule(this->modulo);
	this->x = x;
	this->y = y;
	//x = (WIDTH_SCREEN/2)-(sprite1->WidthModule(0)/2);
	//y= (HEIGHT_SCREEN-80)-(sprite1->HeightModule(0));
	automovimiento = false;
	pasoActual = 0;
	pasoLimite = -1;
}
void nave::SetAutoMovimiento(bool automovimiento)
{
	this->automovimiento = automovimiento;
}
void nave::actualizar()
{
	if(automovimiento)
	{
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