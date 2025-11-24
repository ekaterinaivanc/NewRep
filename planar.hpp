#include <cstddef>
#ifndef PLANAR_HPP
#define PLANAR_HPP

struct Planar
{
  virtual int x() const = 0;
  virtual int y() const = 0;
  virtual int abs_sqr() const = 0;
  virtual ~Planar() = default;
};

//Planar * make(std::istream& is);
Planar * make(size_t pl);
void draw(Planar * pl);
void free_planars(Planar ** pls, size_t k);
Planar * mostleft(Planar ** pls, size_t k);

#endif