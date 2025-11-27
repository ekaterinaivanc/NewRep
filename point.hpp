#ifndef POINT_HPP
#define POINT_HPP
#include "planar.hpp"

struct Point: Planar 
{
  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;   
  Point(int xx, int yy);
  virtual ~Point() = default;
  virtual double area() const;
  virtual frame_t frame() const;

  private:
    int data[2];
};

#endif