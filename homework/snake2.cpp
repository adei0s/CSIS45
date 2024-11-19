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

struct snake {
    int x;
    int y; 
};


int main() {

    // canvas size
    string space = " ";
    int row_size = 4;
    int col_size = 10;

    // player input
    char move;

    // init 1st snake segment
    snake seg1;
    seg1.x = 2;
    seg1.y = 3;

    // create grid
    vector<vector<string>> grid (row_size, vector<string> (col_size, space));
    grid[seg1.x][seg1.y] = "■";

    // first player input
    cout << ">> Use 'w' 'a' 's' 'd' to move, 'e' to exit" << endl;
    print(grid, row_size, col_size);
    cout << ">> move: ";
    cin >> move;

    while (true) {

        cout << ">> Use 'w' 'a' 's' 'd' to move, 'e' to exit" << endl;
 
        grid[seg1.x][seg1.y] = space; 

        if (move == 'w') {

            // wrap around when touching edge
            seg1.x =  ((seg1.x - 1 + (row_size)) % (row_size));            
        }

        else if (move == 'a') {

            seg1.y =  ((seg1.y - 2 + (col_size)) % (col_size));   
        }

        else if (move == 's') {
            
            seg1.x =  ((seg1.x + 1) % (row_size));           
        }

        else if (move == 'd') {

            seg1.y =  ((seg1.y + 2) % (col_size));
        }

        else if (move == 'e') {
            cout << "Thanks for playing!" << endl << endl;
            break;
        }
        
        else {
            cout << ">> Invalid entry, Try again. " << endl;
        }

        grid[seg1.x][seg1.y] = "■";

        print(grid, row_size, col_size); 

        cout << ">> move: ";
        cin >> move;
        cout << endl;
    }
    return 0;
}