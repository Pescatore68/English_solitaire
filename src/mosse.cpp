#include "mosse.h"

void move::apply(board& b) const {
        b.set(from, false);
        b.set(over, false);
        b.set(to, true);

}

int get_moves(const board& b, move m[132]) {
        int n = 0;
        for (int i = 0; i < pos::n_valid; i++) {
                pos from = pos::valid_pos[i];
                if (!b.get(from)) continue;

                for (const pos& d : pos::dirs) {
                        pos over = from + pos(d.r / 2, d.c / 2);
                        pos to   = from + d;

                        if (!over.is_valid() || !b.get(over)) continue;//se la biglia in mezzo è in una posizione valida e è presente una biglia
                        if (!to.is_valid()   ||  b.get(to)  ) continue; // "" e non è presente una biglia

                        m[n++] = {from, over, to}; //salva nell'array tutte le mosse possibili data una disposizione nella scacchiera
                }
        }
        return n;
}


