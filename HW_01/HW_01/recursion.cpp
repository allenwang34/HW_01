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
	/*if (str[str.size() - 1] == ')') {
		return ;
	}
	return str.erase(str.end() - 1);*/
    return " ";



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
	/*if (size <= 0 && a[0] == target)*/	return true;

}


int main() {

	

    assert(pairPlus("goodbye")=="go++odbye");
    assert(pairPlus("yyuu")=="y++yu++u");
    assert(pairPlus("aaaa")=="a++a++a++a");
    cout << "[!] Tests passed!" << endl;


}
