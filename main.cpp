#include <iostream>
#include <fstream>
#include <queue>

class DataHandler {
public:
    DataHandler(); // конструктор
    ~DataHandler(); // деструктор
    void readFromFile(const std::string& filename); // считать данные из файла
    void readFromConsole(); // считать данные из консоли
    void writeToFile(const std::string& filename); // записать данные в файл
    void writeToConsole(); // вывести данные в консоль
    void sortAscending(); // отсортировать данные по возрастанию
    void sortDescending(); // отсортировать данные по убыванию

private:
    std::queue<int> numbers;
    void sort();
};

DataHandler::DataHandler() {}

DataHandler::~DataHandler() {}

void DataHandler::readFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    int number;
    while (inputFile >> number) {
        numbers.push(number);
    }
    inputFile.close();
}

void DataHandler::readFromConsole() {
    int number;
    while (std::cin >> number) {
        numbers.push(number);
    }
}

void DataHandler::writeToFile(const std::string& filename) {
    std::ofstream outputFile(filename);
    while (!numbers.empty()) {
        outputFile << numbers.front() << " ";
        numbers.pop();
    }
    outputFile.close();
}

void DataHandler::writeToConsole() {
    while (!numbers.empty()) {
        std::cout << numbers.front() << " ";
        numbers.pop();
    }
    std::cout << std::endl;
}

void DataHandler::sortAscending() {
    sort();
}

void DataHandler::sortDescending() {
    sort();

    std::deque<int> reversedNumbers;
    while (!numbers.empty()) {
        reversedNumbers.push_back(numbers.front());
        numbers.pop();
    }
    while ( !reversedNumbers.empty()) {
        numbers.push(reversedNumbers.back());
        reversedNumbers.pop_back();
    }
}

void DataHandler::sort() {
    for (int byteIndex = 0; byteIndex < 4; ++byteIndex) {
        std::vector<std::queue<int>> queues(256);

        while (!numbers.empty()) {
            int current = numbers.front();
            numbers.pop();
            int key = current >> (byteIndex * 8) & 0xFF;
            queues[key].push(current);
        }

        for (int i = 0; i < 256; ++i) {
            while (!queues[i].empty()) {
                numbers.push(queues[i].front());
                queues[i].pop();
            }
        }
    }
}



int main() {
    DataHandler dh;

    dh.readFromConsole();

    dh.sortDescending();

    dh.writeToConsole();

    return 0;
}
