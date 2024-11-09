#include <string>
#include <iostream>
#include <fstream>
#include "tabla.h"
using namespace std;

int main() {
    ifstream inputFile("textodxd.txt");
    string line;
    string word = "";
    int validate = 0;
    int state = 0;
    char letter = '$';

    if (!inputFile.is_open()) {
        cout << "Error: no se pudo abrir el archivo." << endl << endl;
        return 501;
    }

    getline(inputFile, line);

    for (int i = 0; i < line.length(); i++) {
        letter = line[i];

        // Verifica si el carácter es válido
        if ((letter < 'a' || letter > 'z') || letter == ' ') {
            if (validate == 1) {
                cout << "Válida: " << word << endl;
            } else {
                cout << "Inválida: " << word << endl; // Imprimir palabra inválida
            }

            word = "";
            state = 0;
            validate = 0;
            continue;
        }
        switch (letter) {
            case 'a': state = matrix[state][0]; break;
            case 'l': state = matrix[state][1]; break;
            case 'o': state = matrix[state][2]; break;
            case 'p': state = matrix[state][3]; break;
            case 'z': state = matrix[state][4]; break;
            default: break; 
        }

        validate = matrix[state][columns - 1];

        if (state == -1) {
            i--;
            continue;
        }

        word += letter; 
    }
    if (validate == 1) {
        cout << "Válida: " << word << endl;
    } else if (!word.empty()) {
        cout << "Inválida: " << word << endl; 
    }

    return 0;
}