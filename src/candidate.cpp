#include "candidate.h"



Candidate::Candidate()
{
    this->position = Vector2i(-1,0);
    this->number = 1;
}

int Candidate::get_number() const
{
    return this->number;
}

Vector2i Candidate::get_position() const
{
    return this->position;
}



void Candidate::next(Sudoku &sudoku)
{
    this->number = this->number + 1;
    sudoku[this->position]->set_number(this->number);
}


void Candidate::anotate(Sudoku &sudoku)
{
    this->position.x = this->position.x + 1;
    if((this->position.x) >= sudoku.get_size()){
        this->position.x = 0;
        this->position.y = this->position.y + 1;
    }
    if(sudoku[this->position]->is_constant()){
        this->anotate(sudoku); // try again
    }else{
        /*
        int n = sudoku[position]->get_number();
        if(n <= 0){
            this->number = 1;
        }else{
            this->number = n;
        }
        */
        this->number = 1;
        sudoku[position]->set_number(this->number);
    }

}

void Candidate::disanotate(Sudoku &sudoku)
{
    sudoku[position]->set_number(0);
    this->position.x = this->position.x - 1;    
    if((this->position.x) < 0){
        this->position.x = sudoku.get_size() - 1;
        this->position.y = position.y - 1;
    }
    if(sudoku[this->position]->is_constant()){
        this->previus(sudoku); // try again
    }else{
        this->number = sudoku[position]->get_number();
    }
    
}

void Candidate::previus(Sudoku &sudoku)
{
    this->position.x = this->position.x - 1;    
    if((this->position.x) < 0){
        this->position.x = sudoku.get_size() - 1;
        this->position.y = position.y - 1;
    }
    if(sudoku[this->position]->is_constant()){
        this->previus(sudoku); // try again
    }else{
        this->number = sudoku[position]->get_number();
    }
}
