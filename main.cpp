#include "Classes.h"

int main()
{
    int sw1;
    vector <Matrix> Matrixs;

    try{
        do{
            cout << "1) Create new txt file" << endl;
            cout << "2) Create new bin file" << endl;
            cout << "3) Use txt file" << endl;
            cout << "4) Use bin file" << endl;
            cout << "0) Exit" << endl;
            cin >> sw1;
            switch (sw1)
            {
                case 1:
                    menuToDo(Matrixs, "file.txt", sw1);
                    break;
                case 2:
                    menuToDo(Matrixs, "file.bin", sw1);
                    break;
                case 3:
                    menuToDo(Matrixs, "file.txt", sw1);
                    break;
                case 4:
                    menuToDo(Matrixs, "file.bin", sw1);
                    break;
                case 0: return 0;
            }

        } while (sw1 != 0);
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
        if (err == 15)
            cout << "\nSuch file does not exist\nCreate it first\n" << endl;
    }
    return 0;
}
