#include <string>
#include <iostream> 
#include <bitset>
using namespace std;
int main() {
	cout << "1.Babikov Matvey Michaylovich , 221-353 " << endl;

	cout << "2." << endl;
	cout << "min int = " << (int)0b10000000000000000000000000000000 << ", max int = " << (int)0b01111111111111111111111111111111 << ", size of int = " << sizeof(int) << endl;
	cout << "min unsigned int = " << (unsigned int)0 << ", max unsigned int = " << (unsigned int)0b11111111111111111111111111111111 << ", size of unsigned int = " << sizeof(unsigned int) << endl;
	cout << "min short = " << (short)0b1000000000000000 << ", max short = " << (short)0b0111111111111111 << ", size of short = " << sizeof(short) << endl;
	cout << "min unsigned short = " << (unsigned short)0 << ", max unsigned short = " << (unsigned short)0b1111111111111111 << ", size of unsigned short = " << sizeof(unsigned short) << endl;
	cout << "min long = " << (long)0b10000000000000000000000000000000 << ", max long = " << (long)0b01111111111111111111111111111111 << ", size of long = " << sizeof(long) << endl;
	cout << "min long long = " << (long long)0b1000000000000000000000000000000000000000000000000000000000000000 << ", max long long = " << (long long)0b0111111111111111111111111111111111111111111111111111111111111111 << ", size of long long = " << sizeof(long long) << endl;
	cout << "min double = -" << (double)0b1000000000000000000000000000000000000000000000000000000000000000 << ", max double = " << (double)0b0111111111111111111111111111111111111111111111111111111111111111 << ", size of double = " << sizeof(double) << endl;
	cout << "min char = " << (char)0b10000000 << ", max char = " << (char)0b01111111 << ", size of char = " << sizeof(char) << endl;
	cout << "min bool = " << (bool)0 << ", max bool = " << (bool)0b01111111 << ", size of bool = " << sizeof(bool) << endl << endl;


	cout << "3.Enter a number: " << endl; // ¬ведите число: 65 
	int f;
	cin >> f;
	cout << "In binary form " << bitset<numeric_limits<int>::digits>(f) << endl;
	cout << "In hexadecimal form " << hex << f << endl;
	cout << "bool " << (bool)f << endl;
	cout << "double " << (double)f << endl;
	cout << "char " << (char)f << endl;

	cout << "4. a*x=b. Enter a,b value: "; // ¬ведите коэфиценты:  2 4 
	int a, b;
	float x;
	cin >> a;
	cin >> b;
	cout << "a" << "*" << "x" << "=" << "b" << endl;
	cout << a << "*" << "x" << "=" << b << endl;
	cout << "x" << "=" << b << "/" << a << endl;
	x = b / a;
	cout << "x" << "=" << x << endl;
	cout << "Answer:" << x << endl;

	cout << "5.Enter the coordinates of the segment on the straight line:"; // ¬ведите координаты отрезка на пр€мой: 3 7
	int d, c;
	float g;
	cin >> d >> c;
	g = (d + c) / 2;
	cout << "The middle of the segment is at the point with the coordinate " << g << "." << endl;

	return 0;
}