#pragma once
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include"Background.h"

class Pantalla
{
public:
	Pantalla();
	~Pantalla();

	//funciones
	ALLEGRO_DISPLAY* generar_pantalla(ALLEGRO_DISPLAY* window);
	bool ventana(ALLEGRO_DISPLAY* window);
	void destruir_pantalla(ALLEGRO_DISPLAY* window);
};

