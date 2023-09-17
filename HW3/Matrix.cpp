#include "Matrix.h"

// Fill in here
using namespace std;


// 1. Matrix ------------------------------------------------------------------------------------

    // 1-1. Matrix Constructor
Matrix::Matrix(int row_, int col_) : rownum(row_), colnum(col_) {
    m = new double*[rownum];
    for (int i = 0; i < rownum; ++i) {
        m[i] = new double[colnum];
    }
    
    for (int i=0; i<rownum; i++) {
        for (int j=0; j<colnum; j++) {
            m[i][j] = 0;
        }
    }
}
    
    // 1-2. Copy constructor
Matrix::Matrix(const Matrix& right) : rownum(right.rownum), colnum(right.colnum) {
    m = new double*[rownum];
    for (int i = 0; i < rownum; ++i) {
        m[i] = new double[colnum];
    }
    
    for (int i=0; i<rownum; i++) {
        for (int j=0; j<colnum; j++) {
            m[i][j] = right.m[i][j];
        }
    }
}

    // 1-3. operator overloading: +
Matrix Matrix::operator+ (const Matrix& right){
    Matrix temp(rownum, colnum);
    for (int i = 0; i < rownum; ++i) {
        for (int j = 0; j < colnum; ++j) {
            temp.m[i][j] = m[i][j] + right.m[i][j];
        }
    }
    return temp;
}

    // 1-4. operator overloading: -
Matrix Matrix::operator- (const Matrix& right){
    Matrix temp(rownum, colnum);

    for (int i = 0; i < rownum; ++i) {
        for (int j = 0; j < colnum; ++j) {
            temp.m[i][j] = m[i][j] - right.m[i][j];
        }
    }
    return temp;
}

    // 1-5. operator overloading: *
Matrix Matrix::operator* (const Matrix& right){
    Matrix temp(rownum, right.colnum);
    for (int i = 0; i < temp.rownum; ++i) {
        for (int j = 0; j < temp.colnum; ++j) {
            for (int k = 0; k < colnum; ++k) {
                temp.m[i][j] += (m[i][k] * right.m[k][j]);
            }
        }
    }
    return temp;

}

    // 1-6. Transpose
Matrix Matrix::Transpose(void) {
    Matrix ret(colnum, rownum);
    for (int i = 0; i < rownum; ++i) {
        for (int j = 0; j < colnum; ++j) {
            ret.m[j][i] = m[i][j];
        }
    }
    return ret;
}

    // 1-7. Get subVector by column
Matrix Matrix::GetSubVectorbyColumn(int column) {
    Matrix temp(rownum, 1);
    for (int i=0; i<rownum; i++) {
        temp.m[i][0] = m[i][column];
    }
    return temp;
}

    // 1-8. Print
void Matrix::Print(void) {
    for (int i=0; i<rownum; i++) {
        for (int j=0; j<colnum; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

    // 1-9. Return # of rows
int Matrix::GetNumRow(void) {
    return rownum;
}

    // 1-10. Return # of columns
int Matrix::GetNumColumn(void) {
    return colnum;
}

    // 1-11. Return value from matrix with exact location
double Matrix::GetVal(int x, int y) {
    return m[x][y];
}


// 2. DataFrame ------------------------------------------------------------------------------------

    // 2-0. split function
vector<string> split(string input, char delimiter) {
    vector<string> v;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        v.push_back(temp);
    }
    return v;
}

    // 2-1. DataFrame Constructor
DataFrame::DataFrame(void) {}


    // 2-2. Read Data to DataFrame
int DataFrame::ReadData(string path, char sep, char comment, bool IsHeader) {   
    ifstream input_file(path);
    string line;

    while (getline(input_file, line)) {

        if (line[0] == comment) {
            continue;
        }
        
        if (IsHeader) {
            IsHeader = false;
            for (int i=0; i<line.length(); i++)
                if (line[i] == sep)
                    colnum += 1;
            continue;
        }

        rownum += 1;

        vector<string> v = split(line, sep);
        for (int i=0; i<v.size(); i++)
            values.push_back(stod(v[i]));
    }

    input_file.close();
    return 0;
}

    // 2-3. Get Matrix from DataFrame
Matrix DataFrame::GetMatrix(int index[], int nColumn) {
    Matrix temp(rownum, nColumn);
    for (int i=0; i<nColumn; i++) {
        int k = index[i];
        for (int j=0; j<rownum; j++) {
            temp.m[j][i] = values[k];
            k += colnum;
        }
    }
    return temp;
}


// 3. Correlation, LinearRegression ------------------------------------------------------------------------------------

    // 3-0-1. vector mean
double vec_mean(const Matrix &mat) {
    double sum = 0;
    for (int i=0; i<mat.rownum; i++) {
        sum += mat.m[i][0];
    }
    
    double mean = sum / mat.rownum;
    return mean;
}
    
    // 3-0-2. Standard Deviation
double st_dev(const Matrix& mat) {
    double rss = 0;
    double st_dev = 0;
    for (int i=0; i<mat.rownum; i++) {
        rss += pow(mat.m[i][0] - vec_mean(mat), 2);
    }
    st_dev = sqrt(rss);
    return st_dev;
}

    // 3-0-3. Covariance
double covariance(const Matrix &left, const Matrix &right) {
    double cov = 0;
    for (int i=0; i<left.rownum; i++) {
        double residual_l = left.m[i][0] - vec_mean(left);
        double residual_r = right.m[i][0] - vec_mean(right);
        
        cov += residual_l * residual_r;
    }
    return cov;
}

    // 3-0-4. Concordant
double concordant(const Matrix& left, const Matrix& right) {
    double C = 0;
    for (int i=0; i<left.rownum; i++) {
        for (int j=0; j<i; j++) {
            if ((left.m[i][0] - left.m[j][0]) * (right.m[i][0] - right.m[j][0]) >= 0) {
                C++;
            }
        }
    }
    return C;
}

    // 3-0-5. Disconcordant
double disconcordant(const Matrix& left, const Matrix& right) {
    double D = 0;
    for (int i=0; i<left.rownum; i++) {
        for (int j=0; j<i; j++) {
            if ((left.m[i][0] - left.m[j][0]) * (right.m[i][0] - right.m[j][0]) < 0) {
                D++;
            }
        }
    }
    return D;
}

    // 3-1. Pearson Correlation
Matrix Cor(Matrix &mat, int method) {
    Matrix temp(mat.colnum, mat.colnum);
    if (method == 1) {
        for (int i=0; i<mat.colnum; i++) {
            for (int j=0; j<mat.colnum; j++) {

                Matrix left = mat.GetSubVectorbyColumn(i);
                Matrix right = mat.GetSubVectorbyColumn(j);

                double std_l = st_dev(left);
                double std_r = st_dev(right);

                double cov = covariance(left, right);

                temp.m[i][j] = cov / (std_l * std_r);

                if (i == j) {
                    temp.m[i][j] = 1;
                }
            }
        }
    }
    else {
        for (int i=0; i<mat.colnum; i++) {
            for (int j=0; j<mat.colnum; j++) {
                double C = 0;
                double D = 0;
                
                Matrix left = mat.GetSubVectorbyColumn(i);
                Matrix right = mat.GetSubVectorbyColumn(j);

                C += concordant(left, right);
                D += disconcordant(left, right);

                temp.m[i][j] = (C-D) / (C+D);
            
                if (i == j) {
                    temp.m[i][j] = 1;
                }            
            }
        }
    }
    return temp;
}

    // 3-2. Linear Regression
Matrix SimpleLinearRegression(Matrix &X, Matrix &Y) {
    Matrix temp(2,1);
    
    double Beta_0;
    double Beta_1;

    Beta_1 = covariance(X, Y) / pow(st_dev(X), 2);
    Beta_0 = vec_mean(Y) - (Beta_1 * vec_mean(X));

    temp.m[0][0] = Beta_0;
    temp.m[1][0] = Beta_1;
    return temp;
}