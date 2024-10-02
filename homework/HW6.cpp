#include <iostream>
#include <iomanip>
using namespace std;

// goal: to create a data structure where I can look up one value by another value at O(1) time

// creating the container for our key/value pairs with arrays

const int tableSize = 101;
string keys[tableSize];
string values[tableSize];
bool occupied[tableSize] = {false}; // array to track available slots

// creating a hash function to generate idx 
// I'm using sum of the ascii value of the letters

int hashing(string str) { 
    int hash = 0; 
    for (char c : str) {
        hash += static_cast<int>(c); // static_cast converts c to ord(c)
    }
    hash = hash % tableSize; // keeping idx within tablesize 
    return hash; 
}

// insert function to assign key, value pair to idx

bool insert(string key, string value) {
    int idx = hashing(key);
    // cout << idx << endl; (checking idx, ignore)
   
    while (occupied[idx]) {   // collision handling
      
      if (keys[idx] == key) {  // if this key already exist, update value
        values[idx] = value;
        return true;
      }
        idx = (idx + 1) % tableSize;  // if this key already exist, update value
      }
    
    if (occupied[idx] == false) {   // if this key already exist, update value
      keys[idx] = key;
      values[idx] = value;
      occupied[idx] = true;
      return true;
    }
    else {
      return false;
    }
}

// look up function to retrieve value from key

string lookup(string key) {
  int idx = hashing(key);
  
  while (occupied[idx]) {   // same as insert for collision, probe up
    if (keys[idx] == key) {
        return values[idx];
    }
    idx = (idx + 1) % tableSize;
  }
  return "[Key not found, check typo]"; 
}
  

int main() {

  // populate key/value table with data

  string states[10] = {"Alaska", "California", "Delaware", "Florida", "Georgia", "Hawaii", "Idaho", "Kansas", "Maine", "Nebraska"};
  string capitals[10] = {"Juneau", "Sacramento", "Dover", "Tallahassee", "Atlanta", "Honolulu", "Boise", "Topeka", "Augusta", "Lincoln"};

  for (int i=0; i<10; i++) {
    insert(states[i], capitals[i]);
  }

  // Enter state ==> Output capital

  cout << "Enter a state: ";
  string state;
  cin >> state;
  cout << "The state capital of " << state << " is " << lookup(state) << "!" << endl;
  cout << "----------------------" << endl;
  
  return 0;
}