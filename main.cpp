#include <iostream>
#include <stdexcept>
#include <cstddef>
#include "planar.hpp"
#include "point.hpp"
#include "vector.hpp"

int main()
{
  size_t k = 0;
  size_t c = 20;
  Planar ** pls = new Planar *[c];
  while (std::cin)
  {
    Planar * pl = nullptr;
    try
    {
      pl = make(std::cin);
      if (k == c)
      {
        Planar ** epls = new Planar *[c * 2];
        for ( size_t i = 0; i < k; ++i)
        {
          epls[i] = pls[i];
        }
        delete[] pls;
        pls = epls;
        c *= 2;
      }
      pls[k++] = pl;
    }
    catch(...)
    {
      delete[] pl;
      free_planars(pls, k);
      delete[] pls;
      return 2;
    }
  }
  if (!std::cin.eof())
  {
    free_planars(pls, k);
    delete[] pls;
    return 2;
  }
  Planar ** m = mostleft(pls, k);
  if (m == pls + k)
  {
    std::cout << "not found";
    free_planars(pls, k);
    delete[] pls;
    return 0;
  }
  draw(*m);
  std::cout << "\n";
  free_planars(pls, k);
  delete[] pls;
  return 0;
}

Planar * make(std::istream& is)
{
  char cmd[2] = {};
  is >> cmd[0] >> cmd[1];
  int data[4] = {};
  if (cmd[0] == 'P' && cmd[1] == 'T')
  {
    if (is >> data[0] >> data[1])
    {
      return new Point(data[0], data[1]);
    }
  }
  else if (cmd[0] == 'V' && cmd[1] == 'T')
  {
    if (is >> data[0] >> data[1] >> data[2] >> data[3])
    {
      return new Vector(Point(data[0], data[1]), Point(data[2], data[3]));
    }
  }
    throw std::logic_error("bad cmd");
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

Planar ** mostleft(Planar ** pls, size_t k)
{
  if (!k) //нулевая длина
  {
    return pls;
  }
  Planar ** res = pls;
  while (--k)
  {
    int next_x = (*(++pls))->x();
    int curr_x = (*res)->x();
    if (next_x < curr_x)
    {
      res = pls;
    }
  }
  return res;
}