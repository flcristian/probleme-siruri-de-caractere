#include <iostream>

using namespace std;

int countDiv(int);
bool estePrim(int);
void rezolvare(int[], int);

int main() {
	int x[5] = { 3,5,6,7,14 };
	int d = 5;
	rezolvare(x,d);
}

int countDiv(int x) {
	int c = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			c++;
		}
	}
	return c;
}

bool estePrim(int x) {
	if (countDiv(x) == 2) {
		return 1;
	}
	return 0;
}

void rezolvare(int x[], int d) {
	for (int i = 0; i < d; i++) {
		if (estePrim(x[i])) {
			cout << x[i] << " ";
		}
	}
}