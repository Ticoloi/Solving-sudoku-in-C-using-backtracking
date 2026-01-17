/**
 * Ticoloi
 * 2026
 */

#ifndef VECTOR2I_H
#define VECTOR2I_H



class Vector2i{
    public:

    // Variables

    int x;
    int y;

    // CONSTRUCTORS

    /**
     * Base constructor
     * Pre: 
     * Post: x = 0 and y = 0
     */
    Vector2i();

    /**
    * Constuctor with parametres
    * Pre: x and y
    * Post: x = x and y = y
    */
    Vector2i(const int& x, const int& y);

    /**
    * Constuctor copy
    * Pre: Vector v
    * Post: x = v.x and y = v.y
    */
    Vector2i(const Vector2i& v);

    // DESTRUCTOR

    /**
    * Destroys Vector2i
    */
    ~Vector2i();

    // SETTERS

    /**
    * Pre: int n
    * Post: x = n
    */
    void set_x(const int& x);

    /**
    * Pre: int n
    * Post: y = n
    */
    void set_y(const int& y);

    // GETTERS

    /**
    * Pre:
    * Post: returns x
    */
    int get_x() const;

    /**
    * Pre: 
    * Post: returns y
    */
    int get_y() const;

    // OPERATORS

    friend Vector2i operator+( Vector2i v1,
        const Vector2i &v2); 

    Vector2i& operator+=(const Vector2i &v);

    friend Vector2i operator-( Vector2i v1,
        const Vector2i &v2); 

    Vector2i& operator-=(const Vector2i &v);

    Vector2i& operator=(const Vector2i &v); 

    bool operator==(const Vector2i &v) const; 

     








};

#endif //VECTOR2I_H