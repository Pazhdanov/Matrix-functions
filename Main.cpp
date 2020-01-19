#include "Classes.h"

int main()
{
    int sw1;
    vector <Matrix> Matrixs;
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
    return 0;
}
