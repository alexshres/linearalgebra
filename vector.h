/*
* Author: Alex Shrestha
* Vector class that emulates mathematical vector objects.
* Operations that should be possible:
*   1. Addition/Subtraction
*   2. Scalar Multiplication
*   3. Dot Product
*   4. Given another vector object, maybe also find the angle between them
*/


#ifndef VECTOR_H
#define VECTOR_H

namespace LinearAlgebra {

class Vector {
  private:
    int length;
    float *arr;   // underlying data type really is just a float 
  public:
    Vector();
    Vector(std::size_t size);
    Vector(const float *a, std::size_t size);
    Vector(const Vector &other);
    ~Vector();

    int dotProduct(const Vector &other);
    

};
  
}


#endif
