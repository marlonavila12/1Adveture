#include "Background.h"
using namespace std;


Background::Background()
{
}

Background::~Background()
{
}

ALLEGRO_BITMAP* Background::backgroundLoad(ALLEGRO_BITMAP* banner)
{
	banner = al_load_bitmap("banner.jpg");
	return banner;
}

void Background::gif(ALLEGRO_DISPLAY* window)
{
	
	/*char const* path = "prueba.gif";
	ALGIF_ANIMATION* gif = algif_load_animation(path);
	int size = gif->frames_count;
	ALLEGRO_BITMAP* frames[100];

	for (int n = 0; n < size; n++) {
		frames[n] = algif_get_frame_bitmap(gif, n);
	}

	for (int p = 0; p < size; p++) {
		al_draw_bitmap(frames[p], 0, 0, 0);
	}*/
}
