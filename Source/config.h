#ifndef __CONFIG_H__
#define __CONFIG_H__

#define WIDTH_SCREEN 640
#define HEIGHT_SCREEN 480

#define FPS_LIMIT 30.0f
#define FPS_DELAY 1000.0f / FPS_LIMIT

#define BORDE_IZQUIERDO  1<<0
#define BORDE_SUPERIOR   1<<1
#define BORDE_DERECHO    1<<2
#define BORDE_INFERIOR   1<<3

//Sprite
//#TIPO_IMAGEN_NOMBRE

#define MODULO_MINAVE_NAVE     0
#define MODULO_TITULO1_FONDO   1
#define MODULO_ENEMIGO_NAVE    2
#define MODULO_MENU_TITULO     3
#define MODULO_MENU_NOMBRE     4
#define MODULO_MENU_INICIO1    5
#define MODULO_MENU_SALIR1     6
#define MODULO_MENU_INICIO2    7
#define MODULO_MENU_SALIR2     8
#define MODULO_BALAS_BALA      9

#define MAXIMO_DE_BALAS  20

#define NAVE_PROPIA       0
#define NAVE_ENEMIGO      1

#endif