#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	estado = ESTADO_INICIANDO;
	atexit(SDL_Quit);
}


void CGame::Finalize()
{
	SDL_Quit();
}

void CGame::Iniciando()
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	screen = SDL_SetVideoMode(WIDTH_SCREEN, 480, 24, SDL_HWSURFACE);
	if (screen == NULL)
	{
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("Mi primer Juego", NULL);

	atexit(SDL_Quit);
	nave1 = new nave(screen,"../Data/Minave.bmp");
	
}
bool CGame::Start()
{
	
	int salirJuego = false;
          
	while (salirJuego == false){
            
		
		switch(estado){
		case Estado::ESTADO_INICIANDO:
			Iniciando();
			estado = Estado::ESTADO_MENU;
			break;
		case Estado::ESTADO_MENU:
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,0,0,0));

			keys = SDL_GetKeyState(NULL);
			if(keys[SDLK_RIGHT]){
				nave1->Mover(1);
				
			}
			if (keys[SDLK_LEFT]){
			nave1->Mover(-1);
			}
			nave1->Pintar();
			
			break;
		case Estado::ESTADO_JUGANDO:	
			break;
		case Estado::ESTADO_TERMINANDO: 
				salirJuego = true;
				break;
		case Estado::ESTADO_FINALIZANDO:
			delete(nave1);
			SDL_FreeSurface(screen);
			SDL_Quit();
			break;
		};

		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) {salirJuego = true;}
			if(event.type == SDL_KEYDOWN) { }
		}
		SDL_Flip(screen);
    }
	return true;
}
