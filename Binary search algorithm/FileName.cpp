#include<iostream>
using namespace std;
bool isSorted(int arr[],int size) {
	for (int a = 1; a < size; a++) {
		if (arr[a] < arr[a - 1]) {
			return false;
		}
	}
	return true;
}
int binarySearch(int arr[], int size,int key) {
	int start = 0;
	int end = size - 1;
	int mid = 0;
	while (start <= end) {
		mid = start + ((end - start) / 2);
		if (key > arr[mid]) {
			start = mid + 1;
		}
		else if (key < arr[mid]) {
			end = mid - 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}
int binarySearchRecursive(int arr[], int size, int start, int end, int key) {
	if (start > end) {
		return -1;
	}
	int mid = start + ((end - start) / 2);
	if (key > arr[mid]) {
		return binarySearchRecursive(arr, size, mid + 1, end, key);
	}
	else if (key < arr[mid]) {
		return binarySearchRecursive(arr, size, start, mid - 1, key);
	}
	else {
		return mid;
	}
}
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10};
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Sorted status: " << (isSorted(arr, 10) ? "True" : "False");
	cout << endl;
	cout << binarySearchRecursive(arr, size, 0, size - 1, 6);
	cout << endl;
	cout<<binarySearch(arr, 11, 6);
	cin.get();
	return 0; 
}