#pragma once
#include "Studentas.h"

extern std::ifstream f;
extern vector<Studentas> vnesimoke2;
extern list<Studentas> lnesimoke2;

void generavimas(int K);
int words_in_a_string(char* str);
//void skaitymas(studentas& kint, int paz_sk);
//void skaiciavimai(studentas& kint);
int lis_failo(list<Studentas>& grupe);
int vis_failo(vector<Studentas>& grupe);
void ldalinimas(char uzk, list<Studentas>& grupe, list<Studentas>& moksliukai, list<Studentas>& nesimoke);
void vdalinimas(char uzk, vector<Studentas>& grupe, vector<Studentas>& moksliukai, vector<Studentas>& nesimoke);
void ldalinimas2(char uzk, list<Studentas>& grupe);
void vdalinimas2(char uzk, vector<Studentas>& grupe);
void lisvedimas_i_faila(char uzk, string falo_vardas, list<Studentas>& studentai);
void visvedimas_i_faila(char uzk, string falo_vardas, vector<Studentas>& studentai);


