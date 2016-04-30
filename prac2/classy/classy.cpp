#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Person {
public:
	string name;
	double score;
	string economic_class;
	Person() {
	}
};

// Class score is alphabetical so compute_class_score works for alphabetical as well
double compute_class_score(string economic_class){
    double num_classes = 0;
	double score = 0;
	for (int i = economic_class.length() - 1; i > -1; i--) {
		if (economic_class[i - 1] == '-' || i == 0) {
			score += double(economic_class[i] - 'm')/pow(10.0, num_classes);
            num_classes += 1;
		}
	}
	return score;
}

void binary_insert(Person in_person, vector<Person> &people_list) {
    int people_list_len = people_list.size();

    if (people_list_len == 0) {
        people_list.push_back(in_person);
        return;
    }

    int cur_index = people_list_len/2;
    int lower_bound = 0;
    int upper_bound = people_list_len;
    bool is_endpoint = false;

    // Need to make sure we're not trying to access invalid memory
    while(1) {
        is_endpoint = cur_index == people_list_len - 1 || cur_index == 0;

        if (in_person.score > people_list[cur_index].score) {
            //cout << "Greater" << endl;

            // If it is between a greater and a lesser then we're done
            if (cur_index == people_list_len - 1 || in_person.score < people_list[cur_index + 1].score) {
                people_list.insert(people_list.begin() + cur_index + 1, in_person);
                break;
            } else {
                lower_bound = cur_index;
                cur_index = (cur_index + upper_bound)/2;
            }
        }

        if (in_person.score < people_list[cur_index].score) {
            // Same as the above case but in reverse
            //cout << "Lesser" << endl;
            if (cur_index == 0 || in_person.score > people_list[cur_index - 1].score) {
                people_list.insert(people_list.begin() + cur_index, in_person);
                break;
            } else {
                upper_bound = cur_index;
                cur_index = cur_index/2;
            }
        }

        // If two scores are equal, we perform a slightly different operation on the names
        if (in_person.score == people_list[cur_index].score) {
            //cout << "Equal" << endl;
            /*
                If the current input name comes alphabetically before the name at current index,
                we need to insert the input name to the right of the current name
            */
            if (in_person.name < people_list[cur_index].name) {
                if (cur_index == people_list_len - 1 || in_person.score != people_list[cur_index + 1].score || in_person.name > people_list[cur_index + 1].name ) {
                    people_list.insert(people_list.begin() + cur_index + 1, in_person);
                    break;
                } else {
                    cur_index += 1;
                }
            } else {
                //cout << "List len: " << people_list.size() << endl;
                //cout << "Current index: " << cur_index << endl;
                if (cur_index == 0 || in_person.score != people_list[cur_index - 1].score || in_person.score != people_list[cur_index - 1].score) {
                    people_list.insert(people_list.begin() + cur_index, in_person);
                    break;
                } else {
                    cur_index -= 1;
                }
            }
        }
    }
}

vector<Person> handle_case() {
	int num_people = 0;
	int delimeter_pos = 0;
	cin >> num_people;

	vector<Person> people_list;
    string junk;

	for(int i = 0; i < num_people; i++) {
        Person cur_person_obj = Person();
        cin >> cur_person_obj.name >> cur_person_obj.economic_class >> junk;
        cur_person_obj.name = cur_person_obj.name.substr(0, cur_person_obj.name.length() - 1);
		cur_person_obj.score = compute_class_score(cur_person_obj.economic_class);
        //cout << "Name: " << cur_person_obj.name;
        // Inserts the person using binary parsing
        binary_insert(cur_person_obj, people_list);
	}

    return people_list;
}

int main() {
	int num_cases;
    //int sweg = 0;
    cin >> num_cases;
    vector<Person> people_list;
	for(int i = 0; i < num_cases; ++i) {
		people_list = handle_case();
        for(int j = people_list.size() - 1; j > -1; j--) {
            cout << people_list[j].name << endl;
            //sweg++;
        }
        cout << "==============================" << endl;
    }
}
