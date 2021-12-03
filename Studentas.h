#pragma once
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;

class Studentas
{
private:
	string vard, pavard;
	vector <int> nd;
	int egz;
	float gal_v;
	float gal_m;
public:
	Studentas() : egz(0), gal_v(0.0), gal_m(0.0) {}
	Studentas(char gen);
	Studentas(std::ifstream& ifs, int paz_sk);
	inline string vardas() const { return vard; }
	inline string pavarde() const { return pavard; }
	inline float galutinis_v() const { return gal_v; }
	inline float galutinis_m() const { return gal_m; }
	inline vector <int> namdarb() const { return nd; }
	void pildyti(char gen);
	void skaiciavimai();
};

