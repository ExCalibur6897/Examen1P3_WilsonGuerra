#include "Auto.h"

Auto::Auto(std::string marca, std::string modelo, int velMax, int caballosFuerza, float aceleracion)
    : marca(marca), modelo(modelo), velMax(velMax), caballosFuerza(caballosFuerza), aceleracion(aceleracion) {
    c = new Ciguenal(0, 0);
    r = new Radiador(0);
    n = new Neumaticos(0);
    d = new Diferencial(0);
    cdc = new CajaDeCambios(0, 0);
}

Auto::~Auto() {
    delete c;
    delete r;
    delete n;
    delete d;
    delete cdc;
}