#include<iostream>
#include<vector>
using namespace std;

int binarySearch (int arr[], int size, int target) {
    int left = 0;
    int right = size - 1 ;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
        return mid;
        }

        else if (target < arr[mid]) {
            right = mid - 1;
        }

        else if (target < arr[mid]) {
            left = mid + 1;
        }
    }
    return -1;
}


int main() {

    int multi_array[3][5] = { {1, 2, 3, 4, 5},
                              {6, 7, 8, 9, 10},
                              {11, 12, 13, 14, 15}
    };

    for (int i=0; i<3; i++) {
        for (int j=0; j<5; j++) {
            cout << multi_array[i][j] << endl;

        }
    }
}