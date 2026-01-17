#ifndef DATA_H
#define DATRA_H

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#include <iostream>
#include <iomanip>
#include <ios>
#include <iostream>

#define SPACE 3

using namespace std;


class Data{
    private:
    /**
    * stores sudoku number
    */
    int number;
    /**
    * false if player can modify it,
    * true if not.
    */
    bool constant;

    public:

    Data(const int& number, const bool& constant);

    Data(const int& number);

    // GETTERS

    /**
    * false if player can modify it,
    * true if not.
    */
    bool is_constant() const;

    /**
    * returns number
    */
    int get_number() const;

    void set_number(const int& n);

    friend ostream& operator<<(ostream& os, const Data& d);
};

#endif // DATRA_H