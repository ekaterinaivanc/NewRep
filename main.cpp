#include <iostream>

struct Planar
{
  virtual int x() const;
  virtual int y() const;
  virtual int abc_sqr() const = 0;
  virtual ~Planar() = default;
};

Planar * make(std::istream& is);
Planar * mostleft(Planar ** pls, size_t k);

int main()
{
  Planar * pls[10] = {};
  size_t k = 0;
  //pls[k++] = make(std::cin);
  //Planar * left = mostleft(pls, k);
  //draw(left);
  //free_planars(pls, k);
}