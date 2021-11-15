#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** T, const int r, const int c) {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			T[i][j] = -50 + rand() * 101 / RAND_MAX;
}

void Print(int** T, const int r, const int c) {
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) {
			cout << setw(4) << T[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int SumMinInRow(int** T, const int r,const int c) {
	int min, s = 0;
	for (int i = 0; i < r; i++) {
		min = T[i][0];
		for (int j = 0; j < c - 1; j++) {
			if (min > T[i][j + 1])
				min = T[i][j + 1];
		}
		s += min;
	}
	return s;
}

int main() {
	srand((unsigned)time(NULL));

	const int r = 3, c = 3;
	int** T = new int* [r];
	for (int i = 0; i < r; i++)
		T[i] = new int[c];

	cout << "Array: " << endl;
	Create(T, r, c);
	Print(T, r, c);
	cout << "Sum = " << SumMinInRow(T, r, c) << endl;

	for (int i = 0; i < r; i++)
		delete[] T[i];
	delete[] T;


	return 0;
}