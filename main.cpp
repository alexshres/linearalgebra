// Main file to currently test Matrix class functions

#include "matrix.h"

int main()
{
    Matrix test_default;

    std::cout << "Testing default constructor with test_default:\n" << test_default << std::endl;

    int rows = 3;
    int cols = 4;

    Matrix test_given_size(rows, cols);
    std::cout << "Testing constructor with rows and cols:\n" 
              << test_given_size << std::endl;


    int n = 5;
    Matrix test_given_input(rows, cols, n);
    std::cout << "Testing constructor with rows and cols and default value:\n" 
              << test_given_input<< std::endl;
    
    int scalar = 3; 

    Matrix scalar_mult = test_given_input * scalar;
    std::cout << "Testing matmul with scalar value of 3:\n" 
              << scalar_mult << std::endl;


    return 0;
}
