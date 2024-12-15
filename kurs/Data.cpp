#include "Data.h"



const long int FROM = 1e4;
const long int TO = 1e5;
const int STEP = 1e3;
const long int MAX_VALUE = 1e6;

void fillArray(vector<int>& arr, int TO) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, MAX_VALUE);

    std::unordered_set<int> unique_numbers;

    while (unique_numbers.size() < TO) {
        int val = dis(gen);
        unique_numbers.insert(val);
    }

    arr.assign(unique_numbers.begin(), unique_numbers.end());
    std::sort(arr.begin(), arr.end());
}

void fillDataFile(string filename) {
	ofstream data_file(filename);
    if (!data_file.is_open()) {
        cout << "ERROR\n";
        return;
    }
    
    data_file << "search;case;n;T(n)\n";

    // LS
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        
        auto start = chrono::high_resolution_clock::now();
        linearSearch(arr, MAX_VALUE * 2);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "LS;W;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        auto start = chrono::high_resolution_clock::now();
        linearSearch(arr, arr[0]);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "LS;F;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        auto start = chrono::high_resolution_clock::now();
        linearSearch(arr, arr[(n - 1)/2]);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "LS;M;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        auto start = chrono::high_resolution_clock::now();
        linearSearch(arr, arr[n - 1]);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "LS;L;" << n << ";" << T << endl;
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
        data_file << "BS;W;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        auto start = chrono::high_resolution_clock::now();
        binarySearch(arr, arr[0]);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "BS;F;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        auto start = chrono::high_resolution_clock::now();
        binarySearch(arr, arr[(n - 1)/2]);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "BS;M;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        auto start = chrono::high_resolution_clock::now();
        binarySearch(arr, arr[n - 1]);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "BS;L;" << n << ";" << T << endl;
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
        data_file << "TS;W;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        auto start = chrono::high_resolution_clock::now();
        ternarySearch(arr, arr[0]);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "TS;F;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        auto start = chrono::high_resolution_clock::now();
        ternarySearch(arr, arr[(n - 1) / 2]);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "TS;M;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        auto start = chrono::high_resolution_clock::now();
        ternarySearch(arr, arr[n - 1]);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "TS;L;" << n << ";" << T << endl;
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
        data_file << "IS;W;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        auto start = chrono::high_resolution_clock::now();
        interpolationSearch(arr, arr[0]);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "IS;F;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        auto start = chrono::high_resolution_clock::now();
        interpolationSearch(arr, arr[(n - 1) / 2]);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "IS;M;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        auto start = chrono::high_resolution_clock::now();
        interpolationSearch(arr, arr[n - 1]);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        double T = duration.count();
        data_file << "IS;L;" << n << ";" << T << endl;
    }
    cout << "INTERPOLATION SEARCH: DONE\n";
    


    data_file.close();
}


