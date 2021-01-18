#include <stack>
#include <iostream>
#include <vector>


using namespace std;


void displayQueens(vector<std::vector<int> > loc, int N) {        //create a function to display the queens (take in parameter:vector<std::vector<int> > loc, int N)
    for (int i = 0; i < N; i++) {                                   // for loop set i = 0, i less than n, increment
        for (int y = 0; y < N; y++) {                              //set x=0, same thing here
            cout << loc[i][y]<<" ";                               //outputs the position of queens into columns and rows
        }
        cout << endl;                                             //allows construction of multiple rows and columns
    }
}

vector<vector<int> > loc;

bool NQueen(int Row,int Column, int N, vector<std::vector<int> > loc) {         //boolean function of N queen. Takes in parameter ("int Row,int Column, int N, vector<std::vector<int> > loc)
    for (int i = 0; i < N; i++) {                                                   //for loop for i and x.
        for (int y = 0; y < N; y++) {
            if (loc[i][y] == 1) {                                                     //sets i and y to 1
                if (Row == i && Column == y) {                                        // column = y, row = i
                }
                else if (Column == y) {
                    return false;                                              //if and else if statements
                }
                else if (abs(Column - y) == 1 && abs(Row - i ) == 1) {       //use absolute value
                    return false;
                }
                else if (abs(Column - y) == abs(Row - i)) {
                    return false;
                }
            }
        }
    }

    return true;
}



bool Shift(int Column, int N) {         //boolean shift function
    if (Column <= N)                     //if column is less than or equal to n
        return true;
    return false;
}

int main(int argc, char** argv) {           //main function
    struct global {
        int row;
        int col;
        global(int Row, int Col) : row(Row), col(Col) {}
    };
    stack < struct global > queenStack;

    int Row, Column, full;                   //set bool (position) and backtrack to true
    bool position = true,
            backtrack = true;

    const int N = 6;           //this allows you to set how many queens you want.

    vector<std::vector<int> > loc(N, std::vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int y = 0; y < N; y++) {
            loc[i][y] = 0;                   //for loop
        }
    }

    loc[0][0] = 1;
    Row = 0;
    Column = 0;                   //set to 0
    full = 0;
    queenStack.push(global(Row, Column));       //push

    while (position) {
        if (NQueen(Row,Column,N,loc) && backtrack) {
            full++;
            if (full == N) {
                position = false;
            }
            else {
                Row++;
                Column = 0;
                loc[Row][Column] = 1;
                queenStack.push(global(Row, Column));

            }
        }
        else if (Shift(Column+1,N-1)) {       //this is where the queens shift based on thier position

            loc[Row][Column] = 0;             //resets and pops
            queenStack.pop();
            //sets the queen and pushes
            Column++;
            loc[Row][Column] = 1;
            queenStack.push(global(Row, Column));
            backtrack = true;

        }
        else {
            full--;
            loc[Row][Column] = 0;        //pop
            queenStack.pop();
            Row = queenStack.top().row;
            Column = queenStack.top().col;
            backtrack = false;

        }
    }

    cout << "Printed N-Queens in Position:" << endl;      //display queens correctly
    displayQueens(loc, N);
    return 0;
}