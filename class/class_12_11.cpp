#include<iostream>
using namespace std;

class Node {
    public:
        int num;
        Node* next;
};

class Stack {
    private:
        Node* head = NULL;

    public:
        void push (int input_val) {
            Node* temp = head;
            head = new Node;
            head->num = input_val;
            head->next = temp;
        }

        int pop () {
            int top = head->num;
            head = head->next;
            return top;
        }

        int peek () {
            return head->num;
        }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << stack.pop() << endl;
    cout << stack.peek() << endl;

    return 0;
}