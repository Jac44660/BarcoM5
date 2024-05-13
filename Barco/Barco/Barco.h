#include <iostream>
using namespace std;

class Barco
{
    //Atributos
private:
    int velocidad;
    float distancia;
    int nitro;
    string nombre;

    //Metodos
public:
    Barco();
    Barco(string nombreDado);
    void setNombre(string nombre);
    int getVelocidad();
    void gastarNitro();
    bool disponibleNitro();
    string getNombre();
    void setVelocidad(int numeroDado);
    float getDistancia();
    void calcularDistancia();
};