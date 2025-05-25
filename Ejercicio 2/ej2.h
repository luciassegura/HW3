#ifndef EJ2_H
#define EJ2_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Punto{
    private:
        float posicion_x, posicion_y;
    
    public:
        Punto(float posicion_x, float posicion_y);
        double getX() const;
        double getY() const;
        void setX(float nuevo_x);
        void setY(float nuevo_y);
};

class Circulo{
    private:
        Punto centro;
        float radio;
    
    public:
        Circulo(float posicion_x, float posicion_y, float radio);
        Punto getCentro() const;
        double getRadio() const;
        void setCentro(float nuevo_x, float nuevo_y);
        void setRadio(float nuevo_radio);
};

class Elipse{
    private:
        Punto centro;
        float semieje_mayor; // a
        float semieje_menor; // b

    public:
        Elipse(float posicion_x, float posicion_y, float semieje_mayor, float semieje_menor);
        Punto getCentro() const;
        double getSemieje_mayor() const;
        double getSemieje_menor() const;
        void setCentro(float x, float y);
        void setSemieje_mayor(float nuevo_semieje_mayor);
        void setSemieje_menor(float nuevo_semieje_menor);
};

class Rectangulo{
    private:
        Punto vertice_inferior_izquierdo;
        float ancho, largo;

    public:
        Rectangulo(float posicion_x, float posicion_y, float ancho, float largo);
        Punto getVertice_izquierdo() const;
        double getAncho() const;
        double getLargo() const;
        void setVertice_izquierdo(float x, float y);
        void setAncho(float nuevo_ancho);
        void setLargo(float nuevo_largo);
};

template <typename T>
class ProcesadorFigura{
public:
    double calcularArea(const T&){
        static_assert(sizeof(T) == -1, "No hay especialización para este tipo de figura.");
        return 0.0;
    }
};

template <>
class ProcesadorFigura<Circulo>{
public:
    double calcularArea(const Circulo& circulo){
        return M_PI * circulo.getRadio() * circulo.getRadio();
    }
};

template <>
class ProcesadorFigura<Rectangulo>{
public:
    double calcularArea(const Rectangulo& rectangulo){
        return rectangulo.getAncho() * rectangulo.getLargo();
    }
};

template <>
class ProcesadorFigura<Elipse>{
public:
    double calcularArea(const Elipse& eclipse){
        return M_PI * eclipse.getSemieje_mayor() * eclipse.getSemieje_menor();
    }
};

ostream& operator<<(ostream& os, const Punto& p);

#endif