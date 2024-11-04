#include<iostream>
#include<vector>
using namespace std;


// insertion sort

void insertionSort (vector<int>& numbers, int size) {
    for (int i=1; i<size; i++) {
        int key = numbers[i];
        int target = i - 1;

        while (target >= 0 && key < numbers[target]) {
            numbers[target + 1] = numbers[target];
            target -= 1;
        }
        numbers[target + 1] = key;
    }
}

// binary search

int binarySearch (vector<int> numbers, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (numbers[mid] == target) {
        return mid;
        }

        else if (target < numbers[mid]) {
            right = mid - 1;
        }

        else {
            left = mid + 1;
        }
    }
    return -1;
}

// main function

int main() {

    int size;
    int target;

    // take input for size and numbers

    cout << "Enter the total number of elements: ";
    cin >> size;

    vector<int> numbers(size);

    for (int i=0; i<size; i++) {
        cout << "Enter number " << i+1 << "/" << size << ": ";
        cin >> numbers[i]; 
    }

    cout << "Enter target value to search for: ";
    cin >> target;

    // sort numbers and display sorted result

    insertionSort(numbers, size);

    cout << "Sorted numbers: ";
    for (int i=0; i<size; i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;

    // search for targe in sorted numbers and display result

    int result = binarySearch(numbers, size, target);

    if (result == -1) {
        cout << "Number " << target << " not found." << endl;
    }

    else {
        cout << "Target found at index: " << result << endl;
    }

    return 0;
}
