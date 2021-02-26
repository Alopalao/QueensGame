#pragma once
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;
void Save(int* queens, int pointHu, int pointCom, int turn, int The_End, int n, int free, int time) {
	ofstream archivo;
	archivo.open("Saved.txt");
	for (int i = 0; i < 8; i++) {
		archivo << to_string(queens[i]) + ' ';
	}
	archivo << to_string(pointHu) + ' ' + to_string(pointCom) + ' ' + to_string(turn) + ' ' + to_string(The_End) + ' ' + to_string(n) + ' ' + to_string(free) + ' ' + to_string(time);
	archivo.close();
}