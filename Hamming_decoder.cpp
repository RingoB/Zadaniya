//
//
//НЕТУ ЛЕСТНИЦЫ
//ИЗВИНИТЕ
//Я УСТАЛ
//ПИСАЛ ЭТО НОЧЬЮ
//ВРОДЕ РАБОТАЕТ
//
//

//
// 1337 - снова стоп слово
//


#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

int BinToTen(int ch) {
	int m; //poslednaya cifra
	int n = 0; //Samo chislo v 10 st;
	int i = 0;
	while (ch > 0) {
		m = ch % 10;
		n = n + m*pow(2, i);
		i++;
		ch = ch / 10;
	}
	return n;
}

int* chToMass(long long int chislo) {
	int mass[15];
	int k;
	long long int l = chislo;
	int y = 0;
	int x;
	while (l > 0) {
		l = l / 10;
		y++;
	}
	if (y < 15) {
		x = 15 - y;
		for (int i = 14;i >= 0;i--) {
			if (i == (x - 1)) {
				mass[i] = 0;
			}
			else {
				k = chislo % 10;
				mass[i] = k;
				chislo = chislo / 10;
			}
		}
	}
	else {
		for (int i = 14;i >= 0;i--) {
			k = chislo % 10;
			mass[i] = k;
			chislo = chislo / 10;
		}
	}
	return mass;
}

int* hemming(long long int curr) {
	int st;
	int mass[15];
	int sum = 0;
	for (int i = 0;i < 15;i++)
		*(mass+i) = *(chToMass(curr)+i);
again:
	int sec1=0, sec2=0, sec4=0, sec8=0;
	for (int i = 0;i < 4;i++) {
		if (i == 0) {
			if (mass[0] == 1) {
				sec1++;
			}
			if (mass[2] == 1) {
				sec1++;
			}
			if (mass[4] == 1) {
				sec1++;
			}
			if (mass[6] == 1) {
				sec1++;
			}
			if (mass[8] == 1) {
				sec1++;
			}
			if (mass[10] == 1) {
				sec1++;
			}
			if (mass[12] == 1) {
				sec1++;
			}
			if (mass[14] == 1) {
				sec1++;
			}
		}
		if (i == 1) {
			if (mass[1] == 1) {
				sec2++;
			}
			if (mass[2] == 1) {
				sec2++;
			}
			if (mass[5] == 1) {
				sec2++;
			}
			if (mass[6] == 1) {
				sec2++;
			}
			if (mass[9] == 1) {
				sec2++;
			}
			if (mass[10] == 1) {
				sec2++;
			}
			if (mass[13] == 1) {
				sec2++;
			}
			if (mass[14] == 1) {
				sec2++;
			}
		}
		if (i == 2) {
			if (mass[3] == 1) {
				sec4++;
			}
			if (mass[4] == 1) {
				sec4++;
			}
			if (mass[5] == 1) {
				sec4++;
			}
			if (mass[6] == 1) {
				sec4++;
			}
			if (mass[11] == 1) {
				sec4++;
			}
			if (mass[12] == 1) {
				sec4++;
			}
			if (mass[13] == 1) {
				sec4++;
			}
			if (mass[14] == 1) {
				sec4++;
			}
		}
		if (i == 3) {
			if (mass[7] == 1) {
				sec8++;
			}
			if (mass[8] == 1) {
				sec8++;
			}
			if (mass[9] == 1) {
				sec8++;
			}
			if (mass[10] == 1) {
				sec8++;
			}
			if (mass[11] == 1) {
				sec8++;
			}
			if (mass[12] == 1) {
				sec8++;
			}
			if (mass[13] == 1) {
				sec8++;
			}
			if (mass[14] == 1) {
				sec8++;
			}
		}
	}
	int error=0000;
	if (sec8 % 2 != 0) {
		error = 1000;
	}
	if (sec4 % 2 != 0) {
		error += 100;
	}
	if (sec2 % 2 != 0) {
		error += 10;
	}
	if (sec1 % 2 != 0) {
		error += 1;
	}
	sum = BinToTen(error);
	if (sum == 0) {
		//ok, go to the next step;
	}
	else {
		int currER = mass[sum-1];
		if (currER == 1) {
			mass[sum - 1] = 0;
		}
		else if (currER == 0) {
			mass[sum - 1] = 1;
		}
		goto again;
	}
	int finalmass[11];
	int count = 0;
	for (int i = 0;i < 15;i++) {
		if ((i == 0) || (i == 1) || (i == 3) || (i == 7)) {

		}
		else {
			finalmass[count] = mass[i];
			count++;
		}
	}
	return finalmass;
}


string ExePath() {
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

int main() {
	setlocale(LC_ALL, "rus");
	system("title Hamming Decoder by RingoB");
	ofstream file;
	ifstream get;
	string OutName = "OutString";
	string GetName = "GetCode";
	string settings = ExePath() + "\\" + OutName + ".txt";
	string getSettings = ExePath() + "\\" + GetName + ".txt";
	long long int code;
	int massCode[15];
	int count = 0;
	int sec1, sec2, sec4, sec8;
	int newMass[11];
	file.open(settings);
	if (file) {
		//ok. go to the next step.
	}
	else {
		ofstream file(settings, ios::out);
		ifstream get(getSettings);
	}
	get.open(getSettings);
	if (get) {
		//ok. go to the next step.
	}
	else {
		cout << "Не найден файл \"GetCode.txt\"! Убедитесь, что он находится в папке с программой." << endl;
		_getch();
		return 0;
	}
	char answer;
	cout << "Load from file? (y/n): ";
	cin >> answer;
	if (answer == 'n') {
		for (;;) {
			cin >> code;
			if (code == 1337) {
				break;
			}
			for (int i = 0;i < 11;i++)
			*(newMass+i) = *(hemming(code)+i);
			for (int i = 0;i < 11;i++) {
				file << newMass[i];
			}
			cout << " ";
		}
	}
	else if (answer == 'y') {
		for (;;) {
			get >> code;
			if (code == 1337) {
				cout << "OK!";
				break;
			}
			for (int i = 0;i < 11;i++)
				*(newMass + i) = *(hemming(code) + i);
			for (int i = 0;i < 11;i++) {
				file << newMass[i];
			}
			file << " ";
		}
	}
	system("pause");
}
