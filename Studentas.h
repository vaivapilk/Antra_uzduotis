#pragma once
#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Asmuo.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;

/// Isvestine studento pazymiu klase.
class Studentas: public Asmuo
{
private:
	vector <int> nd;	///< Namu darbu pazymiai.
	int egz;			///< Egzamino pazymys.
	float gal_v;		///< Galutinis pazymys paskaièiutas naudojant namu darbu vidurki.
	float gal_m;		///< Galutinis pazymys paskaièiutas naudojant namu darbu mediana.
public:
	/// Numatytasis konstruktorius.
	Studentas() : Asmuo() {}
	/// Konstruktorius.
	/// <param name="gen"></param>
	Studentas(char gen);
	/// Konstruktorius kuriame studento pazymiai nuskaitomi is duomenu failo.
	/// <param name="ifs">duomenu failo srauto itentifikatorius</param>
	/// <param name="paz_sk">namu darbu pazymiu skaicius</param>
	Studentas(std::ifstream& ifs, int paz_sk);
	/// Konstruktorius su vardo, pavardes ir pazymiu parametrais.
	/// <param name="vardas">studento vardas</param>
	/// <param name="pavarde">studento pavarde</param>
	/// <param name="namudarbai">namu darbu pazymiai</param>
	/// <param name="egzaminas">egzamino pazymys</param>
	Studentas(string vardas, string pavarde, vector<int>namudarbai, int egzaminas);
	/// Kopijavimo konstruktorius.
	Studentas(const Studentas& x);
	/// Get'er funkcija: grazina egzamino pazymi.
	inline int egzaminas() const { return egz;  }
	/// Get'er funkcija: grazina galutini pazymi paskaiciuta naudojant namu darbu vidurki.
	inline float galutinis_v() const { return gal_v; }
	/// Get'er funkcija: grazina galutini pazymi paskaiciuta naudojant namu darbu vidurki.
	inline float galutinis_m() const { return gal_m; }
	/// Get'er funkcija: grazina namu darbu pazymius
	inline vector <int> namdarb() const { return nd; }
	/// Kopijavimo priskirimo operatorius.
	Studentas& operator= (const Studentas&);
	/// Binarinis aritmetinis sumos operatorius.
	Studentas& operator+=(const Studentas&);
	
	void pildyti(char);
	/// Galutinio pazymio apskaiciavimo metodas
	void skaiciavimai();
	///Destrutorius
	~Studentas();
};
std::ostream& operator<<(std::ostream& os, const Studentas&);
