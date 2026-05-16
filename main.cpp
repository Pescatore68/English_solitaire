#include <iostream>

#include "scacchiera.h"
#include "mosse.h"
#include "partita.h"

#include <iostream>
#include <chrono>
#include <cstdlib>
#include "scacchiera.h"
#include "risultati.h"
#include "partita.h"

int main(int argc, char* argv[]) {
    pos::init_valid();

    int n_sim = 1000000;
    if (argc >= 2) {
        n_sim = std::max(1, std::atoi(argv[1]));
    }

    std::cout << "Solitario Inglese\n" << "Partite: " << n_sim << "\n";

    std::mt19937 rng = result::make_rng();

    //auto t0 = std::chrono::steady_clock::now(); // decommentare se si vuole il timing dell'esecuzione

    MCResults mc;
    mc.run(n_sim, rng);

    /*auto t1 = std::chrono::steady_clock::now();
    double elapsed = std::chrono::duration<double>(t1 - t0).count();

    std::cout << "Completato in " << elapsed << " s  ("
              << static_cast<int>(n_sim / elapsed) << " partite/s)\n\n";*/

    mc.print();
    mc.export_csv();

    return 0;
}