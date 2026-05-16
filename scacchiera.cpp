//
// Created by Sofia Chen on 05/05/26.
//
#include "scacchiera.h"

int pos::n_valid=0;
const pos pos::centro = pos(3,3);
const pos pos::dirs[4] = {{-2,0}, {2,0}, {0,-2}, {0,2}};
pos pos::valid_pos[33];

//caselle valide sono per r(2,3,4) -> c(0...6); per r(0,1,5,6) -> c(2,3,4)
bool pos::is_valid(int r, int c) {
    if (r<0 || r>6 || c<0 || c>6) return false;
    if (r<2|| r>4) {
        return (c>1 && c<5);
    }
    return true;
}

bool pos::is_valid() const {
    return is_valid(r, c);
}

void pos::init_valid() {
    n_valid = 0;
    for (int i=0; i<7; i++) {
        for (int j=0; j<7; j++) {
            if (is_valid(i,j)) {
                valid_pos[n_valid++] = pos(i,j);
            }
        }
    }
}

pos pos::operator+ (const pos& p) const {
    return {r+p.r, c+p.c};
}

bool pos::operator== (const pos& p) const {
    return c==p.c && r==p.r;
}

void board::init() {
    memset(cells, false, sizeof(cells));

    for (int i = 0; i < pos::n_valid; i++) {
        const pos& p = pos::valid_pos[i];
        set(p, !(p == pos::centro));
    }
}

void board::set(const pos& p, bool val) {
    cells[p.r][p.c] = val;
}

bool board::get(const pos& p) const {
    return cells[p.r][p.c];
}

int board::count() const {
    int n = 0;
    for (int i = 0; i < pos::n_valid; i++)
        if (get(pos::valid_pos[i])) n++;
    return n;
}

bool board::victory() const {
    return count()==1 && get(pos::centro);
}






