#include <iostream> 
using namespace std;
void task1() {
    setlocale(LC_ALL, "rus");
    int n, j;
    cout << "Введите номер : ";
    cin >> n;
    for (int i = 0; i <= n; i++) {

        j = 0;
        while (j <= i) {
            cout << j;
            j++;
        }
        cout << endl;
    }
}
void task2() {
    int b, c;
    std::cout << "Введите номер : ";
    cin >> b;
    c = b;
    for (int k = 1; k <= b; k++)
    {
        std::cout << k << ' ' << c << endl;
        c *= (b - k);
        c /= (k + 1);
    }
}
void task3() {
    bool flag = true;
    double num, sum = 0.0, count = 0.0;
    cout << "Введите число или 0 для выхода: " << endl;
    while (flag) {
        cin >> num;
        if (num == 0) {
            cout << "Ответ:" << endl;
            cout << sum / count << endl;
            flag = false;
        }
        sum += num;
        count++;
    }

}
int main()
{
    int choice = 0;
    setlocale(LC_ALL, "rus");
    while (true)
    {
        cout << "/////////////////////////////////////////\n" << "Задачи: \n" << "1. Задача 1\n" << "2. Задача 2\n" << "3. Задача 3\n" << "4. Выход\n" << endl;
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