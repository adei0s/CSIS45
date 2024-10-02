#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int nums[] = {1, 2, 3, 4};


/*
    for(int i=0; i<4; i++){
        if (nums[i] == 3) {
            for (int i=0; i<4; i++) {
                if (nums[i] == 2) {
                    cout << "pass" << endl;
                }
            }
        }
    }
*/

    bool is_3 = false; 
    bool is_4 = false;

    for(int i=0; i<4; i++){
        if (nums[i] == 3) {
            is_3 = true;
            }
        if (nums[i] == 4) {
            is_4 = true;
            }
        }
    if (is_3 && is_4) {
        cout << "pass" << endl;
    }

    else {
        cout << "3 and 4 are not here" << endl;
    }
    return 0;
}