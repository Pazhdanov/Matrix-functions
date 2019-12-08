#include "Classes.h"

int main()
{
	int sw;
	int signal = 0;
	vector <Matrix> Matrixs;
	do{
		cout << "Choose what you want to do: " << endl;
		cout << "1) Add new Matrix;" << endl;
		cout << "11) Add new Elementary Matrix;" << endl;
		cout << "12) Add new Diagonal Matrix;" << endl;
		cout << "13) Add new Upper Triangle Matrix;" << endl;
		cout << "14) Add new Down Triangle Matrix;" << endl;
		cout << "15) Add new Simmetric Matrix;" << endl;
		cout << "16) Add new Random Matrix;" << endl;
		cout << "2) Delete Matrix;" << endl;
		cout << "3) Print Matrix on display" << endl;
		cout << "41) Summarise;" << endl;
		cout << "42) Subtract;" << endl;
		cout << "43) Multiply by number;" << endl;
		cout << "44) Multiply by Matrix;" << endl;
		cout << "45) Transpose Matrix;" << endl;
		cout << "46) Rank;" << endl;
		cout << "47) Inverted matrix;" << endl;
		cout << "48) Minor;" << endl;
		cout << "51) Adamar;" << endl;
		cout << "52) Matrix trace;" << endl;
		cout << "53) Square Matrix Determinant;" << endl;
		cout << "54) Scalar;" << endl;
		cout << "55) Outer;" << endl;
		cout << "56) Norm;" << endl;
		cout << "57) Max Norm;" << endl;
		cout << "58) Mat norm;" << endl;
		cout << "59) Vectors Angle;" << endl;
		cout << "9) Clear console;" << endl;
		cout << "10) Exit." << endl;
		cin >> sw;
		try {
			switch (sw) {
			case 1: {
						int n, m;
						cout << "Input your Matrix dimention :";
						cin >> n >> m;
						Matrix M(n, m);
						for (int i = 0; i < n; i++) {
							for (int j = 0; j < m; j++) {
								M.Display(signal);
								cin >> M.Element(i, j);
								system("cls");
							}
						}
						Matrixs.push_back(M);

						break;
			}
			case 11: {
						 int n, m;
						 cout << "Input your Matrix dimention :";
						 cin >> n >> m;
						 Elementary M(n, m);

						 Matrixs.push_back(M);

						 break;
			}
			case 12: {
						 int n, m;
						 cout << "Input your Matrix dimention :";
						 cin >> n >> m;
						 Diagonal M(n , m);
						 for (int i = 0; i < n; i++) {
							 M.Display(signal);
							 cin >> M.Element(i, i);
							 system("cls");
						 }
						 Matrixs.push_back(M);

						 break;
			}
			case 13:{
						int n, m;
						cout << "Input your Matrix dimention :";
						cin >> n >> m;
						UpperTriang M(n, m);
						for (int i = n - 1; i > -1; i--) {
							for (int j = 0; j <= i; j++) {
								M.Display(signal);
								cin >> M.Element(i, j);
								system("cls");
							}
						}
						Matrixs.push_back(M);

						break;
			}
			case 14:{
						int n, m;
						cout << "Input your Matrix dimention :";
						cin >> n >> m;
						DownTriang M(n, m);
						for (int i = 0; i < n; i++) {
							for (int j = i; j < n; j++) {
								M.Display(signal);
								cin >> M.Element(i, j);
								system("cls");
							}
						}
						Matrixs.push_back(M);

						break;
			}
			case 15:{
						int n, m;
						cout << "Input your Matrix dimention :";
						cin >> n >> m;
						Simmetric M(n, m);
						for (int i = 0; i < n; i++) {
							for (int j = i; j < n; j++) {
								M.Display(signal);
								cin >> M.Element(i, j);
								M.Element(j, i) = M.Element(i, j);
								system("cls");
							}
						}
						Matrixs.push_back(M);

						break;
			}
			case 16:{
						int n, m;
						cout << "Input your Matrix dimention :";
						cin >> n >> m;
						Matrix M(n, m);
						for (int i = 0; i < n; i++) {
							for (int j = 0; j < m; j++) {
								M.Element(i, j) = rand() % 10 +1;
							}
						}
						Matrixs.push_back(M);
						break;
			}
			case 2: {
						int j;
						for (int i = 0; i < Matrixs.size(); i++) {
							cout << i + 1 << ") ";
							signal = 1;
							Matrixs[i].Display(signal);
						}
						if (Matrixs.size() == 0)
							throw 7;
						cout << "Choose Matrix you want to delete or '0' to go back to menu: " << endl;
						cin >> j;
						if (Matrixs.size() == 1)
							Matrixs.pop_back();
						else {
							if (j == 0)
								break;
							Matrixs.erase(Matrixs.begin() + j - 1);
						}
						signal = 0;
						break;
			}
			case 3: {
						system("cls");
						if (Matrixs.size() == 0)
							throw 7;
						for (int k = 0; k < Matrixs.size(); k++) {
							cout << k + 1 << ") ";
							signal = 1;
							Matrixs.at(k).Display(signal);
						}
						signal = 0;
						break;
			}
			case 41: {
						int a, b;
						for (int i = 0; i < Matrixs.size(); i++) {
							cout << i + 1 << ") ";
							signal = 1;
							Matrixs[i].Display(signal);
						}
						if (Matrixs.size() == 0 || Matrixs.size() == 1)
							throw 7;
						cout << "Choose 2 Matrix you want to summarise: ";
						cin >> a >> b;
						if (a == b)
							throw 1;
						Matrixs.at(a - 1) + Matrixs.at(b - 1);
						signal = 0;
						break;
			}
			case 42: {
						int a, b;
						for (int i = 0; i < Matrixs.size(); i++) {
							cout << i + 1 << ") ";
							signal = 1;
							Matrixs[i].Display(signal);
						}
						if (Matrixs.size() == 0 || Matrixs.size() == 1)
							throw 7;
						cout << "Choose 2 Matrix you want to subtract: ";
						cin >> a >> b;
						if (a == b)
							throw 1;
						Matrixs.at(a - 1) - Matrixs.at(b - 1);
						signal = 0;
						break;
			}
			case 43: {
						int a;
						double b;
						for (int i = 0; i < Matrixs.size(); i++) {
							cout << i + 1 << ") ";
							signal = 1;
							Matrixs[i].Display(signal);
						}
						if (Matrixs.size() == 0)
							throw 7;
						cout << "Choose Matrix you want to multiply and by what (can be double): ";
						cin >> a >> b;
						Matrixs.at(a - 1) * b;
						signal = 0;
						break;
			}
			case 44: {
						int a, b;
						for (int i = 0; i < Matrixs.size(); i++) {
							cout << i + 1 << ") ";
							signal = 1;
							Matrixs[i].Display(signal);
						}
						if (Matrixs.size() == 0 || Matrixs.size() == 1)
							throw 7;
						cout << "Choose 2 Matrix you want to multiply: ";
						cin >> a >> b;
						if (a == b)
							throw 1;
						Matrixs.push_back(Matrixs.at(a - 1) * Matrixs.at(b - 1));
						signal = 0;
						break;
			}
			case 45: {
						 int a;
						 for (int i = 0; i < Matrixs.size(); i++) {
							 cout << i + 1 << ") ";
							 signal = 1;
							 Matrixs[i].Display(signal);
						 }
						 if (Matrixs.size() == 0)
							 throw 7;
						 cout << "Choose 1 Matrix you want to transpose: ";
						 cin >> a;
						 Matrixs.push_back(Matrixs.at(a - 1).Transpose());
						 signal = 0;
						 break;
			}
			case 46: {
						 int a;
						 for (int i = 0; i < Matrixs.size(); i++) {
							 cout << i + 1 << ") ";
							 signal = 1;
							 Matrixs[i].Display(signal);
						 }
						 if (Matrixs.size() == 0)
							 throw 7;
						 cout << "Choose 1 Matrix which rank you want to know: ";
						 cin >> a;
						 cout << "\nRank = " << Matrixs.at(a - 1).Rank() << '\n' << endl;
						 signal = 0;
						 break;
			}
			case 47: {
						 int a;
						 for (int i = 0; i < Matrixs.size(); i++) {
							 cout << i + 1 << ") ";
							 signal = 1;
							 Matrixs[i].Display(signal);
						 }
						 if (Matrixs.size() == 0)
							 throw 7;
						 cout << "Choose 1 Matrix to invert: ";
						 cin >> a;
						 cout << "\nCompleted!\n" << endl;
						 Matrixs.push_back(Matrixs.at(a - 1).InvertMat());
						 signal = 0;
						 break;
			}
			case 48: {
						 int a, i, j;
						 for (int i = 0; i < Matrixs.size(); i++) {
							 cout << i + 1 << ") ";
							 signal = 1;
							 Matrixs[i].Display(signal);
						 }
						 if (Matrixs.size() == 0)
							 throw 7;
						 cout << "Choose 1 Matrix view minor and 2 numbers (row and column): ";
						 cin >> a >> i >> j;
						 cout << Matrixs.at(a - 1).Minor(i-1, j-1) << '\n' << endl;;
						 signal = 0;
						 break;
			}
			case 51: {
						int a, b;
						for (int i = 0; i < Matrixs.size(); i++) {
							cout << i + 1 << ") ";
							signal = 1;
							Matrixs[i].Display(signal);
						}
						if (Matrixs.size() == 0 || Matrixs.size() == 1)
							throw 7;
						cout << "Choose 2 Matrix you want to multiply whit Adamar multiplication: ";
						cin >> a >> b;
						if (a == b)
							throw 1;
						Matrixs.push_back(Matrixs.at(a - 1).Adamar(Matrixs.at(b - 1)));
						signal = 0;
						break;
			}
			case 52:{
						int a;
						for (int i = 0; i < Matrixs.size(); i++) {
							cout << i + 1 << ") ";
							signal = 1;
							Matrixs[i].Display(signal);
						}
						if (Matrixs.size() == 0)
							throw 7;
						cout << "Choose 1 Matrix which trace you want to know: ";
						cin >> a;
						cout << "Choosen Matrix trace : " << Matrixs.at(a - 1).Trace() << endl;
						signal = 0;
						break;
			}
			case 53:{
						int a;
						for (int i = 0; i < Matrixs.size(); i++) {
							cout << i + 1 << ") ";
							signal = 1;
							Matrixs[i].Display(signal);
						}
						if (Matrixs.size() == 0)
							throw 7;
						cout << "Choose 1 Matrix which Determinant you want to know: ";
						cin >> a;
						Matrix Matr = Matrixs[a - 1];
						cout << "\nChoosen Matrix Det : " << Matr.DetByGauss() << '\n' << endl;
						Matr.~Matrix();
						signal = 0;
						break;
			}
			case 54:{
						int a, b;
						for (int i = 0; i < Matrixs.size(); i++) {
							cout << i + 1 << ") ";
							signal = 1;
							Matrixs[i].Display(signal);
						}
						if (Matrixs.size() == 0 || Matrixs.size() == 1)
							throw 7;
						cout << "Choose 2 Vectors you want to scalar multiply: ";
						cin >> a >> b;
						if (a == b)
							throw 1;
						cout << "\nScalar = " << Matrixs.at(a - 1).Scalar(Matrixs.at(b - 1)) << '\n' << endl;
						signal = 0;
						break;
			}
			case 55:{
						int a, b;
						for (int i = 0; i < Matrixs.size(); i++) {
							cout << i + 1 << ") ";
							signal = 1;
							Matrixs[i].Display(signal);
						}
						if (Matrixs.size() == 0 || Matrixs.size() == 1)
							throw 7; 
						cout << "Choose 2 Vectors you want to outer multiply: ";
						cin >> a >> b;
						if (a == b)
							throw 1;
						cout << "\nExternal multiply: " << endl;
						Matrixs.at(a - 1).Vect(Matrixs.at(b - 1)).Display(0);
						signal = 0;
						break;
			}
			case 56:{
						int a;
						for (int i = 0; i < Matrixs.size(); i++) {
							cout << i + 1 << ") ";
							signal = 1;
							Matrixs[i].Display(signal);
						}
						if (Matrixs.size() == 0)
							throw 7;
						cout << "Choose Vector that norm you want to know (Euclidean): ";
						cin >> a;
						cout << "\nNorm = " << Matrixs.at(a - 1).Norm() << '\n' << endl;
							signal = 0;
						break;
			}
			case 57:{
						int a;
						for (int i = 0; i < Matrixs.size(); i++) {
							cout << i + 1 << ") ";
							signal = 1;
							Matrixs[i].Display(signal);
						}
						if (Matrixs.size() == 0)
							throw 7;
						cout << "Choose Vector that norm you want to know (Max): ";
						cin >> a;
						cout << "\nMax norm = " << Matrixs.at(a - 1).MaxNorm() << '\n' << endl;
							signal = 0;
						break;
			}
			case 58:{
						int a;
						for (int i = 0; i < Matrixs.size(); i++) {
							cout << i + 1 << ") ";
							signal = 1;
							Matrixs[i].Display(signal);
						}
						if (Matrixs.size() == 0)
							throw 7;
						cout << "Choose Matrix that norm you want to know: ";
						cin >> a;
						cout << "\nMatrix norm = " << Matrixs.at(a - 1).MatNorm() << '\n' << endl;
						signal = 0;
						break;
			}
			case 59:{
						int a, b;
						for (int i = 0; i < Matrixs.size(); i++) {
							cout << i + 1 << ") ";
							signal = 1;
							Matrixs[i].Display(signal);
						}
						if (Matrixs.size() == 0 || Matrixs.size() == 1)
							throw 7;
						cout << "Choose 2 Vectors which angle you want to know: ";
						cin >> a >> b;
						if (a == b)
							throw 1;
						cout << "\nAngle = " << Matrixs.at(a - 1).VectAngle(Matrixs.at(b - 1)) << '\n' << endl;
						signal = 0;
						break;
			}
			case 9: { system("cls");
						break;
			}
			case 10: {
						return 0;
			}
			}
		}
		catch (int err)
		{
			if (err == 1)
				cout << "\nOperator- : error\n" << endl;
			if (err == 2)
				cout << "\nOperator+ : error\n" << endl;
			if (err == 3)
				cout << "\nOperator* by Matrix : error\n" << endl;
			if (err == 4)
				cout << "\nOperator Adamar : error\n" << endl;
			if (err == 5)
				cout << "\nMatrix Creation : error\n" << endl;
			if (err == 6)
				cout << "\nMatrixs should be with different numbers : error\n" << endl;
			if (err == 7)
				cout << "\nThere are not enough Matrixs\n" << endl;
			if (err == 8)
				cout << "\nCan not be not square : error\n" << endl;
			if (err == 9)
				cout << "\nTrace : error\n" << endl;
			if (err == 10)
				cout << "\nShould be square : error\n" << endl;
			if (err == 11)
				cout << "\nScalar : error\n" << endl;
			if (err == 12)
				cout << "\nNorm : error\n" << endl;
			if (err == 13)
				cout << "\nIs not vector : error\n" << endl;
			if (err == 14)
				cout << "\nDet is 0 : error\n" << endl;
		}

	} while (sw != 10);
}