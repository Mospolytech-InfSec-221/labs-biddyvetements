#include <iostream> 
#include <cstring>
#include <stdio.h>

using namespace std;
//1
bool Pc(char* str)
{
    int len = strlen(str);
    int j = 0;
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        if (str[i] == ' ')
        {
            i++;
        }
        if (str[j] == ' ')
        {
            j--;
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - 'A' + 'a';
        }
        if (str[j] >= 'A' && str[j] <= 'Z')
        {
            str[j] = str[j] - 'A' + 'a';
        }
        if (str[i] != str[j])
        {
            return 0;
        }
    }
    return 1;
}

//2
int f1(const char* str_for_search_in, const char* substring, int start_position)
{
    int len = strlen(substring);
    int s = 0;
    for (int i = start_position; i < start_position + len; i++, s++)
    {
        if (str_for_search_in[i] != substring[s])
        {
            return 1;
        }

    }
    return start_position;
}


void f2(const char* str_for_search_in, const char* substring)
{
    int len = strlen(str_for_search_in);
    for (int i = 0; i <= len - 1; i++)
    {
        if (f1(str_for_search_in, substring, i) != 1)
        {
            cout << f1(str_for_search_in, substring, i) << " ";
        }
    }
    cout << endl;
}

//3
void en(char* str_for_encrypt, int key)
{
    int len = strlen(str_for_encrypt);
    for (int i = 0; i < len; i++)
    {
        if (str_for_encrypt[i] != ' ')
        {
            if (str_for_encrypt[i] >= 'A' && str_for_encrypt[i] <= 'Z' || str_for_encrypt[i] >= 'a' && str_for_encrypt[i] <= 'z')
            {
                str_for_encrypt[i] = char(str_for_encrypt[i] + key);
                if (str_for_encrypt[i] > 'Z' && str_for_encrypt[i] < 'a')
                {
                    str_for_encrypt[i] = 'A' - 1 + key;
                }
                if (str_for_encrypt[i] > 'z')
                {
                    str_for_encrypt[i] = 'a' - 1 + key;
                }
            }
        }
        else
        {
            str_for_encrypt[i] == ' ';
        }
    }
    for (int j = 0; j < len; j++)
    {
        cout << str_for_encrypt[j];
    }
    cout << endl;
}

//4
void k(const char* str)
{
    bool flag = 0;
    int len, zahod = 1;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == char(34))
        {
            if (flag == 0)
            {
                flag = 1;
                len = 0;
                int j = i + 1;
                while (str[j] != char(34))
                {
                    cout << str[j];
                    j++;
                    len++;
                }
            }
            else
            {
                flag = 0;
            }
            cout << endl;
        }
    }
}

void P()
{
    setlocale(LC_ALL, "rus");
    char str[255];
    cout << "Введите строку: ";
    cin.ignore();
    cin.getline(str, 255);
    if (Pc(str))
    {
        cout << "Палиндром" << endl;
    }
    else
    {
        cout << "Не палиндром" << endl;
    }
}

void S()
{
    setlocale(LC_ALL, "rus");
    char str[255];
    cout << "Введите строку: ";
    cin.ignore();
    cin.getline(str, 255);
    char substring[255];
    cout << "Введите подстроку: ";
    cin.getline(substring, 255);
    f2(str, substring);
}

void C()
{
    setlocale(LC_ALL, "rus");
    char str[255];
    cout << "Введите строку: ";
    cin.ignore();
    cin.getline(str, 255);
    int key = 0;
    cout << "Клавиша ввода: ";
    cin >> key;
    en(str, key);
}

void T()
{
    setlocale(LC_ALL, "rus");
    char str[255];
    cout << "Введите строку: ";
    cin.ignore();
    cin.getline(str, 255);
    k(str);
}

int main()
{
    setlocale(LC_ALL, "rus");
    int choice = 0;
    while (true)
    {
        cout << "-------------------------------------------\n"
            << "Выберите задачу:\n"
            << "1. Палиндром\n"
            << "2. Поиск подстроки в строке\n"
            << "3. Шифр Цезаря\n"
            << "4. Текст\n"
            << "5. Выход\n"
            << "-------------------------------------------" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            P();
            break;
        }
        case 2:
        {
            S();
            break;
        }
        case 3:
        {
            C();
            break;
        }
        case 4:
        {
            T();
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
}
