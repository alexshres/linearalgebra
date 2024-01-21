#include "vector.h"


namespace LinearAlgebra {
  Vector::Vector() : length(0), arr(nullptr);
  {}


  Vector::Vector(std::size_t size): length(size): arr(nullptr) {
    arr = new float(size);
    for (int i = 0; i < size; i++)
      arr[i] = 0;
  }
}
