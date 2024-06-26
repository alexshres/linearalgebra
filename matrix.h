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
        
        // Scalar multiplication
        friend Matrix operator*(const Matrix& mat, int scalar);
        friend Matrix operator*(int scalar, const Matrix& mat);

        // Matrix-matrix multiplication
        friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);


        /*
         *
         * MATRIX OPERATIONS
         *      * Inverse
         *      * LU Decomposition
         *      * Echelon Form
         *      * Row-Reduced Echelon Form
         *      * Transpose
         *      * Rank
         */

        // TODO
        Matrix inverse() const;
        Matrix lower_decomp() const;
        Matrix upper_decomp() const;
        Matrix echelon_form() const;
        Matrix rref() const;
        Matrix transpose() const;

        int rank() const;
        
        bool isSymmetric() const;
        bool isSquare() const;

        // Returns a vector of length 2 with the rows in the 0th index 
        // and columns in the 1st index
        std::vector<int> getDimensions() const;

        /*
            DISPLAY
        */
        // Display operator
        friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);

};
