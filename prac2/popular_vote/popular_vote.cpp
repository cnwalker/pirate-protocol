#include <iostream>
#include <string>


using namespace std;

void run_election() {
	int num_candidates;
	int cur_biggest = 0;
	int biggest_index = 0;
	int temp = 0; 
	float sum  =  0;
	bool is_winner = false;

	string win_type;
	
	cin >> num_candidates;

	for(int i = 0; i < num_candidates; i++) {
		cin >> temp;
		sum += temp;
		if(temp > cur_biggest) {
			cur_biggest = temp;
			biggest_index = i;
			is_winner = true;
		} else if(temp == cur_biggest) {
			is_winner = false;
		}
	}

	if (!is_winner) {
		cout << "no winner" << endl;
	} else {
		if (cur_biggest * 2 > sum) {
			win_type = "majority";
		} else {
			win_type = "minority";
		}
		cout << win_type << " winner " << biggest_index + 1 << endl;
	}
}

int main() {
	int test_cases;
	cin >> test_cases;
	for(int i = 0; i < test_cases; i++)
	{	
		run_election();
	}
	return 0;
}