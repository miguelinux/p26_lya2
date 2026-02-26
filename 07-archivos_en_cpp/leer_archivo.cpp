#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
	if (argc < 2) {
		cerr << "Error: no hay suficientes argumentos" << endl;
		return 1;
	}
	for (int i=0; i<argc; i++) {
		cout << i << ": " << argv[i] << endl;
	}
	return 0;
}

// vi: set shiftwidth=8 tabstop=8 noexpandtab:
