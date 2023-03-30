#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Bools

bool esteVocala(char a) {
	char v[10] = { 'A','a','E','e','I','i','O','o','U','u' };
	for (int i = 0; i < 10; i++) {
		if (a == v[i]) {
			return 1;
		}
	}
	return 0;
}

bool esteConsoana(char a) {
	if (a == NULL || a == ' ') {
		return 0;
	}
	if (!esteVocala(a)) {
		return 1;
	}
	return 0;
}

bool contineDoarConsoaneSauI(char s[]) {
	char x[8] = { 'A','a','E','e','O','o','U','u' };
	for (int i = 0; i < strlen(s); i++) {
		char c = s[i];
		for (int j = 0; j < 8; j++) {
			if (c == x[j]) {
				return 0;
			}
		}
	}
	return 1;
}

bool estePalindrom(char s[]) {
	char seg1[200] = "", seg2[200] = "";
	int k = strlen(s) / 2;
	strncpy(seg1, s, k);
	if (strlen(s) % 2 == 1) {
		k++;
	}
	strcpy(seg2, s + k);
	for (int i = 0, j = strlen(s) - 1; i < strlen(s) / 2; i++, j--) {
		if (s[i] != s[j]) {
			return 0;
		}
	}
	return 1;
}

// Utility

void split(char s[], char cuvinte[200][200], int& d) {
	char sir[200] = "";
	strcpy(sir, s);
	d = 0;
	char* a;
	a = strtok(sir, " .,;!?");
	while (a != NULL) {
		strcpy(cuvinte[d], a);
		d++;
		a = strtok(NULL, " .,;!?");
	}
}

void formareAcronim(char sir[], char acronim[]) {
	char s[500] = "";
	char r[3] = "";
	strcpy(s, sir);

	char cuvinte[200][200];
	int d;
	split(s, cuvinte, d);

	for (int i = 0; i < d; i++) {
		char litera = cuvinte[i][0];
		if (litera > 64 && litera < 91) {
			r[0] = litera;
			strcat(acronim, r);
		}
	}
}

char vocalaMaxAparitii(char sir[]) {
	char s[200] = "";
	strcpy(s, sir);
	char vocale[10] = { 'A','a','E','e','I','i','O','o','U','u' };
	int f[5]{};
	for (int i = 0; i < strlen(s); i++) {
		bool gasit = false;
		for (int j = 0; j < 5 && !gasit; j++) {
			if (s[i] == vocale[j]) {
				f[j / 2]++;
				gasit = true;
			}
		}
	}

	int max = 0, r = 0;
	for (int i = 0; i < 5; i++) {
		if (f[i] > max) {
			r = i;
			max = f[i];
		}
	}

	return vocale[r * 2];
}

void afisarePrefixe(char cuvant[]) {
	for (int i = strlen(cuvant); i > 0; i--) {
		char p[200] = "";
		strncpy(p, cuvant, i);
		cout << p << endl;
	}
}

void afisareSufixe(char cuvant[]) {
	for (int i = 0; i < strlen(cuvant); i++) {
		cout << cuvant + i << endl;
	}
}

int posPrimaVocala(char cuvant[]) {
	for (int i = 0; i < strlen(cuvant); i++) {
		if (esteVocala(cuvant[i])) {
			return i;
		}
	}
	return -1;
}

int posPrimaConsoana(char cuvant[]) {
	for (int i = 0; i < strlen(cuvant); i++) {
		if (!esteVocala(cuvant[i])) {
			return i;
		}
	}
	return -1;
}

int posUltimaVocala(char cuvant[]) {
	for (int i = strlen(cuvant) - 1; i > -1; i--) {
		if (esteVocala(cuvant[i])) {
			return i;
		}
	}
	return -1;
}

int posUltimaConsoana(char cuvant[]) {
	for (int i = strlen(cuvant) - 1; i > -1; i--) {
		if (!esteVocala(cuvant[i])) {
			return i;
		}
	}
	return -1;
}

// Modifiers

void inserare(char sir[], int k, char c) {
	char r[3] = "";
	r[0] = c;
	char seg[255] = "";
	strncpy(seg, sir, k);
	strcat(seg, r);
	strcat(seg, sir + k);
	strcpy(sir, seg);
}

void stergere(char sir[], int k) {
	char seg[255] = "";
	strncpy(seg, sir, k);
	strcat(seg, sir + k + 1);
	strcpy(sir, seg);
}

void FNume(char s[], char id[]) {
	char* a;
	a = strtok(s, " ");
	while (a != NULL) {
		strcpy(id, a);
		a = strtok(NULL, " ");
	}
	strcat(id, "2022");
}

void firstLastLetterUppercase(char s[]) {
	if (s[0] > 96 && s[0] < 123) {
		s[0] -= 32;
	}
	if (s[strlen(s) - 1] > 96 && s[strlen(s) - 1] < 123) {
		s[strlen(s) - 1] -= 32;
	}
}

void lastLetter5(char s[]) {
	s[strlen(s) - 1] = '5';
}

void interschimbarePrimaVocalaUltimaConsoana(char cuvant[]) {
	int posVocala = posPrimaVocala(cuvant);
	int posConsoana = posUltimaConsoana(cuvant);

	if (posVocala == -1) {
		posVocala = posConsoana;
	}
	else if (posConsoana == -1) {
		posConsoana = posVocala;
	}

	char r = cuvant[posVocala];
	cuvant[posVocala] = cuvant[posConsoana];
	cuvant[posConsoana] = r;
}

void stelutaDupaVocala(char sir[]) {
	for (int i = 0; i < strlen(sir); i++) {
		if (esteVocala(sir[i])) {
			inserare(sir, i + 1, '*');
			i++;
		}
	}
}

void capsLock(char sir[]) {
	bool activat = false;
	for (int i = 0; i < strlen(sir); i++) {
		if (sir[i] == '#') {
			activat = (activat + 1) % 2;
			stergere(sir, i);
			i--;
		}
		else if (activat) {
			sir[i] -= 32;
		}
	}
}