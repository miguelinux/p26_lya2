/*SOLIS MORALES CARLOS ALBERTO
FLORES RODRIGUEZ JAIR JECSAN
CASTRO MELGOZA KATIA ELIZABETH
OROZCO LOPEZ JUAN ESTEBAN
CORREA CRUZALEY HECTOR FERNANDO
*/

#include "automata_diosarrolladores.h"
#include <iostream>
#include <string>

using namespace std;

int analiza(string str) {
  int estado = E_INICIAL;

  for (char c : str) {
    switch (c) {
    case '+':
    case '-':
      if (estado == E_INICIAL) {
        estado = E_SIGNO;
      }

      else if (estado == E_EXP_ESPERA) {
        estado = E_EXP_ESPERA;
      } else {
        estado = E_ERROR;
      }
      break;

    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      switch (estado) {
      case E_INICIAL:
      case E_SIGNO:
      case E_ENTERO:
        estado = E_ENTERO;
        break;
      case E_FLOTANTE:
        estado = E_FLOTANTE;
        break;
      case E_EXP_ESPERA:
        estado = E_NOTA_CIEN;
        break;
      default:
        estado = E_ERROR;
      }
      break;

    case '.':
      if (estado == E_ENTERO) {
        estado = E_FLOTANTE;
      } else {
        estado = E_ERROR;
      }
      break;

    case 'e':
    case 'E':
      if (estado == E_ENTERO || estado == E_FLOTANTE) {
        estado = E_EXP_ESPERA;
      } else {
        estado = E_ERROR;
      }
      break;

    default:
      estado = E_ERROR;
      break;
    }
    if (estado == E_ERROR)
      break;
  }
  return estado;
}

int main(int argc, char *argv[]) {
  int estado_final = E_ERROR;
  string cadena;

  cout << "Ingresa la cadena a analizar: ";
  cin >> cadena;

  estado_final = analiza(cadena);

  switch (estado_final) {
  case E_ENTERO:
    cout << "Es un entero" << endl;
    break;
  case E_FLOTANTE:
    cout << "Es un flotante" << endl;
    break;
  case E_NOTA_CIEN:
    cout << "Es un flotante en notación cientifica" << endl;
    break;
  default:
    cout << "Error: no se identifico la entrada" << endl;
  }
  return 0;
}
