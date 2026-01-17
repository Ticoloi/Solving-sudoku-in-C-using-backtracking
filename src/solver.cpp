#include "solver.h"
#include <chrono>
#include <thread>
bool Solver::solve_backtracking(Sudoku & s, Candidate & c)
{   
    
    cout << BOLDMAGENTA << "BOARD" << RESET << endl;
    cout << s;
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    sleep_for(nanoseconds(10));
    sleep_until(system_clock::now() + milliseconds(10));
    
    if(s.is_valid()){
        if(!s.is_completed()){
            c.anotate(s);
            while (c.get_number() <= s.get_size())
            {
                if(solve_backtracking(s,c)){
                    return true;
                }else{
                    c.next(s);
                }
            }
            c.disanotate(s);
            return false;
        }else{
            return true;
        }
    }else{
        return false;
    }
}


Solver::Solver()
{
    
}


bool Solver::solve(Sudoku &s)
{
    Candidate c;
    if(!s.is_valid()){
        cout << BOLDRED << "ERROR, IMPOSSIBLE TO SOLVE" << RESET << endl;
        return false;
    }

    return solve_backtracking(s,c);
    
}
