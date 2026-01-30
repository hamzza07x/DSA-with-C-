#include<iostream>
using namespace std;
int getMajorityElement(int arr[], int size) {
	int vote = 0;
	int majorityElement = 0;
	for (int a = 0; a < size; a++) {
		if (vote == 0) {
			majorityElement = arr[a];
		}
		if (majorityElement == arr[a]) {
			vote++;
		}
		else {
			vote--;
		}
	}
	return majorityElement;
}
int main() {
	int size;
	cout << "Enter size: ";
	cin >> size;
	int* arr = new int[size];
	cout << "Enter array" << endl;
	for (int a = 0; a < size; a++) {
		cout << "Enter: ";
		cin >> arr[a];
	}
	cout << endl;
	cout << "Array: ";
	for (int a = 0; a < size; a++) {
		cout << arr[a] << " ";
	}
	cout << endl;
	cout << "Majority element: " << getMajorityElement(arr, size) << endl;
	delete[]arr;
	cin.get();
	return 0;
}