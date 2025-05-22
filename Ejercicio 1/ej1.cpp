#include "ej1.h"

MedicionBase::MedicionBase(float t) : tiempoMedicion(make_unique<float>(t)) {}

MedicionBase::MedicionBase(const MedicionBase& other)
    : tiempoMedicion(make_unique<float>(*other.tiempoMedicion)) {}

MedicionBase& MedicionBase::operator=(const MedicionBase& other){
    if (this != &other){  // no se puede hacer a = a
        tiempoMedicion = make_unique<float>(*other.tiempoMedicion); // nuevo unique_ptr con el valor de other.tiempoMedicion
    }
    return *this;
}

float MedicionBase::getTiempo() const{
    return *tiempoMedicion;
}

Presion::Presion(float p, float q, float t) 
    : MedicionBase(t), presionEstatica(p), presionDinamica(q) {} 

void Presion::serializar(ofstream& out){
    out.write(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
    out.write(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(float)); 
}

void Presion::deserializar(ifstream& in){
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
    float t;
    in.read(reinterpret_cast<char*>(&t), sizeof(t));
    tiempoMedicion = make_unique<float>(t);
}

void Presion::imprimir() const{
    cout << "La presión estática es " << presionEstatica << endl;
    cout << "La presión dinámica es " << presionDinamica << endl;
    cout << "El tiempo en el que se realizó la medición es " << getTiempo() << endl;
}

Posicion::Posicion(float lat, float lon, float alt, float t)
    : MedicionBase(t), latitud(lat), longitud(lon), altitud(alt) {} 

void Posicion::serializar(ofstream& out){
    out.write(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<char*>(&altitud), sizeof(altitud));
    out.write(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(float));
}

void Posicion::deserializar(ifstream& in){
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
    float t;
    in.read(reinterpret_cast<char*>(&t), sizeof(t));
    tiempoMedicion = make_unique<float>(t); 
}

void Posicion::imprimir() const{
    cout << "La latitud es " << latitud << endl;
    cout << "La longitud es " << longitud << endl;
    cout << "La altitud es " << altitud << endl;
    cout << "El tiempo en el que se realizó la medición es " << getTiempo() << endl;
}

SaveFlightData::SaveFlightData(const Posicion& pos, const Presion& pres)
    : posicion(pos), presion(pres) {}

void SaveFlightData::serializar(ofstream& out){
    posicion.serializar(out);
    presion.serializar(out);
}

void SaveFlightData::deserializar(ifstream& in){
    posicion.deserializar(in);
    presion.deserializar(in);
}

void SaveFlightData::imprimir() const{
    cout << "---- Datos de Posición ----" << endl;
    posicion.imprimir();
    cout << "---- Datos de Presión ----" << endl;
    presion.imprimir();
}