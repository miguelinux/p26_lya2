/*
Graciela Mora Esparza 210111853
Carlos Santiago Ramírez Sandoval 220111400
Omar Ulises Hernandez Perez 220111901
*/

#include <iostream>
#include <string>
#include <cctype>
#include <set>
#include "estados.h"

using namespace std;

// Palabras reservadas de C++
set<string> palabrasReservadas = {
    "int","float","double","char","if","else","while","for",
    "return","void","switch","case","break","continue","do"
};

bool esIdentificador(const string& str)
{
    if (!(isalpha(str[0]) || str[0] == '_'))
        return false;

    for (char c : str)
    {
        if (!(isalnum(c) || c == '_'))
            return false;
    }
    return true;
}

bool esSignoAritmetico(const string& str)
{
    return (str == "+" || str == "-" || str == "*" || str == "/" || str == "%" || str == "="|| str == "=="|| str == "++"|| str == "--") ;
}

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
                estado = 100;
            else if (isdigit(c))
                estado = 200;
            else
                return E_ERROR;
            break;

        case 100:
            if (isdigit(c))
                estado = 200;
            else
                return E_ERROR;
            break;

        case 200:
            if (isdigit(c))
                estado = 200;
            else
                return E_ERROR;
            break;
        }
    }

    if (estado == E_ENTERO)
        return E_ENTERO;

    if (estado == E_FLOTANTE)
    {
        if (isdigit(str.back()))
            return E_FLOTANTE;
        else
            return E_ERROR;
    }

    if (estado == 200)
        return E_NOTA_CIEN;

    return E_ERROR;
}

int main()
{
    string cadena;
    cin >> cadena;

    if (palabrasReservadas.count(cadena))
    {
        cout << "Es palabra reservada" << endl;
        return 0;
    }

    if (esSignoAritmetico(cadena))
    {
        cout << "Es signo aritmetico" << endl;
        return 0;
    }

    if (esIdentificador(cadena))
    {
        cout << "Es identificador" << endl;
        return 0;
    }

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
