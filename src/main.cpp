/**
 * Ticoloi
 * 2026
 */
#include <iostream>
#include "sudoku.h"
#include "solver.h"
using namespace std;


int  main(int argc, const char * argv[]){
    if(argc <= 1){
        cout << BOLDRED << "ERROR, EXPECTED FILE NAME" << RESET << endl;
        return -1;
    }else{
        fstream f;
        f.open(argv[1]);
        if(f.is_open()){
            Sudoku s(f);
            // file f is closed in sudoku
            Solver solver;
            solver.solve(s);
            cout << s;
        }else{
            cout << BOLDRED << "ERROR, COULD NOT FIND FILE NAMED: " <<
            argv[1] << RESET << endl;
        }
        
        
        return 0;
    }

}