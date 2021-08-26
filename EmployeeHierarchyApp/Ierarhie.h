#pragma once
#include <fstream>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#pragma warning(disable : 4996)
using namespace std;


class Angajati {
public:
	string nume, functie, departament;
	unsigned int salariu;
public:
	Angajati() {
		this->nume = "";
		this->functie = "";
		this->departament = "";
		this->salariu = 0;

	}
	Angajati(const string nume, const string functie, const string departament, unsigned int salariu) {
		this->nume = nume;
		this->functie = functie;
		this->departament = departament;
		this->salariu = salariu;

	}
	Angajati(const Angajati&) {
		this->nume = nume;
		this->functie = functie;
		this->departament = departament;
		this->salariu = salariu;


	}

	double getSalariu()
	{
		return salariu;
	}
	void setSalariu(int s) {
		salariu = s;
	}
};

class Muncitori :public Angajati {
public:
	Muncitori() :Angajati() {
	}

	Muncitori(const string nume, const string functie, const string departament, unsigned int salariu) :Angajati(nume, functie, departament, salariu) {

	}
	bool Superior(const Muncitori&, string t);


	friend ostream& operator<<(ostream&, const Muncitori&);
	friend istream& operator>>(istream&, Muncitori&);
};

class Lideri {

public: unsigned int nr = 0;
	  string lista[10];

	  Lideri() {
		  unsigned int nr = 5;
		  for (int i = 0; i < this->nr; i++)
			  this->lista[i] = "";

	  }
	  Lideri(string lista[10], unsigned int nr) {
		  this->nr = nr;
		  for (int i = 0; i < nr; i++)
			  this->lista[i] = lista[i];

	  }

	  friend ostream& operator<<(ostream&, const Lideri&);
	  friend istream& operator>>(istream&, Lideri&);
};

class Manageri :public Angajati, public Lideri {

public:

	Manageri() :Angajati(), Lideri() {

	}
	Manageri(const string nume, const string functie, const string departament, unsigned int salariu, string lista[10], unsigned int nr) :Angajati(nume, functie, departament, salariu), Lideri(lista, nr) {

	}

	double getsalariu() { cout << Angajati::salariu; }

	string func() { return functie; }
	void input(Manageri&);
	int bonus() { return salariu * 0.1; }

	friend ostream& operator<<(ostream&, const Manageri&);
	friend istream& operator>>(istream&, Manageri&);
};



class SefDepart :public Manageri {
public:
	SefDepart() :Manageri() {}
	SefDepart(const string nume, const string functie, const string departament, unsigned int salariu, string lista[10], unsigned int nr) :Manageri(nume, functie, departament, salariu, lista, nr) {

	}
	int bonus() { return salariu * 0.2; }
	SefDepart& operator =(const SefDepart&);
	SefDepart& operator =(const Manageri&);
	friend ostream& operator<<(ostream&, const SefDepart&);
	friend istream& operator>>(istream&, SefDepart&);
};