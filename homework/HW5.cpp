#include<iostream>
using namespace std;

int main() {
    
    // Part I: Array Manipulation

    int nums[] = {4, 2, 7, 1, 5, 6, 3, 8, 0, 9};
    
    cout << "Forward Order:" << endl;
    for (int i=0; i<10; i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;

    cout << "Reverse Order:" << endl;
    for (int i=9; i>=0; i--) {
        cout << nums[i] << ' ';
    }
    cout << endl;

    cout << "Difference of All Values:" << endl;
    int diff = nums[0];
    for (int i=1; i<10; i++) {
        diff -= nums[i];
    }
    cout << diff << endl << endl;
    // output did not match sample output 
    // 4 - 2 - 7 - 1 - 5 - 6 - 3 - 8 - 0 - 9 = -37
     

    cout << "Odd Index Elements:" << endl;
    int product = 1;
    for (int i=1; i<10; i += 2) {
        cout << nums[i] << ' ';
        product *= nums[i];
    }
    cout << endl;
    cout << "Product of Odd Index Elements:" << endl;
    cout << product << endl << endl;

    float sum = 0;
    int count = 0;
    cout << "Even Index Elements:" << endl;
    for (int i=0; i<10; i += 2) {
        cout << nums[i] << ' ';
        sum += nums[i];
        count++;
    }
    cout << endl;
    cout << "Average of Even Index Elements:" << endl;
    cout << sum/count << endl << endl;

    // Part II: String Processing

    string words = "Hello, World!";
    int len_words = words.length();

    cout << "Character-by-Character Printing:" << endl;
    for (int i=0; i<len_words; i++) {
        cout << words[i] << endl;
    }
    cout << endl;

    cout << "Reversed String (character-by-character):" << endl;
    for (int i=len_words-1; i>=0; i--) {
        cout << words[i] << endl;
    }
    cout << endl;

    cout << "Reversed String:" << endl;
    string reversed_words = "";
    for (int i=len_words; i>=0; i--) {
        reversed_words += words[i];
    }
    cout << reversed_words << endl << endl;

    cout << "Manual Substring (from index 7 to 11):" << endl;
    string sub_words = "";
    for (int i=7; i<12; i++) {
        sub_words += words[i];
    }
    cout << sub_words << endl << endl;

    return 0;
}