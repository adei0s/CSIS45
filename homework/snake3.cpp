#include<iostream>
#include<vector>
#include<string>
using namespace std;

// print current grid state
void print(vector<vector<string>> grid, int row_size, int col_size) {
    string s (col_size + 2, '-');
    cout << s << endl;
    for (int i=0; i<row_size; i++) {
        cout << '|';
        for (int j=0; j<col_size; j++) {
            cout << grid[i][j]; 
        }
        cout << '|' << endl;
    }
    cout << s << endl;
}

// segment class
class Node {
    public:
        int x; 
        int y;
        Node* next;  // pointer to the next segment
};

class Snake {
    private:
        Node* head = NULL; // pointer to the first node
        Node* tail = NULL;
        
    public:
        void grow(int x_val, int y_val) {
            Node* temp = head; 
            head = new Node; 
            if (temp == NULL){
                tail = head;
            }
            head->x = x_val; 
            head->y = y_val;
            head->next = temp;
        }
        
        void update(vector<vector<string>>& grid, int row_size, int col_size, string space) {
            for (int i=0; i<row_size; i++) {
                for (int j=0; j<col_size; j++) {
                    grid[i][j] = space;
                }
            }
            // for (int i=0; i<3; i++) {
            //     grid[food[i][1]][food[1][2]] = "O";
            // }
            Node* curr = head;
            while (curr != NULL) {
                grid[curr->x][curr->y] = "■";
                // cout << curr->x << curr->y << endl;
                curr = curr->next;
            }
        }

        void move(char dir, int row_size, int col_size) {
            // save old head value
            Node prev = *head;
            // assign new value to head
            if (dir == 'w') {
                head->x = ((head->x - 1 + (row_size)) % (row_size));            
            }

            else if (dir == 'a') {
                head->y = ((head->y - 2 + (col_size)) % (col_size));   
            }

            else if (dir == 's') {
                head->x = ((head->x + 1) % (row_size));           
            }

            else if (dir == 'd') {
                head->y = ((head->y + 2) % (col_size));
            }

            else {
                cout << ">> Invalid entry, Try again. " << endl;
            }

            Node* curr = head->next;
            while (curr != NULL) {
                Node temp = *curr;
                curr->x = prev.x;
                curr->y = prev.y;
                prev = temp;
                curr = curr->next;
            }
        }
};


int main() {

    // canvas size
    string space = " ";
    int row_size = 8;
    int col_size = 20;

    // create grid
    vector<vector<string>> grid (row_size, vector<string> (col_size, space));
    // vector<vector<int>> food = {{4, 11}, {7, 19}, {6, 3}};

    // player input
    char dir;

    Snake snake;
    snake.grow(7,5);
    snake.grow(7,7);
    snake.grow(7,9);
    snake.grow(6,9);
    snake.grow(5,9);


    snake.update(grid, row_size, col_size, space);

    // first player input
    cout << ">> Use 'w' 'a' 's' 'd' to move, 'e' to exit" << endl;
    print(grid, row_size, col_size);
    cout << ">> move: ";
    cin >> dir;

    while (true) {

        cout << ">> Use 'w' 'a' 's' 'd' to move, 'e' to exit" << endl;

        if (dir == 'e') {
            cout << "Thanks for playing!" << endl << endl;
            break;
        }


        snake.move(dir, row_size, col_size);
        snake.update(grid, row_size, col_size, space);

        print(grid, row_size, col_size); 

        cout << ">> move: ";
        cin >> dir;
        cout << endl;
    }
    return 0;
}