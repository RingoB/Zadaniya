//coded by RingoBarbos. Яндекс.Настольные игры

//-------------------
//-------------------
// Код был переписан под двумерные массивы. Возможны баги. Старый билд: https://github.com/RingoB/Zadaniya/blob/24feb/TicTacToeBackup.cpp
//-------------------
//------------------

//Некторые проверки можно убрать, но я боюсь. Вдруг все перестанет работать.
//Нету проверки на ничью. Я её добавлял, но так и не смог проверить, поэтому выпилил.
//Можно было функцию с проверками комбинаций разбить ещё на несколько функций (Горизонталь, вертикаль, диагоноль влево, диагональ вправо).
//Код ужасен, но это мой первый большой проект на С++.
//На компиляторе VS2015 всё прекрасно запускается.
//Приятной проверки.

// version 1.1 changelog:
// + Теперь сохраняются результаты игр.

// version 1.2 changelog:
// + Добавлена командная строка.
// + Добавлена отмена хода
// + Добавлен сброс счёта

// version 1.2.1 alpha changelog:
// + Добавлен тупой бот. 

// version 1.2.2 alpha changelog:
// + Оптимизирован код (вместо >800 строк кода теперь 300)

// version 1.2.3 alpha changelog:
// + Бот стал на 0,1% умней.

//Немного оптимизировал код. Возможно всё теперь не работает.

//Возможно код с багами. Переписывал его под двумерные массивы.

#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

char ryad[10][10] = { { '.','.','.','.','.','.','.','.','.','.' },
{ '.','.','.','.','.','.','.','.','.','.' } ,
{ '.','.','.','.','.','.','.','.','.','.' } ,
{ '.','.','.','.','.','.','.','.','.','.' } ,
{ '.','.','.','.','.','.','.','.','.','.' } ,
{ '.','.','.','.','.','.','.','.','.','.' } ,
{ '.','.','.','.','.','.','.','.','.','.' } ,
{ '.','.','.','.','.','.','.','.','.','.' } ,
{ '.','.','.','.','.','.','.','.','.','.' } ,
{ '.','.','.','.','.','.','.','.','.','.' } };
int player = 1;

int hod(int a, int b) {  //Функция, отвечающая за ходы.
	if (ryad[a - 1][b - 1] != '.') {
		return 1;
	}
	if (player == 1) {
		ryad[a - 1][b - 1] = 'X';
	}
	else {
		ryad[a - 1][b - 1] = 'O';
	}
	return 0;
}
int endgamecheck() { //Проверка комбинаций
	int k = 0, s = 0, d = 0, n = 0, p = 0, r = 0;

	for (int i = 0; i < 10; i++) { //Горизонталь
		if (k > 4) { return 1; }
		for (int m = 0; m < 10; m++) {
			if ((ryad[i][m] == ryad[i][m + 1]) && (ryad[i][m] != '.')) { k++; }
			else { k = 0; }
			if (k > 3) { return 1; }
		}
	}

	for (int i = 0; i < 10; i++) { //Вертикаль
		if (s > 4) { return 1; }
		for (int m = 0; m < 10; m++) {
			if ((ryad[m][i] == ryad[m + 1][i]) && (ryad[m][i] != '.')) { s++; }
			else { s = 0; }
			if (s > 3) { return 1; }
		}
	}

	int z = 0;
	for (int i = 0; i < 9; i++) { //Диагональ вправо 1
		if (d > 3) { return 1; }
		for (int m = 0; m < 9; m++) {
			if ((ryad[z][m] == ryad[z + 1][m + 1]) && (ryad[z][m] != '.')) { d++; }
			else { d = 0; }
			z++;
			if (z == 10) { break; }
			if (d > 3) { return 1; }
		}
		z = i;
	}

	z = 0;
	for (int i = 0; i < 9; i++) { //Диагональ вправо 2
		if (n > 3) { return 1; }
		for (int m = 0; m < 9; m++) {
			if ((ryad[m][z] == ryad[m + 1][z + 1]) && (ryad[m][z] != '.')) { n++; }
			else { n = 0; }
			z++;
			if (z == 10) { break; }
			if (n > 3) { return 1; }
		}
		z = i;
	}

	for (int i = 0; i < 9; i++) { //Диагональ влево 1
		z = i;
		for (int m = 9; m > 0; m--) {
			if ((ryad[z][m] == ryad[z + 1][m - 1]) && (ryad[z][m] != '.')) { p++; }
			else { p = 0; }
			z++;
			if (z == 10) { break; }
			if (p > 3) { return 1; }
		}
	}

	z = 0;
	for (int i = 0; i < 9; i++) {  //Диагональ влево 2
		z = 0;
		for (int m = 9 - i; m > 0; m--) {
			if ((ryad[z][m] == ryad[z + 1][m - 1]) && (ryad[z][m] != '.')) { r++; }
			else { r = 0; }
			if (r > 3) { return 1; }
			z++;
		}
	}
}

void pole() { //Вывод поля.
	for (int i = 1; i < 11; i++) {
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		for (int n = 0; n < 10; n++) {
			cout << ryad[i][n] << " ";
		}
		cout << i + 1;
		cout << endl;
	}
	return;
}
int newgame() { //Обнуление игры.
	for (int i = 0; i < 10; i++) {
		for (int n = 0; n < 10; n++) {
			ryad[i][n] = '.';
		}
	}
	player = 1;
	system("cls");
	return 0;
}

void cancel(int a, int b) {
	ryad[a - 1][b - 1] = '.';
}

string ExePath() { //Читаем путь
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

int bot(int a, int b) {
	int check;
	pole();
newhod:
	int a1, a2;
	int b1, b2;
	int lastA, lastB;
	srand(time(NULL));
	a1 = a - 1;
	a2 = a + 1;
	b1 = b - 1;
	b2 = b + 1;
	lastA = rand() % a2 + a1;
	lastB = rand() % b2 + b1;
	if ((lastA > 10) || (lastB > 10) || (lastA < 1) || (lastB < 1)) {
		goto newhod;
	}
	check = hod(lastA, lastB);
	if (check == 1) {
		goto newhod;
	}
	hod(lastA, lastB);
	return 0;
}

int cmd(int a, int b, int wins[]) {
	int pl;
	bool ind = false;
	bool ng = false;
	char command;
	cout << "CMD: Доступные команды: b - отмена последнего хода, n - новая игра, r - сбросить счёт, c - закрыть консоль" << endl;
again1:
	cout << "CMD: ";
	cin >> command;
	if (command == 'b') {
		cancel(a, b);
		ind = true;
		pole();
		goto again1;
	}
	else if (command == 'n') {
		newgame();
		return 1;
	}
	else if (command == 'r') {
		*(wins) = 0;
		*(wins + 1) = 0;
		goto again1;
	}
	else if (command == 'c') {
		if (ind == true) {
			if (player == 1) {
				player = 2;
			}
			else {
				player = 1;
			}
			ind = false;
		}
		return 0;
	}
	else {
		cout << command << " не является командой" << endl;
		goto again1;
	}
	return 0;
}

int main() {
	int wins[2] = { 0,0 };
	int check;
	char otvet;
	int mode;
	int botA;
	int botB;
	int a = 1, b = 1;

	string settings = ExePath() + "\\data.ini";
	fstream file;
	file.open(settings);
	if (file)
	{
		file >> wins[0] >> wins[1]; //Считываем значения
	}
	else {
		ofstream file(settings, ios::out);
		file << 0 << " " << 0; //Создаём файл и записываем туда значения
	}

	setlocale(LC_ALL, "rus");

newgame:

	bool ind = false;
	cout << "Крестики-нолики v1.2.3 alpha (с) RingoB" << endl;
	cout << "1 игрок или 2 игрока? 1/2?" << endl;
	cin >> mode;
	cout << "Нажмите F10, чтобы открыть командную строку." << endl;

again:

	if ((player == 2) && (mode == 1)) {
		bot(botA, botB);
		goto afterbot;
	}

	pole();

retry:

	cout << "Нажмите любую клавишу для продолжения..." << endl;
	int key = _getch();

	if (key == 0) {
		int ng = cmd(a, b, wins);
		if (ng == 1) {
			goto newgame;
		}
		ofstream file(settings, ios::out);
		file << wins[0] << " " << wins[1];//Запись новых значений
	}

next:

	cout << "Ход игрока " << player << ": ";
	cin >> a >> b;

	if ((a > 10) || (b > 10) || (a < 1) || (b < 1)) {
		cout << "ОШИБКА! ВЫ ВВЕЛИ КООРДИНАТЫ ЗА ПРЕДЕЛАМИ ПОЛЯ!" << endl;
		goto next;
	}

	check = hod(a, b);

	if (check == 1) {
		cout << "ОШИБКА! КЛЕТКА ЗАНЯТА!" << endl;
		goto next;
	}
	botA = a;
	botB = b;
	hod(a, b);

afterbot:

	int end = endgamecheck();

	if (end == 1) {
		pole();
		cout << "Игрок " << player << " победил!" << endl;
		wins[player - 1]++;
		cout << "Счёт: Игрок 1 (" << wins[0] << " : " << wins[1] << ") Игрок 2" << endl;
		ofstream file(settings, ios::out);
		file << wins[0] << " " << wins[1];//Запись новых значений
		cout << "Хотите начать заново? y/n?: ";

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
			cout << "ОШИБКА!" << endl;
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
