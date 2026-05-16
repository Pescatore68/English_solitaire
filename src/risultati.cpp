#include "risultati.h"

void MCResults::reset() {
    n_sim = 0;
    n_victory = 0;
    total_moves = 0;
    total_pegs = 0;
    for (int i = 0; i <= 32; ++i) count_k[i] = 0;
    for (int i = 0; i <= 31; ++i) count_N[i] = 0;
}

void MCResults::print() const{

    std::cout << "\na) P(vittoria) = " << p_victory() << "\n";

    std::cout << "\nb)Distribuzione pedine finali (P(K = k)):\n";
    for (int k = 1; k <= 32; ++k)
        if (count_k[k] > 0)
            std::cout << "   k=" << k << ": " << p_k(k) << "\n";

    std::cout << "\nc)Distribuzione mosse  (P(N = n)):\n";
    for (int n = 1; n <= 31; ++n)
        if (count_N[n] > 0)
            std::cout << "   N=" << n << ": "<< p_N(n) << "\n";

    std::cout << "\nd) Durata media: E[N] = " << mean_moves() << " mosse\n"
              << "\ne) Pedine medie finali  E[K] = " << mean_pegs()  << "\n";
}

void MCResults::export_csv() const {
    std::ofstream fk("dist_k.csv");
    fk << "k,P_k\n";
    for (int k = 1; k <= 32; ++k)
        fk << k << "," << p_k(k) << "\n";

    std::ofstream fn("dist_N.csv");
    fn << "N,P_N\n";

    for (int n = 1; n <= 31; ++n)
        fn << n << "," << p_N(n) << "\n";
}

void MCResults::add(const result& r) { //contatore
    ++n_sim;
    if (r.victory) ++n_victory;
    if (r.n_pegs  >= 1 && r.n_pegs  <= 32) count_k[r.n_pegs]  += 1;
    if (r.n_moves >= 1 && r.n_moves <= 31) count_N[r.n_moves] += 1;
    total_moves += r.n_moves;
    total_pegs  += r.n_pegs;
}

void MCResults::run(int n, std::mt19937& rng) {
    for (int i = 0; i < n; ++i)
        add(result::play_random_game(rng));
}
