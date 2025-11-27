#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "planar.hpp"
#include "point.hpp"

struct Rectangle: Planar 
{
  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;   
  Rectangle(int x1, int y1, int x2, int y2);
  Rectangle(const Point & t1, const Point & t2);
  virtual ~Rectangle() = default;

  private:
    Point top1, top2;
};

#endif