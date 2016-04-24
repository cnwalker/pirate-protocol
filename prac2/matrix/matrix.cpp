#include <vector>
#include <iostream>

using namespace std;

int main() {
	vector<string> board;

	int numTrials;

	int r, c;
	cin >> numTrials;

	for (int nt = 0; nt < numTrials; ++nt) {
		cin >> r >> c;

		vector<string> board (r);

		for (int i = 0; i < board.size(); ++i) {
			string s;
			cin >> s;
			board[i] = s;
		}
		bool possible = true;
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				if (board[i][j]=='1') {
					for (int x = 0; x < board.size(); ++x) {
						for (int y = 0; y < board.size(); ++y) {
							if (board[x][y] == '1') {
								if (board[x][j] == '0' || board[i][y] == '0') {
									possible = false;
								}
							}
						}
					}
				}
			}
		}
		if (!possible) {
			cout << "impossible" << endl;
		} else {
			for (int i = 0; i < board.size(); ++i) {
				for (int j =0 ; j < board[i].size(); ++j) {
					if (board[i][j] == '1') {
						bool row_det, col_det;
						row_det = col_det = true;
						for (int r = 0; r < board.size(); ++r) {
							if (board[r][j] == '1') {
								row_det = false;
							}
						}
						for (int c =0 ; c < board[i].size(); ++c) {
							if (board[i][c] == '1') {
								col_det = false;
							}
						}
						if (!row_det || !col_det){ 
							cout << 'I';
						} else {
							cout << 'P';
						}
					} else {
						cout << 'N';
					}
				}
				cout << endl;
			}			
		}
		cout << "----------" << endl;
	}
}