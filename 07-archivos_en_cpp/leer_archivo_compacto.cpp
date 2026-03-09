#include <iostream>
#include <fstream>
#include <string>

using namespace std;int main (int argc, char *argv[]){if(argc < 2){cerr<<"Error: no hay suficientes argumentos"<<endl;return 1;}string nombreArchivo = argv[1];ifstream archivo(nombreArchivo);if(!archivo.is_open()){cerr<<"Error: No se pudo abrir el archivo '"<<nombreArchivo<<"'"<<endl;return 1;}string linea;while(getline(archivo,linea)){cout<<linea<<endl;}archivo.close();return 0;}

// vi: set shiftwidth=8 tabstop=8 noexpandtab:
