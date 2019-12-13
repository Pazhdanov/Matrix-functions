#include "Classes.h"
//#include "Realisation.cpp"

int main()
{
    int sw;
    int signal = 0;
    vector <Matrix> Matrixs;
    do{
        cout << "Choose what you want to do: " << endl;
        cout << "1) Add new Matrix;" << endl;
        cout << "2) Add new Elementary Matrix;" << endl;
        cout << "3) Add new Diagonal Matrix;" << endl;
        cout << "4) Add new Upper Triangle Matrix;" << endl;
        cout << "5) Add new Down Triangle Matrix;" << endl;
        cout << "6) Add new Simmetric Matrix;" << endl;
        cout << "7) Add new Random Matrix;" << endl;
        cout << "8) Delete Matrix;" << endl;
        cout << "9) Print Matrix on display" << endl;
        cout << "10) Summarise;" << endl;
        cout << "11) Subtract;" << endl;
        cout << "12) Multiply by number;" << endl;
        cout << "13) Multiply by Matrix;" << endl;
        cout << "14) Transpose Matrix;" << endl;
        cout << "15) Rank;" << endl;
        cout << "16) Inverted matrix;" << endl;
        cout << "17) Minor;" << endl;
        cout << "18) Adamar;" << endl;
        cout << "19) Matrix trace;" << endl;
        cout << "20) Square Matrix Determinant;" << endl;
        cout << "21) Scalar;" << endl;
        cout << "22) Outer;" << endl;
        cout << "23) Norm;" << endl;
        cout << "24) Max Norm;" << endl;
        cout << "25) Mat norm;" << endl;
        cout << "26) Vectors Angle;" << endl;
        cout << "27) Clear console;" << endl;
        cout << "0) Exit." << endl;
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
                            //system("cls");
                        }
                    }
                    Matrixs.push_back(M);

                    break;
                }
                case 2: {
                    int n, m;
                    cout << "Input your Matrix dimention :";
                    cin >> n >> m;
                    Elementary M(n, m);

                    Matrixs.push_back(M);

                    break;
                }
                case 3: {
                    int n, m;
                    cout << "Input your Matrix dimention :";
                    cin >> n >> m;
                    Diagonal M(n , m);
                    for (int i = 0; i < n; i++) {
                        M.Display(signal);
                        cin >> M.Element(i, i);
                        //system("cls");
                    }
                    Matrixs.push_back(M);

                    break;
                }
                case 4:{
                    int n, m;
                    cout << "Input your Matrix dimention :";
                    cin >> n >> m;
                    UpperTriang M(n, m);
                    for (int i = n - 1; i > -1; i--) {
                        for (int j = 0; j <= i; j++) {
                            M.Display(signal);
                            cin >> M.Element(i, j);
                            //system("cls");
                        }
                    }
                    Matrixs.push_back(M);

                    break;
                }
                case 5:{
                    int n, m;
                    cout << "Input your Matrix dimention :";
                    cin >> n >> m;
                    DownTriang M(n, m);
                    for (int i = 0; i < n; i++) {
                        for (int j = i; j < n; j++) {
                            M.Display(signal);
                            cin >> M.Element(i, j);
                            //system("cls");
                        }
                    }
                    Matrixs.push_back(M);

                    break;
                }
                case 6:{
                    int n, m;
                    cout << "Input your Matrix dimention :";
                    cin >> n >> m;
                    Simmetric M(n, m);
                    for (int i = 0; i < n; i++) {
                        for (int j = i; j < n; j++) {
                            M.Display(signal);
                            cin >> M.Element(i, j);
                            M.Element(j, i) = M.Element(i, j);
                            //system("cls");
                        }
                    }
                    Matrixs.push_back(M);

                    break;
                }
                case 7:{
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
                case 8: {
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
                case 9: {
                    //system("cls");
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
                case 10: {
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
					if (abs(a) >= Matrixs.size() || abs(b) >= Matrixs.size())
						throw 14;
                    Matrixs.at(a - 1) + Matrixs.at(b - 1);
                    signal = 0;
                    break;
                }
                case 11: {
                    int a, b, c;
                    for (int i = 0; i < Matrixs.size(); i++) {
                        cout << i + 1 << ") ";
                        signal = 1;
                        Matrixs[i].Display(signal);
                    }
					
                    cout << "Choose 2 Matrix you want to subtract: ";
                    cin >> a >> b;
                    if (a == b)
                        throw 1;
					for (int i = 0; i < Matrixs.size(); i++)
					if (a != i || b != i)
                    Matrixs.at(a - 1) - Matrixs.at(b - 1);
                    signal = 0;
                    break;
                }
                case 12: {
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
                case 13: {
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
                case 14: {
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
                case 15: {
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
                case 16: {
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
                case 17: {
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
                    cout << '\n' << endl;
                    Matrixs.at(a-1).DisplayDet(i - 1, j - 1);
                    cout << '\n' << endl;
                    signal = 0;
                    break;
                }
                case 18: {
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
                case 19:{
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
                case 20:{
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
                    //Matrix Matr = Matrixs[a - 1];
                    cout << "\nChoosen Matrix Det : " << Matrixs[a - 1].DetByGauss() << '\n' << endl;
                    //Matr.~Matrix();
                    signal = 0;
                    break;
                }
                case 21:{
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
                case 22:{
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
                case 23:{
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
                case 24:{
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
                case 25:{
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
                case 26:{
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
                case 27: { system("cls");
                    break;
                }
                case 28: {
                    return 0;
                }
                default: return 0;
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

    } while (sw != 0);
}