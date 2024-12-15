#include <iostream>
#include <vector>
#include "Searches.h"
#include "Data.h"
#include <random>

using namespace std;
const int MAX_VALUE = 100;


int main() {
	vector<int> arr;
	int key = 20;
	srand(time(0));
	for (int i = 0; i < 50; i++) {
		arr.push_back(rand() % MAX_VALUE);
	}
	std::sort(arr.begin(), arr.end());
	cout << endl << "result of search = " << ternarySearch(arr, key) << endl;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == key) {
			cout << "{" << arr[i] << " index " << i << "} ";
		}
		else
			cout << arr[i] << " ";
	}

	vector<int> a;
	fillArray(a, 50000);
	interpolationSearch(a, a[50000 / 2]);
	
	cout << "\n\n\n\n";
	fillDataFile("DATA.csv");
	
	

	return 0;
}