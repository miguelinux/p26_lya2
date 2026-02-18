#include "automata_diosarrolladores.h"
#include <iostream>
#include <string>
#include <cctype>
#include <set>

using namespace std;

bool esReservada(string str) {
    static const set<string> palabras = {
        "int", "float", "double", "char", "if", "else", "while", "for", "return", "class"
    };
    return palabras.count(str) > 0;
}
int analiza(string str) {
    int estado = E_INICIAL;

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];

        switch (estado) {
            case E_INICIAL:
                if (isdigit(c)) estado = E_ENTERO;
                else if (c == '.') estado = E_PUNTO_ESPERA;
                else if (isalpha(c) || c == '_') estado = E_IDENTIFICADOR;
                else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
                    estado = E_ARITMETICO;
                }
                else estado = E_ERROR;
                break;

            case E_ENTERO:
                if (isdigit(c)) estado = E_ENTERO;
                else if (c == '.') estado = E_FLOTANTE;
                else if (c == 'e' || c == 'E') estado = E_EXP_ESPERA;
                else estado = E_ERROR;
                break;

            case E_PUNTO_ESPERA:
                if (isdigit(c)) estado = E_FLOTANTE;
                else estado = E_ERROR;
                break;

            case E_FLOTANTE:
                if (isdigit(c)) estado = E_FLOTANTE;
                else if (c == 'e' || c == 'E' || c == '+' || c == '-') estado = E_EXP_ESPERA;
                else estado = E_ERROR;
                break;

            case E_EXP_ESPERA:
                if (isdigit(c) || c == '+' || c == '-') estado = E_NOTA_CIEN;
                else if (c == 'e' || c == 'E') estado = E_EXP_ESPERA;
                else estado = E_ERROR;
                break;

            case E_NOTA_CIEN:
                if (isdigit(c)) estado = E_NOTA_CIEN;
                else estado = E_ERROR;
                break;

            case E_IDENTIFICADOR:
                if (isalnum(c) || c == '_') estado = E_IDENTIFICADOR;
                else estado = E_ERROR;
                break;

            case E_ARITMETICO:
                if (c == '.') {
                    estado = E_PUNTO_ESPERA;
                }
                else if (isdigit(c)) {
                    estado = E_ENTERO;
                }
                else if (c == '=' || (c == '+' && str[i-1] == '+') || (c == '-' && str[i-1] == '-')) {
                    estado = E_ARITMETICO;
                }
                else {
                    estado = E_ERROR;
                }
                break;

            default:
                estado = E_ERROR;
        }
        if (estado == E_ERROR) break;
    }

    if (estado == E_IDENTIFICADOR && esReservada(str)) return E_RESERVADA;
    if (estado == E_PUNTO_ESPERA) return E_FLOTANTE;

    return estado;
}

int main() {
    string cadena;
    cout << "Ingresa el token a analizar: ";
    cin >> cadena;

    int resultado = analiza(cadena);

    switch (resultado) {
        case E_ENTERO:        cout << "Resultado: Numero Entero" << endl; break;
        case E_FLOTANTE:      cout << "Resultado: Numero Flotante" << endl; break;
        case E_NOTA_CIEN:     cout << "Resultado: Notacion Cientifica" << endl; break;
        case E_IDENTIFICADOR: cout << "Resultado: Identificador" << endl; break;
        case E_RESERVADA:     cout << "Resultado: Palabra Reservada (C++)" << endl; break;
        case E_ARITMETICO:    cout << "Resultado: Signo Aritmetico" << endl; break;
        default:              cout << "Resultado: Error de Lexico" << endl; break;
    }
    return 0;
}
