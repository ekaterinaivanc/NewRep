#include <iostream>
#include <stdexcept>
#include <cstddef>
#include "planar.hpp"
#include "point.hpp"
#include "vector.hpp"

int main()
{
  Planar * pls[10] = {};
  size_t k = 0;
  for (size_t i = 0; i < 10; ++i)
  {
    try{
        pls[k] = make(i % 2);
    }
    catch(...)
    {
      free_planars(pls, k);
      return 2;
    }
    k++;
  }
  draw(mostleft(pls, k));
  free_planars(pls, k);
  //pls[k++] = make(std::cin);
  Planar * left = mostleft(pls, k);
  draw(left);
}

Planar * make(size_t id)
{
  Planar * r = nullptr;
  switch(id)
  {
    case 0:
      r = new Point(0,0);
      break;
    case 1:
      r = new Vector(1,1);
      break;
    default:
      throw std::logic_error("bad id");
  }
  return r;
}

void free_planars(Planar ** pls, size_t k)
{
  for (size_t i = 0; i < k; ++i)
  {
    delete pls[i];
  }
}

void draw(Planar * pl)
{
  std::cout << pl->x();
  std::cout << " ";
  std::cout << pl->y() << "\n";
}

Planar * mostleft(Planar ** pls, size_t k)
{
  return nullptr;
}