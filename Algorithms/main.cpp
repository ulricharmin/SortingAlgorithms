#include <iostream>
#include <string>
#include <vector>

#include "BubbleSort.h"
#include "QuickSort.h"

using namespace std;

int main(int argc, const char* argv[]) {
	vector<int> nums = { 52, 24, 10, 15, 63, 30 };

	quickSort(nums, 0, nums.size()-1);
	bubbleSort(nums);

	cout << "Sorted by Quicksort:" << endl;
	printQuick(nums);

	cout << "\n" << endl;

	cout << "Sorted by Bubble Sort:" << endl;
	printBubble(nums);
}