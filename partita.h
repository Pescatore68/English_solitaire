#ifndef PARTITA_H
#define PARTITA_H
#include <iostream>
#include <random>
#include "scacchiera.h"
#include "mosse.h"


class result {
public:
    int  n_moves;
    int  n_pegs;
    bool victory;

    result(int moves = 0, int pegs = 0, bool win = false)
        : n_moves(moves), n_pegs(pegs), victory(win) {}

    //void print() const;

    static std::mt19937 make_rng(); //genera seed randomico

    static result play_random_game(std::mt19937& rng);
};




#endif //PARTITA_H
