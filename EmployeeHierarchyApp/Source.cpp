#include "Ierarhie.h"

ostream& operator<<(ostream& out, const Manageri& s) {
	out << s.Angajati::nume << " (" << s.Angajati::functie << ")" << endl << "Departament: " << s.Angajati::departament << " (salariu: " << s.Angajati::salariu << ")" << endl;
	out << "Subordonati: ";
	for (int i = 0; i < s.nr; i++)
		out << s.lista[i] << " ";
	out << endl;
	return out;
}
ostream& operator<<(ostream& out, const Muncitori& s) {
	out << s.nume << " (" << s.functie << ") " << endl << "Departament: " << s.departament << " (salariu: " << s.salariu << ")" << endl;
	return out;
}
istream& operator >>(istream& in, Muncitori& s)
{
	in >> s.nume >> s.functie >> s.departament >> s.salariu;
	return in;
}
istream& operator >>(istream& in, Manageri& s)
{

	in >> s.nume >> s.functie >> s.departament >> s.salariu;
	in >> s.nr;

	for (int i = 0; i < s.nr; i++)
		in >> s.lista[i];
	return in;
}
ostream& operator<<(ostream& out, const SefDepart& s) {
	out << s.nume << " (" << s.functie << ")" << endl << "Departament: " << s.departament << " (salariu: " << s.salariu << ")" << endl;

	out << "Subordonati: ";
	for (int i = 0; i < s.nr; i++)
		out << s.lista[i] << " ";
	out << endl;
	return out;
}
istream& operator >>(istream& in, SefDepart& s)
{

	in >> s.nume >> s.functie >> s.departament >> s.salariu;
	in >> s.nr;
	for (int i = 0; i < s.nr; i++)
		in >> s.lista[i];
	return in;
}
bool Muncitori::Superior(const Muncitori& mun, string t)
{
	if (mun.nume == t)
	{
		return true;
	}
	return false;
}
SefDepart& SefDepart::operator=(const SefDepart& f) {
	if (this != &f) {
		this->nume = f.nume;
		this->functie = f.functie;
		this->departament = f.departament;
		this->salariu = f.salariu;
		this->nr = f.nr;
		for (int i = 0; i < f.nr; i++)
			this->lista[i] = f.lista[i];
	}
	return *this;
}
SefDepart& SefDepart::operator=(const Manageri& f) {
	if (this != &f) {
		this->nume = f.nume;
		this->functie = f.functie;
		this->departament = f.departament;
		this->salariu = f.salariu;
		this->nr = f.nr;
		for (int i = 0; i < f.nr; i++)
			this->lista[i] = f.lista[i];
	}
	return *this;
}
int main()
{
	ifstream f("muncitori.txt");
	ifstream g("manageri.txt");

	Manageri manag[20];
	Muncitori munc[20];
	SefDepart sefi[5];
	Angajati h;
	int i = 0, j = 0;
	unsigned int p = 0;
	while (!f.eof())
	{
		f >> munc[i++];
	}

	while (!g.eof())
	{
		g >> manag[j++];
		if (manag[j - 1].func() == "sef-departament")
		{
			sefi[p] = manag[j - 1];

			j--;
			p++;
		}
	}

	string angajat;
	string muncit;
	int salariu;
	int s = 0;
	cout << endl;
	int nr = 0, nr2 = 0;
	do
	{

		cout << "Alegeti functia" << endl;
		cout << "1.afisarea informatiilor despre toti angajatii" << endl;
		cout << "2.total cheltuieli cu salariile" << endl;
		cout << "3.introducerea unui nou angajat (angajarea unei persoane in firma)" << endl;
		cout << "4.modificarea salariului unui angajat" << endl;
		cout << "5.inchidere" << endl;
		cout << endl;
		cin >> nr;
		switch (nr)
		{
		case 1:
			for (int k = 0; k < i; k++)
				cout << munc[k] << endl;
			for (int k = 0; k < j; k++)
				cout << manag[k] << endl;
			for (int k = 0; k < p; k++)
				cout << sefi[k] << endl;
			break;
		case 2:s = 0;
			for (int k = 0; k < i; k++)
				s += munc[k].getSalariu();
			for (int k = 0; k < j; k++)
				s += manag[k].getSalariu();
			for (int k = 0; k < p; k++)
				s += sefi[k].getSalariu();
			cout << "S= " << s << endl;

			break;
		case 3:

			cout << "Functia dorita pentru noul angajat? (1.Muncitor/2.Manager) ";
			cin >> nr2;
			switch (nr2)
			{
			case 1:
				cin >> munc[i++];


				break;
			case 2:
				cin >> manag[j++];
				if (manag[j - 1].func() == "sef-departament")
				{
					sefi[p] = manag[j - 1];

					j--;
					p++;
				}
				break;
			}


			break;
		case 4:

			cout << "Numele angajatului ";
			cin >> angajat;
			cout << "Salariul: ";
			cin >> salariu;
			for (int k = 0; k < i; k++)
				if (angajat == munc[k].nume)
				{
					munc[k].setSalariu(salariu);
				}
			for (int k = 0; k < j; k++)
				if (angajat == manag[k].nume)
				{
					manag[k].setSalariu(salariu);
				}
			for (int k = 0; k < i; k++)
				if (angajat == sefi[k].nume)
				{
					sefi[k].setSalariu(salariu);
				}
			break;

			break;

		case 6:
			cout << "Numele muncitorului ";
			cin >> muncit;
			for (int k = 0; k < i; k++)
			{
				if (muncit == munc[k].nume)
				{
					for (int k2 = 0; k2 < j; k2++)
						for (int k3 = 0; k3 < manag[k2].nr; k3++)
							if (munc[k].Superior(munc[k], manag[k2].lista[k3]))
								cout << "Superiorul este " << manag[k2].nume << endl;
				}
			}
			cout << endl;
			break;
		}

	} while (nr != 5);





	return 0;
}