/**
 * Ticoloi
 * 2026
 */

 #ifndef CANDIDATE_H
 #define CANDIDATE_H

#include "sudoku.h"
#include <map>

using namespace std;



class Candidate{
    private:
    /**
     * position of current checked number
     */
    Vector2i position;

    /**
     * valiue of current checked number
     */
    int number;

    /**
     * If desanotate fails, then try this one
     */
    void previus(Sudoku &sudoku); 


    public:
    
        Candidate();

        // GETTERS: 

        int get_number() const;

        Vector2i get_position() const;


        // FUNCTIONS: 

        /**
        * on current coords, adds + 1, if not possible then returns false
        */
        void next(Sudoku &sudoku);


        /**
        * anotate a number
        */
        void anotate(Sudoku &sudoku);



        /**
        * disanotate a number
        */
        void disanotate(Sudoku &sudoku);


};


#endif // CANDIDATE_H