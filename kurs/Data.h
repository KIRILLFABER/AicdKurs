#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <time.h>
#include <unordered_set>
#include "Searches.h"



using namespace std;

void fillDataFile(string filename);
void fillArray(vector<int>& arr, int size);
double averaging(vector<double> arr);
int findUndef(vector<int> arr);
void createUniqueKeys(vector<int> arr, vector<int>& keys, int k);




