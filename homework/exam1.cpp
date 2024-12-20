#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
   
    vector<int> merged;
    int idx1 = 0;
    int idx2 = 0;
    
    while (idx1 < left.size() && idx2 < right.size()) {
        if (left[idx1] < right [idx2]) {
            merged.push_back(left[idx1]);
            idx1 += 1;
        }
        else {
            merged.push_back(right[idx2]);
            idx2 += 1;
        }
    }
    
    while (idx1 < left.size()) {
        merged.push_back(left[idx1]);
        idx1 += 1;
    }
    while (idx2 < right.size()) {
        merged.push_back(right[idx2]);
        idx2 += 1;
    }
    
    return merged;
}

vector<int> mergesort(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums;
    }

    int mid = nums.size() / 2;
    vector<int> left(nums.begin(), nums.begin() + mid);
    vector<int> right(nums.begin() + mid, nums.end());

    left = mergesort(left);
    right = mergesort(right);

    return merge(left, right);
}

bool two_sum(int arr[], const int size, int target, int result[2]) {
    
    vector<int> nums(arr, arr + size);
    vector<int> sorted = mergesort(nums); // sorting not necessary for two_sum
    
    unordered_set<int> diff;

    for (int i=0; i<size; i++) {
        if (diff.find(arr[i]) != diff.end()) {
            result[0] = arr[i];
            result[1] = target - arr[i]; 
            return true;
        }  
        else {
            diff.insert(target - arr[i]);
        }
    }
    return false;
}

int main() {

    int arr[] = {7, 2, 11, 15};
    int target = 9;
    int result[2] = {0, 0};
    
    int size = sizeof(arr) / sizeof(arr[0]);
    bool found = two_sum(arr, size, target, result);

    if (found) {
        cout << "Found: " << result[0] << ", " << result[1] << endl; // Output: Found: 2, 7
    } 
    else {
        cout << "No pair found." << endl; // Output: No pair found.
    }

    return 0;
}