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

// Text in "input.txt" ! ! !

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

// Problema 8
// Se dă o propoziție formată din litere mari și mici ale alfabetului englez, 
// cifre, spații și semne de punctuație, în care literele mari și mici se consideră identice.
// Determinați vocala din șir cu număr maxim de apariții.

void problema8() {
	char s[200] = "";
	cout << "Introduceti sirul :\n";
	cin.getline(s, 200);

	cout << vocalaMaxAparitii(s);
}

// Problema 9
// Să se afişeze lista prefixelor şi lista sufixelor cuvântului dat.

void problema9() {
	char cuvant[200] = "";
	cout << "Introduceti cuvantul :\n";
	cin.getline(cuvant, 200);

	cout << "\nPrefixe : \n\n";
	afisarePrefixe(cuvant);
	cout << "\nSufixe : \n\n";
	afisareSufixe(cuvant);
}

// Problema 10
// Să se scrie un program care citește un cuvânt și îl afișează după 
// interschimbarea primei vocale cu ultima consoană.

void problema10() {
	char cuvant[200] = "";
	cout << "Introduceti cuvantul :\n";
	cin.getline(cuvant, 200);

	interschimbarePrimaVocalaUltimaConsoana(cuvant);
	cout << endl << cuvant;
}

// Problema 11
// Să se scrie un program care citește un text și inserează după fiecare vocală caracterul *.

void problema11() {
	char s[200] = "";
	cout << "Introduceti sirul :\n";
	cin.getline(s, 200);

	stelutaDupaVocala(s);
	cout << s;
}

// Problema 12
// Marcel a primit o tastatura noua de ziua lui. El vrea sa scrie un text folosind doar 
// litere ale alfabetului englez si spatii. El a descoperit tasta CapsLock, care atunci 
// cand este apasata se activeaza. Daca tasta este activata, atunci toate literele care 
// le va scrie in continuare, pana in momentul in care tasta este dezactivata (apasand 
// CapsLock inca o data) vor fi majuscule.
// Exemplu : #s#alut #andrei => Salut ANDREI

// Text in "input.txt" ! ! !

void problema12() {
	ifstream f("input.txt");
	char s[255] = "";
	f.getline(s, 255);

	capsLock(s);
	cout << s;
}

// Problema 13
// Să se scrie un program care citește mai multe cuvinte și determină despre fiecare dacă este palindrom.

// Text in "input.txt" ! ! !

void problema13() {
	ifstream f("input.txt");
	char cuvinte[200][200], dt[10];
	int d;
	f.getline(dt, 10);
	d = atoi(dt);
	for (int i = 0; i < d; i++) {
		f.getline(cuvinte[i], 200);
	}
	f.close();
	
	for (int i = 0; i < d; i++) {
		cout << estePalindrom(cuvinte[i]) << endl;
	}
}

// Problema 14
// Să se scrie un program care citește mai multe propoziții și determină propoziția cu cele mai multe vocale.

// Text in "input.txt" ! ! !

void problema14() {
	ifstream f("input.txt");
	char cuvinte[200][200], dt[10];
	int d;
	f.getline(dt, 10);
	d = atoi(dt);
	for (int i = 0; i < d; i++) {
		f.getline(cuvinte[i], 200);
	}
	f.close();
}

// Problema 15
// Fișierul de intrare vocmax.in conține pe prima linie un număr natural n, iar pe următoarele n linii câte o 
// propoziție alcătuită din litere mici ale alfabetului englez și spații.

void problema15() {
	ifstream f("input.txt");
	char prop[255][255], dt[10];
	int d;
	f.getline(dt, 10);
	d = atoi(dt);
	for (int i = 0; i < d; i++) {
		f.getline(prop[i], 255);
	}
	
	rezolvarePb15(prop, d);
}

// Problema 16
// Să se scrie un program care citeşte un şir de caractere format 
// din litere mici ale alfabetului englez şi elimină din șir toate vocalele.

void problema16() {
	char s[255] = "";
	cout << "Introduceti sirul :\n";
	cin.getline(s, 255);
	stergereVocale(s);

	cout << s;
}

// Problema 17
// Determinați numărul de perechi de vocale consecutive din propoziție.

void problema17() {
	char s[255] = "";
	cout << "Introduceti sirul :\n";
	cin.getline(s, 255);

	cout << "Numarul de perechi de vocale consecutive este : " << countVocaleConsecutive(s);
}

// Problema 18
// Să se scrie un program care verifică dacă două cuvinte date sunt anagrame.

void problema18() {
	char cuv1[200] = "", cuv2[200] = "";
	cout << "Introduceti primul cuvant :\n";
	cin.getline(cuv1, 200);
	cout << "Introduceti al doilea cuvant :\n";
	cin.getline(cuv2, 200);

	string raspuns = "Cuvintele";
	if (suntAnagrame(cuv1, cuv2)) {
		raspuns += " sunt ";
	}
	else {
		raspuns += " nu sunt ";
	}
	raspuns += "anagrame.";
	cout << raspuns;
}

// Problema 19
// Scrieți un program care citește de la tastatură două șiruri formate fiecare din cel mult 20 de caractere. 
// Primul șir reprezintă numele unei persoane, iar al doilea șir reprezintă prenumele aceleiași persoane. 
// Atât numele, cât și prenumele sunt formate doar din litere ale alfabetului englez și fiecare conține 
// cel puțin o consoană.
// Programul construiește în memorie și afișează pe ecran un al treilea șir de caractere, care va conține 
// consoanele din prenumele citit dispuse în ordinea în care apar în prenume, urmate de exact un spațiu și de
// numele citit.

void problema19() {
	char nume[20] = "", prenume[20] = "";
	cout << "Introduceti numele : ";
	cin.getline(nume, 20);
	cout << "Introduceti prenumele : ";
	cin.getline(prenume, 20);
	char rezultat[40] = "";
	rezolvarePb19(nume, prenume, rezultat);
	cout << rezultat;
}

// Problema 20
// Scrieți un program care citește de tastatură două șiruri de cel mult 30 caractere de aceeași lungime 
// care conțin doar litere mici ale alfabetului englez și construiește în memorie și apoi afișează pe ecran 
// un cel mai bun șablon comun al lor, adică șablonul comun cu număr minim de caractere ?.
// Un șir de caractere s este șablon pentru un șir de caractere x dacă are aceeași lungime cu x și este alcătuit 
// numai din caractere ale mulțimii {*,#,?}, iar pe fiecare poziție din s în care apare * în x apare vocală, pe 
// fiecare poziție din s în care apare # în x apare consoană, iar pe fiecare poziție din s în care apare ? în x 
// putem avea orice caracter.

void problema20() {
	char cuv1[200] = "", cuv2[200] = "";
	cout << "Introduceti primul cuvant :\n";
	cin.getline(cuv1, 200);
	cout << "Introduceti al doilea cuvant :\n";
	cin.getline(cuv2, 200);
	char sablon[200] = "";
	sablonDouaCuvinte(cuv1, cuv2, sablon);
	cout << "Cel mai bun sablon este : " << sablon;
}

// Problema 21
// Să se scrie un program care citește un șir de caractere 
// și afișează litera mică cel mai des întâlnită în șir.

void problema21() {
	char cuvant[200] = "";
	cout << "Introduceti cuvantul :\n";
	cin.getline(cuvant, 200);
	int f[26]{};
	frecventaLitere(cuvant, f);
	int max = 0, r = 0;
	for (int i = 0; i < 26; i++) {
		if (f[i] > max) {
			max = f[i];
			r = i;
		}
	}
	char raspuns = 97 + r;
	cout << "Litera cu cea mai mare frecventa este : " << raspuns;
}

// Problema 22
// Scrieţi un program care citeşte de la tastatură un şir de cel mult 60 de caractere 
// (litere mici şi mari ale alfabetului englez, cifre, puncte, virgule şi spaţii) şi afişează pe 
// ecran cifra care apare de cele mai multe ori în şirul citit.

void problema22() {
	char sir[255] = "";
	cout << "Introduceti sirul :\n";
	cin.getline(sir, 255);
	int f[10]{};
	frecventaCifre(sir, f);
	int max = 0, r = 0;
	for (int i = 0; i < 10; i++) {
		if (f[i] > max) {
			max = f[i];
			r = i;
		}
	}
	cout << "Cifra cu cea mai mare frecventa este : " << r;
}

// Problema 23
// Să se determine numărul cuvintelor care conțin doar vocale.

// Text in "input.txt" ! ! !

void problema23() {
	ifstream f("input.txt");
	char cuvinte[200][200], dt[10] = "";
	int d;
	f.getline(dt, 10);
	d = atoi(dt);
	for (int i = 0; i < d; i++) {
		f.getline(cuvinte[i], 200);
	}
	
	rezolvarePb23(cuvinte, d);
}

// Problema 24
// Se dă un șir de caractere care conține litere mici și mari ale alfabetului englez, 
// spații și semne de punctuație. Să se afișeze fiecare cuvânt și frecvența de apariție a lui în șirul de 
// caractere pe câte o linie fiecare pereche cuvânt-frecvență ordonate lexicografic.

void problema24() {
	char s[255] = "";
	cout << "Introduceti sirul :\n";
	cin.getline(s, 255);
	char cuvinte[200][200];
	int d;
	split(s, cuvinte, d);

	rezolvarePb24(cuvinte, d);
}

// Problema 25
// Caracterul mediu a două sau al mai multor caractere este caracterul care are codul 
// ASCII egal cu partea întreagă a mediei aritmetice a codurilor ASCII ale caracterelor date.
// Un caracter se numeste bun daca nu este spatiu, nu este litera mare si nu este vocala.

void problema25() {
	char s[255] = "";
	cout << "Introduceti sirul :\n";
	cin.getline(s, 255);

	int medie = medieCoduriAscii(s);
	cout << "Caracterul mediu bun este : " << (char)medie;
}

// Problema 26
// Se dă un şir de caractere ce conţine cuvinte formate din litere mici ale alfabetului englez, 
// separate prin unul sau mai multe spații.
// Să se afişeze şirul obţinut după eliminarea din șir unor spații, astfel încât între cuvinte 
// să fie un singur spațiu și să nu nu existe spații înainte de primul cuvânt și nici după ultimul.

void problema26() {
	char s[255] = "";
	cout << "Introduceti sirul :\n";
	cin.getline(s, 255);

	removeSpaces(s);
	cout << s;
}

// Problema 27
// Se citește un șir format din cel mult 255 caractere, litere mici ale alfabetului englez. 
// Să se determine ce mai lungă secvență din șir formată numai din consoane.

void problema27() {
	char s[255] = "";
	cout << "Introduceti sirul :\n";
	cin.getline(s, 255);

	char secventa[255] = "";
	maxSecventaConsoane(s, secventa);
	cout << secventa;
}

// Problema 28
// Se dă un şir de caractere ce conţine cuvinte formate din litere mici ale alfabetului englez, separate 
// prin unul sau mai multe spații. Înaintea primului cuvânt nu există spații, și nici după ultimul. 
// Să se modifice șirul dat, astfel încât să se înlocuiască fiecare cuvânt cu exact trei litere din șir
// cu simbolul *.

void problema28() {
	char s[255] = "";
	cout << "Introduceti sirul :\n";
	cin.getline(s, 255);

	swapCuvinte3LitereCuSteluta(s);
	cout << s;
}

// Problema 29
// Se dă un șir de caractere care conține cuvinte formate din litere mici ale alfabetului englez și 
// separate printr-un singur spațiu. Să se determine cel mai lung cuvânt care are toate literele 
// distincte. Dacă nu există niciun cuvânt cu toate literele distincte se va afișa -1.

void problema29() {
	char s[255] = "";
	cout << "Introduceti sirul :\n";
	cin.getline(s, 255);
	char cuvinte[200][200];
	int d;
	split(s, cuvinte, d);
	
	int r = cuvantMaxLitereDistincte(cuvinte, d);
	if (r == -1) {
		cout << r;
	}
	else {
		cout << cuvinte[r];
	}
}

// Problema 30
// Se dă un număr natural l și un șir de cel mult 10000 de caractere ce conține cuvinte separate prin câte 
// un spațiu. Fiecare cuvânt din șir este format din cel mult l litere mari ale alfabetului englez.
// Să se scrie un program care afișează cuvintele din text, în ordine, pe linii de cel mult l caractere, 
// astfel încât orice linie începe și se termină cu un cuvânt și oricare două cuvinte de pe aceeași linie 
// sunt separate printr-un singur spațiu.Fiecare linie va fi folosită la maxim, adică dacă un cuvânt are 
// loc pe acea linie va fi pus acolo și nu va fi trecut pe linia următoare sau despărțit în silabe.

void problema30() {
	ifstream f("input.txt");
	char s[255] = "", lt[10] = "";
	f.getline(lt, 10);
	f.getline(s, 255);
	int l = atoi(lt);

	rezolvarePb30(s, l);
}