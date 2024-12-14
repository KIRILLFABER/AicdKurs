#include "Data.h"


const long int FROM = 1e4;
const long int TO = 1e5;
const int STEP = 1e4;
const int MAX_VALUE = 1e5;

void fillArray(vector<int>& arr, int TO) {
    srand(time(NULL));
    for (int i = 0; i < TO; i++) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, MAX_VALUE);
        arr.push_back(dis(gen));
    }
    sort(arr.begin(), arr.end());
}

void fillDataFile(string filename) {
	ofstream data_file(filename);
    if (!data_file.is_open()) {
        cout << "ERROR\n";
        return;
    }
    
    data_file << "search;n;T(n)\n";

    // LS
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        
        auto start = chrono::high_resolution_clock::now();
        linearSearch(arr, MAX_VALUE * 2);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "LS;" << n << ";" << T << endl;
    }
    cout << "LINEAR SEARCH: DONE\n";
    // BS
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        auto start = chrono::high_resolution_clock::now();
        binarySearch(arr, MAX_VALUE * 2);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "BS;" << n << ";" << T << endl;
    }
    cout << "BINARY SEARCH: DONE\n";
    // TS
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        auto start = chrono::high_resolution_clock::now();
        ternarySearch(arr, MAX_VALUE * 2);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "TS;" << n << ";" << T << endl;
    }
    cout << "TERNARY SEARCH: DONE\n";
    // IS
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        auto start = chrono::high_resolution_clock::now();
        interpolationSearch(arr, MAX_VALUE * 2);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "IS;" << n << ";" << T << endl;
    }
    cout << "INTERPOLATION SEARCH: DONE\n";
    


    data_file.close();
}
