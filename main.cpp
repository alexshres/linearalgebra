// Main file to currently test Matrix class functions

#include "matrix.h"
#include <stdexcept>

int main()
{
    /*
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

    Matrix mat_mul(4, 3, 1);

    try {
        Matrix mat_mul_result = scalar_mult * mat_mul; 
        std::cout << "Testing matrix mul with matrices:\n" 
                  << mat_mul_result << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    */

    Matrix inv_mat(2, 2, 1);
    Matrix sc = inv_mat.inverse();

    std::cout << "inverted of 2x2 is \n" << sc << std::endl;

    std::vector<int> dimensions(2);

    dimensions = sc.getDimensions();

    std::cout << "Number of rows: " << dimensions[0] << "\nNumber of cols: " 
              << dimensions[1] << std::endl;

    return 0;
}
