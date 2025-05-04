#ifndef MENU_H
#define MENU_H

#include <allegro.h>

void menu_init();
void afficher_menu(BITMAP* buffer);
void gerer_menu();
int get_etat_menu();
char* get_nom_joueur();

#endif
