#define _CRT_SECURE_NO_WARNINGS
#ifndef _STR_H
#define _STR_H
#include <iostream>
#include <string.h>

using namespace std;


class Str
{
	//C'tors & D'tor
public:
	Str();
	Str(const Str& other);
	Str(const char* str);
	~Str();

	//Metods - Operators
public:
	bool		operator==(const Str& other) const;
	bool		operator!=(const Str& other) const;
	bool		operator>(const Str& other) const;
	bool		operator<(const Str& other) const;
	const Str&  operator=(const Str& other);
	const Str&  operator=(const char* str);
	char&       operator[](int index) const;
	const Str&  operator++();
	Str			operator++(int);
	int		    operator()(char ch) const;
	Str		    operator+(const Str& other) const;
	const Str& operator+=(const Str& other);

	//Cast Operators
public:
	operator int() const;

	//Friend Operators
public:
	friend Str operator+(const char* str, const Str& other);
	friend Str operator*(int num, const Str& other);

public:
	const char* getStr() const { return m_str; }
	//Data Members 
private:
	char* m_str;
};

#endif // _STR_H

