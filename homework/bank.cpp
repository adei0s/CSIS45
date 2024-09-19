#include<iostream> 
#include<iomanip>
using namespace std;

int main() {
    
    cout << "Welcome to Mini Bank!" << endl;

    // initialize variables
    string names[] = {"Andy", "Barry", "Celia", "Deryl", "Eugene", "Francine", "Gisele", "Henry", "Ignacio"};
    float balance[] = {129.65, 231.21, 568.98, 372.32, 10.09, 2.10, 876.87, 211.21, 22.11};
    float sum = 0;
    int account_num = 0;
    float transaction = 0;
    float average = 0;
    string name = " ";
    
    // current holdings
    for (int i=0; i<9; i++) {
        cout << i << " : " << names[i] << " : " << balance[i] << endl;
        sum += balance[i];
    }
    average = sum/9;
    cout << "Average Account Balance: " << fixed << setprecision(2) << average << endl;
    cout << "=========================" << endl;
    sum = 0;

    // deposit
    cout << "Make a Deposit" << endl;
    cout << "Enter account numbers: ";
    cin >> account_num;
    cout << "Deposit amount: ";
    cin >> transaction;
    balance[account_num] += transaction;
    cout << "New balance: " << balance[account_num] << endl;
    cout << "=========================" << endl;
    transaction = 0;

    // withdrawl
    cout << "Make a Withdrawl" << endl;
    cout << "Enter account numbers: ";
    cin >> account_num;
    cout << "Withdrawl amount: ";
    cin >> transaction;
    balance[account_num] -= transaction;
    cout << "New balance: " << balance[account_num] << endl;
    cout << "=========================" << endl;
    transaction = 0;

    // changing account owner
    cout << "Change Account Owner" << endl;
    cout << "Enter account numbers: ";
    cin >> account_num;
    cout << "New Holder Name: ";
    cin >> name;
    names[account_num] = name;
    cout << "=========================" << endl;

    // check current holdings
    for (int i=0; i<9; i++) {
        cout << i << " : " << names[i] << " : " << balance[i] << endl;
        sum += balance[i];
    }
    average = sum/9;
    cout << "Average Account Balance: " << fixed << setprecision(2) << average << endl;
    return 0;
}