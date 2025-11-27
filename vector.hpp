#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "planar.hpp"
#include "point.hpp"

struct Vector: Planar 
{
  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;   
  Vector(int x1, int y1, int x2, int y2);
  Vector(const Point & t1, const Point & t2);
  virtual ~Vector() = default;
  virtual double area() const;
  virtual frame_t frame() const;

  private:
    Point start;
    Point end;
};

#endif