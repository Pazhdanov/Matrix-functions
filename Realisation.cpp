#include "Classes.h"
#include "Exceptions.h"

Matrix Matrix::Adamar(Matrix& B) {
    if (m != B.m || n != B.n){
        if (B.n == m && B.m == n){
            char c;
            cout << "Your matrixs have dimention error. Do you want to transpose last matrix? (y/n): ";
            cin >> c;
            if (c == 'y')
                B = B.Transpose();
            else
                throw DimentionError("\nSome dimentions error\nCheck it\n");
        }
        else
			throw DimentionError("\nSome dimentions error\nCheck it\n");
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
					throw  DimentionError("\nSome dimentions error\nCheck it\n");
            }
            else
				throw DimentionError("\nSome dimentions error\nCheck it\n");
        }
        double c1 = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                c1 += Mat[i][j] * B.Element(i, j);
        return c1;
    }
	else throw DimentionError("\nSome dimentions error\nCheck it\n");
}

void Matrix::Display(int signal) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (signal && i == 0 && j == 0)
                cout.width(1);
            else
                cout.width(4);
            (round(Mat.at(i).at(j)*1000)/1000 == 0) ? cout << 0 : cout << round(Mat.at(i).at(j)*1000)/1000;
        }
        cout << endl;
    }
}

double &Matrix::Element(int i, int j) {
    if (i >= m || j >= n)
        throw NoElement("\nThere is no element with number: ", i, j);
    return Mat[i][j];
}

void Matrix::operator>>(ofstream &fileTxt)
{
    fileTxt << '\n' << m << ' ' << n << '\n';
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fileTxt << Mat[i][j] << ' ';
        }
        fileTxt << '\n';
    }
}

Matrix Matrix::operator<<(ifstream &fileTxt)
{
    int col, row;
    fileTxt >> col >> row;
    Matrix Temp(col, row);
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            fileTxt >> Temp.Element(i, j);
        }
    }
    return Temp;
}

void Matrix::WriteBin(FILE *fileBin)
{
    fwrite(&m, sizeof(int), 1, fileBin);
    fwrite(&n, sizeof(int), 1, fileBin);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            fwrite(&Mat.at(i).at(j), sizeof(double), 1, fileBin);
}

Matrix Matrix::ReadBin(FILE *fileBin)
{
    int col, row;
    fread(&col, sizeof(int), 1, fileBin);
    fread(&row, sizeof(int), 1, fileBin);
    Matrix Temp(col, row);
    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
            fread(&Temp.Element(i, j), sizeof(double), 1, fileBin);
    return Temp;
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
				throw DimentionError("\nSome dimentions error\nCheck it\n");
        }
        else
			throw DimentionError("\nSome dimentions error\nCheck it\n");
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
				throw DimentionError("\nSome dimentions error\nCheck it\n");
        }
        else
			throw DimentionError("\nSome dimentions error\nCheck it\n");
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
				throw DimentionError("\nSome dimentions error\nCheck it\n");
        }
        else
			throw DimentionError("\nSome dimentions error\nCheck it\n");
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
		throw DimentionError("\nSome dimentions error\nMatrix should be square\n");
    double trace = 0;
    for (int i = 0; i < n; i++)
        trace += Mat.at(i).at(i);
    return trace;
}

int Matrix::Rank()
{
    int signal = 0, nim = 0;
    Matrix tmp(m, n);
    tmp.Mat = Mat;
    tmp = tmp.ElemChange(0);
    for (int k = 0; k < m; k++)
        if (tmp.Mat[k][0] == 0){
            for (int c = 0; c < n; c++){
                if (tmp.Mat[k][c] == 0)
                    signal++;
            }
            if (signal == n){
                nim++;
            }
            signal = 0;
        }
    return tmp.m - nim;
}

Matrix Matrix::ElemChange(int num)
{
    Matrix tmp(1, m), M(m, n);
    double mu;
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
                        l++;
                    }
        for (int i = l + 1; i < n; i++){
            mu = Mat[i][l] / Mat[l][l];
            for (int j = 0; j < n; j++){
                Mat[i][j] -= Mat[l][j] * mu;
                //Display(0);
                //cout << '\n';
            }
        }
    }
    double numu;
    int signal = 0;
    for (int l = 0; l < n; l++){
        numu = Mat[l][0];
        for (int k = 0; k < n; k++)
            if (Mat[k][0] == numu && k != l){
                for (int c = 0; c < m; c++)
                    if (Mat[k][c] == Mat[l][c])
                        signal++;
                if (signal == m)
                    for (int c1 = 0; c1 < m; c1++)
                        Mat[k][c1] = 0;
                signal = 0;
            }
    }
    if (sign % 2 == 1 && num == 1)
        Mat[0][0] = -Mat[0][0];
    M.Mat = Mat;
    //M.Display(0);
    return M;
}

double Matrix::DetByGauss()
{
    if (n != m)
		throw DimentionError("\nSome dimentions error\nMatrix should be square\n");
    Matrix tmp(n, m);
    tmp.Mat = Mat;
    double det = 1;

    tmp = tmp.ElemChange(1);

    for (int i = 0; i < n; i++)
        det *= tmp.Mat.at(i).at(i);

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
		throw DimentionError("\nSome dimentions error\nIt is not vector\n");
    double norm = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            norm += (abs(Mat[i][j])) * (abs(Mat[i][j]));

    return sqrt(norm);
}

double Matrix::MaxNorm()
{
	if (n != 1 && m != 1)
		throw DimentionError("\nSome dimentions error\nIt is not vector\n");
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
		throw DimentionError("\nSome dimentions error\nOne or both are not vectors\n");
    Matrix C(m, n);
    C.Mat = Mat;
    if (m != 1) C = C.Transpose();
    if (rv.n != 1) rv = rv.Transpose();
    if (rv.m != n)
		throw DimentionError("\nSome dimentions error\nCheck it\n");
    //C.Display(0);
    return rv * C;
}

Matrix Matrix::Cross(Matrix &rv)
{
    if ((n != 1 && m != 1) || (rv.n != 1 && rv.m != 1))
		throw DimentionError("\nSome dimentions error\nOne or both are not vectors\n");
    if (m != 1) Transpose();
    if (rv.m != 1) rv = rv.Transpose();
    if (rv.n != 3 || n != 3)
		throw DimentionError("\nSome dimentions error\nOne or both are not with 3 columns\n");
    Matrix C (1,3);
    C.Mat[0][0] = (Mat[0][1] * rv.Mat[0][2]) - (rv.Mat[0][1] * Mat[0][2]);
    C.Mat[0][1] = -(Mat[0][0] * rv.Mat[0][2]) + (rv.Mat[0][0] * Mat[0][2]);
    C.Mat[0][2] = (Mat[0][0] * rv.Mat[0][1]) - (rv.Mat[0][0] * Mat[0][1]);
    
    return C;
}

double Matrix::VectLarge()
{
    if (n != 1 && m != 1)
		throw DimentionError("\nSome dimentions error\nIt is not vector\n");
    Matrix C(m, n);
    double sum = 0;
    C.Mat = Mat;
    if (m != 1) C = C.Transpose();
    for (int i = 0; i < m; i++)
        sum += C.Element(0, i) * C.Element(0, i);
    return sqrt(sum);
}

double Matrix::VectAngle(Matrix& rv)
{
	if ((n != 1 && m != 1) || (rv.n != 1 && rv.m != 1))
		throw DimentionError("\nSome dimentions error\nOne or both are not vectors\n");
    cout << Scalar(rv) / (VectLarge() * rv.VectLarge()) << endl;
    return acos(Scalar(rv) / (VectLarge() * rv.VectLarge())) * 180.0 / 3.14159265;
}

Matrix Matrix::Minor(int n1, int n2)
{
    Matrix tmp(n, m);
    tmp.Mat = Mat;
    tmp.Mat.erase(tmp.Mat.begin()+n1);
    for (int i = 0; i < n - 1; i++)
        tmp.Mat.at(i).erase(tmp.Mat.at(i).begin() + n2);
    Matrix tmp1(n - 1, m - 1);
    tmp1.Mat = tmp.Mat;
    return tmp1;
}

Matrix Matrix::InvertMat()
{
    double det;
    Matrix tmp(n, m);
	if (m != n)
		throw DimentionError("\nSome dimentions error\nMatrix should be square\n");
    if (DetByGauss())
    {
        det = DetByGauss();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++){
                tmp.Element(i, j) = pow(-1, i + j) * Minor(i, j).DetByGauss();
            }

        tmp = tmp.Transpose();
        tmp * (1 / det);
        tmp.Display(0);
        return tmp;
    }
    else throw DetEqualsZero("\nDeterminant should not be equal to zero\n");
}

void Matrix::DisplayDet(int i, int j)
{
	if (m != n)
		throw DimentionError("\nSome dimentions error\nMatrix should be square\n");
    int k = 0;
    for(int l = 0; l < Minor(i,j).m; l++) {
        cout << '|';
        for(int h = 0; h < Minor(i,j).n; h++)
            (h == 0) ? cout << setw(1) << Minor(i,j).Element(l,h) : cout << setw(4) << Minor(i,j).Element(l,h);
        cout << '|';
        if (l == (Minor(i,j).m)/2 && k == 0) {
            cout << " = " << setw(2) << Minor(i,j).DetByGauss() << endl;
            k++;
        }
        else cout << endl;
    }
}

