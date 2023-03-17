#include <iostream> 
using namespace std;
const int nmax = 1000;
void M1(int Mavelis[], int b, int e)
{
    int i = b,
        t = 0,
        mid = b + (e - b) / 2,
        j = mid + 1,
        d[nmax];

    while (i <= mid && j <= e) {

        if (Mavelis[i] <= Mavelis[j]) {
            d[t] = Mavelis[i]; i++;
        }
        else {
            d[t] = Mavelis[j]; j++;
        }
        t++;
    }
    // проверка
    while (i <= mid) {
        d[t] = Mavelis[i]; i++; t++;
    }
    // проверка
    while (j <= e) {
        d[t] = Mavelis[j]; j++; t++;
    }
    // запись в основной массив
    for (i = 0; i < t; i++)
        Mavelis[b + i] = d[i];
}
// разделение строки на части по формуле "left + (right - left) / 2"
void M2(int* arr, int left, int right)
{
    int  temp = 0;
    if (left < right)
        if (right - left == 1) {
            if (arr[left] > arr[right]) {
                temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
        }
        else {
            M2(arr, left, left + (right - left) / 2);
            M2(arr, left + (right - left) / 2 + 1, right);
            M1(arr, left, right);
        }
}

void Bubble_sort(int* linked_mas, int len)
{
    int b;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (linked_mas[j] > linked_mas[j + 1])
            {
                b = linked_mas[j];
                linked_mas[j] = linked_mas[j + 1];
                linked_mas[j + 1] = b;
            }
        }
    }
}

void Counting_sort(char* linked_mas, int len)
{
    int count[26] = { 0 };
    int j;
    for (int i = 0; i < len; i++)
    {
        j = int(linked_mas[i] - 97);
        count[j]++;
    }
    int i = 0;
    j = 0;
    while (j < 26)
    {
        if (count[j] > 0)
        {
            linked_mas[i] = char(int(97 + j));
            i++;
            count[j]--;
        }
        else
        {
            j++;
        }
    }
}

void int_input(int* mas, int& mas_len)
{
    cout << "Enter len of massive: ";
    cin >> mas_len;
    cout << "Enter massive: ";
    for (int i = 0; i < mas_len; i++)
    {
        cin >> mas[i];
    }
}

void char_input(char* mas, int& mas_len)
{
    cout << "Enter len of massive: ";
    cin >> mas_len;
    cout << "Enter massive: ";
    for (int i = 0; i < mas_len; i++)
    {
        cin >> mas[i];
    }
}

void task1()
{
    int mas[1000];
    int mas_len = 0;
    int_input(mas, mas_len);
    Bubble_sort(mas, mas_len);
    cout << "Sorted massive: ";
    for (int i = 0; i < mas_len; i++)
    {
        cout << mas[i] << " ";
    }
    cout << endl;
}

void task2()
{
    char mas[1000];
    int mas_len = 0;
    char_input(mas, mas_len);
    Counting_sort(mas, mas_len);
    std::cout << "Sorted massive: ";
    for (int i = 0; i < mas_len; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}

void tesk3(int* m, int& n)
{

    cout << "Enter len of massive:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]=";
        cin >> m[i];
    }

    for (int i = 0; i < n; i++)
        cout << m[i] << " ";
    cout << "\n";
}
void print(int* m, int n)
{
    for (int i = 0; i < n; i++)
        cout << m[i] << " ";
    cout << "\n";

}

void task3()
{
    setlocale(LC_ALL, "rus");
    int n, a[nmax];
    tesk3(a, n);
    M2(a, 0, n - 1);
    cout << "Sorted massive:\n";
    print(a, n);
}

int main()
{
    setlocale(LC_ALL, "rus");
    int choice = 0;
    while (true)
    {
        cout << "Choose a task:\n"
            << "1. Sorting bubbles\n"
            << "2. Counting sorting\n"
            << "3. Merge sorting\n"
            << "4. Exit\n"
            << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            task1();
            break;
        }
        case 2:
        {
            task2();
            break;
        }
        case 3:
        {
            task3();
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
}
