#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class Matrix {
protected:
	vector<vector<double> > Mat;
	int m, n;

	void Create();

public:

	Matrix() : m(2), n(2) { Create(); }
	Matrix(int i) : m(i), n(1) { Create(); }
	Matrix(int i, int j) : m(i), n(j) { Create(); }

	~Matrix(){
		Mat.clear();
	}

	Matrix Transpose();
	void operator+(Matrix &rv);
	void operator-(Matrix &rv);
	void operator*(double rv);
	Matrix operator*(Matrix &rv);
	double &Element(int i, int j);
	void Display(int signal);
	Matrix Adamar(Matrix& B);
	double Trace();
	double DetByGauss();
	double Scalar(Matrix& B);
	double Norm();
	double MaxNorm();
	double MatNorm();
	Matrix Vect(Matrix& rv);
};

class Elementary : public Matrix{
public:
	Elementary(int i, int k) : Matrix(i, i){
		if (i != k) throw 8;
		for (int j = 0; j < i; j++) {
			Mat.at(j).at(j) = 1;
		}
	}
};

class Diagonal : public Elementary{
public:
	Diagonal(int i, int k) : Elementary(i, i){ if (i != k) throw 8; }
};

class UpperTriang : public Matrix{
public:
	UpperTriang(int i, int k) : Matrix(i, i){ if (i != k) throw 8; }
};

class DownTriang : public Matrix{
public:
	DownTriang(int i, int k) : Matrix(i, i){ if (i != k) throw 8; }
};

class Simmetric : public Matrix{
public:
	Simmetric(int i, int k) : Matrix(i, i){ if (i != k) throw 8; }
};