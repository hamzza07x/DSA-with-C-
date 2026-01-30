#include<iostream>
#include<vector>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
	if (nums.size() == 1) {
		return nums[0];
	}
	int start = 0;
	int end = nums.size() - 1;
	while (start < end) {
		int mid = start + (end - start) / 2;
		if (mid == 0 && nums[0] != nums[1]) {
			return nums[mid];
		}
		if (mid == nums.size() - 1 && nums[nums.size() - 1] != nums[nums.size() + 1]) {
			return nums[mid];
		}
		if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
			return nums[mid];
		}
		if (nums[mid] == nums[mid + 1]) {
			if (mid % 2 == 0) {
				start = mid + 2;
			}
			else {
				end = mid - 1;
			}
		}
		if (nums[mid] == nums[mid - 1]) {
			if (mid % 2 == 0) {
				end = mid - 2;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return nums[start];
}
int main() {
	vector<int> arr = {1,1,2,3,3,4,4,8,8};
	cout << "Single element: " << singleNonDuplicate(arr) << endl;
	arr = {3, 3, 7, 7, 10, 11, 11};
	cout << "Single element: " << singleNonDuplicate(arr) << endl;
	cin.get();
	return 0;
}