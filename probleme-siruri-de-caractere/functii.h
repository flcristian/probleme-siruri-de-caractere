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

// Utility

void split(char s[], char cuvinte[200][200], int& d) {
	char sir[200] = "";
	strcpy(sir, s);
	d = 0;
	char* a;
	a = strtok(sir, " ");
	while (a != NULL) {
		strcpy(cuvinte[d], a);
		d++;
		a = strtok(NULL, " ");
	}
}