#include <SDL.h>
class CGame
{
public:
	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();

	enum Estado{
		ESTADO_INICIADO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZANDO
	};
private:
	void iniciando();
	SDL_Surface*Screen;
	Estado estado;
};