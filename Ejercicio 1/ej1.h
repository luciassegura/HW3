#ifndef EJ1_H
#define EJ1_H

#include <iostream>
#include <fstream>

using namespace std;

class IMediciones{
    public:
        virtual void serializar(ofstream& out) = 0;     // escribe la información de un objeto en un archivo
        virtual void deserializar(ifstream& in) = 0;   // lee la información del archivo y reconstruye el objeto
};

class MedicionBase : public IMediciones{
    protected:
        unique_ptr<float> tiempoMedicion;
    public:
        MedicionBase(float t);      // constructor principal, para construir un objeto con un tiempo nuevo
        MedicionBase(const MedicionBase& other);  // constructor por copia, toma una referencia constante a otro MedicionBase
        MedicionBase& operator=(const MedicionBase& other);
        float getTiempo() const;   // implementar acá
        virtual void imprimir() const = 0;       // implementar en las derivadas
};

class Presion : public MedicionBase{
    public:
        float presionEstatica;
        float presionDinamica;
    
        Presion(float p, float q, float t);
        void serializar(ofstream& out) override;
        void deserializar(ifstream& in) override;
        void imprimir() const override;
};

class Posicion : public MedicionBase{
    public:
        float latitud;
        float longitud;
        float altitud;

        Posicion(float lat, float lon, float alt, float t);
        void serializar(ofstream& out) override;
        void deserializar(ifstream& in) override;
        void imprimir() const override;
};

class SaveFlightData{
    public:
        Posicion posicion;
        Presion presion;

        SaveFlightData(const Posicion& pos, const Presion& pres);
        void serializar(ofstream& out);
        void deserializar(ifstream& in);
        void imprimir() const;
};

#endif