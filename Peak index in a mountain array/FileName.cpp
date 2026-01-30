#include<iostream>
#include<vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;
    
    while (start < end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] < arr[mid + 1]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    
    return start;
}

int main() {
	vector<int> arr = {0,1,0};
	cout << "Peak index is" << peakIndexInMountainArray(arr) << endl;
	cout << "Peak element is " << arr[peakIndexInMountainArray(arr)] << endl;
	cin.get();
	return 0;
}