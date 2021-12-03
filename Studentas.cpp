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
	int k;
	ifs >> vard >> pavard;
	for (int i = 0; i < paz_sk; i++)
	{
		ifs >> k;
		nd.push_back(k);
	}
	ifs >> egz;
	skaiciavimai();
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

void Studentas::pildyti(char gen) {
	cout << "Iveskite studento varda ir pavarde: ";
	cin >> vard >> pavard;
	int x;
	if (gen == 'a')
	{
		cout << "Iveskite, kiek pazymiu norite sugeneruoti (egzamino pazymys taip pat bus sugeneruotas automatiskai): ";
		while (!(cin >> x))
		{
			cout << "Blogai ivedete, bandykite is naujo ";
			clearInput();
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
		regex integer("^([1-9]|1[0])$");
		while (true)
		{
			cin >> input;
			if (input == "q")
				break;
			if (regex_match(input, integer))
			{
				nd.push_back(std::stoi(input));
			}
			else
			{
				cout << "Ivestis klaidinga! Pabandykite is naujo " << endl;
				clearInput();
			}
		}
		clearInput();
		cout << "Iveskite egzamino pazymi: " << endl;
		tikrinam_regex(egz);
		clearInput();
	}

}
