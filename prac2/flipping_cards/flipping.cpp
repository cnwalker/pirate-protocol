#include <iostream>
#include <vector>

using namespace std;

int main() {
	int numTrials;
	cin >> numTrials;
	for (int i = 0; i < numTrials; ++i) {
		bool cont = true;
		int numCards;
		cin >> numCards;
		vector< vector<int> > hand (2*numCards + 1);
		for (int p = 0; p < hand.size(); ++p) {
			hand[p] = vector<int> (0);
//			cout << hand[p].size() << endl;
		}
//		cout << hand.size() << endl;
		for (int j = 0; j < numCards; ++j) {
			int p, q;
			cin >> p >> q;
			for (int k = 0; k < hand[p].size() && cont; ++k) {
//				cout << "p, q, k: " << p << q << k << endl;
//				cout << hand[p].size() << endl;
				if (hand[p][k] == q) {
					cont = false;
				}
//				cout << "b" << endl;
			}
			if (cont) {
				hand[p].push_back(q);
			}
		}
		if (cont) {
			cout << "possible" << endl;
		} else {
			cout << "impossible" << endl;
		}
	}
}