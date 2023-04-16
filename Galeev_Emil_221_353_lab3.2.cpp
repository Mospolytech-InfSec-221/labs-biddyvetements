#include <iostream>
using namespace std;


void input(int*& mass, int* size)
{
    cout<<"Enter massive size\n";
    cin>>*size;
    mass = new int[*size];
    for (int i = 0; i < *size; i++)
    {
        cin >> mass[i];
    }
}

void output(int*& mass, int* size)
{
    if (*size != 0)
    {
        for (int i = 0; i < *size; i++)
        {
            cout << mass[i] <<" ";
        }
        cout << endl;
    }
    else
    {
        cout << "Error with massive occured" << endl;
    }
}

int sorting(int num)
{
    int summ = 0;

    while (num > 0)
    {
        summ += num % 100 / 10;
        num /= 100;
    }

    return summ;
}

void sorting2(int* mass, int* size)
{
    bool checkSort = true;
    while (checkSort)
    {
        checkSort = false;
        for (int i = 0; i < *size - 1; i++)
        {
            if (sorting(mass[i])>sorting(mass[i+1])||((sorting(mass[i])==sorting(mass[i+1]))&&(mass[i]>mass[i+1])))
            {
                int temp = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = temp;
                checkSort = true;
            }
        }
    }
}

void sort1(int*& mass, int* size)
{
    if (*size != 0)
    {
        sorting2(mass, size);
        output(mass, size);
    }
    else {
        cout << "Error with massive occured" << endl;
    }
    delete [] mass;
}

void sort2(int* mass, int* size)
{
    int temp;
    for (int i = 0; i < *size; i++)
        for (int j = 0; j < *size - i - 1; j++)
            if (mass[j]%10 > mass[j + 1]%10)
            {
                temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = temp;
            }

    for (int i = 0; i < *size; i++)
    {
        cout << mass[i] << " ";
    }
}

int main()
{

    setlocale(LC_ALL, "Eng");
    int* mass;
    int size=0;

    int choice =0; // user variable choice

    while (true) // endless cycle

    {
        cout << "What number task you wanna do? \n"
             <<"1. Task 1\n"
             <<"2. Task 2\n"
             <<"3. Task 3\n"
             <<"4. Task 4\n"
             <<"5. Exit\n";

        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                /*Call function for exercise 1*/;
                input(mass, &size);
                break;
            }

            case 2:
            {
                /*Call function for exercise 2*/;
                output(mass, &size);
                break;
            }

            case 3:
            {
                /*Call function for exercise 3*/;
                sort1(mass, &size);
                break;
            }

            case 4:
            {
                /*Call function for exercise 4*/;
                sort2(mass, &size);
                break;
            }
            default:
            {
                return 0;
            }
        }
    }
}
