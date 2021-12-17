#include "vart_ivedimas.h"


void clearInput() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
//tikrinam, ar tai sveikasis skaicius intervale [1;10], del idomumo naudoju REGEX
void tikrinam_regex(int& x) {
	string input;
	regex integer("^([1-9]|1[0])$");
	while (true)
	{
		cin >> input;
		if (regex_match(input, integer))
			break;
		else
		{
			cout << "Ivestis klaidinga! Pabandykite is naujo " << endl;
			clearInput();
		}
	}
	x = std::stoi(input);
}

void pats_ivesiu(int stud_kiek, vector<Studentas>& vgrupe, list<Studentas>& lgrupe)
{
	//uzklausa, ar generuoti pazymius automatiskai, ar pats vartotojas ives
	char gen;
	while (true)
	{
		cout << "Jei norite, kad programa sugeneruotu pazymius bei egzamino rez automatiskai, parasykite 'a', jei ivesite pats- 'p' ";
		cin >> gen;
		if (gen == 'a' || gen == 'p') {
			break;
		}
		else {
			cout << "Ivestis klaidinga, bandykite is naujo " << endl;
			clearInput();
		}
	}
	vgrupe.reserve(stud_kiek);
	for (int i = 0; i < stud_kiek; i++)
	{
		Studentas temp(gen);
		vgrupe.push_back(temp);
		lgrupe.push_back(temp);
	}
}