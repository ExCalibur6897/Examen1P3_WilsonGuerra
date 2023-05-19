#ifndef AUTO_H
#define AUTO_H

#include <string>
#include "Ciguenal.h"
#include "Radiador.h"
#include "Neumaticos.h"
#include "Diferencial.h"
#include "CajaDeCambios.h"

class Auto {
public:
    std::string marca;
    std::string modelo;
    int velMax;
    int caballosFuerza;
    float aceleracion;
    Ciguenal* c;
    Radiador* r;
    Neumaticos* n;
    Diferencial* d;
    CajaDeCambios* cdc;

    Auto(std::string marca, std::string modelo, int velMax, int caballosFuerza, float aceleracion);
    ~Auto();
};

#endif