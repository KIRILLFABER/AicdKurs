#include "Searches.h"


int binarySearch(vector<int>& arr, int key) {
	if (arr.empty()) return -1;
	int left = 0, right = arr.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2; 
		if (arr[mid] == key) {
			return mid;
		}
		if (arr[mid] < key) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;


	// Time complexity
	// worst case: 
	// best case: 1 + 2 + 1 + 1 + 1 = 6 = O(1)
	// average case:
	// Space complexity
	// 4 + 4 + 4 = O(1)
}

int linearSearch(vector<int>& arr, int key) {
	int i = 0;
	for (; i < arr.size() && arr[i] != key; i++);
	return i < arr.size() && arr[i] == key ? i : -1;
	// Time complexity
	// worst case: 1 + 2n + n + 2 = 3n + 3 = O(n)
	// best case: 1 + 1 + 1  + 2 = 5 = O(1)
	// average case: 1 + 2(n / 2) + n / 2 + 2 = 1 + n + n/2 + 2 = 3 + 3/2n = O(n) 
	// Space complexity
	// 4 = O(1)
}

int ternarySearch(vector<int>& arr, int key) {
	return 1;
}
int interpolationSearch(vector<int>& arr, int key) {
	if (arr.empty()) return - 1;
	int left = 0;
	int right = arr.size() - 1;
	
	while (arr[left] < key && arr[right] > key && arr[left] != arr[right]) {
		int i = (key - arr[left]) * (left - right) / (arr[left] - arr[right]) + left; 
		if (arr[i] > key) {
			right = i - 1;
		}
		else if (arr[i] < key) {
			left = i + 2;
		}
		else {
			return i;
		}
	}
	if (arr[left] == key) {
		return left;
	}
	if (arr[right] == key) {
		return right;
	}
	return -1;
}

