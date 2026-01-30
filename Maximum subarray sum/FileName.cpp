#include<iostream>
#include<stdexcept>
using namespace std;
int bruteForce(int arr[],int size) {
	int maximumSum = INT_MIN;
	for (int start = 0; start < size; start++) {
		int currentSum = 0;
		for (int end = start; end < size; end++) {
			currentSum = currentSum + arr[end];
			maximumSum = max(currentSum, maximumSum);
		}
	}
	return maximumSum;
}
int kadanesAlgorithm(int arr[],int size) {
	int maximumSum = INT_MIN;
	int currentSum = 0;
	for (int a = 0; a < size; a++) {
		currentSum = currentSum + arr[a];
		maximumSum = max(currentSum, maximumSum);
		if (currentSum < 0) {
			currentSum = 0;
		}
	}
	return maximumSum;
}
int main() {
	int size;
	cout << "Enter number of elements you want in the array: ";
	cin >> size;
	int* arr = new int[size];
	cout << "Enter array" << endl;
	for (int a = 0; a < size; a++) {
		cout << "Enter " << a + 1 << " : ";
		cin >> arr[a];
	}
	cout << "Array: ";
	for (int a = 0; a < size; a++) {
		cout << arr[a] << " ";
	}
	cin.get();
	cout << endl;
	int userChoice;
	cout << "Enter method by which you want the sum of maximum subarray" << endl;
	cout << "1.Brute Force" << endl;
	cout << "2.Kadane's algorithm" << endl;
	cout << "Enter: ";
	cin >> userChoice;
	cout << endl;
	if (userChoice == 1) {
		cout << "Maximum subarray sum: " << bruteForce(arr, size) << endl;
	}
	else if (userChoice == 2) {
		cout<<"Maximum subarray sum: "<<kadanesAlgorithm(arr, size)<<endl;
	}
	else {
		throw invalid_argument("Error");
	}
	delete[] arr;
	cin.get();
	return 0;
}
