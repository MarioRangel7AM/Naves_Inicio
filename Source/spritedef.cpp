#include "spritedef.h"
#include "config.h"


    spritedef::spritedef(){
	modulos[0].id = 0;
	modulos[0].x = 0;
	modulos[0].y = 0;
	modulos[0].w = 64;
	modulos[0].h = 64;

	modulos[1].id = 1;
	modulos[1].x = 0;
	modulos[1].y = 0;
	modulos[1].w = WIDTH_SCREEN;
	modulos[1].h = HEIGHT_SCREEN;

	modulos[2].id = 2;
	modulos[2].x = 0;
	modulos[2].y = 0;
	modulos[2].w = 54;
	modulos[2].h = 61;

	modulos[3].id = 3; // Titulo
	modulos[3].x = 178;
	modulos[3].y = 34;
	modulos[3].w = 250;
	modulos[3].h = 38;

	modulos[4].id = 4; // Nombre
	modulos[4].x = 164;
	modulos[4].y = 435;
	modulos[4].w = 284;
	modulos[4].h = 37;
	
	modulos[5].id = 5; //iniciar1
	modulos[5].x = 165;
	modulos[5].y = 162;
	modulos[5].w = 120;
	modulos[5].h = 32;

	modulos[6].id = 6; // Salir1
	modulos[6].x = 162;
	modulos[6].y = 194;
	modulos[6].w = 91;
	modulos[6].h = 30;
	
	modulos[7].id = 7; //Iniciar2
	modulos[7].x = 324;
	modulos[7].y = 163;
	modulos[7].w = 123;
	modulos[7].h = 33;

	modulos[8].id = 8;  //Salir2
	modulos[8].x = 324;
	modulos[8].y = 194;
	modulos[8].w = 91;
	modulos[8].h = 30;
}