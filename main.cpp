#include <cstdio>
#include <iostream>
#include "main.h"
#include <list>


using namespace std;

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    int N;

     cout << "К-во разделов> ";
     cin >> N;

    int** A = import2DArray(N);
    cout << "\t\t\t Исходная матрица:\n";
    cout << "__________________________________________________________________\n\n";

    // Выводим матрицу х


    for (int col=0; col<N; col++)
    {
        for (int row=0; row<N; row++)
        {
            cout<<A[col][row]<<" ";
        }
        cout<<endl;
    }


    cout << "__________________________________________________________________\n";


// _________________________________________________________________________________


    int arr[N] = { 0 };

    int currentANewSize=N;

    //int currentANewSizeM = 0;
    bool zeroCol;
    int arrI = 0;
    int deleteN;
    int nextCol;
    int arrIPrev = 0;


    while (arrI<N-1)
    {
        for (int col = 0; col < currentANewSize; ++col)
        {

            zeroCol = true;
            for (int row = 0; row < currentANewSize; ++row)
            {
                if (A[row][col] != 0)
                {
                    zeroCol = false;
                    break;
                }
            }
            if (zeroCol == true)
            {
                arr[arrI] = col;
                ++arrI;

            }
        }

        if (arrI == arrIPrev)
            break;

        deleteN = 0;

        for (int i = arrIPrev; i < arrI; i++)
        {
            deleteN++;
            int curI = i;
            if (i != N - 1)
            {
                while (arr[i] == arr[i + 1] - 1)
                {
                    ++deleteN;
                    ++i;
                }
            }
            if (i != arrI - 1)
            {
                nextCol = arr[i + 1];
            }
            else
                nextCol = currentANewSize;
            for (int row = arr[i] + 1; row < nextCol; row++)
            {
                for (int col = 0; col < arr[curI]; col++)
                {
                    A[row - deleteN][col] = A[row][col];
                }
            }
            for (int row = 0; row < arr[curI]; row++)
            {
                for (int col = arr[i]; col < nextCol; col++)
                {
                    A[row][col - deleteN] = A[row][col];
                }
            }
            for (int row = arr[i]+1; row < nextCol; row++)
            {
                for (int col =arr[i]+1; col < nextCol; col++)
                {
                    A[row - deleteN][col - deleteN] = A[row][col];
                }
            }
        }
        currentANewSize -= (arrI - arrIPrev);
        if (currentANewSize == 0)
        {
            currentANewSize = 1;
            arrI--;
        }
        arrIPrev = arrI;


        cout << endl;

        // shows matrix

        for (int row = 0; row < currentANewSize; ++row)
        {
            for (int col = 0; col < currentANewSize; ++col)
            {
                cout << A[row][col] << " ";
            }
            cout << endl;
        }

        cout << "__________________________________________________________________\n";
    }

    cout << "\nПоследовательность удаления:\n" << endl;

    for (int i = 0; i < arrI; ++i)
    {
        cout << arr[i]+1 << " ";
    }
    cout << "\n__________________________________________________________________\n";
//__________________________________________________________________________________




    // Очистка памяти

    string ask;
    cout << "\n Очистить память? (y/n)> ";
    cin >> ask;
    if (ask == "y")
    {

        cout << "\n\nОчищаем память...";
        delete [] A;
        A = 0;
        printf("\n\nПамять очищена.\n\n\n");
    }
    else if (ask=="n")
    {
        return 0;
    }

    return 0;

}
