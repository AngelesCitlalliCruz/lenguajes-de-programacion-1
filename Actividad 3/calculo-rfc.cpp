/******************************************************************************

Nombre del programa: Calculo del RFC
Angeles Citlalli Cruz Torres 
Lenguajes de programacion 1 

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>

// Diccionario de palabras No permitidas
const std::vector<std::string> palabrasProhibidas = {
    "COLA", "PEDO", "COJA", "MOCO", "CULO", "MEON", "RATA", "GUEY", "PUTO",
    "PUTA", "PEDA", "PENE", "LOCO", "QULO", "KOGE", "COJO", "CAKA", "KOJO",
    "MAME", "MEAR", "CACA", "BUEI", "KULO", "KAGA", "CAGA", "JOTO", "POPO" 
};

//Verificar y modificar palabras prohibidas del diccionario 
std::string corregirRFC(const std::string& rfc) {
    for (const std::string& palabra : palabrasProhibidas) {
         if (rfc == palabra) {
             return rfc.substr(0,3) + "X"; // Remplazar la ultima letra por por 'X'
        }
    } 
     return rfc;
}
// Funcion para obtener la primera vocal interna de una cadena 
char obtenerPrimeraVocalInterna(const std::string& str) {
    for (size_t i = 1; i < str.length(); ++i) {
        char c = toupper(str[i]);
        if ( c == 'A'|| c == 'E' || c == 'I' || c == 'O' || c== 'U' )
             return c;
    }
    return 'X'; // si no se encuentra ninguna vocal interna, se usa una X
}
// Funcion principal para calcular el RFC del empleado 
std::string calcularRFC(const std::string& nombre, const std::string& apellidoPaterno, 
const std::string& apellidoMaterno, const std::string& fechaNacimiento) {
    
    // Se declara la variable donde guardaremos el RFC
    std::string rfc;
    
    // Se obtiene la letra inicial y la primera vocal interna del apellido paterno 
    char letraInicial = apellidoPaterno[0];
    char primeraVocalInterna = obtenerPrimeraVocalInterna(apellidoPaterno);
    
    // Se obtiene la inicial del apellido materno o se usa ena 'X' si no existe
    char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? apellidoMaterno[0] : 'X';
    
    // Se obtiene la inicial del primer nombre 
    char inicialNombre = nombre[0];
    
    // Se obtienen los dos ultimos digitos del año de nacimiento 
    std::string año = fechaNacimiento.substr(2,2);
    
    // Se obtiene el mes y dia de nacimiento 
    std::string mes = fechaNacimiento.substr(5,2);
    std::string dia = fechaNacimiento.substr(8,2);
    
    // Se construye el RFC sumando el texto de la informacion proporcionada 
    rfc = toupper (letraInicial);
    rfc += toupper (primeraVocalInterna); 
    rfc += toupper (inicialApellidoMaterno);
    rfc += toupper (inicialNombre);

    // Aqui se ejecuta la comparacion de malas palabras en el diccionario y se sustituye con una 'X'
    rfc = corregirRFC(rfc);
    
    // Realizar la correccion y se continua creando el rfc
    rfc += año;
    rfc += mes;
    rfc += dia;
    
    return rfc;
}
int main() {
    // Escribe en consola los pasos a seguir y espera los datos en mayusculas 
    std::string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;
    std::cout << "Introduce tu nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Introduce tu apellido paterno: ";
    std::getline(std::cin, apellidoPaterno);
    std::cout << "Introduce tu apellido materno (si no cuenta con apellido presione ENTER): ";
    std::getline(std::cin, apellidoMaterno);
    std::cout << "Introduce la fecha de nacimiento en el siguiente formato (YYYY-MM-DD): ";
    std::getline(std::cin, fechaNacimiento);
    std::string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);
    std::cout << "RFC: " << rfc << std::endl;
    
    return 0;
}