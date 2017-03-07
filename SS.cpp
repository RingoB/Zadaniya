#include <iostream>
#include <fstream>
using namespace std;


void perevod(int ch, int st) {
	if (ch >= st) {
		perevod(ch / st, st);
	}
	if (st > 10) {
		if (ch%st == 10) {
			cout << "a";
		}
		if (ch%st == 11) {
			cout << "b";
		}
		if (ch%st == 12) {
			cout << "c";
		}
		if (ch%st == 13) {
			cout << "d";
		}
		if (ch%st == 14) {
			cout << "e";
		}
		if (ch%st == 15) {
			cout << "f";
		}
	}
	else {
		cout << ch % st;
	}
}

int main() {
	int ch;
	int st;
	cin >> ch >> st;
	perevod(ch, st);
	return 0;
}
