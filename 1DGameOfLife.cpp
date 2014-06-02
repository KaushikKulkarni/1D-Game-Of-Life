/**
*Now this seems to be an interesting problem .
*But one thing which is troubling me at this moment is the runtime my project is gonna take .
*Well that seems to be OKay as I continue to work with my project .
*Hope it works fine .
*All the very best .
**/

#include<iostream>/**For the basic input output usage .*/
#include<string>/**Working with the strings would be quite difficult without this inclusion .*/
#include<cmath>/**For the power function .*/

using namespace std ;

string input  ;/**A variable to store the input string value .*/
string Solution ; /**This variable will store the correct solution .*/

/**
*Now this funtion will return the next string present in the binary sequence .
**/

string Next(string s)
{
	string Next = "" ;/**This would be the string I would return and the one which could make wonders .*/
	int i ;/**Required aas acounter variable for the looping purpose .*/
	
	for ( i  = 0 ; i < s.length() ; i++ )
	{
		if(s[s.length() - i - 1] == '1' )
		{
			Next =  "0" + Next ;
		}
		else
		{
			Next = "1" + Next ;
			Next = s.substr(0,s.length() - i - 1) + Next ;
			break ;
		}	
	}
	
	return Next ;

}
/** 
* Now defining a function which will give us the manipulated string according to the problem statement i.e. the game of life .
* And  it will return us whether the Manipulated string is equivalent to the input string .
**/
bool ManipulatorCheck(string s)
{
	char c1,c2 ;/**now these two characters are the adjacent of the current charaacter of the intrest .*/
	string Manip = "" ;/**This one is the manipulated string which is to be returned after the process of manipulation .*/
	int i ;/**Now this one would again serve as the coounter variable for the looping purpose .*/
	char c ;/**To store the current character of interest .*/
	int StoreIndex[s.length()] ;/**A variable to store the indices of the characters which are needed to be changed.*/
	int count = 0 ;/**To store the current value of the of the cuurent point where to store the next index whose value is to changed .*/
	for( i =0 ; i < s.length() ; i++ )
	{
		c = s[i] ;
		if( i == 0)
		{
			c1 = s[s.length() -1] ;/**According to the given question it wouls go in a circular type .*/
			c2 = s[1] ;/**Obviously the next character .*/
		}
		else if( i == (s.length() - 1))
		{
			c2 = s[s.length() - 2] ;/**The second last character .*/
			c1 = s[0] ;/**Obviously the first character .*/
		}
		else
		{
			c1 = s[ i - 1] ;
			c2 = s[ i + 1] ;
		}
		if((c1 == '1' && c2 == '0')||(c2 == '1' && c1 == '0'))
		{
			if ( c == '1')
			{
				Manip = Manip + '0' ;
			}
			else
			{
				Manip = Manip + '1' ;
			}
		}
		else
		{
			Manip = Manip + c ;
		}		
	}
	if(Manip == input)
	{
		Solution = s ;
		return true ;
	} 
	return false ;
}
 
int main()
{
	int n ;/** A variable to store the number of test cases .*/
	int  i ;/**To work as  a counter variable for the loop .*/
	string s = "" ;/**A temporary string to work on ..*/
	int count = 0 ;/**This would store the number of solutions .*/
	cout << "First enter the number of test cases .\n" ;
	cin >> n;
	cout << "Now enter the string or whatever you wanna enter .\n" ;
	cin >> input ;
	for(int j =0 ; j < n ; j ++ )
	{
		/**
		*Now initializing the string 's' to "000..."
		**/
		
		for( i = 0 ; i < input.length() ; i++)
		{
			s = s + "0" ;  	
		}
		
		for( i = 0 ; i < (pow(2,s.length())) ; i++  )
		{
			
			if(count == 2)
			{
				cout << "Multiple solutions ." << endl ;
				break ;
			}
			s = Next(s) ;
			if( ManipulatorCheck(s) )
			{
				count ++ ;
			}
		}
		if(count == 0)
		{
			cout << "No solution ." << endl ;
		}
		if(count == 1)
		{
			cout << Solution <<endl;
		}
	}
}
