#pragma once
#include <math.h>
#include "Save.h"
#include "Load.h"
#include "Game.h"
#include "Queens.h"
using namespace System;
class ArrGame {
private:
	Game** arrGame;
	int n;
	int pointHu;
	int pointCom;
	int The_End;
	int turn;
	int free;
	int time;
	int count;
	int* queens;
public:
	int* auxqueens;
public:
	ArrGame() {
		time = 0;
		turn = 0;
		The_End = 0;
		pointHu = 0;
		pointCom = 0;
		n = 0;
		free = 0;
		arrGame = new Game * [n];
		queens = new int[8];
		auxqueens = new int[8];
		count = 0;
		for (int i = 0; i < 8; i++) {
			queens[i] = -1;
			auxqueens[i] = -1;
		}
	}
	~ArrGame() {
		time = 0;
		turn = 0;
		for (int i = 0; i < n; i++) {
			delete arrGame[i];
		}
		delete arrGame;
		pointHu = 0;
		pointCom = 0;
		n = 0;
		The_End = 0;
		for (int i = 0; i < 8; i++) {
			queens[i] = -1;
			auxqueens[i] = -1;
		}
	}
	int Com_points() {
		return pointCom;
	}
	int Hu_points() {
		return pointHu;
	}
	int The_time() {
		time++;
		return time;
	}
	bool Check(int ini) {
		if (ini >= 7) {
			The_End = 1;
			return false;

		}
		if (queens[ini] == -1) {
			for (int w = 0; w < 8; w++) {
				if (Available(w, ini) == true) {
					return true;
				}
			}
		}
		return Check(ini + 1);
	}
	int The_turn() {
		return turn;
	}
	int End() {
		return The_End;
	}
	int Num() {
		Random r;
		int x = 0;
		for (int i = 0; i < 1000; i++) {
			x = r.Next(0, 7);
			if (queens[x] == -1) {
				return x;
			}
		}
	}
	void DrawTable(Graphics^ g) {
		g->DrawImage(gcnew Bitmap("Table.png"), 9, 8, 449, 487);
	}
	bool Free(int rcol, int rfil) {
		if (queens[rfil] == -1) {
			return Available(rcol, rfil);
		}
		else {
			return false;
		}
	}
	bool Available(int rcol, int rfila) {
		for (int fil = 0; fil < 8; fil++) {
			int col = queens[fil];
			if (col != -1 && (col != rcol || rfila != fil)) {
				if (fil == rfila)
					return false;
				if (col == rcol)
					return false;
				if (abs(fil - rfila) == abs(col - rcol))
					return false;
			}
		}
		return true;
	}
	bool Huma_PutQueen(int col, int fila) {

		Add_queen(col, fila);
		if (Free(col, fila) == true) {
			SaveAll();
			queens[fila] = col;
			pointHu += 10;
			turn = 1;
			time = 0;
			return true;
		}
		else {
			pointHu -= 5;
			Delete();
			return false;
		}

	}
	bool Add_queen(int x, int y) {

		float col = x * 54.15 + 18;
		float fil = y * 58.25 + 23;
		Game** aux = new Game * [n + 1];
		for (int w = 0; w < n; w++) {
			aux[w] = arrGame[w];
		}
		aux[n] = new Queens(int(col), int(fil), 50, 50, 0);
		delete arrGame;
		arrGame = aux;
		n = n + 1;
		return true;
	}
	void Delete() {
		Game** aux = new Game * [n - 1];
		for (int i = 0; i < n - 1; i++) {
			aux[i] = arrGame[i];
		}
		delete arrGame;
		arrGame = aux;
		n = n - 1;
	}
	void Draw(Graphics^ g) {
		for (int i = 0; i < n; i++) {
			arrGame[i]->DrawIm(g);
		}
		g->DrawString("Human points: " + pointHu, gcnew Font("Arial", 10), gcnew SolidBrush(Color::Black), 500, 100);
		g->DrawString("Computer points: " + pointCom, gcnew Font("Arial", 10), gcnew SolidBrush(Color::Black), 480, 120);

	}
	bool Com_PutQueen() {
		int fila = Num();
		for (int i = 0; i < 8; i++) {
			if (Available(i, fila) == true) {
				time = 0;
				pointCom += 10;
				queens[fila] = i;
				Add_queen(i, fila);
				turn = 0;
				return true;
			}
		}
		return Com_PutQueen();
	}
	void SaveAll() {
		Save(queens, pointHu, pointCom, turn, The_End, n, free, time);
	}
	void Load() {
		if (count < 3) {
			count++;
			int lol;
			QueensLoad(queens, pointHu, pointCom, turn, The_End, n, free, time);
			Delete();
			for (int i = 0; i < 8; i++) {
				lol = queens[i];
				if (lol != -1) {
					Add_queen(lol, i);
				}
			}
		}

	}
};