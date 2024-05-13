#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "Barco.h"

using namespace std;

int main() {
    //Definición de la variable cantidadCorredores
    int cantidadCorredores;
    //Asignación de valor a la semilla de los valores aleatorios, pasando como semilla la hora actual en la que se ejecuta el programa
    srand(time(NULL));
    cout << "Cuantos corredores van a apuntarse? ";
    //Recuperación de la terminal el valor, y se asigna a la variable cantidadCorredores
    cin >> cantidadCorredores;
    //Creación de un vector con el numero de corredores (funcionamiento similar a array)
    vector<Barco> barcos(cantidadCorredores);

    //Iteración del array de barcos para asignar valor al nombre del corredor
    for (Barco& barco : barcos) {
        //Definición de la variable nombreCorredor
        string nombreCorredor;
        //Recuperación de la terminal el valor, y se asigna a la variable nombreCorredor
        cout << "Nombre del corredor: ";
        cin >> nombreCorredor;
        //Creación de cada barco mediante constructor, usando constructor con argumento string (nombre corredor)
        barco = Barco(nombreCorredor);
    }

    cout << endl << "Inicia la carrera:" << endl << "-----------" << endl;

    //Iteración for, en lugar de comenzar en 0 se comienza en 1 ya que más adelante usaremos este indice para indicar el numero de vuelta
    for (int i = 1; i < 6; i++) {
        //Iteración del array de barcos por cada vuelta para realizar su turno en cada una
        for (Barco& barco : barcos) {
            //Calculo de valor aleatorio de 1 a 6 para la variable numeroDado
            int numeroDado = 1 + rand() % 6;
            cout << "Vuelta " << i << "|" << barco.getNombre() << "|Dado: " << numeroDado << endl;
            //Validación de si el barco iterado dispone del nitro
            if (barco.disponibleNitro()) {
                //En caso de contar con el nitro, se decide mediante un valor aleatorio si lo va a usar
                int randomNitro = 1 + rand() % 2;
                //Si el valor aleatorio resultante es 2, es decir, se usa el nitro se procede al calculo del mismo
                if (randomNitro == 2) {
                    //Se pone la velocidad actual del barco
                    barco.setVelocidad(numeroDado);
                    //Mediante un valor aleatorio, se decide si el nitro es exitoso
                    int nitroExitoso = 1 + rand() % 2;
                    if (nitroExitoso == 2) {
                        cout << "Vuelta " << i << "|" << barco.getNombre() << " usa el nitro satisfactoriamente." << endl;
                        //En caso exitoso, se asigna el valor de velocidad recuperando la velocidad actual y multiplicandola por 2
                        barco.setVelocidad(barco.getVelocidad() * 2);
                    }
                    else {
                        cout << "Vuelta " << i << "|" << barco.getNombre() << " usa el nitro, y sale mal." << endl;
                        //En caso no exitoso, se asigna el valor de velocidad recuperando la velocidad actual y dividiendola por 2
                        barco.setVelocidad(barco.getVelocidad() / 2);
                    }
                    //Independientemente del resultado de nitroExitoso, se gasta el nitro
                    barco.gastarNitro();
                }
                //En caso de no contar con nitro
            }
            else {
                //Únicamente asignamos el valor del resultado del dado
                barco.setVelocidad(numeroDado);
            }
            //En base a la velocidad, calculamos la distancia recorrida por el barco en este turno
            barco.calcularDistancia();
        }
    }

    //Usando la librería algorithm y el metodo sort, mediante este bloque de código se ordena el array de mayor a menor, comparando los elementos entre ellos por la distancia recorrida
    sort(barcos.begin(), barcos.end(), [](Barco& barco1, Barco& barco2) {
        return barco1.getDistancia() > barco2.getDistancia();
        });

    cout << endl << "-----------" << endl << "Resultados" << endl << "-----------" << endl;

    //Iteración del array de barcos para mostrar los resultados
    for (Barco& barco : barcos) {
        cout << barco.getNombre() << ": " << barco.getDistancia() << endl;
    }
}