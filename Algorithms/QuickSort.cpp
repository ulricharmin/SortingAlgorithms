#include <iostream>
#include <vector>

#include "QuickSort.h"

using namespace std;

// function that interchanges the given parameters
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
* Our Vector: 52, 24, 10, 15, 63, 30;
* pivot = end = 5; // last element
* j = start = 0; //first element
	1. compare first element with pivot. If the current element is smaller than our pivot, we swap it.
		In this case, the vector after the first swap looks like this: 24, 52, 10, 15, 63, 30.
		Thats because we skipped increasing "j" one time so it still is 0 while "i" is already 1 (swap 0 with 1).
		Now we count "j" up by one. j = 1; i = 2;
	2. Do the same again: 10 is smaller than 30 so we swap (index 1 with index 2): 24, 10, 52, 15, 63, 30.
		j = 2; i = 3;
	3. 15 is smaller than 30: 24, 10, 15, 52, 63, 30.
		j = 3; i = 4;
	4. 63 is greater than 30 so nothing happens. The for-loop is done.
	5. After all that, we swap our pivot with whatever number is on the position "j".
		"j" is the number of elements that are smaller than the pivot.
		The pivot now is in the right spot (smaller numbers to the left, greater numbers to the right).
	Our vector now look like that: 24, 10, 30, 15, 63, 52.
*/

int partition(vector<int>& nums, int start, int end) {
	int pivot = end;
	int j = start;
	for (int i = start; i < end; i++) {
		if (nums.at(i) < nums.at(pivot)) {
			swap(nums.at(j), nums.at(i));
			j++;
		}
	}
	swap(nums.at(j), nums.at(pivot));
	return j;
}

/*
	After we "divided" the vector in 1. list before pivot and 2. list after pivot, we are now ready to repeat the
	steps from above recursively. The first recursion-layer is responsible for the right sublist and the second for the left.
*/
void quickSort(vector<int>& nums, int start, int end) {
	if (start < end) {
		int p = partition(nums, start, end);
		quickSort(nums, start, p - 1);
		quickSort(nums, p + 1, end);
	}
}

// print vector
void printQuick(vector<int> nums) {
	for (int element : nums) {
		cout << element << " ";
	}
}
