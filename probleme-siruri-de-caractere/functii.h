#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Bools

bool esteVocala(char a) {
	char v[5] = { 'a','e','i','o','u' };
	for (int i = 0; i < 5; i++) {
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
	char x[4] = { 'a','e','o','u' };
	for (int i = 0; i < strlen(s); i++) {
		char c = s[i];
		for (int j = 0; j < 4; j++) {
			if (c == x[j]) {
				return 0;
			}
		}
	}
	return 1;
}

// Modifiers

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