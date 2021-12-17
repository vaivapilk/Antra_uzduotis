#pragma once
#include <string>
using std::string;

class Asmuo
{
protected:
	string *vard, *pavard;
public:
	Asmuo() : vard(new string), pavard(new string) {}
	inline string vardas() const { return *vard; }
	inline string pavarde() const { return *pavard; }

	virtual void skaiciavimai() = 0;
};

