/**
 * Ticoloi
 * 2026
 */
#include "sudoku.h"

map<int, bool> Sudoku::get_empty_dict() const
{
    map<int,bool> dict;
    for(int n = 1; n <= this->get_size(); n++){
        dict.insert(pair<int,bool>(n, false));
    }
    return dict;
}


void Sudoku::build_sudoku(fstream& file)
{   
    // buildding an empty table
    for(int i = 0; i < this->size; i++){
        vector<Data> n;
        for(int j = 0; j < this->size; j++){
            n.push_back(Data(0, false));
        }
        table.push_back(n);
    }

    // fillin the table
    int n = 0;
    while (!file.eof())
    {
       string line;
       getline(file, line);
       for(int i = 0; i < line.size(); i++){
            if(line[i] != '0'){
                this->table[n][i] = Data((int)line[i]  - 48, true);
            }
       }
       n++;
    }
    // file closes here
    file.close();
}

Sudoku::Sudoku(const int &size, fstream& file)
{
    this->size = size*size;
    this->build_sudoku(file);
}

Sudoku::Sudoku(fstream& file)
{
    this->size = 9;
    this->build_sudoku(file);
}

int Sudoku::get_tile(const Vector2i &pos) const
{
    return this->table[pos.x][pos.y].get_number();
}

bool Sudoku::can_be_edited(const Vector2i &pos) const
{
    return !this->table[pos.x][pos.y].is_constant();
}

int Sudoku::get_size() const
{
    return size;
}

int Sudoku::get_sub_size() const
{
    return sqrt(size);
}

bool Sudoku::is_valid() const
{
    Vector2i coords;
    for(int i = 0 ; i < this->get_size(); i++){
        // Create 2 dictionaries
        map<int, bool> dict_vert = this->get_empty_dict();
        map<int, bool> dict_hor = this->get_empty_dict();
        // now let's check rows
        for(int j = 0 ; j < this->get_size(); j++){
            // do a check (horizontal)
            coords = Vector2i(i,j);
            if(this->table[coords.x][coords.y].get_number() != 0){
                if(dict_hor[this->table[coords.x][coords.y].get_number()]){
                    return false;
                }else{
                    dict_hor[this->table[coords.x][coords.y].get_number()] = true;
                }
            }
            // another check (vertical)
            coords = Vector2i(j,i);
            if(this->table[coords.x][coords.y].get_number() != 0){
                if(dict_vert[this->table[coords.x][coords.y].get_number()]){
                    return false;
                }else{
                    dict_vert[this->table[coords.x][coords.y].get_number()] = true;
                }
            }
        }
    }
    // I may be wrong abaut vertical and horizontal, sorry
    // Ok, now let's check other area
    const int QUADRANT_SIZE = this->get_sub_size();
    for(int y = 0; y < QUADRANT_SIZE; y++){
        for(int x = 0; x < QUADRANT_SIZE; x++){
            // create a new dictionary
            map<int, bool> dict = get_empty_dict();
            // iterate AGAIN
            for(int i = 0; i < QUADRANT_SIZE; i++){
                for(int j = 0; j < QUADRANT_SIZE; j++){
                    coords = Vector2i(
                        x * QUADRANT_SIZE + j,
                        y * QUADRANT_SIZE + i
                    );
                    int number =  this->table[coords.x][coords.y].get_number();
                    if(number != 0){
                        if(dict[number]){
                            return false;
                        }else{
                            dict[number] = true;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool Sudoku::is_completed() const
{
    for(int i = 0;  i < this->get_size(); i++){
        for(int j = 0;  j < this->get_size(); j++){
            if(this->table[j][i].get_number() == 0){
                return false;
            }
        }
    }
    return is_valid();
}

bool Sudoku::add_tile(const Vector2i &pos)
{
    if(this->table[pos.x][pos.y].is_constant()){
        return false;
    }
    return true;
}

Data *Sudoku::operator[](const Vector2i &pos)
{
    return &this->table[pos.x][pos.y];
}

Data Sudoku::operator[](const Vector2i &pos) const
{
    return this->table[pos.x][pos.y];
}


vector<Data> *Sudoku::operator[](const int &pos)
{
     return &this->table[pos];
}

vector<Data> Sudoku::operator[](const int &pos) const
{
    return this->table[pos];
}

Sudoku &Sudoku::operator=(const Sudoku &s)
{
    this->table = s.table;
    this->size = s.get_size();
    return *this;
}

ostream &operator<<(ostream &os, const Sudoku &s)
{
    // this function is not too easy to read, i know
    for(int i = 0; i < s.get_size(); i++){
        // ADDING - IN WHITE
        if(i%int(sqrt(s.get_size())) == 0){
            for(int j = 0 - int(sqrt(s.get_size()) + 1);  j < s.get_size(); j++){
                for(int k = 0; k < SPACE ; k++){
                    // LOOPING FOR ADDING '-'
                    os << BOLDWHITE << "-" << RESET;
                }
                
            }
            os << endl;
        }
        for(int j = 0;  j < s.get_size(); j++){
            // ADDING NUMBERS
            if(j%int(sqrt(s.get_size())) == 0){
                // SEPARATION
                os << BOLDWHITE << setw(SPACE)  << "|" << RESET;
            }
            os << s[Vector2i(i,j)];
        }
        // the end of row
        os << BOLDWHITE << setw(SPACE)  << "|" << RESET;
        os << endl;
        
    }
    for(int j = 0 - int(sqrt(s.get_size()) + 1);  j < s.get_size(); j++){
        // LOOPING FOR ADDING '-', this way you have the end
        for(int k = 0; k < SPACE ; k++){
            os << BOLDWHITE << "-" << RESET;
        }
    }
    cout << endl;
    return os;
}

