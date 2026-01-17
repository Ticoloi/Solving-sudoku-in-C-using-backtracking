#include "data.h"

Data::Data(const int& number, const bool& constant):
    number(number), constant(constant)
{
}
Data::Data(const int& number):
    number(number)
{
    this->constant = true;
}

bool Data::is_constant() const{
    return this->constant;
}

int Data::get_number() const{
    return this->number;
}

void Data::set_number(const int& n)
{
    if(!this->constant){
        this->number = n;
    }
}

ostream &operator<<(ostream &os, const Data &d)
{
    string character = "-";
    if(d.get_number() != 0){
        // first checking if its a number
        character = to_string(d.get_number());
        if(d.is_constant()){
            // RED BECAUSE ITS CONSTANT
            os << BOLDRED << setw(SPACE) <<  character << RESET;
        }else{
            // You can modify it
            os << GREEN  << setw(SPACE) << character << RESET;
        }
    }else{
        // if its not a number, then add spaces
        os << BOLDWHITE << setw(SPACE) << character << RESET;
    }

    return os;
}
