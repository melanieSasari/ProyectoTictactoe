#pragma once
#include "Casilla.h"
class Estado
{
private:
	int TAM;
	Casilla** lista;
public:
	Estado(int t) {
		this->TAM = t;
		lista = new Casilla * [TAM];
	}
	~Estado() {}
	void crearEstadoInicial() {
		int ind = 0;
		for (int i = 1;i <=TAM;i++)
		{
			for (char aux = 'A';aux <'A'+TAM;aux++)
			{
				lista[ind] = new Casilla(i, aux);
				ind++;
			}
		}
	}
	void mostrarCasillas() {
		int ind = 0;
		for (int i = 1;i <= TAM;i++)
		{
			for (char aux = 'A';aux < 'A' + TAM;aux++)
			{
				lista[ind]->mostrarCasilla();
				ind++;
			}
			cout << endl;
		}
	}
	void cambiarCasilla(int f, char c,string v) {
		for (int i = 0;i < TAM * TAM;i++)
		{
			if (lista[i]->getFila() == f, lista[i]->getColumna() == c)
			{
				lista[i]->setValor(v);
			}
		}
	}
};

