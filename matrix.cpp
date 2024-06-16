/*
 * Alex Shrestha
 * Matrix Class Implementation
 */

#include "matrix.h"
#include <stdexcept>


Matrix::Matrix(): rows(2), cols(2), data(2, std::vector<int>(2, 0))
{}


Matrix::Matrix(int r, int c): rows(r), cols(c), data(r, std::vector<int>(c, 0))
{}


Matrix::Matrix(int r, int c, int n): rows(r), cols(c), data(r, std::vector<int>(c, n))
{}



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
    Matrix result(lhs.rows, rhs.cols);


    for (int r = 0; r < lhs.rows; ++r) {
        for (int c = 0; c < rhs.cols; ++c) {
            for (int k = 0; k < lhs.cols; ++k)
                result.data[r][c] += lhs.data[r][k] * rhs.data[k][c];
        }
    }

    return result;
}

// TODO
Matrix Matrix::inverse() const
{

    if (rows != cols) {
        throw std::invalid_argument("Matrix must be a square matrix.\n");
    }
    // create new matrix with identity augmented to it

    Matrix scratch(rows, 2*cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            scratch.data[i][j] = data[i][j];
    }

    // Add diagonal 1's to create the identity augment
    for (int i = 0; i < rows; ++i) {
        scratch.data[i][i+rows] = 1;
    }

    return scratch;
}

std::vector<int> Matrix::getDimensions() const
{
    std::vector<int> result(2);

    result[0] = rows;
    result[1] = cols;

    return result;
}


std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
    for (int r = 0; r < mat.rows; ++r) {
        for (int c = 0; c < mat.cols; ++c) 
            os << mat.data[r][c] << " ";
        os << "\n";
    }

    return os;
}
