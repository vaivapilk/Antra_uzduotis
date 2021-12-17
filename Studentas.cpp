#include <algorithm>
#include <numeric>
#include "Studentas.h"
#include "vart_ivedimas.h"

Studentas::Studentas(char gen)
{
	pildyti(gen);
	skaiciavimai();
}

Studentas::Studentas(std::ifstream& ifs, int paz_sk)
{
	string _vard, _pavard;
	int k;
	ifs >> _vard >> _pavard;
	vard = new string(_vard);
	pavard = new string(_pavard);
	for (int i = 0; i < paz_sk; i++)
	{
		ifs >> k;
		nd.push_back(k);
	}
	ifs >> egz;
	skaiciavimai();
}

Studentas::Studentas(string vardas, string pavarde, vector<int>namudarbai, int egzaminas)
{
	vard = new string(vardas);
	pavard = new string(pavarde);
	nd = namudarbai;
	egz = egzaminas;
}

Studentas::Studentas(const Studentas & x)
{
	vard = new string(x.vardas());
	pavard = new string(x.pavarde());
	nd = x.namdarb();
	egz = x.egzaminas();
	gal_m = x.galutinis_m();
	gal_v = x.galutinis_v();
}

void Studentas::skaiciavimai()
{
	float vid = 0, med = 0;
	vid = std::accumulate(nd.begin(), nd.end(), 0.0) / nd.size();
	gal_v = vid * 0.4 + egz * 0.6;
	//medianos skaiciavimas
	typedef vector<int>::size_type int_vecSize;
	int_vecSize int_size = nd.size();
	sort(nd.begin(),nd.end());
	int_vecSize vidu = int_size / 2;
	if (int_size % 2 != 0)
		med = nd[vidu];
	else
		med = (nd[vidu] + nd[vidu - 1]) / 2.0;
	gal_m = med * 0.4 + egz * 0.6;
}

Studentas::~Studentas()
{
	delete vard; 
	delete pavard;
}

Studentas & Studentas::operator=(const Studentas & x)
{
	delete vard;
	delete pavard;
	vard = new string(x.vardas());
	pavard = new string(x.pavarde());
	nd = x.namdarb();
	egz = x.egzaminas();
	gal_m = x.galutinis_m();
	gal_v = x.galutinis_v();
	return *this;
}

Studentas & Studentas::operator+=(const Studentas & x)
{
	if ((x.vardas() == *vard) && (x.pavarde() == *pavard))
	{
		//nd.insert(nd.end(),x.namdarb().begin(), x.namdarb().end());
		int size = x.namdarb().size();
		for (int i = 0; i < size; ++i) {
			nd.push_back(x.namdarb()[i]);
		}
	}
	return *this;
}



void Studentas::pildyti(char gen) {
	string _vard, _pavard;
	cout << "Iveskite studento varda ir pavarde: ";
	cin >> _vard >> _pavard;
	vard = new string(_vard);
	pavard = new string(_pavard);
	int x;
	if (gen == 'a')
	{
		cout << "Iveskite, kiek pazymiu norite sugeneruoti (egzamino pazymys taip pat bus sugeneruotas automatiskai): ";
		while (!(cin >> x))
		{
			cout << "Blogai ivedete, bandykite is naujo ";
//			clearInput();
		}
		//random pazymiu generavimas
		int R = rand() % 10 + 1;
		for (int i = 0; i < x; i++)
		{
			nd.push_back(R);
			R = rand() % 10 + 1;
		}
		egz = R;
	}
	if (gen == 'p')
	{
		//pazymiu ivedimas, kai dar nenuspresta, kiek pazymiu bus
		cout << "Iveskite pazymius, kai nuspresite, kad jau ivedete visus (iki 10 pazymiu), parasykite 'q' ir spauskite enter " << endl;
		string input;
		//regex integer("^([1-9]|1[0])$");
		while (true)
		{
			cin >> input;
			if (input == "q")
				break;
			//if (regex_match(input, integer))
			//{
				nd.push_back(std::stoi(input));
			//}
			//else
			//{
			//	cout << "Ivestis klaidinga! Pabandykite is naujo " << endl;
			//	clearInput();
			//}
		}
		//clearInput();
		cout << "Iveskite egzamino pazymi: " << endl;
		cin >> egz;
		//tikrinam_regex(egz);
		//clearInput();
	}

}

std::ostream & operator<<(std::ostream & os, const Studentas & st)
{
	os << std::setw(15) << std::left << st.pavarde() << std::setw(15) << st.vardas();
	for (int pz : st.namdarb())
		os << std::setw(5) << pz;
	return os;
}
