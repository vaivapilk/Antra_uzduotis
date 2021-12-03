#include "pagalb_funkcijos.h"
//#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

using std::endl;
using std::setw;
using std::left;
using std::setprecision;
using std::fixed;



void generavimas(int K)
{
	std::ostringstream os;
	std::ofstream duomenys("kursiokai_sugeneruoti1.txt");
	int stud_kiek = K;
	int k = 1;
	string s;

	os << setw(17) << left << "Vardas " << setw(19) << "Pavarde " << setw(5) << "ND1" << setw(5) << "ND2" << setw(5) << "ND3" << setw(5) << "ND4" << setw(5) << "ND5"
		<< setw(5) << "ND6" << setw(5) << "ND7" << setw(5) << "ND8" << setw(5) << "ND9" << setw(5) << "ND10" << "Egz";

	duomenys << os.str();
	os.seekp(0);

	for (int i = 0; i < stud_kiek; i++)
	{
		s = std::to_string(k);
		os << endl << setw(17) << left << "Vardas" + s << setw(17) << "Pavarde" + s;
		int x = 11;
		//random pazymiu generavimas
		os << std::right;
		for (int j = 0; j < x; j++)
		{
			int R = rand() % 10 + 1;
			os << setw(5) << R;
		}
		k++;
		duomenys << os.str(); os.seekp(0);
	}
	duomenys.close();
}

int words_in_a_string(char* str)
{
	int count = 0;
	int temp = 0;
	while (*str) {
		if (*str == ' ' || *str == '\n' || *str == '\t') {
			temp = 0;
		}
		else if (temp == 0) {
			temp = 1;
			count++;
		}
		++str;
	}
	return count;
}

int lis_failo(list<Studentas>& grupe)
{
	char str[256];
	f.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {

		f.open("kursiokai_sugeneruoti1.txt");
		f.get(str, 256);
		int paz_sk = words_in_a_string(str) - 3;
		while (!f.eof()) {
			Studentas stud(f, paz_sk);
			grupe.push_back(stud);
			//stud.namdarb().clear();
		}
		f.close();
		f.clear();
	}

	catch (std::ifstream::failure e) {
		std::cout << "Exception opening/reading/closing file\n";
		return 1;
	}

	//rikiavimas
	/*sort(grupe.begin(), grupe.end(), [](studentas a, studentas b)
		{
			if (a.vard == b.vard) return a.pavard < b.pavard;
			else return a.vard < b.vard;
		});*/

	return 0;
}

int vis_failo(vector<Studentas>& vgrupe)
{
	char str[256];
	f.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {

		f.open("kursiokai_sugeneruoti1.txt");
		f.get(str, 256);
		int paz_sk = words_in_a_string(str) - 3;
		while (!f.eof()) {
			Studentas stud(f, paz_sk);
			vgrupe.push_back(stud);
			stud.namdarb().clear();
		}
		f.close();
	}

	catch (std::ifstream::failure e) {
		std::cout << "Exception opening/reading/closing file\n";
		return 1;
	}

	/*sort(vgrupe.begin(), vgrupe.end(), [](studentas a, studentas b)
		{
			if (a.vard == b.vard) return a.pavard < b.pavard;
			else return a.vard < b.vard;
		});*/

	return 0;
}

void ldalinimas(char uzk, list<Studentas>& grupe, list<Studentas>& moksliukai, list<Studentas>& nesimoke)
{
	if (uzk == 'v')
	{
		for (Studentas st : grupe)
		{
			if (st.galutinis_v() < 5)
				nesimoke.push_back(st);
			else
				moksliukai.push_back(st);
		}
	}
	if (uzk == 'm')
	{
		for (Studentas st : grupe)
		{
			if (st.galutinis_m() < 5)
				nesimoke.push_back(st);
			else
				moksliukai.push_back(st);
		}
	}

}

void vdalinimas(char uzk, vector<Studentas>& grupe, vector<Studentas>& moksliukai, vector<Studentas>& nesimoke)
{
	if (uzk == 'v')
	{
		for (Studentas st : grupe)
		{
			if (st.galutinis_v() < 5)
				nesimoke.push_back(st);
			else
				moksliukai.push_back(st);
		}
	}
	if (uzk == 'm')
	{
		for (Studentas st : grupe)
		{
			if (st.galutinis_m() < 5)
				nesimoke.push_back(st);
			else
				moksliukai.push_back(st);
		}
	}

}

void ldalinimas2(char uzk, list<Studentas>& grupe)
{
	if (uzk == 'v')
	{
		grupe.erase(remove_if(begin(grupe), end(grupe), [](const auto& x)
			{
				if (x.galutinis_v() >= 5) return false;
				else
				{
					lnesimoke2.push_back(x);
					return true;
				}
			}), end(grupe));
	}
	if (uzk == 'm')
	{
		auto gend = partition(begin(grupe), end(grupe), [](const auto& x) {return (x.galutinis_m() >= 5) == 1; });
		copy(gend, end(grupe), back_inserter(lnesimoke2));
		grupe.erase(gend, end(grupe));
	}
}

void vdalinimas2(char uzk, vector<Studentas>& vgrupe)
{
	if (uzk == 'v')
	{
		auto gend = partition(begin(vgrupe), end(vgrupe), [](const auto& x) {return (x.galutinis_v() >= 5) == 1; });
		vnesimoke2.resize(end(vgrupe)- gend);
		copy(gend, end(vgrupe), begin(vnesimoke2));
		vgrupe.erase(gend, end(vgrupe));
	}
	if (uzk == 'm')
	{
		auto gend = partition(begin(vgrupe), end(vgrupe), [](const auto& x) {return (x.galutinis_m() >= 5) == 1; });
		vnesimoke2.resize(end(vgrupe) - gend);
		copy(gend, end(vgrupe), begin(vnesimoke2));
		vgrupe.erase(gend, end(vgrupe));
	}
}

void lisvedimas_i_faila(char uzk, string failo_vardas, list<Studentas>& studentai)
{
	std::ofstream d_m(failo_vardas+".txt");
	if (uzk == 'v') {
		d_m << setw(10) << "Galutinis (Vid.) "+ failo_vardas << endl;
	}
	if (uzk == 'm') {
		d_m << setw(10) << "Galutinis (Med.) "+ failo_vardas << endl;
	}

	for (int i = 0; i < 50; i++)
		d_m << "-";
	d_m << endl;

	for (Studentas st : studentai) {
		d_m << setw(17) << left << st.pavarde() << setw(17) << st.vardas();
		if (uzk == 'v') {
			d_m << setw(10) << left << fixed << setprecision(2) << st.galutinis_v() << endl;
		}
		if (uzk == 'm') {
			d_m << setw(10) << left << fixed << setprecision(2) << st.galutinis_m() << endl;
		}
	}
	d_m.close();

}

void visvedimas_i_faila(char uzk, string failo_vardas, vector<Studentas>& studentai)
{
	std::ofstream d_m(failo_vardas + ".txt");
	if (uzk == 'v') {
		d_m << setw(10) << "Galutinis (Vid.) " + failo_vardas << endl;
	}
	if (uzk == 'm') {
		d_m << setw(10) << "Galutinis (Med.) " + failo_vardas << endl;
	}

	for (int i = 0; i < 50; i++)
		d_m << "-";
	d_m << endl;

	for (Studentas st : studentai) {
		d_m << setw(17) << left << st.pavarde() << setw(17) << st.vardas();
		if (uzk == 'v') {
			d_m << setw(10) << left << fixed << setprecision(2) << st.galutinis_v() << endl;
		}
		if (uzk == 'm') {
			d_m << setw(10) << left << fixed << setprecision(2) << st.galutinis_m() << endl;
		}
	}
	d_m.close();

}