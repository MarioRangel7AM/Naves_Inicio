#ifndef __SPRITEDEF_H__
#define __SPRITEDEF_H__


class spritedef{
public:
	struct Modulos{
		int id, x, y, w, h;
	};

	Modulos modulos [10]; // numero de modulos
	spritedef(); 

};
#endif