#pragma once
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Asmuo.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;

class Studentas: public Asmuo
{
private:
//	string *vard, *pavard;
	vector <int> nd;
	int egz;
	float gal_v;
	float gal_m;
public:
	Studentas() : Asmuo() {}
	Studentas(char gen);
	Studentas(std::ifstream& ifs, int paz_sk);
	Studentas(const string&, const string&, vector <int>, int);
	//Copy constructor
	Studentas(const Studentas& x);
//	inline string vardas() const { return *vard; }
//	inline string pavarde() const { return *pavard; }
	inline int egzaminas() const { return egz;  }
	inline float galutinis_v() const { return gal_v; }
	inline float galutinis_m() const { return gal_m; }
	inline vector <int> namdarb() const { return nd; }
	//Copy assignment
	Studentas& operator= (const Studentas&);
	//Binary arithmetic operator
	Studentas& operator+=(const Studentas&);
	
	void pildyti(char);
	void skaiciavimai();
	//Destructor
	~Studentas();
};
std::ostream& operator<<(std::ostream& os, const Studentas&);
