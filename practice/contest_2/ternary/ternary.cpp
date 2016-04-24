#include <iostream>
#include <string>
#include <vector>
using namespace std;


void display_weights(int weight) {
    int factor = 1;
    vector<int> left (0);
    vector<int> right (0);

    while (weight != 0) {
        int m = weight % 3;
        if (m == 2) {
            m = -1;
        }
        weight -= m;
        if (m == -1) {
            left.push_back(factor);
        } else if (m == 1) {
            right.push_back(factor);
        }
        factor *= 3;
        weight /= 3;
    }

    cout << "left pan:";
    for (int i = left.size() - 1; i >= 0; --i) {
        cout << " " << left[i];
    }
    cout << endl << "right pan:";
    for (int i = right.size() - 1; i >= 0; --i) {
        cout << " " << right[i];
    }
    cout << endl;
}

int main() {
    int num;
    int cur_weight;
    cin >> num;
    for(int i = 0; i < num; ++i) {
        cin >> cur_weight;
        display_weights(cur_weight);
        if (i < num - 1) {
            cout << endl;
        }
    }
    return 0;
}
