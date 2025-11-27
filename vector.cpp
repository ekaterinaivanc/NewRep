#include "vector.hpp"

Vector::Vector(const Point & t1, const Point & t2):
  start(t1),
  end(t2)
  {}

Vector::Vector(int x1, int y1, int x2, int y2):
  start(x1, y1),
  end(x2, y2)
  {}

int Vector::x() const
{
  return end.x() - start.x();
}

int Vector::y() const
{
  return end.y() - start.y();  
}

int Vector::abs_sqr() const
{
  int dx = end.x() - start.x();
  int dy = end.y() - start.y();  
  return dx * dx + dy * dy; 
}

double Vector::area() const
{
  return 0.0;
}

frame_t Vector::frame() const
{
  int min_x = (start.x() < end.x()) ? start.x() : end.x();    
  int min_y = (start.y() < end.y()) ? start.y() : end.y();  
  int max_x = (start.x() > end.x()) ? start.x() : end.x();   
  int max_y = (start.y() > end.y()) ? start.y() : end.y();   

  return frame_t{{min_x, min_y}, {max_x, max_y}};
}