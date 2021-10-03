#include <iostream>
#include "Casilla.h"
#include "Estado.h"
int tam = 0;

struct Accion
{
    int fila;
    char col;
};
string jugador;
string computadora;

int max(int num1, int num2) {
    int result;
    if (num1 > num2) {
        result = num1;
    }
    else {
        result = num2;
    }
    return result;
}
int min(int num1, int num2) {
    int result;
    if (num1 < num2) {
        result = num1;
    }
    else {
        result = num2;
    }
    return result;
}

int utilidad(Estado estadoJuego)
{
    Casilla** lista = estadoJuego.getLista();
    int aux = 0;
    //verificar por filas
    int col = 0;
    for (int fil = col;fil < tam ;fil++)
    {
        aux = 0;
        for (col = fil;col < tam - 1+fil;col++)
        {
            if (lista[col]->getValor() == lista[col + 1]->getValor())
            {
                aux++;
            }
            if (aux == tam - 1 && lista[col+1]->getValor() == "X")
            {
                return +1;
            }
            else if(aux == tam-1 && lista[col + 1]->getValor() == "O")
            {
                return -1;
            }
        } 
        
        
        
    }
    //verificar por columnas
    for (int fil = 0;fil < tam;fil++)
    {
        aux = 0;
        for (int col = fil;col < tam*tam-tam;col=col+tam)
        {
            if (lista[col]->getValor() == lista[col + tam]->getValor())
            {
                aux++;
            }
            if (aux == tam - 1 && lista[col+tam]->getValor() == "X")
            {
                return +1;
            }
            else if (aux == tam - 1 && lista[col+tam]->getValor() == "O")
            {
                return -1;
            }
        }
       
    }
    //verificar en diagonal
   
    for (int col = 0;col < tam * tam-tam;col = col + tam+1)
    {
        if (lista[col]->getValor() == lista[col+tam+1]->getValor())
        {
            aux++;
        }
        if (aux == tam - 1 && lista[col + tam + 1]->getValor() == "X")
        {
            return +1;
        }
        else if (aux == tam - 1 && lista[col + tam + 1]->getValor() == "O")
        {
            return -1;
        }
    }

    
    //verificar en diagonal
    for (int col = tam-1;col < tam * tam-tam;col = col + tam - 1)
    {
        if (lista[col]->getValor() == lista[col + tam - 1]->getValor())
        {
            aux++;
        }
        if (aux == tam - 1 && lista[col + tam - 1]->getValor() == "X")
        {
            return +1;
        }
        else if (aux == tam - 1 && lista[col + tam - 1]->getValor() == "O")
        {
            return -1;
        }
    }
    
    return 0;
}
bool terminalTest(Estado estadoJuego)
{
    int puntaje = utilidad(estadoJuego);
    if (puntaje == 1)
    {
        if (jugador == "X")
        {
            cout << "Tu ganaste!!!" << endl;
        }
        else
        {
            cout << "Gano la computadora!!!" << endl;
        }
        return true;
    }
    if (puntaje == -1)
    {
        if (jugador == "O")
        {
            cout << "Tu ganaste!!!" << endl;
        }
        else
        {
            cout << "Gano la computadora!!!" << endl;
        }
        return true;
    }
    if (estadoJuego.hayCasillasDisponibles() == false)
    {
        cout << "Empate!!!" << endl;
        return true;
    }

    return false;
}
int minmax(Estado estadoJuego, int nivel, bool maximo)
{
    int puntaje = utilidad(estadoJuego);
    if (puntaje == 1)
    {
        return puntaje;
    }
    if (puntaje == -1)
    {
        return puntaje;
    }
    if (estadoJuego.hayCasillasDisponibles() == false)
    {
        return 0;
    }
    if (maximo)
    {
        int aux = -1000;
        for (int i = 0;i < tam*tam;i++)
        {
            if (estadoJuego.getLista()[i]->getValor() == "_")
            {
                estadoJuego.cambiarCasilla(estadoJuego.getLista()[i]->getFila(), estadoJuego.getLista()[i]->getColumna(),"X");
                aux = max(aux, minmax(estadoJuego, nivel + 1, !maximo));
                estadoJuego.cambiarCasilla(estadoJuego.getLista()[i]->getFila(), estadoJuego.getLista()[i]->getColumna(), "_");
            }
        }
        return aux;
    }
    else
    {
        int aux = 1000;
        for (int i = 0;i < tam * tam;i++)
        {
            if (estadoJuego.getLista()[i]->getValor() == "_")
            {
                estadoJuego.cambiarCasilla(estadoJuego.getLista()[i]->getFila(), estadoJuego.getLista()[i]->getColumna(), "O");
                aux = max(aux, minmax(estadoJuego, nivel + 1, !maximo));
                estadoJuego.cambiarCasilla(estadoJuego.getLista()[i]->getFila(), estadoJuego.getLista()[i]->getColumna(), "_");
            }
        }
        return aux;
    }


}

Accion preguntarCasilla()
{
    int f;
    char c;
    cout << "Ingrese la fila(1, 2,.. N) : ";
    cin >> f;
    cout << "Ingrese la columna(a, b,.. N) : ";
    cin >> c;
    return { f,c };
}
int main()
{
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
    string op;
    cout << "Elija que ficha jugara X o O: " << endl;
    cin >> op;
    if (op == "X")
    {
        jugador = "X";
        computadora = "O";
    }
    else
    {
        jugador = "O";
        computadora = "X";
    }
    
    Estado estadoJuego(tam);
    estadoJuego.crearEstadoInicial();
	Estado estadoInicial(tam);
    estadoInicial.crearEstadoInicial();

    bool i = terminalTest(estadoInicial);
    cout << "utilidad: " << i << endl;
    estadoInicial.mostrarCasillas();
    estadoJuego.cambiarCasilla(1, 'A', "X");
    estadoJuego.cambiarCasilla(2, 'B', "X");
    estadoJuego.cambiarCasilla(3, 'C', "X");
    i= terminalTest(estadoJuego);
    cout << "utilidad: " << i << endl;
    estadoJuego.mostrarCasillas();
}

