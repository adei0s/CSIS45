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
struct Segment {
    
    Segment* next;
    
    int x;
    int y;
 
};

void move(char dir, Segment& head, int row_size, int col_size) {
    if (dir == 'w') {

    // wrap around when touching edge
        head.x =  ((head.x - 1 + (row_size)) % (row_size));            
    }

    else if (dir == 'a') {
        head.y =  ((head.y - 2 + (col_size)) % (col_size));   
    }

    else if (dir == 's') {
        head.x =  ((head.x + 1) % (row_size));           
    }

    else if (dir == 'd') {
        head.y =  ((head.y + 2) % (col_size));
    }

    else {
        cout << ">> Invalid entry, Try again. " << endl;
    }
}



int main() {

    // canvas size
    string space = " ";
    int row_size = 4;
    int col_size = 10;

    // player input
    char dir;

    Segment head;
    head.x = 2;
    head.y = 3;
    

    // create grid
    vector<vector<string>> grid (row_size, vector<string> (col_size, space));
    grid[head.x][head.y] = "■";

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

        grid[head.x][head.y] = " ";

        move(dir, head, row_size, col_size);

        grid[head.x][head.y] = "■";

        print(grid, row_size, col_size); 

        cout << ">> move: ";
        cin >> dir;
        cout << endl;
    }
    return 0;
}