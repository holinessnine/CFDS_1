#include <iostream>
#include <fstream>
#include <string>
#include "Matrix.h"
using namespace std;

int main()
{

	DataFrame frame;
	frame.ReadData("coris.txt", ',', '#', true);

	int Column[3] = {1, 3, 4}; // sbp, ldl, adiposity
	Matrix m = frame.GetMatrix(Column, 3);

	Matrix m_t = m.Transpose();
	Matrix m_tm = m_t * m;

	cout << "Matrix M^T M:" << endl;
	m_tm.Print();

	Matrix Pearson = Cor(m);
	
	Matrix Kendall = Cor(m, 2);

	cout << "Pearson:" << endl;
	Pearson.Print();

	cout << "Kendall:" << endl;
	Kendall.Print();

	Matrix a = Pearson + Kendall;
	Matrix b = Pearson - Kendall;
	cout << "Pearson + Kendall:" << endl;
	a.Print();

	cout << "Pearson - Kendall:" << endl;
	b.Print();

	// Simple Linear regression
	Matrix Y = m.GetSubVectorbyColumn(0); // sbp
	Matrix X = m.GetSubVectorbyColumn(1); // ldl

	Matrix Coeff = SimpleLinearRegression(X, Y);

	cout << "Simple Linear Regression Output:" << endl;
	Coeff.Print();

	return 0;
}
