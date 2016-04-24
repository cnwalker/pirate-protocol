#include <iostream>
#include <cmath>

using namespace std;

int lowestdiv(int n) {
	int k = n;

	int m = (int) sqrt(k) + 1;
	int factor = 1;
	if (k%2 == 0) {
		factor *= 2;
	}
	if (k%3 == 0) {
		factor *= 3;
	}
	for (int i = 4; i/factor <= m; ++i) {
		if (k%i == 0) {
			if (i%3 == 0 && i/3 > 3) {
				i /= 3;
			}
			if (i%2 == 0 && i/2 > 3) {
				i /= 2;
			}
			return i;
		}
	}
	return k/factor;
}

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		if (n < 7) {
			if (n == 3) {
				cout << 4 << endl;
			} else {
				cout << "No such base" << endl;
			}
		} else {
			cout << lowestdiv(n - 3) << endl;;
		}
	}
}