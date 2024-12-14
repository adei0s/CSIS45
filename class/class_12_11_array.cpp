#include<iostream>
using namespace std;

class Stack {
    private:
        int stack[10];
        int count = 0;

    public:
        void push (int input_val) {
            count++;
            stack[count] = input_val;
        }

        int pop() {
            int top = stack[count];
            stack[count] = NULL;
            count--;
            return top;
        }

        int peek() {
            return stack[count];
        }

        void print() {
            for (int i=0; i<count; i++) {
                cout << stack[i] << endl;
            }
        }

};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << stack.pop() << endl;
    cout << stack.peek() << endl;
    stack.print();
}