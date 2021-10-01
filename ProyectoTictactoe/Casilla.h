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
	Casilla(int f, char c);
	~Casilla();
	void mostrarCasilla();
	int getFila();
	char getColumna();
	string getValor();
	void setValor(string v);
};
Casilla::Casilla(int f, char c)
{
	this->fila = f;
	this->columna = c;
	valor ="_";
	
}
Casilla::~Casilla()
{

}
void Casilla::mostrarCasilla()
{
	cout << " " << valor << " ";
}
int Casilla::getFila()
{
	return fila;
}
char Casilla::getColumna()
{
	return columna;
}
string Casilla::getValor()
{
	return valor;
}
void Casilla::setValor(string v)
{
	valor = v;
}