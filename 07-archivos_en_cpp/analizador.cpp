#include <iostream>
#include <fstream>
#include <cctype>
#include "analizador.h"

using namespace std;

// Verifica si es palabra reservada
bool esReservada(string palabra) {
    if (palabra == "include") return true;
    if (palabra == "using") return true;
    if (palabra == "namespace") return true;
    if (palabra == "int") return true;
    if (palabra == "return") return true;
    if (palabra == "if") return true;
    if (palabra == "else") return true;
    if (palabra == "while") return true;
    return false;
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        cout << "No se proporciono archivo" << endl;
        return 1;
    }

    ifstream archivo(argv[1]);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }

    char c;
    string lexema = "";
    int estado = 0;

    while (archivo.get(c)) {

        switch (estado) {

        // ===== ESTADO INICIAL q0 =====
        case 0:

            if (isalpha(c) || c == '_') {
                lexema = c;
                estado = 1; // identificador
            }
            else if (isdigit(c)) {
                lexema = c;
                estado = 2; // numero
            }
            else if (c == '"') {
                lexema = c;
                estado = 3; // cadena
            }
            else if (c == '/') {
                lexema = c;
                estado = 4; // posible comentario
            }
            else if (c == '<') {
                cout << "< -> Operador menor que" << endl;
            }
            else if (c == '>') {
                cout << "> -> Operador mayor que" << endl;
            }
            else if (c == '#') {
                cout << "# -> Simbolo" << endl;
            }
            else if (c == '{' || c == '}' ||
                     c == '(' || c == ')' ||
                     c == ';' || c == ',') {
                cout << c << " -> Simbolo" << endl;
            }

            break;

        // ===== IDENTIFICADOR =====
        case 1:

            if (isalnum(c) || c == '_') {
                lexema += c;
            }
            else {
                if (esReservada(lexema))
                    cout << lexema << " -> Palabra reservada" << endl;
                else
                    cout << lexema << " -> Identificador" << endl;

                estado = 0;
                archivo.unget(); // regresamos caracter
            }

            break;

        // ===== NUMERO =====
        case 2:

            if (isdigit(c)) {
                lexema += c;
            }
            else {
                cout << lexema << " -> Numero" << endl;
                estado = 0;
                archivo.unget();
            }

            break;

        // ===== CADENA =====
        case 3:

            lexema += c;

            if (c == '"') {
                cout << lexema << " -> Cadena" << endl;
                estado = 0;
            }

            break;

        // ===== COMENTARIO =====
        case 4:

            if (c == '/') {
                lexema += c;
                while (archivo.get(c) && c != '\n') {
                    lexema += c;
                }
                cout << lexema << " -> Comentario" << endl;
                estado = 0;
            }
            else {
                cout << "/ -> Operador division" << endl;
                estado = 0;
                archivo.unget();
            }

            break;
        }
    }

    archivo.close();
    return 0;
}