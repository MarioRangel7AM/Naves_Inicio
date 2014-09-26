#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	estado = ESTADO_INICIADO;
	if(SDL_Init(SDL_INIT_VIDEO)){
		printf("Error %s ",SDL_GetError());
		exit(EXIT_FAILURE);
	}
	Screen = SDL_SetVideoMode( 640, 480, 24, SDL_SWSURFACE);
	if(Screen == NULL){
		printf("Error!!%s ",SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_WM_SetCaption("Mi primer Jueguini",NULL);
	atexit(SDL_Quit);
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case Estado::ESTADO_INICIADO:
			break;
		case Estado::ESTADO_MENU:
			break;
		case Estado::ESTADO_JUGANDO:
			break;
		case Estado::ESTADO_TERMINANDO:
				salirJuego = true;
			break;
		case Estado::ESTADO_FINALIZANDO:
			break;
		};
		SDL_Flip(Screen);
    }
	return true;
}
