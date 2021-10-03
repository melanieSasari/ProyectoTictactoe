#pragma once
#include <iostream>
#include <string>
using namespace std;
class Casilla
{
private:
	int fila;
	char columna;
	char valor;
public:
	Casilla(int f, char c) {
		this->fila = f;
		this->columna = c;
		valor = '_';
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
	char getValor() {
		return valor;
	}
	void setValor(char v) {
		valor = v;
	}
};
