#include "ej1.h"

int main(){
    SaveFlightData datos(
        Posicion(-34.6f, -58.4f, 950.0f, 5.3),
        Presion(101.3f, 5.8f, 6.1f)
    );

    ofstream archivo("vuelo.dat", ios::binary);
    if (archivo.is_open()) {
        datos.serializar(archivo);
        archivo.close();
    }

    cout << "\nDatos antes de serializar \n" << endl;
    datos.imprimir();

    SaveFlightData datos_leidos(
        Posicion(0,0,0,0),  
        Presion(0,0,0)
    );

    ifstream archivo_in("vuelo.dat", ios::binary);
    if (archivo_in.is_open()) {
        datos_leidos.deserializar(archivo_in);
        archivo_in.close();
    }

    cout << "\nDatos deserializados \n" << endl;
    datos_leidos.imprimir();
    return 0;
}