#include <iostream>
#include <ctime>
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
	system("title Password Generator v0.1 Alpha. by RingoB");
	cout << "Welcome!" << endl;
	begin:
	srand(time(0));
	ofstream file;
	int size;
	int figures;
	int fgtotal=0;
	int smbls;
	int smtotal=0;
	int ch;
	string Bword[26] = {"A","B","C","D","E","F", "G","H","I","J","K","L", "M","N","O","P","Q","R", "S","T","U","V","W","X","Y","Z" };
	string Lword[26] = {"a","b","c","d","e","f", "g","h","i","j","k","l", "m","n","o","p","q","r", "s","t","u","v","w","x","y","z" };
	string symbols[8] = { "*", "=",")","-","(","+", "/",".",};
	string password[50];
	string name;
	cout << "Enter file name: ";
	cin >> name;
	string numb[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	string settings = ExePath() + "\\"+name+".txt"; 
	file.open(settings);
	if (file) {
  //ok. go to next step.
	}
	else {
		ofstream file(settings, ios::out);
	}
	ntry:
	cout << "Enter length (Max 50): ";
	cin >> size;
	cout << "Figures count: ";
	cin >> figures;
	cout << "Symbols count: ";
	cin >> smbls;
	if (figures + smbls > size) {
		cout << "Error. Try to input less Symbols/Figures or a longer lenght." << endl;
		goto ntry;
	}
	for (int i = 0;i < size;i++) {
	retry:
		ch = 1 + rand() % 4;
		if (ch == 1) {
			ch = 0 + rand() % 25;
			password[i] = Bword[ch];

		}
		else if (ch == 2) {
			ch = 0 + rand() % 25;
			password[i] = Lword[ch];
		}
		else if (ch == 3) {
			if (fgtotal <= figures) {
				ch = 0 + rand() % 9;
				password[i] = numb[ch];
				fgtotal++;
			}
			else {
				goto retry;
			}
		}
		else if (ch == 4) {
			if (smtotal <= smbls) {
				ch = 0 + rand() %7;
				password[i] = symbols[ch];
				smtotal++;
			}
			else {
				goto retry;
			}
		}
	}
	for (int i = 0;i < size;i++) {
		cout << password[i];
		file<<password[i];
	}
	char otvet;
	cout << endl<< "One more? [Y/N]: ";
	cin >> otvet;
	if ((otvet == 'y') || (otvet == 'Y')) {
		goto begin;
	}
	else {

	}
	}
