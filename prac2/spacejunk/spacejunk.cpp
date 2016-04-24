#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	int numTrials;
	cin >> numTrials;

	for (int trial = 0; trial < numTrials; ++trial) {
		int sx, sy, sz, svx, svy, svz, jx, jy, jz, jvx, jvy, jvz, sr, jr;

		cin >> sx >> sy >> sz >> sr >> svx >> svy >> svz;
		cin >> jx >> jy >> jz >> jr >> jvx >> jvy >> jvz;

		int i, j, k, x, y, z, r;
		i = sx - jx;
		j = sy - jy;
		k = sz - jz;
		x = svx - jvx;
		y = svy - jvy;
		z = svz - jvz;
		r = sr + jr;

		int a, b, c;
		a = x*x + y*y + z*z;
		b = -2*(i*x + j*y + k*z);
		c = i*i + j*j + k*k - r*r;

		int thing = b*b - 4*a*c;

//		cout << "i,j,k " << i << ',' << j << ',' << k << endl;
//		cout << "x,y,z " << x << ',' << y << ',' << z << endl;
//		cout << "a,b,c " << a << ',' << b << ',' << c << endl;
//		cout << "r " << r << endl;
		if (thing < 0) {
			cout << "No collision" << endl;
			// == 0? tangent--should this be a collision?
		} else if (a == 0) {
			if (b == 0) {
				cout << "No collision" << endl;
				// distance not a function of time--we assume no collision initially
			} else {
				double t = ((double) c) / b;
				if (t > 0) {
					cout << fixed << setprecision(3) << t << endl;
				} else {
					cout << "No collision" << endl;
				}
			}
		} else {
			double t = (b - sqrt(thing))/(2*a);
			if (t < 0) {
				t = (b + sqrt(thing))/(2*a);
			}
			if (t < 0) {
				cout << "No collision" << endl;
//				cout << "at " << t << endl;
			} else {
				cout << fixed << setprecision(3) << t << endl;
			}
		}

	}
}