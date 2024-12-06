#include <iostream>
using namespace std;

struct Node{
    int num;
    Node* nxt;

    // constructor
    Node(int value) {
        num = value;
        nxt = nullptr;
    }
};

int main(){
    int a; //create variable a
    Node my_node(1); //create an instance of Node named my_node
    Node node2(2);
    Node node3(3);
    Node node4(4);

    my_node.nxt = &node2;
    node2.nxt = &node3;
    node3.nxt = &node4;

    Node* curr = &my_node;
    while(curr != nullptr) {
        cout << curr->num << endl;
        curr = curr->nxt;
    }

    // cout << node4.num;

    return 0;
}

// create Dog class?

// create linked list class?

// class Dog;
//     bark();

// class shelter;
//     dogs[];
//     list_dogs;
//     feed_dogs(); // cause dogs to bark

// create shelter object that holds dogs.

// struct Dog {
//     string name;
//     bool fed;

//     void bark() {
//         cout << "BARK!!" << endl;
//     }

//     Dog (string input_name) {
//         name = input_name;
//     }
// };

// struct Shelter {
//     Dog dog_arr[10];
//     int nxt_idx = 0;

//     void add_dog(Dog doggo) {  //
//         dog_arr[nxt_idx] = doggo;
//         nxt_idx++;
//     }

//     void list_dogs() {
//         for (int i=0; i<10; i++) {
//             dog_arr[i].bark();
//         }
//     }

// };

// int main() {
//     Dog my_dog;
//     my_dog.bark();

//     Shelter my_shelter;
//     my_shelter.add_doggo("sparky");
}