#include <iostream>
using namespace std;

// goal: to create a data structure where I can look up one value by another value at O(1) time

// creating the container for our key/value pairs with arrays

const int tableSize = 100;
string keys[tableSize];
string values[tableSize];
bool occupied[tableSize] = {false}; // array to track available slots

// implementing a simplified version of DJB2 hash function 
  // not worrying about neg values, or int overflow
  // input str ==> output idx

int hashDJB2(string str) { 
    int hash = 5381; 
    for (char c : str) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % tableSize; // to keep idx within tableSize
}

// insert function to assign key(state), value(capaital) to idx

bool insert(string key, string value) {
    int idx = hashDJB2(key);

    // if idx occupied, +1 to idx, wrap around if at end
    while (occupied[idx]) { 
      if (keys[idx] == key) {
        
      }
        idx = (idx + 1) % tableSize;
      }
    
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
  int idx = hashDJB2(key);
  return values[idx];
}
  

int main() {

  // populate key/value table
  string states[10] = {"Alaska", "California", "Delaware", "Florida", "Georgia", "Hawaii", "Idaho", "Kansas", "Maine", "Nebraska"};
  string capitals[10] = {"Juneau", "Sacramento", "Dover", "Tallahassee", "Atlanta", "Honolulu", "Boise", "Boise", "Augusta", "Lincoln"};

  for (int i=0; i<10; i++) {
    insert(states[i], capitals[i]);
  }

  cout << keys << endl;
  



}