#include <iostream>
#include <string>
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
	/*if (n.size() <= 0) return n;
	if (n[n.size() - 1] == pairPlus(n)[1]) return n + "++" + pairPlus(n.substr(n.size() - 1));
	return pairPlus(n.resize(n.size()-1));*/

	return n;
	

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
	if (size <= 0 && a[0] == target)	return true;

}


int main() {

	

	cout << pairPlus("goodbye") << endl;


}