//
// Created by Sofia Chen on 08/05/26.
//

#ifndef MOSSE_H
#define MOSSE_H

 /* Una mossa è descritta da:
 *  from = (fr, fc) : pedina che si sposta
 *  over = (or, oc) : pedina saltata
 *  to = (tr, tc) : casella di arrivo
 *
 * Le 4 direzioni di spostamento di 2 caselle: su(-2,0), giù(+2,0), sinistra(0,-2), destra(0,+2) */

#include "scacchiera.h"

class move {
private:
    pos from, over, to;
public:
    move()=default;
    move(pos f, pos o, pos t) : from(f), over(o), to(t) {};
    void apply(board& b) const;
};

int get_moves(const board& b, move m[132]);

#endif //MOSSE_H
