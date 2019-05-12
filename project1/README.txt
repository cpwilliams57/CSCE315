Instructions for compilation and execution of program 

1) Navigate to directory containing "project1.cpp"

2) Compile using command "g++-7.2.0 -std=c++17 -Wall -Wextra -pedantic -fsanitize=address,undefined project1.cpp"

3) 1. If using UNIX redirection to an input file, execute program using command 
	"./a.out <filename" and press ENTER
  
   2. If execution with keyboard input, type command ./a.out and press ENTER
	then input your data points and type Ctl-D and press ENTER
	 Ex. "0 0 0 1 1 1 1 2 Ctl-D"

4) The program will then execute and complete the traveling salesman problem for the given input