//
//
//
// FILE "GetCode.txt" SHOULD BE ALWAYS IN FOLDER WITH THIS PROGRAMM
//
//
// 1337 = stop (end) 
//


#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

string ExePath() {
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

int main() {
	setlocale(LC_ALL, "rus");
	system("title ASCII DECODER by RingoB");
	ofstream file;
	ifstream get; 
	string OutName = "OutString";
	string GetName = "GetCode";
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
			cout << "Не найден файл \"GetCode.txt\"! Убедитесь, что он находится в папке с программой." << endl;
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
		cout << (char)code[i];
		file << (char)code[i];
	}
	cout << endl;
	system("pause");
	return 0;
}
