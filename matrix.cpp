/*
 * Alex Shrestha
 * Matrix Class Implementation
 */

#include "matrix.h"
#include <stdexcept>


Matrix::Matrix(): rows(2), cols(2), data(2, std::vector<int>(2, 0))
{
}

Matrix::Matrix(int r, int c): rows(r), cols(c), data(r, std::vector<int>(c, 0))
{
}

Matrix::Matrix(int r, int c, int n): rows(r), cols(c), data(r, std::vector<int>(c, n))
{
}


std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
    
    for (int r = 0; r < mat.rows; ++r) {
        for (int c = 0; c < mat.cols; ++c) 
            os << mat.data[r][c] << " ";
        os << "\n";
    }

    return os;
}

Matrix operator*(const Matrix& mat, int scalar)
{
    // copy mat to new matrix
    Matrix result = mat;

    for (int r = 0; r < mat.rows; ++r) {
        for (int c = 0; c < mat.cols; ++c) 
            result.data[r][c] = scalar * result.data[r][c]; 
    }

    return result;
}

Matrix operator*(int scalar, const Matrix& mat)
{
    Matrix result = mat * scalar;

    return result;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
    if (lhs.cols != rhs.rows) {
        std::cerr << "Dimensions of matrix don't match" << std::endl;
        throw std::invalid_argument("Columns of left matrix must match rows of right matrix");
    }

    // Initializing matrix
    Matrix result(lhs.cols, rhs.rows);


    for (int r = 0; r < lhs.rows; ++r) {
        for (int k = 0; k < rhs.cols; ++k) {
            for (int c = 0; c < lhs.cols; ++c)
                result.data[r][k] += lhs.data[r][c] * rhs.data[c][k];
        }
    }

    return result;
}
