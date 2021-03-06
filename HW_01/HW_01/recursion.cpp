#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

// Returns the product of two positive integers, m and n,
// using only repeated addition.
int mult(unsigned int m, unsigned int n)
{
	if (n == 1) return m;
	return m + mult(m, n - 1);
}

// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
//
// Pseudocode Example:
//    countDigit(18838, 8) => 3
//    countDigit(55555, 3) => 0
//    countDigit(0, 0)     => 0
//
int countDigit(int num, int digit)
{

	if (num / 10 == 0 && num != digit)   return 0;

	if (num / 10 == 0 && num == digit)   return 1;

	if (num % 10 == digit)               return 1 + countDigit(num / 10, digit);
	else							     return countDigit(num / 10, digit);

}

// Returns a string where the same characters next each other in
// string n are separated by "++"
//
// Pseudocode Example:
//    pairPlus("goodbye") => "go++odbye"
//    pairPlus("yyuu")    => "y++yu++u"
//    pairPlus("aaaa")    => "a++a++a++a"
//
string pairPlus(string n)
{
    string s = "++"; //It's so strange that the compiler does not count n[0] as a string. So I make "++" to a string
	if (n.size() == 1) return n;
    if (n[0] ==pairPlus(n.substr(1))[0]) return n[0] + s + pairPlus(n.substr(1));
    return n[0] + pairPlus(n.substr(1));
}

// str contains a single pair of parenthesis, return a new string
// made of only the parenthesis and whatever those parensthesis
// contain.
//
//  Pseudocode Example:
//     subParen("abc(ghj)789") => "(ghj)"
//     subParen("(x)7")        => "(x)"
//     subParen("4agh(y)")     => "(y)"
//
string subParen(string str)
{
    if (str[0] == '(' && str[str.length()-1] == ')') return str;
    
    //if (str[0] != '(' && str[0] != ')') return subParen(str.substr(1,str.length()-2));
    
    if (str[0] == '(') return subParen(str.substr(0,str.length()-1));
    
    else if (str[str.length()-1] == ')') return subParen(str.substr(1));
    
    else return subParen(str.substr(1,str.length()-2));

}

// Return true if the sum of any combination of elements in the array
// a equals the value of the target.
//
//  Pseudocode Example:
//     sumCombination([2, 4, 8], 3, 10) => true
//     sumCombination([2, 4, 8], 3, 12) => true
//     sumCombination([2, 4, 8], 3, 11) => false
//     sumCombination([], 0, 0)         => true
//
bool sumCombination(const int a[], int size, int target)
{
    int n = a[0];
    //if (target == 0)
        //return true;
    if (n == target)
        return true;
    if (size == 1 && n != target)
        return false;
    return (sumCombination(a+1,size-1,target) || sumCombination(a+1, size-1, target - n));
        //return true;
    
}



/*If the start location is equal to the ending location, then we've
solved the maze, so return true.
Mark the start location as visted.
For each of the four directions,
    If the location one step in that direction (from the start
        location) is unvisited,
            then call pathExists starting from that location (and
                        ending at the same ending location as in the
                        current call).
                If that returned true,
                    then return true.
Return false.*/





bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
    if ( sr == er && sc == ec) {
        return true;
    }
   
    maze[sr][sc] = 'Y';
    
    if (maze[sr+1][sc] == '.' && sr+1 <= nRows && pathExists(maze, nRows, nCols, sr+1, sc, er, ec)) {
        return true;//pathExists(maze, nRows, nCols, sr+1, sc, er, ec);
    }
    if (maze[sr-1][sc] == '.' && sr-1 >= 0 && pathExists(maze, nRows, nCols, sr-1, sc, er, ec)) {
        return true;//pathExists(maze, nRows, nCols, sr-1, sc, er, ec);
    }
    if (maze[sr][sc+1] == '.' && sc+1 <= nCols && pathExists(maze, nRows, nCols, sr, sc+1, er, ec)) {
        return true;//pathExists(maze, nRows, nCols, sr, sc+1, er, ec);
    }
    if (maze[sr][sc-1] == '.' && sc-1 >=0 && pathExists(maze, nRows, nCols, sr, sc-1, er, ec)) {
        return true; //pathExists(maze, nRows, nCols, sr, sc-1, er, ec);
    }
    else
        maze[sr][sc] = '.';
    return false;
    
}




int main() {
    
    int a[] = {2,8,6,4,100,99,98,3,6,7,8,9,10};
    
    cout << sumCombination(a,13,11) << endl;
    
    
    
}









/*int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X.......@X",
        "XX@X@@.XXX",
        "X..X.X...X",
        "X..X...@.X",
        "X....XXX.X",
        "X@X....XXX",
        "X..XX.XX.X",
        "X...X....X",
        "XXXXXXXXXX"
    };
    
    if (pathExists(maze, 10,10, 6,4, 1,1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}*/

