#include <iostream>
using namespace std;
void Mavel_sort(int* g, int* array, int len, int flag)
{
    int b;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                b = array[j];
                array[j] = array[j + 1];
                array[j + 1] = b;
                b = g[j];
                g[j] = g[j + 1];
                g[j + 1] = b;
            }

            if (flag == 2 && array[j] == array[j + 1])
            {
                if (g[j + 1] > g[j])
                {
                    b = g[j];
                    g[j] = g[j + 1];
                    g[j + 1] = b;
                }
            }
        }
    }
}

void g1(int*& g, int& len)
{
    cout << "Enter len mas: ";
    cin >> len;
    if (g != nullptr)
    {
        delete[] g;
    }

    g = new int[len];
    cout << "Enter mas: ";
    for (int i = 0; i < len; i++) {
        cin >> g[i];
    }

}

void g2(int* g, int len)
{
    cout << "Massive: ";
    for (int i = 0; i < len; i++) {
        cout << g[i] << ' ';
    }
    cout << endl;

}

void sort1(int* g, int len)
{
    int flag = 1;
    int const arr_sum_size = len;
    int array[arr_sum_size];
    for (int i = 0; i < len; i++)
    {
        int x2 = 0;
        int sum = 0;
        int x1 = g[i];
        for (int j = 0; j < len; j++)
        {
            if (j % 2 != 0)
            {
                x2 = x1 % 10;
                sum = sum + x2;
            }
            x1 = x1 / 10;
        }
        array[i] = sum;
    }
    Mavel_sort(g, array, len, flag);
}

void sort2(int* g, int len)
{
    int flag = 2;
    int const arr_sum_size = len;
    int array[arr_sum_size];
    for (int i = 0; i < len; i++)
    {
        int x2 = 0;
        int last = 0;
        int x1 = g[i];
        for (int j = 0; j < len; j++)
        {
            if (j == 0)
            {
                x2 = x1 % 10;
                last = last + x2;
            }
            x1 = x1 / 10;
        }
        array[i] = last;
    }
    Mavel_sort(g, array, len, flag);
}

void exit()
{
    exit(0);
}
int main()
{
    int* g = nullptr;
    int choice = 0;
    int len = 0;
    system("color A");
    while (true)
    {
        std::cout << "Choose a task:\n" << "1) Input\n" << "2) Output\n" << "3) Sort1\n" << "4) Sort2\n" << "5) Exit\n" << endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            g1(g, len);
            break;
        }
        case 2:
        {
            g2(g, len);
            break;
        }
        case 3: {
            sort1(g, len);
            break;
        }
        case 4: {
            sort2(g, len);
            break;
        }
        case 5:
        {
            exit();
            break;
        }
        {
            return 0;
        }
        default: {
            std::cout << "Enter the correct value" << std::endl;
        }
        }
    }
}