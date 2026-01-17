/**
 * Ticoloi
 * 2026
 */

 #ifndef SOLVER_H
 #define SOLVER_H

#include "candidate.h"


/**
 * This class solves your sudoku
*/
class Solver{
    private:

    bool solve_backtracking(Sudoku& s, Candidate &c);

    public:

        Solver();
        
        /**
         * You give solver a sudoku and it solves for you
         */
        bool solve(Sudoku& s);

};


#endif // SOLVER_H

