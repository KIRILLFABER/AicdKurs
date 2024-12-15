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
	int left = 0;
	int right = arr.size() - 1;
	int m1 = left + (right - left) / 3;
	int m2 = right - (right - left) / 3;
	while (left <= right) {
		if (key == arr[m1]) {
			return m1;
		}
		if (key == arr[m2]) {
			return m2;
		}
		if (arr[m1] < key && arr[m2] > key) {
			right = m2 - 1;
			left = m1 + 1;
		}
		if (arr[m1] > key) {
			right = m1 - 1;
		}
		if (arr[m2] < key) {
			left = m2 + 1;
		}
		m1 = left + (right - left) / 3;
		m2 = right - (right - left) / 3;
	}
	return -1;

	// Time complexity
	// worst case:
	// best case:
	// average case:
	// Space complexity
	// 4 * 4 = 16 = O(1)
}
int interpolationSearch(vector<int>& arr, int key) {
	if (arr.empty()) return - 1;
	int left = 0;
	int right = arr.size() - 1;
	
	while (arr[left] < key && arr[right] > key && arr[left] != arr[right]) {
		int i = (key - arr[left]) * (left - right) / (arr[left] - arr[right]) + left;
		if (i < 0) return -1;
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

	// Time complexity
	// worst case:
	// best case:
	// average case:
	// Space complexity
	// 4 * 2 = 8 = O(1)
}

