#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

int** import2DArray(unsigned n)
{


    setlocale(LC_ALL, "RUSSIAN");

    ifstream in("input.txt");
        int** x = 0;
        x = new int*[n];
    if (in.is_open())
    {

        int count = 0;// число чисел в файле
        int temp;//Временная переменная

        while (!in.eof())
        {
            in >> temp;
            count++;
        }

        in.seekg(0, ios::beg);
        in.clear();

        int count_space = 0;
        char symbol;
        while (!in.eof())
        {

            in.get(symbol);
            if (symbol == ' ') count_space++;
            if (symbol == '\n') break;
        }

        in.seekg(0, ios::beg);
        in.clear();

        int n = count / (count_space + 1);
        int m = count_space + 1;

        for (int i = 0; i<n; i++)
            x[i] = new int[n];


        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                in >> x[i][j];
        in.close();
    }
    else
    {
        cout << "Файл не найден.";
    }


    return x;

}
