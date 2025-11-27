#include <iostream>
#include <stdexcept>
#include <cstddef>
#include "planar.hpp"
#include "point.hpp"
#include "vector.hpp"
#include "rectangle.hpp"

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
  if (k > 0)
  {
    Planar ** max_area_pl = max_area(pls, k);
    draw(*max_area_pl);
  }
  if (k > 1)
  {
    Planar ** max_intersect_pl = max_frame_intersects(pls, k);
    if (max_intersect_pl)
    {
      draw(*max_intersect_pl);
    }
    frame_t main_frame = (*max_intersect_pl)->frame();
    for (size_t i = 0; i < k; ++i)
    {
      if (pls[i] != * max_intersect_pl && frames_intersect(main_frame, pls[i]->frame()))
      {
        draw(pls[i]);
      }
    }
  }
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
  else if (cmd[0] == 'R' && cmd[1] == 'E')
  {
    if (is >> data[0] >> data[1] >> data[2] >> data[3])
    {
      return new Rectangle(data[0], data[1], data[2], data[3]);
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
      r = new Vector(0, 0, 1,1);
      break;
    case 2:
      r = new Rectangle(0, 0, 2, 2);
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
  frame_t f = pl->frame();
  std::cout << f.AA.x << " " << f.AA.y << " " << f.BB.x << " " << f.BB.y << "\n";
}

Planar ** mostleft(Planar ** pls, size_t k)
{
  if (!k) 
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

Planar ** max_area(Planar ** pls, size_t k)
{
  if (!k)
  {
    return pls;
  }
  Planar ** max_pl = pls;
  double maxx_area = (*pls)->area();
  for (size_t i = 1; i < k; ++i)
  {
    double cur_area = pls[i]->area();
    if (cur_area > maxx_area)
    {
      maxx_area = cur_area;
      max_pl = pls + i;
    }
  }
  return max_pl;
}

bool frames_intersect(const frame_t & f1, const frame_t & f2)
{
  return !(f1.BB.x < f2.AA.x || f1.AA.x > f2.BB.x || f1.BB.y < f2.AA.y || f1.AA.y > f2.BB.y);
}

Planar ** max_frame_intersects(Planar ** pls, size_t k)
{
  if (k < 2)
  {
    return nullptr;
  }
  int max_c = 0;
  Planar ** res = nullptr;
  for (size_t i = 0; i < k; ++i)
  {
    int c = 0;
    frame_t frame_i = pls[i]->frame();
    for (size_t j = 0; j < k; ++j)
    {
      if (i != j && frames_intersect(frame_i, pls[j]->frame()))
      {
        c++;
      }
    }
    if (c > max_c)
    {
      max_c = c;
      res = pls + i;
    }
  }
  return res;
}