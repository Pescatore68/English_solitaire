//
// Created by Sofia Chen on 05/05/26.
//

#ifndef SCACCHIERA_H
#define SCACCHIERA_H

//La scacchiera a croce ha 33 caselle (coordinate riga, col):
//si nota che le caselle valide sono: per r(2,3,4) -> c(0...6), per r(0,1,5,6) -> c(2,3,4)
//board possiede 33 caselle, se casella (r,c) = true occupata, se (r,c) = false libera

#include <cstring>

class board;

class pos {
public:
    int r, c;
    pos(int x=0, int y=0) : r(x), c(y) {}
    static bool is_valid(int r, int c);
    bool is_valid() const;
    static void init_valid();
    pos operator+ (const pos& p) const;
    bool operator== (const pos& p) const;

    static const pos centro;
    static pos valid_pos[33];
    static int n_valid;
    static const pos dirs[4];

};

class board {
private:
    bool cells[7][7];
public:
    void init(); //inizializza la tabella
    bool get(const pos& p) const; // torna valore val nella posizione p
    void set(const pos& p, bool val); // pone posizione p con valore val
    int count() const; //conta biglie rimaste
    bool victory() const;//verifica condizione vittoria
};



#endif //SCACCHIERA_H
