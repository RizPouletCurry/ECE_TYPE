#include "menu.h"
#include <string.h>

#define NB_OPTIONS 3

char* options[NB_OPTIONS] = {"Nouvelle partie", "Reprendre partie", "Quitter"};
int option_selectionnee = 0;
int etat_menu = 0;
char nom_joueur[50] = "";
BITMAP* fond_menu;
BITMAP* fond_menu_off;
int menu_intro_done = 0;

int entree_nom = 0;
int index_nom = 0;
int attente_valid_nom = 0;


void menu_init() {
    fond_menu = load_bitmap("main_menu.bmp", NULL);
    fond_menu_off = load_bitmap("main_menu_off.bmp", NULL);

    if (!fond_menu || !fond_menu_off) {
        allegro_message("Erreur chargement image menu.");
        exit(1);
    }

}

void jouer_intro(BITMAP* buffer) {
    blit(fond_menu_off, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    rest(3000);

    for (int alpha = 0; alpha <= 255; alpha += 15) {
        blit(fond_menu_off, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        for (int y = 0; y < SCREEN_H; y++) {
            for (int x = 0; x < SCREEN_W; x++) {
                int c1 = getpixel(fond_menu_off, x, y);
                int c2 = getpixel(fond_menu, x, y);

                int r1 = getr(c1), g1 = getg(c1), b1 = getb(c1);
                int r2 = getr(c2), g2 = getg(c2), b2 = getb(c2);

                int r = r1 + ((r2 - r1) * alpha / 255);
                int g = g1 + ((g2 - g1) * alpha / 255);
                int b = b1 + ((b2 - b1) * alpha / 255);

                putpixel(buffer, x, y, makecol(r, g, b));
            }
        }
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        rest(30);
    }

    menu_intro_done = 1;
}

void afficher_menu(BITMAP* buffer) {
    if (!menu_intro_done) {
        jouer_intro(buffer);
        return;
    }

    draw_sprite(buffer, fond_menu, 0, 0);

    if (entree_nom) {
        // Zone grise (fond de la barre)
        rectfill(buffer, 450, 320, 750, 370, makecol(10, 10, 10));

        // Contour blanc
        rect(buffer, 450, 320, 750, 370, makecol(255, 255, 255));

        // Texte du prÃ©nom
        textprintf_ex(buffer, font, 460, 335, makecol(255,255,255), -1, "%s_", nom_joueur);


        // Texte narratif
        textprintf_centre_ex(buffer, font, 600, 280, makecol(255, 255, 255), -1, "Comment tu t'appelles petit ?");
        return;
    }

    for (int i = 0; i < NB_OPTIONS; i++) {
        int color = (i == option_selectionnee) ? makecol(255, 255, 0) : makecol(255, 255, 255);
        textprintf_centre_ex(buffer, font, 600, 300 + i * 40, color, -1, options[i]);
    }
}
