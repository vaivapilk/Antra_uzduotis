#pragma once
#include <string>
using std::string;

/// Bazine abstrakti klase.
class Asmuo
{
protected:
	string *vard,		///< Asmens vardas.
		   *pavard;		///< Asmens pavarde.
public:
	
	/// Numatytasis konstruktorius.
	Asmuo() : vard(new string), pavard(new string) {}
	/// Get'er funkcija: grazina asmens varda
	inline string vardas() const { return *vard; }
	/// Get'er funkcija: grazina asmens pavarde
	inline string pavarde() const { return *pavard; }
	/// Virtualus galutinio pazymio apskaiciavimo metodas
	virtual void skaiciavimai() = 0;
};

