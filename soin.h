#ifndef SOIN_H
#define SOIN_H

#include <allegro.h>

typedef struct {
    int x, y;
    int rayon;
    int vx;
    int actif;
} Soin;

extern Soin soin;

void init_soin();
void update_soin();
void draw_soin(BITMAP* buffer);
void ajout_soin(int x, int y);

#endif
