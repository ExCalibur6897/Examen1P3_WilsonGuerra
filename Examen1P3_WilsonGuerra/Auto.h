#pragma once
#include <iostream>
#include "CajaDeCambios.h"
#include "Neumaticos.h"
#include "Radiador.h"
#include "Diferencial.h"
#include "Ciguenal.h"

using namespace std;

class Auto
{
	Auto() {
		string marca;
		string modelo;
		int velMax;
		int caballosFuerza;
		float aceleracion;
		Ciguenal* c;
		Radiador* r;
		Neumaticos* n;
		CajaDeCambios* ca;
		Diferencial* d;
	}
};

