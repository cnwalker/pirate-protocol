#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

/* class Ingredient {
public:
	string name;
	int a, b, c;
	Ingredient(string s) {
		name = s;
		a = b = c = 0;
	}
}; */

class Pair {
public:
	double weight, percentage;
	Pair() {
		weight = 0;
		percentage = 0;
	}
	Pair(double x, double y){
		weight = x;
		percentage = y;
	}
};

void scale_recipe(int recipe_num) {
	int num_ingredients;
	double num_portions;
	double num_desired_portions;

	cin >> num_ingredients;
	cin >> num_portions;
	cin >> num_desired_portions;

	double scaling_factor = num_desired_portions/num_portions;
	double scaled_weight;

	int main_ingredient_index = 0;

	// Will be able to lookup ingredient info for a given ingredient by index (lists same length)
	vector<string> ingredients (num_ingredients);
	vector<Pair> ingredient_info (num_ingredients);

	for(int i = 0; i < num_ingredients; i++) {
		cin >> ingredients[i];
		cin >> ingredient_info[i].weight;
		cin >> ingredient_info[i].percentage;

		if (ingredient_info[i].percentage == 100) {
			scaled_weight = ingredient_info[i].weight * scaling_factor;
			main_ingredient_index = i;
		}
	}

	cout << "Recipe # " << recipe_num << endl; 

	for(int i = 0; i < num_ingredients; i++) {
		cout << fixed << setprecision(1) << ingredients[i] << " " <<  scaled_weight * (ingredient_info[i].percentage/100) << endl;
	}
}


int main() {
	int num_cases;
	cin >> num_cases;
	for (int i = 0; i < num_cases; i++) {
		scale_recipe(i + 1);
		cout << "----------------------------------------" << endl;
	}
	return 0;
}