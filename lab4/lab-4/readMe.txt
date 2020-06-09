Lab4
Group: Marissa Kalkar, Ian Thakur, Annabel Gillespie
We started by walking each other through our previous tictactoe labs and deciding which implementation to build off of. Once
we determined we would use Marissa's tictactoe, we began working on refactoring. Throughout the process, we always
zoomed with all of our teamates, and worked through the steps by using the split screen/ edit screen feature to make sure 
everyone was able to contribute.

Part II
The main problem we had in part two was figuring out how to rewrite the ostream operator, and figuring out a way to avoid 
having to make a destructor class to delete the pointer we created in play(). To do this, we simply initialized the variable
as a shared pointer. We also had to focus on correctly nesting our headerfiles. After refactoring, we ran similar tests as
we did in Lab 3 to ensure that the tictactoe game was working properly.

Tests:
User types "quit":
4
3
2
1
0
  0 1 2 3 4
Enter a valid coordinate or type quit to end play
quit
game is over. Player quit. Total turns: 0

User types out of bounds coordinate:
 4
 3
 2
 1
 0
   0 1 2 3 4
Enter a valid coordinate or type quit to end play
4,4
the position is not valid
Enter a valid coordinate or type quit to end play

User types incorrect number of arguments:
H:\332 agillespie\cse332s-sp20-wustl\Labs\lab4\lab4-lab4-annabel_marissa\lab-4\x64\Debug>lab-4.exe tictactoe 1
usage: lab-4.exe <input_file_name>


Part III
The biggest problem that we faced in Part III was formating the gomoku board's printout. Since the game 
has some two digit coordinates and one digit coordinates we found that the spacing was off by one space 
for each coordinate (x or y) that was greater than or equal to 10. To fix this, we nested if statements
testing whether x, y, or both were greater than 10, and added/ removed the proper padding for that coordinate.
Warnings:
Signed/Unsigned mismatch

Tests:
Edge cases/out of bounds inputs:
Enter a valid coordinate or type quit to end play
21,21
the position is not valid
Enter a valid coordinate or type quit to end play

(program continuously prompts until valid coordinate is played)

Quit:
Enter a valid coordinate or type quit to end play
quit
game is over. Player quit. Total turns: 0

When a tie is reached: 
No winning moves remain. Total turns played was 15

Extra credit:
To implement the features our Gomoku game that would allow a user to choose the size of the game board and number of pieces
connecting in order to win, we first changed the board initialization from a double array to a double vector
created a new constructor. The would allow us to dynamically allocate the length of the board required. We also made
additional enums named size and in_a_row_user to store the user input for these values, and replaced instances in the code
where we had previously had the board size and connecting pieces constant. We also created two new constructors, one for when 
the user only inputs a new game size, and one for when a user specifies both a new board size and a new number of pieces 
connecting in order to win. Finally, in our "check" method, we made our program accept more than two arguments on the command
line.

Tests run for extra credit:
If second extra argument is greater than first extra argument program defaults to original board play:
H:\332 agillespie\cse332s-sp20-wustl\Labs\lab4\lab4-lab4-annabel_marissa\lab-4\x64\Debug>lab-4.exe gomoku 4 5
19
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2
1
0
X 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
Enter a valid coordinate or type quit to end play

Improper number of arguments given:
H:\332 agillespie\cse332s-sp20-wustl\Labs\lab4\lab4-lab4-annabel_marissa\lab-4\x64\Debug>lab-4.exe 4
usage: lab-4.exe <input_file_name>

Tested edge cases, out of bounds coordinates, and invalid coordinates as in part III

Output from different board size than 3 by 3 and a different connecting pieces value than 3:
H:\332 agillespie\cse332s-sp20-wustl\Labs\lab4\lab4-lab4-annabel_marissa\lab-4\x64\Debug>lab-4.exe gomoku 4 3
4
3
2
1
0
X 0 1 2 3 4
Enter a valid coordinate or type quit to end play
