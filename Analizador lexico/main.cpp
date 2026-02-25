#include <iostream>
#include <cctype>
#include <string>

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	string codigo;
	cout<<"Ingresa una linea de codigo";
	
	 int i = 0;

    while (i < codigo.length()) {

        // Ignorar espacios
        if (isspace(codigo[i])) {
            i++;
            continue;
            
            if(isalpha( codigo[i])){
            	string palabra = "";
            	
			}
			while (isalnum(codigo[i])){
				palabra += codigo[i];
				i++;
			}
        }
}
