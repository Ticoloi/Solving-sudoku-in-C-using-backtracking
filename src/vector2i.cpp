/**
 * Ticoloi
 * 2026
 */
#include "vector2i.h"

Vector2i::Vector2i()
{
    this->x = 0;
    this->y = 0;
}

Vector2i::Vector2i(const int &x, const int &y):
    x(x), y(y)
{
}

Vector2i::Vector2i(const Vector2i &v)
{
    *this = v;
}

Vector2i::~Vector2i()
{
}

void Vector2i::set_x(const int &x)
{
    this->x = x;
}

void Vector2i::set_y(const int &y)
{
    this->y = y;
}

int Vector2i::get_x() const
{
    return this->x;
}

int Vector2i::get_y() const
{
    return this->y;
}

Vector2i &Vector2i::operator-=(const Vector2i &v)
{
    this->set_x(this->get_x() - v.get_x());
    this->set_y(this->get_y() - v.get_y());
    return *this;
}

Vector2i &Vector2i::operator=(const Vector2i &v)
{
    this->set_x(v.get_x());
    this->set_y(v.get_y());
    return *this;
}

bool Vector2i::operator==(const Vector2i &v) const
{
    return this->x == v.y and this->y == v.y;
}

Vector2i &Vector2i::operator+=(const Vector2i &v)
{
    this->set_x(this->get_x() + v.get_x());
    this->set_y(this->get_y() + v.get_y());
    return *this;
}

Vector2i operator+(Vector2i v1, const Vector2i &v2)
{   
    v1 += v2;
    return v1;
}

Vector2i operator-(Vector2i v1, const Vector2i &v2)
{
    v1 -= v2;
    return v1;
}
