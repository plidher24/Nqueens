Included:
selection.cpp
selection.o
makefile


One error causing malfunction in makefile:
(listed below)
nQueens.cpp:56:13: warning: template argument uses local type 'global' [-Wlocal-type-template-args]
    stack < struct global > queenStack;

Otherwise code runs and displays queens correctly.

For user:
To run the code is sweet and simple. The code I written automatically prints out the queens correctly in
a "board" format. You can see that no queen is diagonal of each other nor is it in the same column/row.
To change the amount of queens you would like go to line number 62.

Here it is written   const int N = 8;
You can set any amount of number you want N (total amount of queens).
There is an error that I could not debug that does not allow less than 4 queens. Anything above 4 allows the user to see
the correct number of queens.