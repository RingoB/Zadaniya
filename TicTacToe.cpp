//coded by RingoBarbos. Яндекс.Настольные игры
#include <iostream>
#include <stdlib.h>

using namespace std;

	char ryad1[10] = { '*','*', '*', '*', '*', '*', '*', '*', '*', '*' };
	char ryad2[10] = { '*','*', '*', '*', '*', '*', '*', '*', '*', '*' };
	char ryad3[10] = { '*','*', '*', '*', '*', '*', '*', '*', '*', '*' };
	char ryad4[10] = { '*','*', '*', '*', '*', '*', '*', '*', '*', '*' };
	char ryad5[10] = { '*','*', '*', '*', '*', '*', '*', '*', '*', '*' };
	char ryad6[10] = { '*','*', '*', '*', '*', '*', '*', '*', '*', '*' };
	char ryad7[10] = { '*','*', '*', '*', '*', '*', '*', '*', '*', '*' };
	char ryad8[10] = { '*','*', '*', '*', '*', '*', '*', '*', '*', '*' };
	char ryad9[10] = { '*','*', '*', '*', '*', '*', '*', '*', '*', '*' };
	char ryad10[10] = { '*','*', '*', '*', '*', '*', '*', '*', '*', '*' };
	int player = 1;

int hod(int a, int b) {  //Ôóíêöèÿ, îòâå÷àþùàÿ çà õîäû.
	if (a == 1) {
		if (ryad1[b - 1] != '*') {
			return 1;
		}
		if (player == 1) {
			ryad1[b - 1] = 'X';
		}
		else {
			ryad1[b - 1] = 'O';
		}
	}
	else if (a == 2) {
		if (ryad2[b - 1] != '*') {
			return 1;
		}
		if (player == 1) {
			ryad2[b - 1] = 'X';
		}
		else {
			ryad2[b - 1] = 'O';
		}
	}
	else if (a == 3) {
		if (ryad3[b - 1] != '*') {
			return 1;
		}
		if (player == 1) {
			ryad3[b - 1] = 'X';
		}
		else {
			ryad3[b - 1] = 'O';
		}
	}
	else if (a == 4) {
		if (ryad4[b - 1] != '*') {
			return 1;
		}
		if (player == 1) {
			ryad4[b - 1] = 'X';
		}
		else {
			ryad4[b - 1] = 'O';
		}
	}
	else if (a == 5) {
		if (ryad5[b - 1] != '*') {
			return 1;
		}
		if (player == 1) {
			ryad5[b - 1] = 'X';
		}
		else {
			ryad5[b - 1] = 'O';
		}
	}
	else if (a == 6) {
		if (ryad6[b - 1] != '*') {
			return 1;
		}
		if (player == 1) {
			ryad6[b - 1] = 'X';
		}
		else {
			ryad6[b - 1] = 'O';
		}
	}
	else if (a == 7) {
		if (ryad7[b - 1] != '*') {
			return 1;
		}
		if (player == 1) {
			ryad7[b - 1] = 'X';
		}
		else {
			ryad7[b - 1] = 'O';
		}
	}
	else if (a == 8) {
		if (ryad8[b - 1] != '*') {
			return 1;
		}
		if (player == 1) {
			ryad8[b - 1] = 'X';
		}
		else {
			ryad8[b - 1] = 'O';
		}
	}
	else if (a == 9) {
		if (ryad9[b - 1] != '*') {
			return 1;
		}
		if (player == 1) {
			ryad9[b - 1] = 'X';
		}
		else {
			ryad9[b - 1] = 'O';
		}
	}
	else if (a == 10) {
		if (ryad10[b - 1] != '*') {
			return 1;
		}
		if (player == 1) {
			ryad10[b - 1] = 'X';
		}
		else {
			ryad10[b - 1] = 'O';
		}
	}
	return 0;
}
int endgamecheck() { //Ïðîâåðêà êîìáèíàöèé
	int k = 0;
	int s = 0;
	int d = 0;
	int n = 0;
	for (int i = 0; i < 10; i++) {
		if (k > 3) { return 1; }
		if ((ryad1[i] == ryad2[i]) &&(ryad1[i] != '*')) { k++; }
		else { k = 0; }
		if (k > 3) { return 1; }
		if ((ryad2[i] == ryad3[i]) && (ryad2[i] != '*')) { k++; }
		else { k = 0; }
		if (k > 3) { return 1; }
		if ((ryad3[i] == ryad4[i]) && (ryad3[i] != '*')) { k++; }
		else { k = 0; }
		if (k > 3) { return 1; }
		if ((ryad4[i] == ryad5[i]) && (ryad4[i] != '*')) { k++; }
		else { k = 0; }
		if (k > 3) { return 1; }
		if ((ryad5[i] == ryad6[i] )&& (ryad5[i] != '*')) { k++; }
		else { k = 0; }
		if (k > 3) { return 1; }
		if ((ryad6[i] == ryad7[i]) && (ryad6[i] != '*')) { k++; }
		else { k = 0; }
		if (k > 3) { return 1; }
		if ((ryad7[i] == ryad8[i]) && (ryad7[i] != '*')) { k++; }
		else { k = 0; }
		if (k > 3) { return 1; }
		if ((ryad8[i] == ryad9[i]) && (ryad8[i] != '*')) { k++; }
		else { k = 0; }
		if (k > 3) { return 1; }
		if ((ryad9[i] == ryad10[i]) && (ryad9[i] != '*')) { k++; }
		else { k = 0; }
		if (k > 3) { return 1; }
	}
	for (int i = 0; i < 9; i++) {
		if (s > 3) { return 1; }
		if ((ryad1[i] == ryad1[i + 1]) && (ryad1[i] != '*')) { s++; }
		else { s = 0; }
		if (s > 3) { return 1; }
	}
	for (int i = 0; i < 9; i++) {
		if (s > 3) { return 1; }
		if ((ryad2[i] == ryad2[i + 1]) && (ryad2[i] != '*')) { s++; }
		else { s = 0; }
		if (s > 3) { return 1; }
	}
	for (int i = 0; i < 9; i++) {
		if (s > 3) { return 1; }
		if ((ryad3[i] == ryad3[i + 1]) && (ryad3[i] != '*')) { s++; }
		else { s = 0; }
		if (s > 3) { return 1; }
	}
	for (int i = 0; i < 9; i++) {
		if (s > 3) { return 1; }
		if ((ryad4[i] == ryad4[i + 1]) && (ryad4[i] != '*')) { s++; }
		else { s = 0; }
		if (s > 3) { return 1; }
	}
	for (int i = 0; i < 9; i++) {
		if (s > 3) { return 1; }
		if ((ryad5[i] == ryad5[i + 1]) && (ryad5[i] != '*')) { s++; }
		else { s = 0; }
		if (s > 3) { return 1; }
	}
	for (int i = 0; i < 9; i++) {
		if (s > 3) { return 1; }
		if ((ryad6[i] == ryad6[i + 1]) && (ryad6[i] != '*')) { s++; }
		else { s = 0; }
		if (s > 3) { return 1; }
	}
	for (int i = 0; i < 9; i++) {
		if (s > 3) { return 1; }
		if ((ryad7[i] == ryad7[i + 1]) && (ryad7[i] != '*')) { s++; }
		else { s = 0; }
		if (s > 3) { return 1; }
	}
	for (int i = 0; i < 9; i++) {
		if (s > 3) { return 1; }
		if ((ryad8[i] == ryad8[i + 1]) && (ryad8[i] != '*')) { s++; }
		else { s = 0; }
		if (s > 3) { return 1; }
	}
	for (int i = 0; i < 9; i++) {
		if (s > 3) { return 1; }
		if ((ryad9[i] == ryad9[i + 1]) && (ryad9[i] != '*')) { s++; }
		else { s = 0; }
		if (s > 3) { return 1; }
	}
	for (int i = 0; i < 9; i++) {
		if (s > 3) { return 1; }
		if ((ryad10[i] == ryad10[i + 1]) && (ryad10[i] != '*')) { s++; }
		else { s = 0; }
		if (s > 3) { return 1; }
	}
	for (int z = 0; z < 10; z++) {
		int i = 0;
		if (d > 3) { return 1; }
		if (z < 1) {
			if ((ryad1[i] == ryad2[i + 1]) && (ryad1[i] != '*')) { d++; }
			else { d = 0; }
			i++;
		}
		if (z < 2) {
			if (d > 3) { return 1; }
			if ((ryad2[i] == ryad3[i + 1]) && (ryad2[i] != '*')) { d++; }
			else { d = 0; }
			i++;
		}
		if (z < 3) {
			if (d > 3) { return 1; }
			if ((ryad3[i] == ryad4[i + 1]) && (ryad3[i] != '*')) { d++; }
			else { d = 0; }
			i++;
		}
		if (z < 4) {
			if (d > 3) { return 1; }
			if ((ryad4[i] == ryad5[i + 1]) && (ryad4[i] != '*')) { d++; }
			else { d = 0; }
			i++;
		}
		if (z < 5) {
			if (d > 3) { return 1; }
			if ((ryad5[i] == ryad6[i + 1]) && (ryad5[i] != '*')) { d++; }
			else { d = 0; }
			i++;
		}
		if (z < 6) {
			if (d > 3) { return 1; }
			if ((ryad6[i] == ryad7[i + 1]) && (ryad6[i] != '*')) { d++; }
			else { d = 0; }
			i++;
		}
		if (z < 7) {
			if (d > 3) { return 1; }
			if ((ryad7[i] == ryad8[i + 1]) && (ryad7[i] != '*')) { d++; }
			else { d = 0; }
			i++;
		}
		if (z < 8) {
			if (d > 3) { return 1; }
			if ((ryad8[i] == ryad9[i + 1]) && (ryad8[i] != '*')) { d++; }
			else { d = 0; }
			i++;
		}
		if (z < 9) {
			if (d > 3) { return 1; }
			if ((ryad9[i] == ryad10[i + 1]) && (ryad9[i] != '*')) { d++; }
			else { d = 0; }
			i++;
		}
		if (d > 3) { return 1; }
	}

	for (int z = 0; z < 10; z++) {
		int i = 9;
		if (n > 3) { return 1; }
		if (z < 1) {
			if ((ryad1[i] == ryad2[i - 1]) && (ryad1[i] != '*')) { n++; }
			else { n = 0; }
			i--;
		}
		if (z < 2) {
			if (n > 3) { return 1; }
			if ((ryad2[i] == ryad3[i - 1]) && (ryad2[i] != '*')) { n++; }
			else { n = 0; }
			i--;
		}
		if (z < 3) {
			if (n > 3) { return 1; }
			if ((ryad3[i] == ryad4[i - 1]) && (ryad3[i] != '*')) { n++; }
			else { n = 0; }
			i--;
		}
		if (z < 4) {
			if (n > 3) { return 1; }
			if ((ryad4[i] == ryad5[i - 1]) && (ryad4[i] != '*')) { n++; }
			else { n = 0; }
			i--;
		}
		if (z < 5) {
			if (n > 3) { return 1; }
			if ((ryad5[i] == ryad6[i - 1]) && (ryad5[i] != '*')) { n++; }
			else { n = 0; }
			i--;
		}
		if (z < 6) {
			if (n > 3) { return 1; }
			if ((ryad6[i] == ryad7[i - 1]) && (ryad6[i] != '*')) { n++; }
			else { n = 0; }
			i--;
		}
		if (z < 7) {
			if (n > 3) { return 1; }
			if ((ryad7[i] == ryad8[i - 1]) && (ryad7[i] != '*')) { n++; }
			else { n = 0; }
			i--;
		}
		if (z < 8) {
			if (n > 3) { return 1; }
			if ((ryad8[i] == ryad9[i - 1]) && (ryad8[i] != '*')) { n++; }
			else { n = 0; }
			i--;
		}
		if (z < 9) {
			if (n > 3) { return 1; }
			if ((ryad9[i] == ryad10[i - 1]) && (ryad9[i] != '*')) { n++; }
			else { n = 0; }
			i--;
		}
		if (n > 3) { return 1; }
	}
	return 0;
}
void pole() { //Âûâîä ïîëÿ.
	for (int i = 1; i < 11; i++) {
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << ryad1[i]<<" ";
	}
	cout << "1";
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << ryad2[i] << " ";
	}
	cout << "2";
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << ryad3[i] << " ";
	}
	cout << "3";
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << ryad4[i] << " ";
	}
	cout << "4";
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << ryad5[i] << " ";
	}
	cout << "5";
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << ryad6[i] << " ";
	}
	cout << "6";
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << ryad7[i] << " ";
	}
	cout << "7";
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << ryad8[i] << " ";
	}
	cout << "8";
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << ryad9[i] << " ";
	}
	cout << "9";
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << ryad10[i] << " ";
	}
	cout << "10";
	cout << endl;
	return;
}
int newgame() { //Îáíóëåíèå èãðû.
	for (int i = 0; i < 10; i++) {
		ryad1[i] = '*';
	}
	for (int i = 0; i < 10; i++) {
		ryad2[i] = '*';
	}
	for (int i = 0; i < 10; i++) {
		ryad3[i] = '*';
	}
	for (int i = 0; i < 10; i++) {
		ryad4[i] = '*';
	}
	for (int i = 0; i < 10; i++) {
		ryad5[i] = '*';
	}
	for (int i = 0; i < 10; i++) {
		ryad6[i] = '*';
	}
	for (int i = 0; i < 10; i++) {
		ryad7[i] = '*';
	}
	for (int i = 0; i < 10; i++) {
		ryad8[i] = '*';
	}
	for (int i = 0; i < 10; i++) {
		ryad9[i] = '*';
	}
	for (int i = 0; i < 10; i++) {
		ryad10[i] = '*';
	}
	player = 1;
	system("cls");
	return 0;
}
int main() { //Ñîáñòâåííî ìýèí.
	setlocale(LC_ALL, "rus");
newgame:
	cout << "Êðåñòèêè-íîëèêè v1.0 (ñ) RingoBarbos" << endl;
again:
	pole();
	int a, b;
	int hodi = 0;
	int check;
	char otvet;
retry:
	cout << "Õîä èãðîêà" << player << ": ";
	cin >> a >> b;
	if ((a > 10)||(b > 10) || (a < 1) || (b < 1)) {
		cout << "ÎØÈÁÊÀ! ÂÛ ÂÂÅËÈ ÊÎÎÐÄÈÍÀÒÛ ÇÀ ÏÐÅÄÅËÀÌÈ ÏÎËß!" << endl;
		goto retry;
	}
	check = hod(a,b);
	if (check == 1) {
		cout << "ÎØÈÁÊÀ! ÊËÅÒÊÀ ÇÀÍßÒÀ!" << endl;
		goto retry;
	}
	hod(a, b);
	int end = endgamecheck();
	int draw=0;
	hodi++;
	if (hodi == 100) {
		cout << "Íè÷üÿ!" << endl;
		draw = 1;
	}
	if (draw == 1) {
		cout << "Õîòèòå íà÷àòü çàíîâî? y/n?: ";
zan:
		cin >> otvet;
		if (otvet == 'y') {
			newgame();
			goto newgame;
		}
		else if (otvet == 'n') {
			return 0;
		}
		else {
			cout << "ÎØÈÁÊÀ!" << endl;
			goto zan;
		}
	}
	if (end == 1) {
		pole();
		cout << "Èãðîê " << player << " ïîáåäèë!" << endl;
		cout << "Õîòèòå íà÷àòü çàíîâî? y/n?: ";
zanovo:
		cin >> otvet;
		if (otvet == 'y') {
			newgame();
			goto newgame;
		}
		else if (otvet == 'n') {
			return 0;
		}
		else {
			cout << "ÎØÈÁÊÀ!"<<endl;
			goto zanovo;
		}
	}
		if (player == 1) {
			player = 2;
		}
		else {
			player = 1;
		}
		goto again;
}



