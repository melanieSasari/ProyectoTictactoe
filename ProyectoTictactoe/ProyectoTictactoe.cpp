#include <iostream>
#include "Casilla.h"

int main()
{
    std::cout << "Hello World!\n";
    Casilla** lista = new Casilla* [3];
    for (int i = 0;i < 3;i++)
    {
        lista[i] = new Casilla(i, 'a');
    }
    for (int i = 0;i < 3;i++)
    {
        lista[i]->mostrarCasilla();
    }
    cout << endl;

    lista[2]->setValor("X");

    for (int i = 0;i < 3;i++)
    {
        lista[i]->mostrarCasilla();
    }
}

