#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, num_cit;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num_cit;
		vector<string> unique;
		for (int j = 0; j < num_cit; ++j) {
			string s;
			cin >> s;
			bool unq = true;
			for (int i = 0; i < unique.size(); ++i) {
				if (s == unique[i]) {
					unq = false;
				}
			}
			if (unq) {
				unique.push_back(s);
			}
		}
		cout << unique.size() << endl;	
	}
}
