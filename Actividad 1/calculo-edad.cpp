/******************************************************************************

Nombre del programa: Mayor de Edad
Angeles Citlalli Cruz Torres 
Ingenieria en Desarrollo de Software 

*******************************************************************************/
#include <iostream>
#include <string>

using namespace std; 
int main() {
    string nombreCompleto;
    int edad;
    
    cout <<"Ingresa tu nombre completo: ";
    getline(cin, nombreCompleto);
    cout << "Ingresa tu edad: ";
    cin >> edad;
    
    cout <<"Bienvenida, " << nombreCompleto << "." << endl; 
     if (edad>=18) {
        cout <<"Usted es mayor de edad." << endl;
        } else {
            cout <<"Usted es menor de edad." << endl; 
        }
        return 0; 
        
}