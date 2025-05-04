// tir.c
#include "tir.h"

Tir tirs[MAX_TIRS];

int charge_tir = 0;


void init_tirs() {
    for (int i = 0; i < MAX_TIRS; i++) {
        tirs[i].actif = 0;
    }
}

void tirer(Vaisseau joueur, int charge_tir) {
    for (int i = 0; i < MAX_TIRS; i++) {
        if (!tirs[i].actif) {
            tirs[i].x = joueur.x + joueur.largeur;
            tirs[i].y = joueur.y + joueur.hauteur / 2;

            // Hitbox et dégâts selon charge
            if (charge_tir >= 60) {
                tirs[i].largeur = 40;
                tirs[i].hauteur = 12;
                tirs[i].degats = 75; // x3
            } else if (charge_tir >= 30) {
                tirs[i].largeur = 30;
                tirs[i].hauteur = 8;
                tirs[i].degats = 50; // x2
            } else {
                tirs[i].largeur = 20;
                tirs[i].hauteur = 5;
                tirs[i].degats = 25; // x1 (standard)
            }

            tirs[i].vitesse = 50;
            tirs[i].actif = 1;
            break;
        }
    }
}



void update_tirs() {
    for (int i = 0; i < MAX_TIRS; i++) {
        if (tirs[i].actif) {
            tirs[i].x += tirs[i].vitesse;
            if (tirs[i].x > 1280) // écran fixe ici, sinon passer LARGEUR_ECRAN en paramètre
                tirs[i].actif = 0;
        }
    }
}

void draw_tirs(BITMAP* buffer) {
    for (int i = 0; i < MAX_TIRS; i++) {
        if (tirs[i].actif) {
            rectfill(buffer, tirs[i].x, tirs[i].y,
                     tirs[i].x + tirs[i].largeur,
                     tirs[i].y + tirs[i].hauteur,
                     makecol(255, 0, 0));
        }
    }
}
