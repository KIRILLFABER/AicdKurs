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
	// best case: 4 + 1 + 1 = 6 
	// average case:
	// Space complexity
	// 4 * 4 = 16 = O(1)
}
int interpolationSearch(vector<int>& arr, int key) {
	if (arr.empty()) return -1;
	int left = 0;
	int right = arr.size() - 1;

	while (left <= right && key >= arr[left] && key <= arr[right]) {
		if (left == right) {
			if (arr[left] == key) return left;
			return -1;
		}

		int i = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);

		if (i < left || i > right) {
			return -1;
		}

		if (arr[i] == key) {
			return i;
		}

		if (arr[i] < key) {
			left = i + 1;
		}
		else {
			right = i - 1;
		}
	}

	return -1;

	// Time complexity
	// worst case:
	// best case: 1 + 2 + 3 + 1 + 1 + 2 = 10
	// average case:
	// Space complexity
	// 4 * 2 = 8 = O(1)
}

