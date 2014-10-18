#include "nave.h"
#include "Config.h"

<<<<<<< HEAD
nave::nave(SDL_Surface * screen, char * rutaImagen,int x, int y){
	sprite1 = new sprite(screen);
	sprite1->CargarImagen(rutaImagen);
	this->x = x;
	this->y = y;
	//x = (WIDTH_SCREEN/2)-(sprite1->WidthModule(0)/2);
	//y= (HEIGHT_SCREEN-80)-(sprite1->HeightModule(0));
	automovimiento = false;
}
void nave::SetAutoMovimiento(bool automovimiento)
{
	this->automovimiento = automovimiento;
}
void nave::actualizar()
{
	if(automovimiento)
	{
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
