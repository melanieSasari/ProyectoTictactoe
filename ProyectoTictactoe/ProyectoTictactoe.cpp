#include <iostream>
#include "Casilla.h"
#include "Estado.h"
int tam = 0;

char jugador;
char computadora;

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
    int ind = 0;
    for (int fil = 0;fil < tam ;fil++)
    {
        aux = 0;
        for (int col = 0;col < tam - 1;col++)
        {
            if (lista[ind]->getValor() == lista[ind + 1]->getValor())
            {
                aux++;
            }
            ind++;
        } 
        if (aux == tam - 1 && lista[ind]->getValor() == 'X')
        {
            return +1;
        }
        else if(aux == tam-1 && lista[ind]->getValor() == 'O')
        {
            return -1;
        }
        
    }
    //verificar por columnas
    for (int fil = 0;fil < tam;fil++)
    {
        aux = 0;
        ind = fil;
        for (int col = 0;col < tam-1;col=col++)
        {
            if (lista[ind]->getValor() == lista[ind+tam]->getValor())
            {
                aux++;
            }
            ind = ind + tam;
        }
        if (aux == tam - 1 && lista[ind]->getValor() == 'X')
        {
            return +1;
        }
        else if (aux == tam - 1 && lista[ind]->getValor() == 'O')
        {
            return -1;
        }
       
    }
    //verificar en diagonal
    aux = 0;
    for (int col = 0;col < tam * tam-tam;col = col + tam+1)
    {
        if (lista[col]->getValor() == lista[col+tam+1]->getValor())
        {
            aux++;
        }
        if (aux == tam - 1 && lista[col + tam + 1]->getValor() == 'X')
        {
            return +1;
        }
        else if (aux == tam - 1 && lista[col + tam + 1]->getValor() == 'O')
        {
            return -1;
        }
    }

    aux = 0;
    //verificar en diagonal
    for (int col = tam-1;col < tam * tam-tam;col = col + tam - 1)
    {
        if (lista[col]->getValor() == lista[col + tam - 1]->getValor())
        {
            aux++;
        }
        if (aux == tam - 1 && lista[col + tam - 1]->getValor() == 'X')
        {
            return +1;
        }
        else if (aux == tam - 1 && lista[col + tam - 1]->getValor() == 'O')
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
        if (jugador == 'X')
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
        if (jugador == 'O')
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
            if (estadoJuego.getLista()[i]->getValor() == '_')
            {
                estadoJuego.cambiarCasilla(estadoJuego.getLista()[i]->getFila(), estadoJuego.getLista()[i]->getColumna(),'X');
                aux = max(aux, minmax(estadoJuego, nivel + 1, !maximo));
                estadoJuego.cambiarCasilla(estadoJuego.getLista()[i]->getFila(), estadoJuego.getLista()[i]->getColumna(), '_');
            }
        }
        return aux;
    }
    else
    {
        int aux = 1000;
        for (int i = 0;i < tam * tam;i++)
        {
            if (estadoJuego.getLista()[i]->getValor() == '_')
            {
                estadoJuego.cambiarCasilla(estadoJuego.getLista()[i]->getFila(), estadoJuego.getLista()[i]->getColumna(), 'O');
                aux = min(aux, minmax(estadoJuego, nivel + 1, maximo));
                estadoJuego.cambiarCasilla(estadoJuego.getLista()[i]->getFila(), estadoJuego.getLista()[i]->getColumna(), '_');
            }
        }
        return aux;
    }
}
void turnoComputadora(Estado estadoJuego)
{
    int fila=0;
    char columna=' ';

    int valor;
    if (computadora == 'X')
    {
        valor = -1000;
        for (int i = 0;i < tam * tam;i++)
        {
            if (estadoJuego.getLista()[i]->getValor() == '_')
            {
                estadoJuego.getLista()[i]->setValor(computadora);
                int valorAux = minmax(estadoJuego, 0, false);
                estadoJuego.getLista()[i]->setValor('_');

                if (valorAux > valor)
                {
                    fila = estadoJuego.getLista()[i]->getFila();
                    columna = estadoJuego.getLista()[i]->getColumna();
                    valor = valorAux;
                }
            }
        }
    }
    else
    {
        valor = 1000;
        for (int i = 0;i < tam * tam;i++)
        {
            if (estadoJuego.getLista()[i]->getValor() == '_')
            {
                estadoJuego.getLista()[i]->setValor(computadora);
                int valorAux = minmax(estadoJuego, 0, true);
                estadoJuego.getLista()[i]->setValor('_');

                if (valorAux < valor)
                {
                    fila = estadoJuego.getLista()[i]->getFila();
                    columna = estadoJuego.getLista()[i]->getColumna();
                    valor = valorAux;
                }
            }
        }
    }
    
    
    for (int i = 0;i < tam * tam;i++)
    {
        if (estadoJuego.getLista()[i]->getFila() == fila && estadoJuego.getLista()[i]->getColumna() == columna)
        {
            estadoJuego.getLista()[i]->setValor(computadora);
        }
    }
    
}
void turnoJugador(Estado estadoJuego)
{
    int f;
    char c;
    cout << "Ingrese la fila(1, 2,.. N) : ";
    cin >> f;
    cout << "Ingrese la columna(a, b,.. N) : ";
    cin >> c;
    for (int i = 0;i < tam * tam;i++)
    {
        if (estadoJuego.getLista()[i]->getFila() == f && estadoJuego.getLista()[i]->getColumna() == c&& estadoJuego.getLista()[i]->getValor()=='_')
        {
            estadoJuego.getLista()[i]->setValor(jugador);
        }
    }
    
}
void juego(Estado estadoJuego)
{
    while (!terminalTest(estadoJuego))
    {
        if (jugador == 'X')
        {
            turnoJugador(estadoJuego);
            estadoJuego.mostrarCasillas();
            cout << endl;
            turnoComputadora(estadoJuego);
            estadoJuego.mostrarCasillas();
            cout << endl;
        }
        else
        {
            turnoComputadora(estadoJuego);
            estadoJuego.mostrarCasillas();
            cout << endl;
            turnoJugador(estadoJuego);
            estadoJuego.mostrarCasillas();
            cout << endl;
        }

    }
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
    char op;
    cout << "Elija que ficha jugara X o O: " << endl;
    cin >> op;
    if (op == 'X')
    {
        jugador = 'X';
        computadora = 'O';
    }
    else
    {
        jugador = 'O';
        computadora = 'X';
    }
    
    Estado estadoJuego(tam);
    Estado estadoInicial(tam);
    estadoJuego.crearEstadoInicial();
	
    estadoInicial.crearEstadoInicial();

    juego(estadoJuego);
}

