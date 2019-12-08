#include "Classes.h"

Matrix Matrix::Adamar(Matrix& B) {
	if (m != B.m || n != B.n){
		if (B.n == m && B.m == n){
			char c;
			cout << "Your matrixs have dimention error. Do you want to transpose last matrix? (y/n): ";
			cin >> c;
			if (c == 'y')
				B = B.Transpose();
			else
				throw 4;
		}
		else
			throw 4;
	}
	Matrix C(m, n);
	for (int i = 0; i < m; ++i)
	for (int j = 0; j < n; ++j)
		C.Element(i, j) = Mat[i][j] * B.Element(i, j);
	return C;
}

double Matrix::Scalar(Matrix& B) {
	if ((B.m == 1 || B.n == 1) && (m == 1 || n == 1)){
		if (m != B.m || n != B.n){
			if (B.n == m && B.m == n){
				char c;
				cout << "Your matrixs have dimention error. Do you want to transpose last matrix? (y/n): ";
				cin >> c;
				if (c == 'y')
					B = B.Transpose();
				else
					throw 11;
			}
			else
				throw 11;
		}
		double c1 = 0;
		for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			c1 += Mat[i][j] * B.Element(i, j);
		return c1;
	}
	else throw 11;
}

void Matrix::Display(int signal) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (signal && i == 0 && j == 0)
				cout.width(1);
			else
				cout.width(4);
			cout << Mat.at(i).at(j);
		}
		cout << endl;
	}
}

double &Matrix::Element(int i, int j) {
	if (i >= m || j >= n)
		throw 5;
	return Mat[i][j];
}

Matrix Matrix::operator*(Matrix &rv) {
	if (n != rv.m){
		if (rv.n == n && rv.m == m){
			char c;
			cout << "Your matrixs have dimention error. Do you want to transpose last matrix? (y/n): ";
			cin >> c;
			if (c == 'y')
				rv = rv.Transpose();
			else
				throw 3;
		}
		else
			throw 3;
	}
	Matrix C(m, rv.n);
	for (int i = 0; i < m; ++i)
	for (int j = 0; j < rv.n; ++j)
	for (int k = 0; k < n; ++k) {
		C.Element(i, j) += Mat[i][k] * rv.Element(k, j);
	}
	return C;
}

void Matrix::operator+(Matrix &rv) {
	if (rv.n != n || rv.m != m){
		if (rv.n == m && rv.m == n){
			char c;
			cout << "Your matrixs have dimention error. Do you want to transpose last matrix? (y/n): ";
			cin >> c;
			if (c == 'y')
				rv = rv.Transpose();
			else
				throw 2;
		}
		else
			throw 2;
	}
	for (int i = 0; i < m; i++)
	for (int j = 0; j < n; j++)
		Mat.at(i).at(j) += rv.Element(i, j);
}

void Matrix::operator-(Matrix &rv) {
	if (rv.n != n || rv.m != m){
		if (rv.n == m && rv.m == n){
			char c;
			cout << "Your matrixs have dimention error. Do you want to transpose last matrix? (y/n): ";
			cin >> c;
			if (c == 'y')
				rv = rv.Transpose();
			else
				throw 1;
		}
		else
			throw 1;
	}
	for (int i = 0; i < m; i++)
	for (int j = 0; j < n; j++)
		Mat.at(i).at(j) -= rv.Element(i, j);
}

void Matrix::operator*(double rv) {
	for (int i = 0; i < m; i++)
	for (int j = 0; j < n; j++)
		Mat.at(i).at(j) *= rv;
}

void Matrix::Create() {
	for (int k = 0; k < m; k++) {
		Mat.push_back(vector<double>(n));
	}
}

double Matrix::Trace()
{
	if (n != m)
		throw 9;
	double trace = 0;
	for (int i = 0; i < n; i++)
		trace += Mat.at(i).at(i);
	return trace;
}

double Matrix::DetByGauss()
{
	if (n != m)
		throw 10;
	Matrix tmp(1, m);
	double det = 1, mu;
	int sign = 0;
	
	for (int l = 0; l < n; l++){
		for (int k = 0; k < m - 1; k++)
		if (Mat.at(k).at(k) == 0)
		for (int r = 0; r < m; r++)
		if (Mat.at(r).at(k) != 0)
		{
			for (int c = 0; c < n; c++) tmp.Element(0, c) = Mat.at(0).at(c);
			for (int c = 0; c < n; c++) Mat.at(k).at(c) = Mat.at(r).at(c);
			for (int c = 0; c < n; c++) Mat.at(r).at(c) = tmp.Element(0, c);
			sign += abs(r - k);
		}
		for (int i = l + 1; i < n; i++){
			mu = Mat[i][l] / Mat[l][l];
			for (int j = 0; j < n; j++)
				Mat[i][j] -= Mat[l][j] * mu;
		}
	}
	for (int i = 0; i < n; i++)
		det *= Mat.at(i).at(i);
	if (sign % 2 == 0)
		det = -det;
	return det;
}

Matrix Matrix::Transpose()
{
	Matrix res(n, m);

	for (int i = 0; i < n; ++i)
	for (int j = 0; j < m; ++j)
		res.Element(i,j) = Mat[j][i];
	return res;
}

double Matrix::Norm()
{
	if (n != 1 && m != 1)
		throw 12;
	double norm = 0;
	for (int i = 0; i < m; i++)
	for (int j = 0; j < n; j++)
		norm += (abs(Mat[i][j])) * (abs(Mat[i][j]));

	return sqrt(norm);
}

double Matrix::MaxNorm()
{
	if (n != 1 && m != 1)
		throw 12;
	double max = Mat.at(0).at(0);
	for (int i = 0; i < m; i++)
	for (int j = 0; j < n; j++)
	if (abs(Mat[i][j]) > max)
		max = abs(Mat[i][j]);
	return max;
}

double Matrix::MatNorm()
{
	double norm = 0;
	for (int i = 0; i < m; i++)
	for (int j = 0; j < n; j++)
		norm += abs(Mat[i][j]) * abs(Mat[i][j]);
	return sqrt(norm);
}

Matrix Matrix::Vect(Matrix& rv)
{
	if ((n != 1 && m != 1) || (rv.n != 1 && rv.m != 1))
		throw 13;
	Matrix C(m, n);
	C.Mat = Mat;
	if (m != 1) C = C.Transpose();
	if (rv.n != 1) rv = rv.Transpose();
	if (rv.m != n)
		throw 13;
	C.Display(0);
	return rv * C;
}