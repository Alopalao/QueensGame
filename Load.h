#pragma once
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;
string Search(string& ex) {
	string word = "";
	int i;
	for (i = 0; i < ex.size(); i++) {
		if (ex[i] == ' ') {
			break;
		}
		word = word + ex[i];
	}
	ex.erase(0, i + 1);
	return word;
}
void QueensLoad(int*& queens, int& pointHu, int& pointCom, int& turn, int& The_End, int& n, int& free, int& time) {
	ifstream file;
	string ex = "";
	string aux = "";
	file.open("Saved.txt");
	int cont = 0;
	while (getline(file, ex)) {
		aux = Search(ex);
		queens[0] = atoi(aux.c_str());
		aux = Search(ex);
		queens[1] = atoi(aux.c_str());
		aux = Search(ex);
		queens[2] = atoi(aux.c_str());
		aux = Search(ex);
		queens[3] = atoi(aux.c_str());
		aux = Search(ex);
		queens[4] = atoi(aux.c_str());
		aux = Search(ex);
		queens[5] = atoi(aux.c_str());
		aux = Search(ex);
		queens[6] = atoi(aux.c_str());
		aux = Search(ex);
		queens[7] = atoi(aux.c_str());
		aux = Search(ex);
		pointHu = atoi(aux.c_str());
		aux = Search(ex);
		pointCom = atoi(aux.c_str());
		aux = Search(ex);
		turn = atoi(aux.c_str());
		aux = Search(ex);
		The_End = atoi(aux.c_str());
		aux = Search(ex);
		n = atoi(aux.c_str());
		aux = Search(ex);
		free = atoi(aux.c_str());
		aux = Search(ex);
		time = atoi(aux.c_str());
	}
	file.close();
}