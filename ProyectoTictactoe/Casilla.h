#pragma once
#include <iostream>
#include <string>
using namespace std;
class Casilla
{
private:
	int fila;
	char columna;
	string valor;
public:
	Casilla(int f, char c) {
		this->fila = f;
		this->columna = c;
		valor = "_";
	}
	~Casilla(){}
	void mostrarCasilla() {
		cout << " " << valor << " ";
	}
	int getFila() {
		return fila;
	}
	char getColumna() {
		return columna;
	}
	string getValor() {
		return valor;
	}
	void setValor(string v) {
		valor = v;
	}
};
