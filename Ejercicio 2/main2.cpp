#include "ej2.h"
#include <iostream>

int main(){
    Circulo circulo(0, 0, 5.2);
    ProcesadorFigura<Circulo> procesador;
    double area = procesador.calcularArea(circulo);
    cout << "El centro del círculo es (" << circulo.getCentro() << ") y el radio es " << circulo.getRadio() << endl;
    cout << "El área del círculo es: " << area << endl;

    Elipse elipse(1, -2, 3, 2);
    ProcesadorFigura<Elipse> procesador2;
    double area2 = procesador2.calcularArea(elipse);
    cout << "El centro del elipse es (" << elipse.getCentro() << "), el eje mayor es " << 
    elipse.getSemieje_mayor() << " y el menor es " << elipse.getSemieje_menor() << endl;
    cout << "El área del elipse es: " << area2 << endl;

    Rectangulo rectangulo(2, 3.5, 3, 4);
    ProcesadorFigura<Rectangulo> procesador3;
    double area3 = procesador3.calcularArea(rectangulo);
    cout << "El vértice inferior izquierdo del rectángulo es (" << rectangulo.getVertice_izquierdo() << 
    "), el ancho es " << rectangulo.getAncho() << " y el largo es " << rectangulo.getLargo() << endl;
    cout << "El área del rectángulo es: " << area3 << endl;

    return 0;
}