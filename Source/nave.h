#ifndef __NAVE_H__
#define __NAVE_H__
#include "sprite.h"
#include <SDL.h>

class nave{
	sprite *sprite1;
	int x;
	int y;
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
		
};

#endif