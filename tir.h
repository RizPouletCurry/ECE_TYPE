// tir.h
#ifndef TIR_H
#define TIR_H

#include <allegro.h>
#include "kid.h"

#define MAX_TIRS 100

extern int charge_tir;


typedef struct {
    int x, y;
    int largeur, hauteur;
    int vitesse;
    int actif;
    int degats;
} Tir;

void init_tirs();
void tirer(Vaisseau joueur, int charge_tir);
void update_tirs();
void draw_tirs(BITMAP* buffer);

#endif
