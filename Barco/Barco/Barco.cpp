#include "Barco.h"

//Constructor vacio
Barco::Barco() {
    this->velocidad = 0;
    this->distancia = 0;
    this->nitro = 1;
    this->nombre = "?";
}

//Constructor con argumento String para el valor de nombre
Barco::Barco(string nombreDado) {
    this->velocidad = 0;
    this->distancia = 0;
    this->nitro = 1;
    this->nombre = nombreDado;
}

void Barco::setNombre(string nombre) {
    this->nombre = nombre;
}

void Barco::setVelocidad(int numeroDado) {
    this->velocidad = this->velocidad + numeroDado;
}

void Barco::calcularDistancia() {
    this->distancia = this->distancia + this->velocidad * 100;
}

void Barco::gastarNitro() {
    this->nitro = 0;
}
int Barco::getVelocidad() {
    return this->velocidad;
}

float Barco::getDistancia() {
    return this->distancia;
}

string Barco::getNombre() {
    return nombre;
}


bool Barco::disponibleNitro() {
    if (this->nitro == 1) {
        return true;
    }
    else {
        return false;
    }
}