Interpreter for reverse polish notation written in C.  
Takes input until EOF is detected (Ctrl+D in terminal).  
Any valid combination of integers can be interpreted, the addition operator must be represented with 'p', the subtraction operator must be represented with 's', the multiplication operator must be represented with '\*', and the integer division operator must be represented with '/'.  
Any arbitrary amount of whitespace between numbers and operators can be given, but the expression must be valid, and must not result in a value less than INT_MIN or greater than INT_MAX.  
Division is performed as integer (floor) division.  
The output of the expression is returned once EOF is reached.  
