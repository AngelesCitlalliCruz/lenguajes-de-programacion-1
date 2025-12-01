/******************************************************************************

Nombre del programa:Suma, Resta, Multiplicación y Division 
Angeles Citlalli Cruz Torres 
Lneguajes de programacion 1 

*******************************************************************************/
#include <iostream>
using namespace std; 

int main()
{
    float numero1, numero2; 
    std::cout << "Escribe el primer numero: ";
    std::cin >> numero1;
    
    std::cout <<"Escribe el segundo numero: ";
    std::cin >> numero2;
    
    float suma=numero1+numero2;
    float resta=numero1-numero2;
    float multiplicacion=numero1*numero2;
    float division=numero1/numero2;
    std::cout << "La suma es: " << suma << std::endl;
    std::cout << "La resta es: " << resta << std::endl;
    std::cout << "La multipliacion es: " << multiplicacion << std::endl;
    std::cout << "La division es: " << division << std::endl;
    
    return 0; 
}