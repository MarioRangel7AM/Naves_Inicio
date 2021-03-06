#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	tiempoFrame = 0;
	estado = ESTADO_INICIANDO;
	atexit(SDL_Quit);
}


void CGame::Finalize()
{
	delete(nave1);
	//delete *keys;
	delete *enemigoArreglo;
	SDL_FreeSurface(screen);
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
	if(imagena == NULL)
	{
		printf("Error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_WM_SetCaption("Mi primer Jueguini", NULL);
	atexit(SDL_Quit);
	nave1 = new Nave(screen,"../Data/Minave.bmp",(WIDTH_SCREEN/2),(HEIGHT_SCREEN-80),MODULO_MINAVE_NAVE);
	fondo1 = new objeto(screen,"../Data/fondo1.bmp",0,0,MODULO_TITULO1_FONDO);
	titulo = new objeto(screen,"../Data/titulo1.bmp",0,0,MODULO_TITULO1_FONDO);
	menuT = new objeto(screen,"../Data/Menu.bmp",0,0,-1);
	//menuN = new nave(screen,"../Data/Menu.bmp",164,435,MODULO_MENU_NOMBRE);
	//menuI1 = new nave(screen,"../Data/Menu.bmp",165,162,MODULO_MENU_INICIO1);
	//menuS1 = new nave(screen,"../Data/Menu.bmp",162,194,MODULO_MENU_SALIR1);
	for(int i =0; i < 10 ; i++)
	{
		enemigoArreglo[i] = new Nave(screen,"../Data/enemigo.bmp",i*60,0,2);
		enemigoArreglo[i]->GetNaveObjeto()->SetAutoMovimiento(false);
		enemigoArreglo[i]->GetNaveObjeto()->SetPasoLimite(4);
	}
	tick = 0;
	OpcionSeleccionada = MODULO_MENU_INICIO1;
}
bool CGame::Start()
{
	int salirJuego = false;
          int cosa = 0;
	while (salirJuego == false){
		
		switch(estado){
		case Estado::ESTADO_INICIANDO:
			Iniciando();
			inicializandoStage();
			printf("\n1.ESTADO_INICIANDO");
			estado = Estado::ESTADO_MENU;
			//estado = Estado::ESTADO_JUGANDO;
			//estado = Estado::ESTADO_PRE_JUGANDO;
			break;
		case Estado::ESTADO_MENU:
			titulo->Pintar();
			menuT->Pintar(MODULO_MENU_TITULO,178,34);
			menuT->Pintar(MODULO_MENU_NOMBRE,164,435);
			menuT->Pintar(MODULO_MENU_INICIO1,165,162);
			//menuT->Pintar(MODULO_MENU_SALIR1,162,194);
			Menu();
			//estado = Estado::ESTADO_JUGANDO;
			break;
		case Estado::ESTADO_PRE_JUGANDO:
			nivelActual = 0;
			vida = 1;
			enemigosEliminados = 0;
			estado = ESTADO_JUGANDO;
			break;
		case Estado::ESTADO_JUGANDO:
			//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,0,0,0));
			fondo1->Pintar();
			for(int i = 0; i < nivel[nivelActual].NumerosEnemigosVisibles; i++)
			{
				enemigoArreglo[i]->GetNaveObjeto()->actualizar();
			}
			MoverEnemigo();
			keys = SDL_GetKeyState(NULL);
			if(keys[SDLK_RIGHT]){
				if(!EsLimitePantalla(nave1->GetNaveObjeto(),BORDE_DERECHO))
					nave1->MoverDerecha(nivel[nivelActual].VelocidadNavePropia);
			}
			if (keys[SDLK_LEFT]){
				if(!EsLimitePantalla(nave1->GetNaveObjeto(),BORDE_IZQUIERDO))
					nave1->MoverIsquierda(nivel[nivelActual].VelocidadNavePropia);
			}
			if(keys[SDLK_UP]){
				if(!EsLimitePantalla(nave1->GetNaveObjeto(),BORDE_SUPERIOR))
					nave1->MoverArriba(nivel[nivelActual].VelocidadNavePropia);
			}
			if(keys[SDLK_DOWN]){
				if(!EsLimitePantalla(nave1->GetNaveObjeto(),BORDE_INFERIOR))
					nave1->MoverAbajo(nivel[nivelActual].VelocidadNavePropia);
			}

			if(keys[SDLK_SPACE]){
				nave1->Disparar(NAVE_PROPIA,nivel[nivelActual].balasMax);
			}

			//Simulacion de coliciones//
			if(keys[SDLK_x]){
				nave1->simularColicion(true);
			}
			if(keys[SDLK_c]){
				int EnemigosAEliminar = rand() % nivel[nivelActual].NumerosEnemigosVisibles;
				enemigoArreglo[EnemigosAEliminar]->simularColicion(true);
			}
			if(keys[SDLK_v]){
				//NUESTRA NAVE / NAVE ENEMIGO
			}

			//Control de colisiones//

			for(int i=0; i < nivel[nivelActual].NumerosEnemigosVisibles; i++)
			{
				if(enemigoArreglo[i]->EstadoColicionandoConBala(nave1))
					vida--;
				if(nave1->EstadoColicionandoConBala(enemigoArreglo[i]))
				{
					enemigoArreglo[i]->SetVisible(false);
				enemigosEliminados++;
				nave1->simularColicion(false);
				if(enemigosEliminados < nivel[nivelActual].NumeroEnemigosAEliminar)
				{
					enemigoArreglo[i]->CrearNuevo();
				}
				}
			}

			nave1->Pintar(NAVE_PROPIA);
			SDL_SetColorKey;
		    for(int i = 0; i < nivel[nivelActual].NumerosEnemigosVisibles; i++)
			{
				enemigoArreglo[i]->Pintar(NAVE_ENEMIGO);
				enemigoArreglo[i]->AutoDisparar(nivel[nivelActual].balasMax);
			}
			if(vida<=0)
				estado = ESTADO_MENU;
			if(enemigosEliminados>=nivel[nivelActual].NumeroEnemigosAEliminar)
				nivelActual++;
			//maybe cargar otro fondo
			break;
		case Estado::ESTADO_TERMINANDO:
				salirJuego = false;
				break;
		case Estado::ESTADO_FINALIZANDO:
			break;
		};

		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) {salirJuego = true;}
			if(event.type == SDL_KEYDOWN) { }
		}
		SDL_Flip(screen);
		tiempoFrameFinal = SDL_GetTicks();
		while(tiempoFrameFinal < (tiempoFrame + FPS_DELAY))
		{
			tiempoFrameFinal = SDL_GetTicks();
			SDL_Delay(1);
		}
		printf("Frames:%d tiempo:%d Tiempo promedio:%f Tiempo por frame:%d FPS:%f\n",tick,SDL_GetTicks(), (float)SDL_GetTicks()/(float)tick,tiempoFrameFinal - tiempoFrame,1000.0f / (float)(tiempoFrameFinal - tiempoFrame));
		tiempoFrame = tiempoFrameFinal;
		tick++;
    }
	return true;
}
bool CGame::EsLimitePantalla(objeto * objeto,int bandera)
{
	if(bandera & BORDE_IZQUIERDO)
	if(objeto->Obtenerx() <= 0)
		return true;
	if(bandera & BORDE_SUPERIOR)
	if(objeto->Obtenery() <= 0)
		return true;
	if(bandera & BORDE_DERECHO)
	if(objeto->Obtenerx() >= WIDTH_SCREEN-objeto->Obtenerw())
		return true;
	if(bandera & BORDE_INFERIOR)
	if(objeto->Obtenery() >= HEIGHT_SCREEN-objeto->Obtenerh())
		return true;
	return false;
}

void CGame::MoverEnemigo()
{

				for(int i = 0; i < nivel[nivelActual].NumerosEnemigosVisibles; i++)
				{
				
					if(enemigoArreglo[i]->GetNaveObjeto()->ObtenerPasoActual()==0)
						if(!EsLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(),BORDE_DERECHO))
							enemigoArreglo[i]->GetNaveObjeto()->Moverx(nivel[nivelActual].velocidadEnemigo);//derechin
	else
	{
		enemigoArreglo[i]->GetNaveObjeto()->IncrementarPasoActual();
		enemigoArreglo[i]->GetNaveObjeto()->IncrementarPasoActual();
	}
	//if(enemigoArreglo[i]->ObtenerPasoActual()==1)
		//if(!EsLimitePantalla(enemigoArreglo[i],BORDE_INFERIOR))
			//enemigoArreglo[i]->Movery(1);//Abajin
			if(enemigoArreglo[i]->GetNaveObjeto()->ObtenerPasoActual()==2)
				if(!EsLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(),BORDE_IZQUIERDO))
					enemigoArreglo[i]->GetNaveObjeto()->Moverx(-nivel[nivelActual].velocidadEnemigo);//Izquierdin
				else
				{
					enemigoArreglo[i]->GetNaveObjeto()->IncrementarPasoActual();
					enemigoArreglo[i]->GetNaveObjeto()->IncrementarPasoActual();
				}
					//if(enemigoArreglo[i]->ObtenerPasoActual()==3)
						//if(!EsLimitePantalla(enemigoArreglo[i],BORDE_INFERIOR))
							//enemigoArreglo[i]->Movery(1);//abajin
				}
}

/*void CGame::Menu()
{
	for(int i=MODULO_MENU_INICIO1,j = 0; i <= MODULO_MENU_SALIR1;i++,j++)
	{
		if(i == OpcionSeleccionada)
			menuT->Pintar(i+2,165,162+(j*80));
		else
		menuT->Pintar(i,165,162+(j*32));
	}
}*/

void CGame::Menu()
{
	for(int i=MODULO_MENU_INICIO1,j = 0; i <= MODULO_MENU_SALIR1;i++,j++)
	{
		keys = SDL_GetKeyState(NULL);
		if(keys[SDLK_UP])
		{
			OpcionSeleccionada = MODULO_MENU_INICIO1;
		}
		if(keys[SDLK_DOWN])
		{
			OpcionSeleccionada = MODULO_MENU_SALIR1;
		}

		if(i == OpcionSeleccionada)
		{
			menuT->Pintar(i+2,165,162+(j*80));
		}
		else
		{
			menuT->Pintar(i,165,162+(j*80));
		}

		if(keys[SDLK_q])
		{
			if(OpcionSeleccionada == MODULO_MENU_INICIO1)
			{
				estado = ESTADO_PRE_JUGANDO;
			}
			else
			{
				estado = ESTADO_FINALIZANDO;
			}
		}
	}
}