/**
 * Ticoloi
 * 2026
 */
#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <vector>
#include <vector2i.h>
#include <fstream>
#include <map>

#include "data.h"

using namespace std;

/**
 * This object stores the sudoku information and
 * manages logic.
*/
class Sudoku{
    private:

    /**
     * returns a dictionary with numbers,
     * its used in is_valid function
     */
    map<int, bool> get_empty_dict() const;

    /** 
    * Here is where sudoku stores
    * numbers put by user and initials
    */
    vector<vector<Data>> table;

    /**  
    * The size of sudoku, multiply this size*size
    */
    int size;
    /*
        The sqaure root of size. (3*3 has size of 9)
    */
    int sub_size;


    // PRIVATE METHODS

    /**
     * Creates the sudoku, this functions is only 
     * called from constructors methods
     */
    void build_sudoku(fstream& file);

    public:


    // CONSTRUCTORS

    /**
     * Create new sudoku
     * whith size*size
     * size*size x size*sixe
     */
    Sudoku(const int &size, fstream& file);

    /**
     * Create new sudoku
     * whith size 9 x 9
     */
    Sudoku(fstream& file);


    // GETTERS

    int get_tile(const Vector2i& pos) const;

    /**
     * True if can be edited
     * false if not
     */
    bool can_be_edited(const Vector2i& pos) const;

    /**
    * returns size of sudoku
    */
    int get_size() const;

    /**
    * returns square rot of size, lol
    */
    int get_sub_size() const;

    /*
        returns if the soultion is valid or not
    */
    bool is_valid() const;

    /**
     * returns true if is completed
     */
    bool is_completed() const;

    // SETTERS

    /**
    * If possible modifiy the tile on that position
    * if not possible returns false
    */
    bool add_tile(const Vector2i& pos);

    // OPERATORS

    Data* operator[](const Vector2i& pos);

    Data operator[](const Vector2i& pos) const;

    vector<Data>* operator[](const int& pos);

    vector<Data> operator[](const int& pos) const;

    Sudoku& operator=(const Sudoku &s); 

    // COUT

    friend ostream& operator<<(ostream& os, const Sudoku& s);


};

#endif // SUDOKU_H
