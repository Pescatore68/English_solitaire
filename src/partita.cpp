#include "partita.h"

/*void result::print() const {
    std::cout << "Mosse: "   << n_moves
              << " | Pedine: " << n_pegs
              << " | Vittoria: " << (victory ? "SI" : "NO") << "\n";
}*/

std::mt19937 result::make_rng(){
    std::random_device rd;
    std::seed_seq seed { rd(), rd(), rd(), rd() };
    return std::mt19937(seed);
}

result result::play_random_game(std::mt19937& rng) {
    board board;
    board.init();

    move moves[132];
    int  n_moves = 0;

    while (true) {
        int n = get_moves(board, moves);
        if (n == 0) break;

        std::uniform_int_distribution<int> dist(0, n - 1);
        moves[dist(rng)].apply(board);
        n_moves++;
    }

    return result(n_moves, board.count(), board.victory());
}

