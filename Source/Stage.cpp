#include "Stage.h"
#include "Game.h"

void CGame::inicializandoStage()
{
	nivel[0].fondoNivel=0;
	nivel[0].balasMax = 3;
	nivel[0].NumeroEnemigosAEliminar = 10;
	nivel[0].NumerosEnemigosVisibles = 2;
	nivel[0].velocidadBalasEnemigo = 5;
	nivel[0].velocidadBalasPropias = 10;
	nivel[0].velocidadEnemigo = 10;
	nivel[0].VelocidadNavePropia = 5;
	nivel[0].vidaEnemigo = 1;

	nivel[1].fondoNivel = 1;
	nivel[1].balasMax = 6;
	nivel[1].NumeroEnemigosAEliminar = 20;
	nivel[1].NumerosEnemigosVisibles = 4;
	nivel[1].velocidadBalasEnemigo = 7;
	nivel[1].velocidadBalasPropias = 15;
	nivel[1].velocidadEnemigo = 15;
	nivel[1].VelocidadNavePropia = 10;
	nivel[1].vidaEnemigo = 2;
}