#include "ej2.h"

Punto::Punto(float posicion_x, float posicion_y)
    : posicion_x(posicion_x), posicion_y(posicion_y) {}

double Punto::getX() const {
    return posicion_x;
}

double Punto::getY() const {
    return posicion_y;
}

void Punto::setX(float nuevo_x){
    posicion_x = nuevo_x;
}

void Punto::setY(float nuevo_y){
    posicion_y = nuevo_y;
}

Circulo::Circulo(float posicion_x, float posicion_y, float radio)
    : centro(posicion_x, posicion_y), radio(radio) {}

Punto Circulo::getCentro() const{
    return centro;
}

double Circulo::getRadio() const{
    return radio;
}

void Circulo::setCentro(float x, float y){
    centro.setX(x);
    centro.setY(y);
}

void Circulo::setRadio(float nuevo_radio){
    radio = nuevo_radio;
}

Elipse::Elipse(float posicion_x, float posicion_y, float semieje_mayor, float semieje_menor)
    : centro(posicion_x, posicion_y), semieje_mayor(semieje_mayor), semieje_menor(semieje_menor) {}

Punto Elipse::getCentro() const{ 
    return centro; 
}

double Elipse::getSemieje_mayor() const{ 
    return semieje_mayor; 
}

double Elipse::getSemieje_menor() const{ 
    return semieje_menor; 
}

void Elipse::setCentro(float x, float y) {
    centro.setX(x);
    centro.setY(y);
}

void Elipse::setSemieje_mayor(float nuevo_semieje_mayor) {
    semieje_mayor = nuevo_semieje_mayor;
}

void Elipse::setSemieje_menor(float nuevo_semieje_menor) {
    semieje_menor = nuevo_semieje_menor;
}

Rectangulo::Rectangulo(float posicion_x, float posicion_y, float ancho, float largo)
    : vertice_inferior_izquierdo(posicion_x, posicion_y), ancho(ancho), largo(largo) {}

Punto Rectangulo::getVertice_izquierdo() const {
    return vertice_inferior_izquierdo;
}

double Rectangulo::getAncho() const {
    return ancho;
}

double Rectangulo::getLargo() const {
    return largo;
}

void Rectangulo::setVertice_izquierdo(float nuevo_x, float nuevo_y){
    vertice_inferior_izquierdo.setX(nuevo_x);
    vertice_inferior_izquierdo.setY(nuevo_y);
}

void Rectangulo::setAncho(float nuevo_ancho){
    ancho = nuevo_ancho;
}

void Rectangulo::setLargo(float nuevo_largo){
    largo = nuevo_largo;
}

ostream& operator<<(ostream& os, const Punto& p) {
    os << p.getX() << ", " << p.getY();
    return os;
}