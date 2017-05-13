#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cmath>
using namespace std;

int BinToTen(int ch) {
	int m; //poslednaya cifra
	int n=0; //Samo chislo v 10 st;
	int i = 0;
	while (ch > 0) {
		m = ch % 10;
		n = n + m*pow(2, i);
		i++;
		ch = ch / 10;
	}
	return n;
}

string ExePath() {
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

int main() {
	setlocale(LC_ALL, "rus");
	system("title Bin to Ten by RingoB");
	ofstream file;
	ifstream get; 
	string OutName = "Out";
	string GetName = "Get";
	string settings = ExePath() + "\\" + OutName + ".txt";
	string getSettings = ExePath() + "\\" + GetName + ".txt";
	int code[1000];
	int count = 0;
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
		cout << "Не найден файл \"Get.txt\"! Убедитесь, что он находится в папке с программой." << endl;
		_getch();
		return 0;
	}
	char answer;
	cout << "Load from file? (y/n): ";
	cin >> answer;
	if (answer == 'n') {
		for (;;count++) {
			cin >> code[count];
			if (code[count] == 1337) {
				break;
			}
		}
	}
	else if (answer == 'y') {
		for (;;count++) {
			get >> code[count];
			if (code[count] == 1337) {
				break;
			}
		}
	}
	for (int i = 0;i<count;i++) {
		int n = BinToTen(code[i]);
		cout << n << endl;
		file << n << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}
