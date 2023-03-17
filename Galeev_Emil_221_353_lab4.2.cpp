#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

//1
string file_format(const string file_path_full)
{
    string pos;
    int dot;
    string format;
    dot = file_path_full.rfind('.');
    pos = pos.assign(file_path_full, dot);
    format = format.assign(pos, 1);
    //cout << "Format file: ";
    return format;
}

//2
string file_name(const string file_path_full)
{
    string name;
    string flag = "/";
    string pos = file_path_full;
    int flag1;
    int end;
    flag1 = pos.find_last_of(flag);
    name = name.assign(pos,flag1);
    name = name.assign(name, 1);
    end = name.find('.');
    name = name.erase(end);
    //cout << "Name file: ";
    return name;
}

//3
string file_path(const string file_path_full)
{
    string path;
    string flag = "/";
    string pos = file_path_full;
    int end;
    end = pos.find_last_of(flag);
    path = pos.erase(end);
    //cout << "Path file: ";
    return path;
}

//4
char file_disk(const string file_path_full)
{
    char disk[255];
    disk[0] = file_path_full[0];
    //cout << "Disk name: ";
    return disk[0];
}

//5
bool file_rename(string& file_path_full)
{
    string new_name;
    cout << "Enter new name file: ";
    cin >> new_name;
    string name;
    string flag = "/";
    string pos = file_path_full;
    int flag1;
    int end;
    flag1 = pos.find_last_of(flag);
    name = name.assign(pos, flag1);
    name = name.assign(name, 1);
    int dot;
    dot = file_path_full.rfind('.');
    string format;
    format = format.assign(file_path_full, dot);
    new_name = new_name.append(format);
    int size = name.size();
    file_path_full = file_path_full.replace(flag1+1, size, new_name);
    return 1;
}

//6
bool file_copy(const string file_path_full)
{
    ifstream fin;
    ofstream fout;
    string e = "";
    string new_path = file_path(file_path_full) + "/" + file_name(file_path_full) + "_copy." + file_format(file_path_full);
    //cout << new_path << endl;
    fin.open(file_path_full);
    if (!fin.is_open())
    {
        return false;
    }
    fout.open(new_path);
    if (!fout.is_open())
    {
        return false;
    }
    while (!fin.eof())
    {
        fin >> e;
        fout << e;
        fout << "\n";
    }
    fin.close();
    fout.close();
    return true;
}   

int main()
{
    //string file = "D:/VUS/lab.txt";
    string file;
    cout << "Enter Path: ";
    cin >> file;
    int choice = 0;
    while (true)
    {
        cout << "-------------------------------------------\n"
            << "Choose a task:\n"
            << "1. File format\n"
            << "2. File name\n"
            << "3. File path\n"
            << "4. Disk name\n"
            << "5. File rename\n"
            << "6. File copy\n"
            << "7. Exit\n"
            << "-------------------------------------------" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << file_format(file) << endl;
            break;
        }
        case 2:
        {
            cout << file_name(file) << endl;
            break;
        }
        case 3:
        {
            cout << file_path(file) << endl;
            break;
        }
        case 4:
        {
            cout << file_disk(file) << endl;
            break;
        }
        case 5:
        {
            if (file_rename(file))
            {
                cout << "Rename successful" << endl;;
            }
            else
            {
                cout << "Error" << endl;
            }
            break;
        }
        case 6:
        {
            if (file_copy(file))
            {
                cout << "Copy successful" << endl;;
            }
            else
            {
                cout << "Error" << endl;
            }
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
}