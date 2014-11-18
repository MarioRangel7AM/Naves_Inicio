#ifndef __NAVE_H__
#define __NAVE_H__
#include "sprite.h"
#include <SDL.h>

class nave{
	sprite *sprite1;
	int x;
	int y;
<<<<<<< HEAD
	int w;
	int h;
	bool automovimiento;
	int pasoActual;
	int pasoLimite;
	int modulo; //Modulo de actual
public:
		void Moverx(int posicion);
		void Movery(int posicion);
			nave(SDL_Surface * screen, char * rutaImagen,int x,int y,int modulo); //constructor
			void Pintar();
			void Pintar(int modulo,int x, int y);
			void SetAutoMovimiento(bool automovimiento);
			void SetPasoLimite(int pasos);
			int ObtenerPasoActual();
			void IncrementarPasoActual();
			bool EstaColicionando(nave*b);
			void actualizar();
			int Obtenerx();
			int Obtenery();
			int Obtenerw();
			int Obtenerh();
=======
<<<<<<< HEAD
	bool automovimiento;
	
public:
		void Mover(int posicion);
			nave(SDL_Surface * screen, char * rutaImagen,int x,int y);
			void Pintar();
			void SetAutoMovimiento(bool automovimiento);
			void actualizar();
=======
	
public:
		void Mover(int posicion);
			nave(SDL_Surface * screen, char * rutaImagen);
			void Pintar();
>>>>>>> origin/master
>>>>>>> origin/master
		
};

#endif