#include "vector.hpp"

Vector::Vector(const Point & t1, const Point & t2):
  data{t2.x() - t1.x(), t2.y() - t1.y()}
  {}

Vector::Vector(int xx, int yy):
  data{xx, yy}
  {}

int Vector::x() const
{
  return data[0];
}

int Vector::y() const
{
  return data[1];  
}

int Vector::abs_sqr() const
{
  return x() * x() + y() * y();  
}
