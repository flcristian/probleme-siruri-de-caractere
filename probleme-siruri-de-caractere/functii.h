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

bool contineDoarVocale(char s[]) {
	for (int i = 0; i < strlen(s); i++) {
		if (!esteVocala(s[i])) {
			return 0;
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

bool suntAnagrame(char cuv1[], char cuv2[]) {
	_strlwr(cuv1), _strlwr(cuv2);
	int f1[26]{}, f2[26]{};
	for (int i = 0; i < strlen(cuv1); i++) {
		f1[cuv1[i] - 97]++;
	}
	for (int j = 0; j < strlen(cuv2); j++) {
		f2[cuv2[j] - 97]++;
	}

	for (int i = 0; i < 26; i++) {
		if (f1[i] != f2[i]) {
			return 0;
		}
	}
	return 1;
}

bool esteCaracterBun(char c) {
	if (esteVocala(c)) {
		return 0;
	}
	if (c > 64 && c < 91) {
		return 0;
	}
	if (c == ' ') {
		return 0;
	}
	return 1;
}

bool toateLitereleDistincte(char cuvant[]) {
	int f[26]{};
	_strlwr(cuvant);
	for (int i = 0; i < strlen(cuvant); i++) {
		f[cuvant[i] - 97]++;
	}

	for (int i = 0; i < 26; i++) {
		if (f[i] > 1) {
			return 0;
		}
	}
	return 1;
}

int apare(char cuvinte[200][200], int d, char cuvant[]) {
	for (int i = 0; i < d; i++) {
		if (strcmp(cuvinte[i], cuvant) == 0) {
			return i;
		}
	}
	return 0;
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

void sablonDouaCuvinte(char cuv1[], char cuv2[], char sablon[]) {
	char r[3] = "";
	for (int i = 0; i < strlen(cuv1); i++) {
		if (esteVocala(cuv1[i]) && esteVocala(cuv2[i])) {
			r[0] = '*';
		}
		else if (esteConsoana(cuv1[i]) && esteConsoana(cuv2[i])) {
			r[0] = '#';
		}
		else {
			r[0] = '?';
		}
		strcat(sablon, r);
	}
}

void frecventaLitere(char s[], int f[]) {
	_strlwr(s);
	for (int i = 0; i < strlen(s); i++) {
		f[s[i] - 97]++;
	}
}

void frecventaCifre(char s[], int f[]) {
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] > 47 && s[i] < 58) {
			f[s[i] - 48]++;
		}
	}
}

void bubbleSortCuFrecventa(char cuvinte[200][200], int d, int f[]) {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < d - 1; i++) {
			if (strcmp(cuvinte[i], cuvinte[i + 1]) == 1) {
				char r[200] = "", c = f[i];
				strcpy(r, cuvinte[i]);
				strcpy(cuvinte[i], cuvinte[i + 1]);
				f[i] = f[i + 1];
				strcpy(cuvinte[i + 1], r);
				f[i + 1] = c;
				flag = false;
			}
		}
	} while (flag == false);
}

int medieCoduriAscii(char s[]) {
	int suma = 0, c = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (esteCaracterBun(s[i])) {
			suma += s[i];
			c++;
		}
	}
	return (suma / c);
}

void maxSecventaConsoane(char s[], char secventa[]) {
	int max = 0, maxR = -1, c = 0, r = -1;
	for (int i = 0; i < strlen(s); i++) {
		if (esteConsoana(s[i])) {
			c++;
			if (r == -1) {
				r = i;
			}
			if (c > max) {
				max = c;
				maxR = r;
			}
		}
		else {
			c = 0;
			r = -1;
		}
	}
	char seg[255] = "";
	strncpy(secventa, s + maxR, max);
}

int cuvantMaxLitereDistincte(char cuvinte[200][200], int d) {
	int max = 0, r = -1;
	for (int i = 0; i < d; i++) {
		if (toateLitereleDistincte(cuvinte[i])) {
			if (strlen(cuvinte[i]) > max) {
				max = strlen(cuvinte[i]);
				r = i;
			}
		}
	}
	return r;
}

int limitaLiniePentruPb30(char cuvinte[200][200], int i, int d, int l) {
	int suma = 0;
	while (suma + strlen(cuvinte[i]) - 1 < l && i < d) {
		suma += strlen(cuvinte[i]) + 1;
		i++;
	}
	return i;
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

void stergereVocale(char sir[]) {
	for (int i = 0; i < strlen(sir); i++) {
		if (esteVocala(sir[i])) {
			stergere(sir, i);
			i--;
		}
	}
}

int countVocaleConsecutive(char s[]) {
	int c = 0;
	for (int i = 1; i < strlen(s); i++) {
		if (esteVocala(s[i - 1]) && esteVocala(s[i])) {
			c++;
		}
	}
	return c;
}

void removeSpaces(char s[]) {
	char cuvinte[200][200];
	int d;
	split(s, cuvinte, d);
	strcpy(s, "");
	char space[3] = " ";
	for (int i = 0; i < d; i++) {
		strcat(s, cuvinte[i]);
		if (i != d - 1) {
			strcat(s, space);
		}	
	}
}

void swapCuvinte3LitereCuSteluta(char s[]) {
	char cuvinte[200][200];
	int d;
	split(s, cuvinte, d);
	
	char spatiu[3] = " ";
	strcpy(s, "");
	for (int i = 0; i < d; i++) {
		if (strlen(cuvinte[i]) == 3) {
			strcpy(cuvinte[i], "*");
		}
		strcat(s, cuvinte[i]);
		if (i != d - 1) {
			strcat(s, spatiu);
		}
	}
}

// Uncategorized (rezolvari)

void rezolvarePb15(char prop[255][255], int d) {
	int f[255]{};
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < strlen(prop[i]); j++) {
			if (esteVocala(prop[i][j])) {
				f[i]++;
			}
		}
	}

	int max = 0, r = 0;
	for (int i = 0; i < d; i++) {
		if (f[i] > max) {
			max = f[i];
			r = i;
		}
	}

	cout << prop[r] << endl;
}

void rezolvarePb19(char nume[], char prenume[], char rezultat[]) {
	char r[3] = "";
	for (int i = 0; i < strlen(prenume); i++) {
		if (esteConsoana(prenume[i])) {
			r[0] = prenume[i];
			strcat(rezultat, r);
		}
	}
	r[0] = ' ';
	strcat(rezultat, r);
	strcat(rezultat, nume);
}

void rezolvarePb23(char cuvinte[200][200], int d) {
	int c = 0;
	for (int i = 0; i < d; i++) {
		if (contineDoarVocale(cuvinte[i])) {
			c++;
		}
	}
	cout << c << " cuvinte contin doar vocale.";
}

void rezolvarePb24(char cuvinte[200][200], int d) {
	char cuvinteUnice[200][200];
	int f[200]{}, n = 0;

	for (int i = 0; i < d; i++) {
		int k = apare(cuvinteUnice, n, cuvinte[i]);
		if (k != 0) {
			f[k]++;
		}
		else {
			cout << cuvinte[i] << endl;
			strcpy(cuvinteUnice[n], cuvinte[i]);
			f[n]++;
			n++;
		}
	}

	bubbleSortCuFrecventa(cuvinteUnice, n, f);

	for (int i = 0; i < n; i++) {
		cout << cuvinteUnice[i] << " " << f[i] << endl;
	}
}

// ? ? ? ? ? ? ? ? ?

void rezolvarePb30(char s[], int l) {
	char cuvinte[200][200];
	int d;
	split(s, cuvinte, d);
	for (int i = 0; i < d; i++) {
		int k = limitaLiniePentruPb30(cuvinte, i, d, l);
		for (int j = i; j < k; j++) {
			cout << cuvinte[j] << " ";
		}
		cout << endl;
		i = k - 1;
	}
}