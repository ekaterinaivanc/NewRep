#include <iostream>

struct Planar
{
  virtual int x() const;
  virtual int y() const;
  virtual int abc_sqr() const = 0;
  virtual ~Planar() = default;
};

Planar * make(std::istream& is);
Planar * make(size_t pl);
void draw(Planar * pl);
void free_planars(Planar ** pls, size_t k);
Planar * mostleft(Planar ** pls, size_t k);

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
  //Planar * left = mostleft(pls, k);
  //draw(left);
  //free_planars(pls, k);
}

Planar * make(size_t pl)
{
  switch(pl)
  {
    default:
      throw std::logic_error("bad id");
  }
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