#include<iostream>
using namespace std;

int searchInARotatedSortedArray(int arr[],int size,int target) {
	int start = 0;
	int end = size;
	while (start < end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == target) {
			return mid;
		}
		if (arr[start] <= arr[mid]) {
			if (target >= arr[start] && target < arr[mid]) {
				end = mid;
			}
			else {
				start = mid;
			}
		}
		if (arr[start] > arr[mid]) {
			if (target > arr[mid] && target <= arr[mid - 1]) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}

	}
	return -1;
}

int main() {
	int arr[] = { 4, 5, 6, 7, 0, 1, 2 };
	int target;
	cout << "Search: ";
	cin >> target;
	cout << "Index of " << target << " is: ";
	cout << searchInARotatedSortedArray(arr, sizeof(arr) / sizeof(arr[0]), target) << endl;
	cin.get();
	return 0;
}