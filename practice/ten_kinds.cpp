#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_map(vector<vector<int> > input_map) {
    for (int i = 0; i < input_map.size(); ++i) {
        for (int j = 0; j < input_map[0].size(); ++j) {
            cerr << input_map[i][j];
        }
        cerr << endl;
    }
}

// If the starting position is 0 then make it's identifier negative
// If 1 the identifier will be positive
void mark_zone(vector<vector<int> > &world_map, int start_row, int start_col, int mark_number, int travel_number) {
    int up = start_row - 1;
    int down = start_row + 1;
    int left = start_col - 1;
    int right = start_col + 1;

    // Mark the current cell
    world_map[start_row][start_col] = mark_number;

    // Check the:
    // Top
    if (up >= 0 && world_map[up][start_col] == travel_number) {
        mark_zone(world_map, up, start_col, mark_number, travel_number);
    }

    // Bottom
    if (down < world_map.size() && world_map[down][start_col] == travel_number) {
        mark_zone(world_map, down, start_col, mark_number, travel_number);
    }

    // Left
    if (left >= 0 && world_map[start_row][left] == travel_number) {
        mark_zone(world_map, start_row, left, mark_number, travel_number);
    }

    // Right
    if (right < world_map[0].size() && world_map[start_row][right] == travel_number) {
        mark_zone(world_map, start_row, right, mark_number, travel_number);
    }
}

// Gives every continguous sequence a unique identifier to avoid recomputing
string can_travel(vector<vector<int> > &world_map, int start_row, int start_col,
    int end_row, int end_col, int mark_number) {
        
    int start_num = world_map[start_row][start_col];

    if (start_num == 0) {
        mark_zone(world_map, start_row, start_col, mark_number * -1, start_num);
    }

    if (start_num == 1) {
        mark_zone(world_map, start_row, start_col, mark_number, start_num);
    }


    /* cout << "start_row: " << start_row;
    cout << ", start_col: " << start_col << endl;
    cout << "end_row: " << end_row;
    cout << ", end_col: " << end_col << endl;
    cout << "map:" << endl;
    print_map(world_map);
    cout << endl; */

    if (world_map[start_row][start_col] == world_map[end_row][end_col]) {
        return (world_map[start_row][start_col] < 0 ? "binary" : "decimal");
    }

    return "neither";
}

int main() {
    int row_num;
    int column_num;
    vector<vector<int> > world_map;
    cin >> row_num >> column_num;

    string input_string;

    for (int i = 0; i < row_num; ++i) {
        cin >> input_string;
        vector<int> row (column_num);
        for(int j = 0; j < column_num; ++j) {
            row[j] = input_string[j] - '0';
        }
        world_map.push_back(row);
    }

    int query_num;
    cin >> query_num;

    int start_row, start_col;
    int end_row, end_col;

    for(int query_id = 2; query_id < query_num + 2; ++query_id) {
        cin >> start_row >> start_col;
        cin >> end_row >> end_col;
        cout << can_travel(world_map, start_row - 1, start_col - 1,
            end_row - 1, end_col - 1, query_id) << endl;
    }

    return 0;
}
