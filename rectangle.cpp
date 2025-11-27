#include "rectangle.hpp"
#include "point.hpp"

Rectangle::Rectangle(int x1, int y1, int x2, int y2):
  Planar(),
  top1(x1, y1),
  top2(x2, y2)
{}

Rectangle::Rectangle(const Point & t1, const Point & t2):
  top1(t1),
  top2(t2)
  {}

int Rectangle::x() const
{
  return (top1.x() + top2.x()) / 2;
}

int Rectangle::y() const
{
  return (top1.y() + top2.y()) / 2;
}

int Rectangle::abs_sqr() const
{
  return x() * x() + y() * y();  
}

double Rectangle::area() const
{
  int width = ((top2.x() - top1.x()) < 0) ? -(top2.x() - top1.x()) : (top2.x() - top1.x());  
  int height = ((top2.y() - top1.y()) < 0) ? -(top2.y() - top1.y()) : (top2.y() - top1.y());  

  return static_cast<double>(width * height);
}

frame_t Rectangle::frame() const
{
  int min_x = (top1.x() < top2.x()) ? top1.x() : top2.x();    
  int min_y = (top1.y() < top2.y()) ? top1.y() : top2.y();  
  int max_x = (top1.x() > top2.x()) ? top1.x() : top2.x();   
  int max_y = (top1.y() > top2.y()) ? top1.y() : top2.y();   

  return frame_t{{min_x, min_y}, {max_x, max_y}};
}