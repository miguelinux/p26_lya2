/*
Graciela Mora Esparza 210111853
Carlos Santiago Ramírez Sandoval 220111400
Omar Ulises Hernandez Perez 220111901

*/
#include <iostream>
#include <string>
#include <cctype>
#include "estados.h"

using namespace std;

int analiza(string str)
{
    int estado = E_INICIAL;

    for (size_t i = 0; i < str.length(); i++)
    {
        char c = str[i];

        switch (estado)
        {
        case E_INICIAL:
            if (c == '+' || c == '-')
                estado = E_SIGNO;
            else if (isdigit(c))
                estado = E_ENTERO;
            else
                return E_ERROR;
            break;

        case E_SIGNO:
            if (isdigit(c))
                estado = E_ENTERO;
            else
                return E_ERROR;
            break;

        case E_ENTERO:
            if (isdigit(c))
                estado = E_ENTERO;
            else if (c == '.')
                estado = E_FLOTANTE;
            else if (c == 'e' || c == 'E')
                estado = E_NOTA_CIEN;
            else
                return E_ERROR;
            break;

        case E_FLOTANTE:
            if (isdigit(c))
                estado = E_FLOTANTE;
            else if (c == 'e' || c == 'E')
                estado = E_NOTA_CIEN;
            else
                return E_ERROR;
            break;

        case E_NOTA_CIEN:
            if (c == '+' || c == '-')
                estado = 100; // estado interno para signo exponente
            else if (isdigit(c))
                estado = 200; // estado interno para dígitos exponente
            else
                return E_ERROR;
            break;

        case 100: // signo del exponente
            if (isdigit(c))
                estado = 200;
            else
                return E_ERROR;
            break;

        case 200: // dígitos del exponente
            if (isdigit(c))
                estado = 200;
            else
                return E_ERROR;
            break;
        }
    }

    // Estados finales válidos
    if (estado == E_ENTERO)
        return E_ENTERO;

    if (estado == E_FLOTANTE)
        return E_FLOTANTE;

    if (estado == 200)  // terminó correctamente el exponente
        return E_NOTA_CIEN;

    return E_ERROR;
}

int main()
{
    string cadena;
    cin >> cadena;

    int resultado = analiza(cadena);

    switch (resultado)
    {
    case E_ENTERO:
        cout << "Es un entero" << endl;
        break;

    case E_FLOTANTE:
        cout << "Es un flotante" << endl;
        break;

    case E_NOTA_CIEN:
        cout << "Es notacion cientifica" << endl;
        break;

    default:
        cout << "Error" << endl;
    }

    return 0;
}

