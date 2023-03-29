#include "functii.h"

// Problema 1
// Parametrii s și id permit accesul la câte un șir de maximum 50 de caractere, 
// s memorând, separate printr-un singur spațiu, prenumele și numele unei persoane, 
// fiecare fiind format numai din litere ale alfabetului englez. Funcția va memora 
// în id numele persoanei menționate, urmat de 2022.

void problema1() {
	char s[50] = "";
	cin.getline(s, 50);
	char id[50] = "";
	FNume(s, id);
	cout << id << endl;
}

// Problema 2
// Se dă un șir de caractere. Să se determine câte vocale din șir sunt cuprinse între două consoane.

void problema2() {
	char s[255] = "";
	cin.getline(s, 255);

	int count = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (esteVocala(s[i]) && esteConsoana(s[i - 1]) && esteConsoana(s[i + 1])) {
			count++;
		}
	}
	cout << count << endl;
}

// Problema 3
// Să se scrie un program care citeşte un şir de caractere format din litere mici ale alfabetului 
// englez şi înlocuieşte fiecare vocală cu litera mare corespunzătoare.

void problema3() {
	char s[255] = "";
	cin.getline(s, 255);

	for (int i = 0; i < strlen(s); i++) {
		if (esteVocala(s[i])) {
			s[i] -= 32;
		}
	}

	cout << s << endl;
}

// Problema 4
// Să se scrie un program care citeşte de la tastatură o propoziţie formată 
// din mai multe cuvinte separate prin spaţii şi transformă prima şi ultima 
// literă a fiecărui cuvânt în literă mare.

void problema4() {
	char s[255] = "";
	cin.getline(s, 255);
	char cuvinte[200][200];
	int d;
	split(s, cuvinte, d);

	for (int i = 0; i < d; i++) {
		firstLastLetterUppercase(cuvinte[i]);
		cout << cuvinte[i] << " ";
	}
}

// Problema 5
// Se consideră fișierul prosir.in care conține pe primul rând un text format 
// din cel mult 200 de caractere litere mici și spații. Cuvintele din text sunt 
// separate prin unul sau mai multe spații. Să se modifice textul citit din 
// fișier prin înlocuirea ultimei litere a fiecărui cuvânt cu cifra 5.

void problema5() {
	ifstream f("input.txt");
	char s[200] = "";
	f.getline(s, 200);
	f.close();
	char cuvinte[200][200];
	int d;
	split(s, cuvinte, d);

	for (int i = 0; i < d; i++) {
		lastLetter5(cuvinte[i]);
		cout << cuvinte[i] << " ";
	}
}