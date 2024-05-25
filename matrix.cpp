/*
 * Alex Shrestha
 * Matrix Class Implementation
 */

#include "matrix.h"


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

