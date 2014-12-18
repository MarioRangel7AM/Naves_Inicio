#include "objeto.h"
#include "Config.h"

objeto::objeto(SDL_Surface * screen, char * rutaImagen,int x, int y,int modulo){
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
	isVisibl = true;
}
void objeto::SetAutoMovimiento(bool automovimiento)
{
	this->automovimiento = automovimiento;
}
void objeto::actualizar()
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

void objeto::Pintar(){
	if(isVisibl)
   sprite1->PintarModulo(modulo,x,y);
}

void objeto::Pintar(int modulo,int x,int y)
{
	if(isVisibl)
	sprite1->PintarModulo(modulo,x,y);
}

void objeto::SetVisible( bool iSVisibl)
{
	this->isVisibl = isVisibl;
}

void objeto::Moverx(int posicion){
	x += posicion;
}
void objeto::Movery(int posicion){
	y += posicion;
}
int objeto::Obtenerx()
{
	return x;
}
int objeto::Obtenery()
{
	return y;
}
int objeto::Obtenerw()
{
	return w;
}
int objeto::Obtenerh()
{
	return h;
}
void objeto::SetPasoLimite(int pasos)
{
	this ->pasoLimite = pasos;
}

int objeto::ObtenerPasoActual()
{
	return pasoActual;
}

void objeto::IncrementarPasoActual()
{
	pasoActual++;
}

bool objeto::EstaColicionando(objeto*b) //Tarea
{
	return false;
}

void objeto::ponerEn(int x, int y)
{
	this->x=x;
	this->y=y;
}