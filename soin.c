#include "soin.h"
#include "kid.h"


Soin soin;

void init_soin() {
    soin.actif = 0;
}

void ajout_soin(int x, int y) {
    soin.x = x;
    soin.y = y;
    soin.rayon = 20;
    soin.vx = -2;
    soin.actif = 1;
}

void update_soin() {
    // Rien à mettre pour l’instant, bonus statique
}

void draw_soin(BITMAP* buffer) {
    if (soin.actif) {
        circlefill(buffer, soin.x, soin.y, soin.rayon, makecol(0, 255, 0));
    }
}

void check_soin_collision() {
    if (soin.actif) {
        int dx = (joueur.x + joueur.largeur / 2) - soin.x;
        int dy = (joueur.y + joueur.hauteur / 2) - soin.y;
        int distance = dx * dx + dy * dy;
        int rayon_total = soin.rayon + (joueur.largeur / 2);

        if (distance <= rayon_total * rayon_total) {
            joueur.hp = 100;
            soin.actif = 0;
        }
    }
}
