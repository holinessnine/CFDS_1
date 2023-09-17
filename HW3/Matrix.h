#pragma once

// Fill in here
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <valarray>
#include <algorithm>
#include <sstream>
#include <tuple>
#include <cmath>

using namespace std;

class Matrix {
    public:
        // constructor
        Matrix(int, int);
        
        // copy constructor
        Matrix(const Matrix&);

        // operator overloadings
        Matrix operator+ (const Matrix&);
        Matrix operator- (const Matrix&);
        Matrix operator* (const Matrix&);
        
        // transpose
        Matrix Transpose(void);

        // Get SubVector by Column
        Matrix GetSubVectorbyColumn(int);
        
        // Print matrix
        void Print(void);

        // Get Num of Row
        int GetNumRow(void);
        
        // Get Num of Column
        int GetNumColumn(void);
        
        // Get values from matrix
        double GetVal(int, int);
    
        int rownum;
        int colnum;
        double** m;
};


class DataFrame {
    public:
        // constructor
        DataFrame(void);

        // read data to dataframe
        int ReadData(std::string, char, char, bool);

        // dataframe to matrix
        Matrix GetMatrix(int[], int);

        vector<double> values;
        
        int rownum = 0;
        int colnum = 1;
};

Matrix Cor(Matrix&, int method = 1);
Matrix SimpleLinearRegression(Matrix&, Matrix&);