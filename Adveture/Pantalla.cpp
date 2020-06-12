#include "Pantalla.h"

Pantalla::Pantalla() {

}

Pantalla::~Pantalla()
{
}

ALLEGRO_DISPLAY* Pantalla::generar_pantalla(ALLEGRO_DISPLAY* window)
{
	al_init();
	al_init_image_addon();
	window = al_create_display(1400, 790);
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();
	return window;
}

bool Pantalla::ventana(ALLEGRO_DISPLAY* window)
{
	
	bool ciclo = true;
	int posx = 0.03 * al_get_display_width(window), posy = 0.015*al_get_display_height(window), mx, my;
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	ALLEGRO_FONT* font = al_load_ttf_font("Pangolin.ttf", 64, 0);
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);
	ALLEGRO_BITMAP* banner = al_load_bitmap("background.jpg");
	ALLEGRO_BITMAP* settings = al_load_bitmap("settings.png");
	ALLEGRO_BITMAP* map = al_load_bitmap("map.png");
	ALLEGRO_BITMAP* user = al_load_bitmap("small.png");
	ALLEGRO_EVENT event;
	int bx = al_get_bitmap_width(settings), by = al_get_bitmap_height(settings);
	// registro
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_display_event_source(window));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_start_timer(timer);
	//Ciclo de pamtalla
	while (ciclo) {
		//eventos
		al_wait_for_event(queue, &event);
		//definicion de pantalla
		if (event.type == ALLEGRO_EVENT_TIMER) {
			al_draw_bitmap(banner, 0, 0, 0);
			al_draw_bitmap(settings, posx, posy, 0);
			mx = event.mouse.x;
			if(mx >0)
				al_draw_text(font, al_map_rgb(0, 0, 0), 300, 0, 0, "Holalla");
			al_flip_display();
		}

		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			mx = event.mouse.x;
			my = event.mouse.y;
			al_draw_bitmap(user, posx, posy + 60, 0);
			if (mx >= posx && mx <= bx && my >= posy && my < by) {
				al_draw_bitmap(user, posx, posy + 60, 0);
				al_draw_bitmap(map, posx, posy + 120, 0);
			}
		}
		
		
		//Salir
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			al_destroy_bitmap(banner);
			al_destroy_bitmap(user);
			al_destroy_bitmap(settings);
			al_destroy_bitmap(map);
			//al_destroy_font(font2);
			ciclo = false;
		}
			
		
	}
	return false;
}

void Pantalla::destruir_pantalla(ALLEGRO_DISPLAY* window)
{
	al_uninstall_mouse();
	al_destroy_display(window);
}
