#define _CRT_SECURE_NO_WARNINGS
#include "str.h"
#include <iostream>
#include <string.h>

using namespace std;
//Daniel Hay - ID - 209042720


//C'tor && D'tor 

//C'tor -Q1
Str::Str() 
{
	m_str = new char[5];
	strcpy(m_str, "none");
}

//Copy C'tor -Q2
Str::Str(const Str& other)  : m_str(NULL)
{
	*this = other;
}

//C'tor - get string -Q3
Str::Str(const char* str) : m_str(NULL)
{
	*this = str;
}

//D'tor -Q4
Str::~Str()
{
	if(this->m_str != nullptr)
		delete[] m_str;
}

//Metods - Opertors 

//Operator for comparing two strings -Q5
bool Str::operator==(const Str& other) const
{
	bool res = false;
	int x = strcmp(m_str, other.m_str);
	if (x == 0)
	{
		res = true;
	}
	return res;
}

//Operator for comparing two strings -Q6
bool Str::operator!=(const Str& other) const
{
	bool res = false;
	int x = strcmp(m_str, other.m_str);
	if (x != 0)
	{
		res = true;
	}
	return res;
}

//Compares two lexicographic strings -Q7
bool Str::operator>(const Str& other) const
{
	bool res = false;
	int x = strcmp(m_str, other.getStr());
	if (x > 0)
	{
		res = true;
	}
	return res;
}

//Compares two lexicographic strings -Q8
bool Str::operator<(const Str& other) const
{
	bool res = false;
	int x = strcmp(m_str, other.getStr());
	if (x < 0)
	{
		res = true;
	}
	return res;
}

//Object placement operator -Q9
const Str&  Str::operator=(const Str& other)
{
	if (this != &other)
	{
		delete[] m_str;
		m_str = new char[strlen(other.getStr()) + 1];
		strcpy(m_str, other.getStr());
		
	}
	return *this;
}

//String placement operator -Q10
const Str&  Str::operator=(const char* str)
{
	if (this->m_str != str)
	{
		delete[] m_str;
		m_str = new char[strlen(str) + 1];
		strcpy(m_str, str);
	}
	return *this;
}

//Returns the character instead of the index -Q11
char& Str::operator[](int index) const
{
	 return m_str[index];
}

//Askit promotes each character by 1 -Q12
const Str& Str::operator++()
{
	int i = 0;
	
	while (m_str[i] != '\0')
	{
		m_str[i]++;
		i++;
	}
	return *this;
}

//Askit promotes each character by 1 -Q13
Str	Str::operator++(int)
{
	Str temp(*this);
	int i = 0;
	while (m_str[i] != '\0')
	{
		m_str[i]++;
		i++;
	}
	return temp;
	
	
}

//Casting Operator - Returns the length of the string -Q14
Str::operator int() const
{
	int lenght = strlen(m_str);
	return lenght;
}

//Returns the first position of the character ch in a string or (-1) if not found -Q15
int Str::operator()(char ch) const
{
	int size = strlen(m_str);
	for (int i = 0; i < size; i++)
	{
		if (m_str[i] == ch)
		{
			return i;
		}
	}
	return -1;
}

//Threads between strings -Q16
Str Str::operator+(const Str& other) const
{
	Str tmp;
	tmp.m_str = new char[strlen(this->m_str) + strlen(other.m_str) + 1];
	strcpy(tmp.m_str, this->m_str);
	strcat(tmp.m_str, other.m_str);
	return tmp;
}

//Threads between strings - Q19
const Str& Str::operator+=(const Str& other)
{
	*this = *this + other;
	return *this;

}

//Friend Operators

//Global function - Threads between strings -Q17
Str operator+(const char* str, const Str& other)
{
	Str tmp;
	tmp.m_str = new char[strlen(str) + strlen(other.m_str) + 1];
	strcpy(tmp.m_str, str);
	strcat(tmp.m_str, other.m_str);
	return tmp;
	
}

//Global function - Threads the string that gets as a parameter, num times -Q18
Str operator*(int num, const Str& other)
{
	Str tmp("");
	for (int i = 0; i < num; i++)
	{

		tmp = tmp + other;

	}
	return tmp;
}

