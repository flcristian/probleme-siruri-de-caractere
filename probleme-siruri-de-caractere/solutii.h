#include "functii.h"

// Problema 1
// Parametrii s și id permit accesul la câte un șir de maximum 50 de caractere, 
// s memorând, separate printr-un singur spațiu, prenumele și numele unei persoane, 
// fiecare fiind format numai din litere ale alfabetului englez. Funcția va memora 
// în id numele persoanei menționate, urmat de 2022.

void problema1() {
	char s[50] = "";
	cout << "Introduceti sirul :\n";
	cin.getline(s, 50);
	char id[50] = "";
	FNume(s, id);
	cout << id << endl;
}

// Problema 2
// Se dă un șir de caractere. Să se determine câte vocale din șir sunt cuprinse între două consoane.

void problema2() {
	char s[255] = "";
	cout << "Introduceti sirul :\n";
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
	cout << "Introduceti sirul :\n";
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
	cout << "Introduceti propozitia :\n";
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

// Problema 6
// Se consideră un cuvânt format din cel puțin două și cel mult 100 de caractere, 
// numai litere mici ale alfabetului englez.
// Scrieţi un program care citeşte de la tastatură un cuvânt de tipul precizat și 
// afișează pe ecran mesajul DA în cazul în care cuvântul conține doar consoane şi, 
// eventual, vocala i, sau mesajul NU în caz contrar.

void problema6() {
	char cuvant[200] = "";
	cout << "Introduceti cuvantul :\n";
	cin.getline(cuvant, 200);

	if (contineDoarConsoaneSauI(cuvant)) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}
	
}

// Problema 7
// Se consideră un text cu cel mult 100 de caractere, în care cuvintele sunt formate numai 
// din litere mari și mici ale alfabetului englez și sunt separate prin câte un spațiu. 
// Textul reprezintă numele unei instituții sau al unei organizații.
// Scrieți un program care citește de la tastatură un text de tipul precizat și construiește în 
// memorie, apoi afișează pe ecran, un șir de caractere ce reprezintă acronimul corespunzător 
// numelui citit. Acronimul este format din primul caracter al fiecărui cuvânt al numelui care 
// începe cu majusculă.

void problema7() {
	char s[100] = "";
	cout << "Introduceti sirul :\n";
	cin.getline(s, 100);

	char acronim[100] = "";
	formareAcronim(s, acronim);
	cout << acronim;
}