#include<allegro5/allegro.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>

using namespace std;

int main() {
	//inits
	al_init();
	al_init_font_addon();
	al_init_image_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();
	// apuntadores
	ALLEGRO_DISPLAY* pi = al_create_display(1400, 790);
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);
	ALLEGRO_FONT* font = al_load_ttf_font("NotoSerif-BoldItalic.ttf", 74, 0);
	ALLEGRO_FONT* font2 = al_load_ttf_font("NotoSerif-BoldItalic.ttf", 45, 0);
	ALLEGRO_FONT* font3 = al_load_ttf_font("NotoSerif-Italic.ttf", 25, 0);

	//botones y background
	ALLEGRO_BITMAP* settings = al_load_bitmap("settings.png");
	ALLEGRO_BITMAP* user = al_load_bitmap("small.png");
	ALLEGRO_BITMAP* map = al_load_bitmap("map.png");
	ALLEGRO_BITMAP* background = al_load_bitmap("background.jpg");
	//Mapa
	ALLEGRO_BITMAP* backgroundm = al_load_bitmap("backgroundm.jpg");
	ALLEGRO_BITMAP* title = al_load_bitmap("title2.png");
	ALLEGRO_BITMAP* joy1 = al_load_bitmap("pin1.png");
	ALLEGRO_BITMAP* joy2 = al_load_bitmap("pin2.png");
	ALLEGRO_BITMAP* joy3 = al_load_bitmap("pin3.png");
	ALLEGRO_BITMAP* home = al_load_bitmap("star.png");
	int bmx = al_get_bitmap_width(home), bmy = al_get_bitmap_width(home);
	bool incomplete = true, incomplete2 = true, incomplete3 = true;
	bool complete = false, complete2 = false, complete3 = false;
	bool up = false, up2 = false, up3 = false;
	//mapa
	//Mundo bosque
	bool game1 = false, cambio = false, pulse = false;
	int walk = 0, tiempo = 0, t = 0;
	int posix = 100, posix2 = 1080, posiy = 500;
	ALLEGRO_BITMAP* forest = al_load_bitmap("forest.jpg");
	ALLEGRO_BITMAP* walkleft = al_load_bitmap("Walk1.png");
	ALLEGRO_BITMAP* walkleft2 = al_load_bitmap("Walk2.png");
	ALLEGRO_BITMAP* walkleft3 = al_load_bitmap("Walk3.png");
	ALLEGRO_BITMAP* walkleft4 = al_load_bitmap("Walk4.png");
	ALLEGRO_BITMAP* walkleft5 = al_load_bitmap("Walk5.png");
	ALLEGRO_BITMAP* walkleft6 = al_load_bitmap("Walk6.png");
	ALLEGRO_BITMAP* walkright = al_load_bitmap("Walk7.png");
	ALLEGRO_BITMAP* walkright2 = al_load_bitmap("Walk8.png");
	ALLEGRO_BITMAP* walkright3 = al_load_bitmap("Walk9.png");
	ALLEGRO_BITMAP* walkright4 = al_load_bitmap("Walk10.png");
	ALLEGRO_BITMAP* walkright5 = al_load_bitmap("Walk11.png");
	ALLEGRO_BITMAP* walkright6 = al_load_bitmap("Walk12.png");
	ALLEGRO_BITMAP* heart = al_load_bitmap("heart.png");
	ALLEGRO_BITMAP* heartb = al_load_bitmap("heartb.png");
	//Mundo bosque
	//Eventos
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_display_event_source(pi));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_start_timer(timer);

	//Variables
	bool ciclo = true, flag = false, flag2 = false, flag3 = false, flag4 = false, b1 = true, b2 = true;
	int w = al_get_display_width(pi) * 0.05, x = w + 55, posx, isx = al_get_bitmap_width(settings);
	int h = al_get_display_height(pi) * 0.06, posy, isy = al_get_bitmap_height(settings);
	ALLEGRO_EVENT event;

	//Ciclo

	while (ciclo) {
		al_wait_for_event(queue, &event);
		//pantalla
		if (event.type == ALLEGRO_EVENT_TIMER) {
			if (b1) {
				al_draw_bitmap(background, 0, 0, 0);
				al_draw_text(font, al_map_rgb(255, 223, 0), w + 250, 0, 0, "Legend of Terabithia");
				al_draw_text(font2, al_map_rgb(255, 223, 0), w + 350, 82, 0, "Java the lost language");
				al_draw_bitmap(settings, w, h, 0);
				if (flag) {
					al_draw_bitmap(map, w, h + 60, 0);
					al_draw_bitmap(user, w, h + 120, 0);
				}
				if (flag2) {
					al_draw_text(font3, al_map_rgb(255, 255, 255), w + 45, h, 0, "Settings");
				}
				else {
					if (flag3) {
						al_draw_text(font3, al_map_rgb(255, 255, 255), w + 45, h + 60, 0, "Map");
					}
					else {
						if (flag4) {
							al_draw_text(font3, al_map_rgb(255, 255, 255), w + 45, h + 120, 0, "Create User");
						}
					}
				}
			}
			else {
				if(b2){
					//imprimir siempre
					al_draw_scaled_bitmap(backgroundm, 0, 0, 2048, 1536, 0, 0, 1400, 790, 0);
					al_draw_scaled_bitmap(title, 0, 0, 512, 512, w + 430, h - 135, 356, 276, 0);
					al_draw_text(font3, al_map_rgb(255, 255, 255), w + 975, h + 440, 0, "Home");
					al_draw_text(font2, al_map_rgb(255, 255, 255), w + 480, h - 40, 0, "Terabithia");
					al_draw_bitmap(home, w + 985, h + 480, 0);
					//condicion
					if (incomplete && incomplete2 && incomplete3) {
						if (!up) {
							if (!up2) {
								if (!up3) {
									al_draw_bitmap(joy1, w + 95, h + 560, 0);
									al_draw_bitmap(joy1, w + 215, h + 160, 0);
									al_draw_bitmap(joy1, w + 915, h + 160, 0);
								}
								else {
									al_draw_bitmap(joy1, w + 95, h + 560, 0);
									al_draw_bitmap(joy1, w + 215, h + 160, 0);
									al_draw_bitmap(joy3, w + 905, h + 130, 0);
								}
							}
							else {
								al_draw_bitmap(joy1, w + 95, h + 560, 0);
								al_draw_bitmap(joy3, w + 205, h + 130, 0);
								al_draw_bitmap(joy1, w + 915, h + 160, 0);
							}
						}
						else {
							al_draw_bitmap(joy3, w + 85, h + 530, 0);
							al_draw_bitmap(joy1, w + 215, h + 160, 0);
							al_draw_bitmap(joy1, w + 915, h + 160, 0);
						}
					}
					else {
						if (incomplete && incomplete2 && complete3) {
							if (!up) {
								if (!up2) {
									if (!up3) {
										al_draw_bitmap(joy1, w + 95, h + 560, 0);
										al_draw_bitmap(joy1, w + 215, h + 160, 0);
										al_draw_bitmap(joy2, w + 915, h + 160, 0);
									}
									else {
										al_draw_bitmap(joy1, w + 95, h + 560, 0);
										al_draw_bitmap(joy1, w + 215, h + 160, 0);
										al_draw_bitmap(joy3, w + 905, h + 130, 0);
									}
								}
								else {
									al_draw_bitmap(joy1, w + 95, h + 560, 0);
									al_draw_bitmap(joy3, w + 205, h + 130, 0);
									al_draw_bitmap(joy2, w + 915, h + 160, 0);
								}
							}
							else {
								al_draw_bitmap(joy3, w + 85, h + 530, 0);
								al_draw_bitmap(joy1, w + 215, h + 160, 0);
								al_draw_bitmap(joy2, w + 915, h + 160, 0);
							}
						}
						else {
							if (incomplete && complete2 && incomplete3) {
								if (!up) {
									if (!up2) {
										if (!up3) {
											al_draw_bitmap(joy1, w + 95, h + 560, 0);
											al_draw_bitmap(joy2, w + 215, h + 160, 0);
											al_draw_bitmap(joy1, w + 915, h + 160, 0);
										}
										else {
											al_draw_bitmap(joy1, w + 95, h + 560, 0);
											al_draw_bitmap(joy2, w + 215, h + 160, 0);
											al_draw_bitmap(joy3, w + 905, h + 130, 0);
										}
									}
									else {
										al_draw_bitmap(joy1, w + 95, h + 560, 0);
										al_draw_bitmap(joy3, w + 205, h + 130, 0);
										al_draw_bitmap(joy1, w + 915, h + 160, 0);
									}
								}
								else {
									al_draw_bitmap(joy3, w + 85, h + 530, 0);
									al_draw_bitmap(joy2, w + 215, h + 160, 0);
									al_draw_bitmap(joy1, w + 915, h + 160, 0);
								}
							}
							else {
								if (complete && incomplete2 && incomplete3) {
									if (!up) {
										if (!up2) {
											if (!up3) {
												al_draw_bitmap(joy2, w + 95, h + 560, 0);
												al_draw_bitmap(joy1, w + 215, h + 160, 0);
												al_draw_bitmap(joy1, w + 915, h + 160, 0);
											}
											else {
												al_draw_bitmap(joy2, w + 95, h + 560, 0);
												al_draw_bitmap(joy1, w + 215, h + 160, 0);
												al_draw_bitmap(joy3, w + 905, h + 130, 0);
											}
										}
										else {
											al_draw_bitmap(joy2, w + 95, h + 560, 0);
											al_draw_bitmap(joy3, w + 205, h + 130, 0);
											al_draw_bitmap(joy1, w + 915, h + 160, 0);
										}
									}
									else {
										al_draw_bitmap(joy3, w + 85, h + 530, 0);
										al_draw_bitmap(joy1, w + 215, h + 160, 0);
										al_draw_bitmap(joy1, w + 915, h + 160, 0);
									}
								}
								else {
									if (incomplete && complete2 && complete3) {
										if (!up) {
											if (!up2) {
												if (!up3) {
													al_draw_bitmap(joy1, w + 95, h + 560, 0);
													al_draw_bitmap(joy2, w + 215, h + 160, 0);
													al_draw_bitmap(joy2, w + 915, h + 160, 0);
												}
												else {
													al_draw_bitmap(joy1, w + 95, h + 560, 0);
													al_draw_bitmap(joy2, w + 215, h + 160, 0);
													al_draw_bitmap(joy3, w + 905, h + 130, 0);
												}
											}
											else {
												al_draw_bitmap(joy1, w + 95, h + 560, 0);
												al_draw_bitmap(joy3, w + 205, h + 130, 0);
												al_draw_bitmap(joy2, w + 915, h + 160, 0);
											}
										}
										else {
											al_draw_bitmap(joy3, w + 85, h + 530, 0);
											al_draw_bitmap(joy2, w + 215, h + 160, 0);
											al_draw_bitmap(joy2, w + 915, h + 160, 0);
										}
									}
									else {
										if (complete && incomplete2 && complete3) {
											if (!up) {
												if (!up2) {
													if (!up3) {
														al_draw_bitmap(joy2, w + 95, h + 560, 0);
														al_draw_bitmap(joy1, w + 215, h + 160, 0);
														al_draw_bitmap(joy2, w + 915, h + 160, 0);
													}
													else {
														al_draw_bitmap(joy2, w + 95, h + 560, 0);
														al_draw_bitmap(joy1, w + 215, h + 160, 0);
														al_draw_bitmap(joy3, w + 905, h + 130, 0);
													}
												}
												else {
													al_draw_bitmap(joy2, w + 95, h + 560, 0);
													al_draw_bitmap(joy3, w + 205, h + 130, 0);
													al_draw_bitmap(joy2, w + 915, h + 160, 0);
												}
											}
											else {
												al_draw_bitmap(joy3, w + 85, h + 530, 0);
												al_draw_bitmap(joy1, w + 215, h + 160, 0);
												al_draw_bitmap(joy2, w + 915, h + 160, 0);
											}
										}
										else {
											if (complete && complete2 && incomplete3) {
												if (!up) {
													if (!up2) {
														if (!up3) {
															al_draw_bitmap(joy2, w + 95, h + 560, 0);
															al_draw_bitmap(joy2, w + 215, h + 160, 0);
															al_draw_bitmap(joy1, w + 915, h + 160, 0);
														}
														else {
															al_draw_bitmap(joy2, w + 95, h + 560, 0);
															al_draw_bitmap(joy2, w + 215, h + 160, 0);
															al_draw_bitmap(joy3, w + 905, h + 130, 0);
														}
													}
													else {
														al_draw_bitmap(joy2, w + 95, h + 560, 0);
														al_draw_bitmap(joy3, w + 205, h + 130, 0);
														al_draw_bitmap(joy1, w + 915, h + 160, 0);
													}
												}
												else {
													al_draw_bitmap(joy3, w + 85, h + 530, 0);
													al_draw_bitmap(joy2, w + 215, h + 160, 0);
													al_draw_bitmap(joy1, w + 915, h + 160, 0);
												}
											}
											else {
												if (!up) {
													if (!up2) {
														if (!up3) {
															al_draw_bitmap(joy2, w + 95, h + 560, 0);
															al_draw_bitmap(joy2, w + 215, h + 160, 0);
															al_draw_bitmap(joy2, w + 915, h + 160, 0);
														}
														else {
															al_draw_bitmap(joy2, w + 95, h + 560, 0);
															al_draw_bitmap(joy2, w + 215, h + 160, 0);
															al_draw_bitmap(joy3, w + 905, h + 130, 0);
														}
													}
													else {
														al_draw_bitmap(joy2, w + 95, h + 560, 0);
														al_draw_bitmap(joy3, w + 205, h + 130, 0);
														al_draw_bitmap(joy2, w + 915, h + 160, 0);
													}
												}
												else {
													al_draw_bitmap(joy3, w + 85, h + 530, 0);
													al_draw_bitmap(joy2, w + 215, h + 160, 0);
													al_draw_bitmap(joy2, w + 915, h + 160, 0);
												}
											}
										}
									}
								}
							}
						}
					}

				}
				else {
					if (game1) {
						al_draw_scaled_bitmap(forest, 0, 0, 1920, 1080, 0, 0, 1400, 790, 0);
						if (!pulse) {
							al_draw_bitmap(heart, 50, 50, 0);
							al_draw_bitmap(heart, 90, 50, 0);
							al_draw_bitmap(heart, 130, 50, 0);
							if (t > 35) {
								t = 0;
								pulse = true;
							}
							else {
								t++;
							}

						}
						else {
							al_draw_bitmap(heartb, 50, 50, 0);
							al_draw_bitmap(heartb, 90, 50, 0);
							al_draw_bitmap(heartb, 130, 50, 0);
							if (t > 35) {
								t = 0;
								pulse = false;
							}
							else {
								t++;
							}

						}
						switch (cambio)
						{
						case false:
							switch (walk)
							{
							case 0:
								al_draw_bitmap(walkleft, posix, posiy, 0);
								if (tiempo > 7) {
									posix += 6;
									if (posix > 1080) {
										cambio = true;
										posix = 100;
									}
									walk++;
									tiempo = 0;
								}
								else {
									tiempo++;
								}
								break;
							case 1:
								al_draw_bitmap(walkleft2, posix, posiy, 0);
								if (tiempo > 5) {
									posix += 6;
									if (posix > 1080) {
										cambio = true;
										posix = 100;
									}
									walk++;
									tiempo = 0;
								}
								else {
									tiempo++;
								}
								break;
							case 2:
								al_draw_bitmap(walkleft3, posix, posiy, 0);
								if (tiempo > 5) {
									posix += 6;
									if (posix > 1080) {
										cambio = true;
										posix = 100;
									}
									walk++;
									tiempo = 0;
								}
								else {
									tiempo++;
								}
								break;
							case 3:
								al_draw_bitmap(walkleft4, posix, posiy, 0);
								if (tiempo > 5) {
									posix += 6;
									if (posix > 1080) {
										cambio = true;
										posix = 100;
									}
									walk++;
									tiempo = 0;
								}
								else {
									tiempo++;
								}
								break;
							case 4:
								al_draw_bitmap(walkleft5, posix, posiy, 0);
								if (tiempo > 5) {
									posix += 6;
									if (posix > 1080) {
										cambio = true;
										posix = 100;
									}
									walk++;
									tiempo = 0;
								}
								else {
									tiempo++;
								}
								break;
							case 5:
								al_draw_bitmap(walkleft6, posix, posiy, 0);
								if (tiempo > 5) {
									posix += 6;
									if (posix > 1080) {
										posix = 100;
										cambio = true;
									}
									walk = 0;
									tiempo = 0;
								}
								else {
									tiempo++;
								}
								break;
							default:
								break;
							}
							break;
						case true:
							switch (walk)
							{
							case 0:
								al_draw_bitmap(walkright, posix2, posiy, 0);
								if (tiempo > 7) {
									posix2 -= 6;
									if (posix2 < 100) {
										cambio = false;
										posix2 = 1080;
									}
									walk++;
									tiempo = 0;
								}
								else {
									tiempo++;
								}
								break;
							case 1:
								al_draw_bitmap(walkright2, posix2, posiy, 0);
								if (tiempo > 5) {
									posix2 -= 6;
									if (posix2 < 100) {
										cambio = false;
										posix2 = 1080;
									}
									walk++;
									tiempo = 0;
								}
								else {
									tiempo++;
								}
								break;
							case 2:
								al_draw_bitmap(walkright3, posix2, posiy, 0);
								if (tiempo > 5) {
									posix2 -= 6;
									if (posix2 < 100) {
										cambio = false;
										posix2 = 1080;
									}
									walk++;
									tiempo = 0;
								}
								else {
									tiempo++;
								}
								break;
							case 3:
								al_draw_bitmap(walkright4, posix2, posiy, 0);
								if (tiempo > 5) {
									posix2 -= 6;
									if (posix2 < 100) {
										cambio = false;
										posix2 = 1080;
									}
									walk++;
									tiempo = 0;
								}
								else {
									tiempo++;
								}
								break;
							case 4:
								al_draw_bitmap(walkright5, posix2, posiy, 0);
								if (tiempo > 5) {
									posix2 -= 6;
									if (posix2 < 100) {
										cambio = false;
										posix2 = 1080;
									}
									walk++;
									tiempo = 0;
								}
								else {
									tiempo++;
								}
								break;
							case 5:
								al_draw_bitmap(walkright6, posix2, posiy, 0);
								if (tiempo > 5) {
									posix2 -= 6;
									if (posix2 < 100) {
										cambio = false;
										posix2 = 1080;
									}
									walk = 0;
									tiempo = 0;
								}
								else {
									tiempo++;
								}
								break;
							default:
								break;
							}
							break;
						default:
							break;
						}
					}
				}
				
			}
			al_flip_display();
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && b1) {
			posx = event.mouse.x;
			posy = event.mouse.y;
			if (posx >= w && posy >= h && posx <= w+isx && posy <= h+isy) {
				flag = true;
			}
			else {
				if (posx >= w && posy >= h + 60 && posx <= w + isx && posy <= h + isy + 60 && flag) {
					b1 = false;
				}
			}
		}
		else {
			if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && !b1) {
				posx = event.mouse.x;
				posy = event.mouse.y;
				if (posx >= w+985 && posy >= h+480 && posx <= w + isx+985 && posy <= h + isy+480) {
					b1 = true;
					b2 = false;
				}
				else {
					if (posx >= w + 915 && posy >= h + 160 && posx <= w + isx + 915 && posy <= h + isy + 160) {
						game1 = true;
						b2 = false;
					}
				}
			}
		}

		if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			posx = event.mouse.x;
			posy = event.mouse.y;
			if (posx >= w && posy >= h && posx <= w + isx && posy <= h + isy) {
				flag2 = true;
				flag3 = false;
			}
			else {
				flag2 = false;
				flag4 = false;
				if (posx >= w && posy >= h+60 && posx <= w + isx && posy <= h + isy+60 && flag) {
					flag3 = true;
				}
				else {
					flag3 = false;
					if (posx >= w && posy >= h + 120 && posx <= w + isx && posy <= h + isy + 120 && flag) {
						flag4 = true;
					}
					else {
						if (posx < w || posy < h  || posx > w + isx || posy > h + isy + 120 && flag) {
							flag = false;
							flag2 = false;
							flag3 = false;
							flag4 = false;
						}
					}
				}

			}
		}
		
		if (event.type == ALLEGRO_EVENT_MOUSE_AXES && !b1) {
			posx = event.mouse.x;
			posy = event.mouse.y;
			if (posx >= w + 95 && posy >= h + 560 && posx <= w + isx + 95 && posy <= h + isy + 560) {
				up = true;
				up2 = false;
				up3 = false;
			}
			else {
				up = false;
			}
			if (posx >= w + 215 && posy >= h + 160 && posx <= w + isx + 215 && posy <= h + isy + 160) {
				up = false;
				up2 = true;
				up3 = false;
			}
			else {
				up2 = false;
			}
			if (posx >= w + 915 && posy >= h + 160 && posx <= w + isx + 915 && posy <= h + isy + 160) {
				up = false;
				up2 = false;
				up3 = true;
			}
			else {
				up3 = false;
			}
		}

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			ciclo = false;
	}

	//fin
	//Allegro Destroys and Unistalls
	al_uninstall_keyboard();
	al_uninstall_mouse();
	al_destroy_font(font);
	al_destroy_font(font2);
	al_destroy_font(font3);
	al_destroy_bitmap(settings);
	al_destroy_bitmap(map);
	al_destroy_bitmap(user);
	al_destroy_bitmap(background);
	//menu mapa
	al_destroy_bitmap(backgroundm);
	al_destroy_bitmap(joy1);
	al_destroy_bitmap(joy2);
	al_destroy_bitmap(joy3);
	al_destroy_bitmap(title);
	al_destroy_bitmap(home);
	//mapa
	//Mundo bosque
	al_destroy_bitmap(forest);
	al_destroy_bitmap(walkleft);
	al_destroy_bitmap(walkleft2);
	al_destroy_bitmap(walkleft3);
	al_destroy_bitmap(walkleft4);
	al_destroy_bitmap(walkleft5);
	al_destroy_bitmap(walkleft6);
	al_destroy_bitmap(walkright);
	al_destroy_bitmap(walkright2);
	al_destroy_bitmap(walkright3);
	al_destroy_bitmap(walkright4);
	al_destroy_bitmap(walkright5);
	al_destroy_bitmap(walkright6);
	al_destroy_bitmap(heart);
	al_destroy_bitmap(heartb);
	//Mundo bosque
	al_destroy_event_queue(queue);
	al_destroy_timer(timer);
	al_destroy_display(pi);
	return 0;
}