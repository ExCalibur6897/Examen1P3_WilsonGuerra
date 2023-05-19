#include <iostream>
#include <vector>
#include "Auto.h"
#include "Ciguenal.h"
#include "Diferencial.h"
#include "Neumaticos.h"
#include "Radiador.h"
#include "CajaDeCambios.h"

using namespace std;

int main()
{
	int opcion = 0;
	int ciguenal = 0;
	int cajadc = 0;
	int diferencial = 0;
	int neumatico = 0;
	int radiador = 0;
	string opcionn = "";
	char marca[50];
	char modelo[50];
	int pos = 0;
	int velMax = 0;
	int caballosFuerza = 0;
	float aceleracion = 0;
	vector<Ciguenal*> ciguenales;
	vector<Radiador*> radiadores;
	vector<Neumaticos*> neumaticos;
	vector<Diferencial*> diferenciales;
	vector<CajaDeCambios*> cajasDeCambios;
	vector<Auto*> autos;
	Auto* a;
	bool nfs = false;

	Ciguenal* c = new Ciguenal(150, 50);
	Ciguenal* cc = new Ciguenal(200, 60);
	Ciguenal* ccc = new Ciguenal(130, 90);

	Diferencial* d = new Diferencial(0.5);
	Diferencial* dd = new Diferencial(1);
	Diferencial* ddd = new Diferencial(0.8);

	Radiador* r = new Radiador(100);
	Radiador* rr = new Radiador(150);
	Radiador* rrr = new Radiador(125);

	Neumaticos* n = new Neumaticos(0.2);
	Neumaticos* nn = new Neumaticos(0.3);
	Neumaticos* nnn = new Neumaticos(0.1);

	CajaDeCambios* cdc = new CajaDeCambios(0.5, 100);
	CajaDeCambios* cdcc = new CajaDeCambios(0.6, 120);
	CajaDeCambios* cdccc = new CajaDeCambios(0.4, 80);

	ciguenales.push_back(c);
	ciguenales.push_back(cc);
	ciguenales.push_back(ccc);

	diferenciales.push_back(d);
	diferenciales.push_back(dd);
	diferenciales.push_back(ddd);

	radiadores.push_back(r);
	radiadores.push_back(rr);
	radiadores.push_back(rrr);

	neumaticos.push_back(n);
	neumaticos.push_back(nn);
	neumaticos.push_back(nnn);

	cajasDeCambios.push_back(cdc);
	cajasDeCambios.push_back(cdcc);
	cajasDeCambios.push_back(cdccc);
	while (true) {
		nfs = true;
		system("cls");
		cout << "Menu Principal\n1. Need for Speed\n2. Salir del programa";
		cout << "\nIngrese una opcion: ";
		cin >> opcionn;
		if (opcionn == "1")
			opcion = 1;
		else if (opcionn == "2")
			opcion = 2;
		else
			opcion = 0;
		switch (opcion) {
		case 1:
			while (nfs) {
				system("cls");
				cout << "Bienvenido a Need for Speed!\n";
				cout << "1. Agregar Auto\n2. Modificar Auto\n3. Ordenar Autos\n4. Carrera\n5. Salir al menu principal\nIngrese una opcion:\n\n";
				cin >> opcionn;
				if (opcionn == "1")
					opcion = 1;
				else if (opcionn == "2")
					opcion = 2;
				else if (opcionn == "3")
					opcion = 3;
				else if (opcionn == "4")
					opcion = 4;
				else if (opcionn == "5")
					opcion = 5;
				else
					opcion = 0;

				switch (opcion) {
				case 1:
					system("cls");
					cout << "--Agregar Auto--\n\n";
					cout << "Ingrese la marca: ";
					cin >> marca;
					cout << "Ingrese el modelo: ";
					cin >> modelo;
					cout << "Ingrese la velocidad maxima: ";
					cin >> velMax;
					cout << "Ingrese los caballos de fuerza: ";
					cin >> caballosFuerza;
					cout << "Ingrese la aceleracion: ";
					cin >> aceleracion;
					a = new Auto(marca, modelo, velMax, caballosFuerza, aceleracion);
					autos.push_back(a);
					cout << "Auto agregado exitosamente!\n";
					system("pause");
					break;
				case 2:
					system("cls");
					cout << "--Modificar Auto--\n\n";
					cout << "Autos existentes:\n";
					for (int i = 0; i < autos.size(); i++) {
						cout << (i + 1) << ". " << "\nMarca: " << autos[i]->marca << "\nModelo: " << autos[i]->modelo << "\nVelocidad Maxima: " << autos[i]->velMax << "\nCaballos de fuerza: " << autos[i]->caballosFuerza << "\nAceleracion: " << autos[i]->aceleracion << endl << endl;
					}
					cout << "Ingrese la posicion de auto a modificar: \n";
					cin >> pos;
					while (pos < 1 || pos > autos.size()) {
						cout << "Posicion invalida!\nIngrese la posicion de auto a modificar: \n";
						cin >> pos;
					}
					pos--;
					cout << "Modificaciones Dispoinbles:\n1. Ciguenal\n2. Radiador\n3. Neumaticos\n4. Diferencial\n5. Caja de Cambios\nIngrese un aspecto a modificar:\n";
					cin >> opcionn;
					if (opcionn == "1")
						opcion = 1;
					else if (opcionn == "2")
						opcion = 2;
					else if (opcionn == "3")
						opcion = 3;
					else if (opcionn == "4")
						opcion = 4;
					else if (opcionn == "5")
						opcion = 5;
					else
						opcion = 0;
					switch (opcion) {
					case 1:
						system("cls");
						cout << "--Modificar Ciguenal--\n\n";
						cout << "Ciguenales disponibles:\n";
						for (int i = 0; i < ciguenales.size(); i++) {
							cout << (i + 1) << ". " << "\nCaballos de Fuerza: " << ciguenales[i]->caballosFuerza << "\nVelocidad Maxima: " << ciguenales[i]->velMax << endl << endl;
						}
						cout << "Seleccione ciguenal: ";
						cin >> ciguenal;
						while (ciguenal < 1 || ciguenal > ciguenales.size()) {
							cout << "Ciguenal invalido!\nSeleccione ciguenal: ";
							cin >> ciguenal;
						}
						ciguenal--;
						cout << "Resultados de modificacion\n";
						autos[pos]->velMax += ciguenales[ciguenal]->velMax;
						autos[pos]->caballosFuerza -= ciguenales[ciguenal]->caballosFuerza;
						cout << "Marca: " << autos[pos]->marca << "\nModelo: " << autos[pos]->modelo << "\nVelocidad Maxima: " << autos[pos]->velMax << "\nCaballos de fuerza: " << autos[pos]->caballosFuerza << "\nAceleracion: " << autos[pos]->aceleracion << endl;
						system("pause");
						break;
					case 2:

						break;
					}
					case 3:
						system("cls");
						cout << "Ordenar Autos\n";
						system("pause");
						break;
					case 4:
						system("cls");
						cout << "Carrera\n";
						system("pause");
						break;
					case 5:
						system("cls");
						break;
					default:
						system("cls");
						cout << "Opcion invalida!\n";
						system("pause");
						break;
				}
			}
			break;
		case 2:
			system("cls");
			cout << "Gracias por revisar el programa!\n";
			system("pause");
			system("cls");
			cout << "Saliendo...\n";
			system("pause");
			return 0;
			break;
		default:
			system("cls");
			cout << "Opcion invalida!\n";
			system("pause");
			break;
			}
		}
	}
