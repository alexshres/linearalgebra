/*
 * Alex Shrestha
 * Matrix Class Header 
 */

#pragma once

#include <vector>
#include <iostream>

class Matrix {
    private:
        int rows;
        int cols;

        std::vector<std::vector<int>> data;

    public:
        // Default constructor - will create an emptry 2x2 matrix filled w/ 0's
        Matrix();           
        
        // Initialize a matrix with r rows and c columns all to 0's
        Matrix(int r, int c);
        
        // Initialize a matrix with r rows and c columns all to n's
        Matrix(int r, int c, int n);

        // Display operator
        friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);

        // Scalar multiplication
        friend Matrix operator*(const Matrix& mat, int scalar);
        friend Matrix operator*(int scalar, const Matrix& mat);
        friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);

};
