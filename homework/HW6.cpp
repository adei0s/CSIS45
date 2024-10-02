#include <iostream>
#include <iomanip>
using namespace std;

// goal: to create a data structure where I can look up one value by another value at O(1) time

// creating the container for our key/value pairs with arrays

const int tableSize = 101;
string keys[tableSize];
string values[tableSize];
bool occupied[tableSize] = {false}; // array to track available slots

// implementing a hash function to generate idx 
  // I'm using sum of the ordinal value of the letters
  // using unsigned because idx keeps being in the negative

unsigned int hashing(string str) { 
    unsigned int hash = 0; 
    for (char c : str) {
        hash += static_cast<unsigned int>(c); // convert c to ord(c)
    }
    hash = hash % tableSize; // keeping idx within tablesize 
    return hash; 
}

// insert function to assign key(state), value(capaital) to idx

bool insert(string key, string value) {
    int idx = hashing(key);
    // cout << idx << endl; (checking idx, ignore)

    // while idx is already occupied
    while (occupied[idx]) { 
      // if this key already exist, update value
      if (keys[idx] == key) {
        values[idx] = value;
        return true;
      }
      // otherwise, try next idx, wrap around if at end of table
        idx = (idx + 1) % tableSize;
      }
    
    // if idx available, fill with key/value pair
    if (occupied[idx] == false) {
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
  
  // same process as insert, probe up until key found
  while (occupied[idx]) {
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
  string capitals[10] = {"Juneau", "Sacramento", "Dover", "Tallahassee", "Atlanta", "Honolulu", "Boise", "Boise", "Augusta", "Lincoln"};

  for (int i=0; i<10; i++) {
    insert(states[i], capitals[i]);
  }

  // prompt user imput
  cout << "Enter a state: ";
  string state;
  cin >> state;
  cout << "The state capital of " << state << " is " << lookup(state) << "!" << endl;
  cout << "----------------------" << endl;
  
  return 0;
}