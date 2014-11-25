#include <SDL.h>;
#include "objeto.h"
#include "nave.h"
class CGame
{
public:
	bool Start();
	static CGame instanceGame;
	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZANDO
	};

	CGame();
	void Finalize();

private:

	void Iniciando();
	void Menu();
	void MoverEnemigo();
	bool EsLimitePantalla(objeto * objeto,int bandera);
	int OpcionSeleccionada;
	Uint8 *keys;
    SDL_Event  event;
	SDL_Surface *screen,*imagena;
	objeto *fondo1; // super fondo
	objeto *titulo; // fondo del menu
	objeto *menuT;
	
	//nave *menuN;
	//nave *menuI1; //Iniciar1
	//nave *menuI2; //iniciar2
	//nave* menuS1; //salir1
	//nave* menuS2; //salir2
	Nave * nave1;
	objeto *enemigoArreglo [10];
	int tick;
	int tiempoFrame;
	int tiempoFrameFinal;
	Estado estado;
};