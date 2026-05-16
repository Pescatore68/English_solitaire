#ifndef RISULTATI_H
#define RISULTATI_H

#include <iostream>
#include <fstream>
#include "partita.h"

//  Accumula i dati di n_sim partite giocate a caso e calcola:
//    a) P(vittoria)
//    b) P(K = k)  per k = 1..32
//    c) P(N = n)  per n = 1..31
//    d) E[N] (durata media)
//    e) E[K] (pedine medie finali)

class MCResults {
public:
    int    n_sim;
    long   n_victory;
    long   count_k[33];
    long   count_N[32];
    double total_moves;
    double total_pegs;

    MCResults() { reset(); }
    void reset();

    void add(const result& r);
    void run(int n, std::mt19937& rng);

    double p_victory()   const { return n_victory / (double)n_sim; }
    double mean_moves()  const { return total_moves / (double)n_sim; }
    double mean_pegs()   const { return total_pegs / (double)n_sim; }
    double p_k(int k)    const { return count_k[k] / (double)n_sim; }
    double p_N(int n)    const { return count_N[n] / (double)n_sim; }

    void print() const;

    //Export CSV dist_k.csv e dist_N.csv
    void export_csv() const;

};

#endif //RISULTATI_H
