#include <iostream>
#include <queue>

using namespace std;

int divCheck(int a) {
    while (a % 2 == 0) {
        a /= 2;
    }
    while (a % 3 == 0) {
        a /= 3;
    }
    while (a % 5 == 0) {
        a /= 5;
    }
    return a;
}

int main() {
    queue<int> que;
    int n;
    int num = 2;
    int count = 0;

    cout << "N: " << endl;
    cin >> n;
    while (count < n) {
        if (divCheck(num) == 1) {
            que.push(num);
            count++;
        }
        num++;
    }

    for (int i = 0; i < n; i++) {
        cout << que.front() << " ";
        que.pop();
    }
}