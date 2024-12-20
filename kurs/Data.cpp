#include "Data.h"



const long int FROM = 1e4; // нижняя граница количества элементов
const long int TO = 1e5; // верхняя граница количества элементов
const int STEP = 1e3; // шаг
const long int MAX_VALUE = 1e9; // максимальное значение
const int K = 1e4; // Коэффициент усреднения



double averaging(vector<double> arr) {
    double total = 0;
    for (double i : arr) {
        total += i;
    }
    return total / arr.size();
}


int findUndef(vector<int> arr) {
    while (true) {
        int val = rand() % *std::max_element(arr.begin(), arr.end()) + *std::min_element(arr.begin(), arr.end());
        for (int i : arr) {
            if (i != val) return val;
        }
    }


}

void fillArray(vector<int>& arr, int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, MAX_VALUE);

    std::unordered_set<int> unique_numbers;

    while (unique_numbers.size() < n) {
        int val = dis(gen);
        unique_numbers.insert(val);
    }

    arr.assign(unique_numbers.begin(), unique_numbers.end());
    std::sort(arr.begin(), arr.end());
}


void createUniqueKeys(vector<int> arr, vector<int>& keys, int k) {
    std::unordered_set<int> unique_keys;
    while (unique_keys.size() < k) {
        unique_keys.insert(arr[rand() % arr.size()]);
    }
    keys.assign(unique_keys.begin(), unique_keys.end());
}

void fillDataFile(string filename) {
	ofstream data_file(filename);
    if (!data_file.is_open()) {
        cout << "ERROR\n";
        return;
    }
    
    data_file << "search;case;n;T(n)\n";
    srand(time(NULL));
    // LS
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        vector<double> sample;
        fillArray(arr, n);

        for (int i = 0; i < K; i++) {
            int key = findUndef(arr);
            auto start = chrono::high_resolution_clock::now();
            linearSearch(arr, key);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        
        data_file << "LS;W;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        for (int i = 0; i < K; i++) {
            auto start = chrono::high_resolution_clock::now();
            linearSearch(arr, arr[0]);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "LS;F;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        for (int i = 0; i < K; i++) {
            auto start = chrono::high_resolution_clock::now();
            linearSearch(arr, arr[(n - 1) / 2]);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "LS;M;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        for (int i = 0; i < K; i++) {
            auto start = chrono::high_resolution_clock::now();
            linearSearch(arr, arr[n - 1]);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "LS;L;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        vector<int> keys;
        createUniqueKeys(arr, keys, K);
        for (int i = 0; i < K; i++) {
            int key = keys[i];
            auto start = chrono::high_resolution_clock::now();
            linearSearch(arr, key);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "LS;R;" << n << ";" << T << endl;
    }
    cout << "LINEAR SEARCH: DONE\n";
    // BS
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        for (int i = 0; i < K; i++) {
            int key = findUndef(arr);
            auto start = chrono::high_resolution_clock::now();
            binarySearch(arr, key);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "BS;W;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        for (int i = 0; i < K; i++) {
            auto start = chrono::high_resolution_clock::now();
            binarySearch(arr, arr[0]);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "BS;F;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        for (int i = 0; i < K; i++) {
            auto start = chrono::high_resolution_clock::now();
            binarySearch(arr, arr[(n - 1) / 2]);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "BS;M;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        for (int i = 0; i < K; i++) {
            auto start = chrono::high_resolution_clock::now();
            binarySearch(arr, arr[n - 1]);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "BS;L;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        vector<int> keys;
        createUniqueKeys(arr, keys, K);
        for (int i = 0; i < K; i++) {
            int key = keys[i];
            auto start = chrono::high_resolution_clock::now();
            binarySearch(arr, key);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "BS;R;" << n << ";" << T << endl;
    }
    cout << "BINARY SEARCH: DONE\n";
    // TS
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        for (int i = 0; i < K; i++) {
            int key = findUndef(arr);
            auto start = chrono::high_resolution_clock::now();
            ternarySearch(arr, key);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "TS;W;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        for (int i = 0; i < K; i++) {
            auto start = chrono::high_resolution_clock::now();
            ternarySearch(arr, arr[0]);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "TS;F;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        for (int i = 0; i < K; i++) {
            auto start = chrono::high_resolution_clock::now();
            ternarySearch(arr, arr[(n - 1) / 2]);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "TS;M;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        for (int i = 0; i < K; i++) {
            auto start = chrono::high_resolution_clock::now();
            ternarySearch(arr, arr[n - 1]);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "TS;L;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        vector<int> keys;
        createUniqueKeys(arr, keys, K);
        for (int i = 0; i < K; i++) {
            int key = keys[i];
            auto start = chrono::high_resolution_clock::now();
            ternarySearch(arr, key);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "TS;R;" << n << ";" << T << endl;
    }
    cout << "TERNARY SEARCH: DONE\n";
    // IS
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        for (int i = 0; i < K; i++) {
            int key = findUndef(arr);
            auto start = chrono::high_resolution_clock::now();
            interpolationSearch(arr, key);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "IS;W;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        for (int i = 0; i < K; i++) {
            auto start = chrono::high_resolution_clock::now();
            interpolationSearch(arr, arr[0]);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "IS;F;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        for (int i = 0; i < K; i++) {
            auto start = chrono::high_resolution_clock::now();
            interpolationSearch(arr, arr[(n - 1)/2]);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "IS;M;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        for (int i = 0; i < K; i++) {
            auto start = chrono::high_resolution_clock::now();
            interpolationSearch(arr, arr[n - 1]);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "IS;L;" << n << ";" << T << endl;
    }
    for (int n = FROM; n < TO; n += STEP) {
        vector<int> arr;
        fillArray(arr, n);
        vector<double> sample;
        vector<int> keys;
        createUniqueKeys(arr, keys, K);
        for (int i = 0; i < K; i++) {
            int key = keys[i];
            auto start = chrono::high_resolution_clock::now();
            interpolationSearch(arr, key);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            double T = duration.count();
            sample.push_back(T);
        }
        double T = averaging(sample);
        data_file << "IS;R;" << n << ";" << T << endl;
    }
    cout << "INTERPOLATION SEARCH: DONE\n";
    


    data_file.close();
}


