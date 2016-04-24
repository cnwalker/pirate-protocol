#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Person {
public:
	string name;
	double class_score;
	string economic_class;
	Person() {
		name = "";
		score = 0;
		clas = "";
	}
};

// Class score is alphabetical so compute_class_score works for alphabetical as well
double compute_class_score(string economic_class, string name){
	double score;
	for (int i = economic_class.length() - 1; i > 0; i--) {
		if (clas[i - 1] == '-') {
			score += (economic_class[i] - 'm')/pow(10, i);
		}
	}
	return score;
}

/*
    Returns 1 if first name occurs alphabetically before second name, -1 if
    second name occurs before first name and 0 if the two names are the same.
*/
int compare_names(string name_one, string name_two) {
    return 0;
}

void binary_insert(Person in_person, vector<Person> person_list) {
    if (person_list.length() == 0) {
        person_list.push_back(in_person);
        return;
    }

    int cur_index = in_person.length()/2;
    int lower_bound = 0;
    int upper_bound = in_person.length();

    // Need to make sure we're not trying to access invalid memory
    while(cur_index > 0 && cur_index < in_person.length() - 1) {
        if (in_person.score > person_list[cur_index].score) {
            // If it is between a greater and a lesser then we're done
            if (in_person.score < person_list[cur_index + 1].score) {
                person_list.insert(in_person, cur_index);
                return;
            } else {
                lower_bound = cur_index;
                cur_index = (cur_index + upper_bound)/2;
            }
        }

        if (in_person.score < person_list[cur_index].score) {
            // Same as the above case but in reverse
            if (in_person.score > person_list[cur_index - 1].score) {
                person_list.insert(in_person, cur_index);
                return;
            } else {
                upper_bound = cur_index;
                cur_index = cur_index/2;
            }
        }

        // If two scores are equal, we perform a slightly different operation on the names
        if (in_person.score == person_list[cur_index].score) {
            int name_result = compare_names(in_person.name, person_list[cur_index].name);
            // If in_person name comes alphabetically before the current person in the list
            if (name_result < 0) {
                if (in_person.score != person_list[cur_index - 1].score) {
                    person_list.insert(in_person, cur_index);
                } else {
                    cur_index -= 1;
                }
            } else {
                // If in_person name is alphabetically identitcal or after current person in the list
                if (in_person.score != person_list[cur_index + 1].score) {
                    person_list.insert(in_person, cur_index);
                } else {
                    cur_index += 1;
                }
            }
        }

    }
}

void handle_case() {
	int num_people = 0;
	int delimeter_pos = 0;
	string junk;
	cin >> num_people;

	vector<string> person_list;
	string current_person;

	for(int i = 0; i < num_people; i++) {
		cin >> current_person >> junk;
		cur_person_obj = Person();
		delimeter_pos = current_person.find(':');
		cur_person_obj.name = current_person.substring(0, delimeter_pos);
		cur_person_obj.economic_class = current_person.substring(delimeter_pos + 1, current_person.length());
		cur_person_obj.score = compute_class_score(current_person.economic_class, current_person.name);

		if (!people_list.length()) {
			people_list.push_back(current_person)
		} else {
            binary_insert(current_person, person_list)
		}
	}
    return person_list;
}

int main() {
	int num_cases;
    cin >> num_cases;
	for(int i = 0; i < num_cases; ++i) {
		vector<Person> person_list = handle_case();
	}

    /* for(i = 0; i < person_list.length(); ++i) {

    } */
}
