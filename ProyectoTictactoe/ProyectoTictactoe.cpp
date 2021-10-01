#include <iostream>
#include "Casilla.h"
#include "Estado.h"
int tam = 0;
int utilidad(Estado* estadoJuego,string jugador)
{
    Casilla** lista = estadoJuego->getLista();
    int aux;
    //verificar por filas
    for (int fil = 0;fil < tam;fil++)
    {
        aux = 0;
        for (int col = fil;col < tam;col++)
        {
            if (lista[col]->getValor() == jugador)
            {
                aux++;
            }
        }
        if (aux == tam && jugador=="X")
        {
            return +1;
        }
        else if(aux == tam && jugador == "O")
        {
            return -1;
        }
    }
    //verificar por columnas
    for (int fil = 0;fil < tam;fil++)
    {
        aux = 0;
        for (int col = fil;col < tam*tam;col=col+tam)
        {
            if (lista[col]->getValor() == jugador)
            {
                aux++;
            }
        }
        if (aux == tam && jugador == "X")
        {
            return +1;
        }
        else if (aux == tam && jugador == "O")
        {
            return -1;
        }
    }
    //verificar en diagonal
   
    for (int col = 0;col < tam * tam;col = col + tam+1)
    {
        if (lista[col]->getValor() == jugador)
        {
            aux++;
        }
    }
    if (aux == tam && jugador == "X")
    {
        return +1;
    }
    else if (aux == tam && jugador == "O")
    {
        return -1;
    }
    
    //verificar en diagonal
    for (int col = tam;col < tam * tam;col = col + tam + 1)
    {
        if (lista[col]->getValor() == jugador)
        {
            aux++;
        }
    }
    if (aux == tam && jugador == "X")
    {
        return +1;
    }
    else if (aux == tam && jugador == "O")
    {
        return -1;
    }
}

void preguntarCasilla()
{
    int f;
    char c;
    cout << "Ingrese la fila(1, 2,.. N) : ";
    cin >> f;
    cout << "Ingrese la columna(a, b,.. N) : ";
    cin >> c;
}
int main()
{

    int tam = 0;
    int dificultad;
    cout << "Ingrese el nivel de dificultad 1.facil 2.medio 3.dificil: " << endl;
    cin >> dificultad;
    if (dificultad == 1)
    {
        tam = 3;
    }
    else
    { 
        if (dificultad == 2)
        {
            tam = 4;
        }
        else{
            tam = 5;
        }

    }
    
    Estado* estadoJuego= new Estado(tam);

	Estado* estadoInicial = new Estado(tam);
    estadoInicial->crearEstadoInicial();
    estadoInicial->mostrarCasillas();
    estadoInicial->cambiarCasilla(1, 'B', "X");
    estadoInicial->cambiarCasilla(2, 'B', "X");
    estadoInicial->cambiarCasilla(3, 'B', "X");
    estadoInicial->mostrarCasillas();
}

