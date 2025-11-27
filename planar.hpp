#include <cstddef>
#include <iostream>
#ifndef PLANAR_HPP
#define PLANAR_HPP

struct p_t
{
  int x, y;
};

struct frame_t
{
  p_t AA, BB;
};

struct Planar
{
  virtual int x() const = 0;
  virtual int y() const = 0;
  virtual int abs_sqr() const = 0;
  virtual ~Planar() = default;
  virtual double area() const = 0;
  virtual frame_t frame() const = 0;
};

Planar * make(std::istream& is);
Planar * make(size_t pl);
void draw(Planar * pl);
void free_planars(Planar ** pls, size_t k);
Planar ** mostleft(Planar ** pls, size_t k);
Planar ** max_area(Planar ** pls, size_t k);
Planar ** max_frame_intersects(Planar ** pls, size_t k);

#endif