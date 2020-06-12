#pragma once
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<iostream>
#include<stdio.h>
#include"algif.h"



class Background
{
public:
	Background();
	~Background();
	//Funciones 
	ALLEGRO_BITMAP* backgroundLoad(ALLEGRO_BITMAP* banner);
	void gif(ALLEGRO_DISPLAY* window);
};

