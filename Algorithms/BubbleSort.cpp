#include <iostream>
#include <string>
#include <vector>

#include "BubbleSort.h"

using namespace std;

// swaps the given parameters
void swap(vector<int>& nums, int a) {
	int temp = nums.at(a);
	nums.at(a) = nums.at(a + 1);
	nums.at(a + 1) = temp;
}

// Checks if next number in vector is greater than thee current one. If so, done should be set to false and swap gets called.
void bubbleSort(vector<int>& nums) {
	bool done = false;
	while (!done) {
		done = true;
		for (int a = 0; a < nums.size() - 1; a++) {
			if (nums.at(a) > nums.at(a + 1)) {
				swap(nums, a);
				done = false;
			}
		}
	}
}

// prints vector
void printBubble(vector<int>& nums) {
	for (int element : nums) {
		cout << element << " ";
	}
}
