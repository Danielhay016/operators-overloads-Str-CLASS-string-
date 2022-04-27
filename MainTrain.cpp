#define _CRT_SECURE_NO_WARNINGS
#include "Str.h"
#include <iostream>
#include <string.h>

using namespace std;
int main()
{
	//1
	Str s1;
	if (0 != strcmp(s1.getStr(), "none"))
		cout << "Error creating empty Str (-5)" << endl;

	//4
	const char* tmp = "test str";
	Str s4(tmp);
	if (s4.getStr() == tmp)
		cout << "Error creating Str from char* (-5)" << endl;

	if (0 != strcmp(s4.getStr(), tmp))
		cout << "Error creating Str from char* (-5)" << endl;

	//3
	Str s3(s4);
	if (s3.getStr() == s4.getStr())
		cout << "Error creating Str from Str (-5)" << endl;

	if (0 != strcmp(s3.getStr(), s4.getStr()))
		cout << "Error creating Str from Str (-5)" << endl;

	//5
	if (s3 == s1)
		cout << "Error in operator== (-5)" << endl;
	
	//6
	if( s3 != s4 )
		cout << "Error in operator!= (-5)" << endl;

	//7
	if( s3 < s1 )
		cout << "Error in operator< (-5)" << endl;

	//8
	if( s1 > s3 )
		cout << "Error in operator> (-5)" << endl;

	//9
	s4 = s1;
	if( s1.getStr() == s4.getStr() )
		cout << "Error in operator= (-5)" << endl;

	if( 0 != strcmp( s1.getStr(), s4.getStr() ) )
		cout << "Error in operator= (-5)" << endl;

	//10
	const char* tmp2 = "test str2";
	s4 = tmp2;
	if( s4.getStr() == tmp2 )
		cout << "Error in operator= (-5)" << endl;

	if( 0 != strcmp( s4.getStr(), tmp2 ) )
		cout << "Error in operator= (-5)" << endl;

	//11
	if( s4[2] != 's' )
		cout << "Error in operator[] (-5)" << endl;

	//12
	++s4;
	if( s4[2] != 't' )
		cout << "Error in operator++ (-5)" << endl;

	//13
	if( s4++[2] != 't' )
		cout << "Error in operator++(int) (-5)" << endl;
	
	if( s4[2] != 'u' )
		cout << "Error in operator++(int) (-5)" << endl;
	
	//14
	if( int( s1 ) != 4 )
		cout << "Error in operator int (cast) (-5)" << endl;
	
	//15
	if( s1( 'n' ) != 0 )
		cout << "Error in operator() (-5)" << endl;
	
	//16
	s1 = s1 + s3;
	if( 0 != strcmp( s1.getStr(), "nonetest str" ) )
		cout << "Error in operator+(Str) (-5)" << endl;

	//17
	s3 = "this is " + s3;
	if( 0 != strcmp( s3.getStr(), "this is test str" ) )
		cout << "Error in operator+(Str) (-5)" << endl;

	//18
	Str s5( "boom" );
	Str s6 = 3 * s5;
	if( 0 != strcmp( s6.getStr(), "boomboomboom" ) )
		cout << "Error in operator* (-5)" << endl;
	
	//19
	s3 += s5;
	if( 0 != strcmp( s3.getStr(), "this is test strboom" ) )
		cout << "Error in operator+= (-5)" << endl;
		
	cout << "done" << endl;
	
	return 0;
	
}