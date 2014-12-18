#ifndef __OBJETO_H__
#define __OBJETO_H__
#include "sprite.h"
#include <SDL.h>

class objeto{
	sprite *sprite1;
	int x;
	int y;
	int w;
	int h;
	bool automovimiento;
	int pasoActual;
	int pasoLimite;
	int modulo; //Modulo de actual
	bool isVisibl;
public:
	void SetVisible(bool isVisibl);
		void Moverx(int posicion);
		void Movery(int posicion);
			objeto(SDL_Surface * screen, char * rutaImagen,int x,int y,int modulo); //constructor
			void Pintar();
			void Pintar(int modulo,int x, int y);
			void SetAutoMovimiento(bool automovimiento);
			void SetPasoLimite(int pasos);
			int ObtenerPasoActual();
			void IncrementarPasoActual();
			bool EstaColicionando(objeto*b);
			void actualizar();
			int Obtenerx();
			int Obtenery();
			int Obtenerw();
			int Obtenerh();
			void ponerEn(int x, int y);
		
};

#endif