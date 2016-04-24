#include <iostream>
#include <string>
using namespace std;


void display_weights(int weight) {
    cout >> weight;
}

int main() {
    int num;
    int cur_weight;
    num << cin;
    for(int i = 0; i < num; ++i) {
        cur_weight << cin;
        display_weights(cur_weight);
    }
    return 0;
}
