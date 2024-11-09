#include<iostream>
#include<vector>
#include<string>
using namespace std;

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


int main() {

    string space = " ";
    int row_size = 4;
    int col_size = 10;
    int snake[] = {2, 3}; 
    char move;

    vector<vector<string>> grid (row_size, vector<string> (col_size, space));
    grid[snake[0]][snake[1]] = "■";

    cout << ">> Use 'w' 'a' 's' 'd' to move, 'e' to exit" << endl;
    print(grid, row_size, col_size);
    cout << ">> move: ";
    cin >> move;

    while (true) {

        cout << ">> Use 'w' 'a' 's' 'd' to move, 'e' to exit" << endl;
 
        grid[snake[0]][snake[1]] = space; 

        if (move == 'w') {

            // wrap around when touching edge
            snake[0] =  ((snake[0] - 1 + (row_size)) % (row_size));            
        }

        else if (move == 'a') {

            snake[1] =  ((snake[1] - 2 + (col_size)) % (col_size));   
        }

        else if (move == 's') {
            
            snake[0] =  ((snake[0] + 1) % (row_size));           
        }

        else if (move == 'd') {

            snake[1] =  ((snake[1] + 2) % (col_size));
        }

        else if (move == 'e') {
            cout << "Thanks for playing!" << endl;
            break;
        }
        
        else {
            cout << ">> Invalid entry, Use 'w' 'a' 's' 'd' to move, 'e' to exit" << endl;
        }

        grid[snake[0]][snake[1]] = "■";

        print(grid, row_size, col_size); 

        cout << ">> move: ";
        cin >> move;
        cout << endl;
    }
    return 0;
}