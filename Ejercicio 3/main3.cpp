#include "ej3.h"

int main(){
    // crear datos
    vector<double> numeros = {1.3, 2.1, 3.2};
    vector<string> palabras = {"Hola", "Mundo"};
    vector<vector<int>> listas = {{1, 2}, {3,4}};

    // crear objetos de Clase1
    Clase1<vector<double>> obj1;
    obj1.agregar_datos(numeros);

    Clase1<vector<string>> obj2;
    obj2.agregar_datos(palabras);

    Clase1<vector<vector<int>>> obj3;
    obj3.agregar_datos(listas);

    // crear Clase2 y asociar datos
    Clase2 c2;
    c2.asociar_doubles("vec_doubles", obj1.obtener_doubles());
    c2.asociar_palabras("palabras", obj2.obtener_palabras());
    c2.asociar_listas("listas", obj3.obtener_listas());

    c2.guardar_json_archivo();
    cout << c2.construir_json_string();   // imprimir json

    return 0;
}