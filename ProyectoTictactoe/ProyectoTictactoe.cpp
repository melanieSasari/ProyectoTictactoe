#include <iostream>
#include "Casilla.h"
#include "Estado.h"

int main()
{
    Estado* estadoInicial = new Estado(3);
    estadoInicial->crearEstadoInicial();
    estadoInicial->mostrarCasillas();
    estadoInicial->cambiarCasilla(1, 'B', "X");
    estadoInicial->cambiarCasilla(2, 'B', "X");
    estadoInicial->cambiarCasilla(3, 'B', "X");
    estadoInicial->mostrarCasillas();
   
}

