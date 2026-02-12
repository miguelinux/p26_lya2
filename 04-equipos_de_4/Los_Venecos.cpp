//Jose Ismael Gonzalez Cosme
//Jesus Gerardo de la O Duran
//Aaron Alejandro Martinez Serrano

#include <iostream>

#include "suma_Los_Venecos.h"
//#include "resta_Los_Venecos.h"
#include "multiplicacion_Los_Venecos.h"
#include "division_Los_Venecos.h"

using namespace std;

int main (int argc, char *argv[])
{
  cout << "3 + 5 = "<< suma(3,5) << endl;
 // cout << "3 - 5 = "<< resta(3,5) << endl;
  cout << "3 * 5 = "<< multiplicacion(3,5) << endl;
  cout << "3 / 5 = "<< division(3,5) << endl;

  return 0;
}

/*
 * Editor modelines  -  https://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 8
 * tab-width: 8
 * indent-tabs-mode: t
 * End:
 *
 * vi: set shiftwidth=8 tabstop=8 noexpandtab:
 * :indentSize=8:tabSize=8:noTabs=false:
 */

