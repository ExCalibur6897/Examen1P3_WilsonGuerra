//Incluir todas las librerias y clases necesarias
#include <iostream>
#include <vector>
#include "Auto.h"
#include "Ciguenal.h"
#include "Diferencial.h"
#include "Neumaticos.h"
#include "Radiador.h"
#include "CajaDeCambios.h"

using namespace std;

//Funcion para calcular los resultados de las carreras
void carrera(double velMax1, double velMax2, double aceleracion1, double aceleracion2, double distancia) {
	double ta1 = velMax1 / aceleracion1;
	double ta2 = velMax2 / aceleracion2;
	double da1 = 0.5 * aceleracion1 * (ta1 * ta1);
	double da2 = 0.5 * aceleracion2 * (ta2 * ta2);
	double tvmax1 = (da1 - distancia) / velMax1;
	double tvmax2 = (da2 - distancia) / velMax2;
	double t_total1 = ta1 + tvmax1;
	double t_total2 = ta2 + tvmax2;

	cout << "\nTiempo total auto 1: " << t_total2 << endl;
	cout << "\nTiempo total auto 2: " << t_total1 << endl;
	if (t_total2 < t_total1) {
		cout << "\nEl auto 1 es el ganador!\n";
		system("pause");
	}
	else {
		cout << "\nEl auto 2 es el ganador!\n";
		system("pause");
	}
}

int main()
{
	//Declaracion de variables
	int opcion = 0;
	int ciguenal = 0;
	int cajadc = 0;
	int diferencial = 0;
	int neumatico = 0;
	int radiador = 0;
	int ordenar = 0;
	int auto1 = 0;
	int auto2 = 0;
	double distancia = 0;
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
		nfs = true; //Booleano para el menu de need for speed mantenerse en el menu de need for speed.
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
				//Conversion para que el programa no crashee en caso de que se ingresen letras en el menu
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
						cout << "\nResultados de modificacion\n";
						autos[pos]->velMax += ciguenales[ciguenal]->velMax;
						autos[pos]->caballosFuerza += ciguenales[ciguenal]->caballosFuerza;
						cout << "Marca: " << autos[pos]->marca << "\nModelo: " << autos[pos]->modelo << "\nVelocidad Maxima: " << autos[pos]->velMax << "\nCaballos de fuerza: " << autos[pos]->caballosFuerza << "\nAceleracion: " << autos[pos]->aceleracion << endl;
						system("pause");
						break;
					case 2:
						system("cls");
						cout << "--Modificar Radiador--\n\n";
						cout << "Radiadores disponibles:\n";
						for (int i = 0; i < radiadores.size(); i++) {
							cout << (i + 1) << ". " << "\nCaballos de Fuerza: " << radiadores[i]->caballosFuerza << endl;
						}
						cout << "Seleccione radiador: ";
						cin >> radiador;
						while (radiador < 1 || radiador > radiadores.size()) {
							cout << "Radiador invalido!\nSeleccione radiador: ";
							cin >> radiador;
						}
						radiador--;
						autos[pos]->caballosFuerza += radiadores[radiador]->caballosFuerza;
						cout << "\nResultados de modificacion\n";
						cout << "Marca: " << autos[pos]->marca << "\nModelo: " << autos[pos]->modelo << "\nVelocidad Maxima: " << autos[pos]->velMax << "\nCaballos de fuerza: " << autos[pos]->caballosFuerza << "\nAceleracion: " << autos[pos]->aceleracion << endl;
						system("pause");
						break;
					case 3:
						system("cls");
						cout << "--Modificar Neumaticos--\n\n";
						cout << "Neumaticos disponibles:\n";
						for (int i = 0; i < neumaticos.size(); i++) {
							cout << (i + 1) << ". " << "\nAceleracion: " << neumaticos[i]->aceleracion << endl;
						}
						cout << "Seleccione neumatico: ";
						cin >> neumatico;
						while (neumatico < 1 || neumatico > neumaticos.size()) {
							cout << "Neumatico invalido!\nSeleccione neumatico: ";
							cin >> neumatico;
						}
						neumatico--;
						autos[pos]->aceleracion -= neumaticos[neumatico]->aceleracion;
						cout << "\nResultados de modificacion\n";
						cout << "Marca: " << autos[pos]->marca << "\nModelo: " << autos[pos]->modelo << "\nVelocidad Maxima: " << autos[pos]->velMax << "\nCaballos de fuerza: " << autos[pos]->caballosFuerza << "\nAceleracion: " << autos[pos]->aceleracion << endl;
						system("pause");
						break;
					case 4:
						system("cls");
						cout << "--Modificar Diferencial--\n\n";
						cout << "Diferenciales disponibles:\n";
						for (int i = 0; i < diferenciales.size(); i++) {
							cout << (i + 1) << ". " << "\nAceleracion: " << diferenciales[i]->aceleracion << endl;
						}
						cout << "Seleccione diferencial: ";
						cin >> diferencial;
						while (diferencial < 1 || diferencial > diferenciales.size()) {
							cout << "Diferencial invalido!\nSeleccione diferencial: ";
							cin >> diferencial;
						}
						diferencial--;
						autos[pos]->aceleracion -= diferenciales[diferencial]->aceleracion;
						cout << "\nResultados de modificacion\n";
						cout << "Marca: " << autos[pos]->marca << "\nModelo: " << autos[pos]->modelo << "\nVelocidad Maxima: " << autos[pos]->velMax << "\nCaballos de fuerza: " << autos[pos]->caballosFuerza << "\nAceleracion: " << autos[pos]->aceleracion << endl;
						system("pause");
						break;
					case 5:
						cout << "--Modificar Caja de Cambios--\n\n";
						cout << "Cajas de cambios disponibles:\n";
						for (int i = 0; i < cajasDeCambios.size(); i++) {
							cout << (i + 1) << ". " << "\nAceleracion: " << cajasDeCambios[i]->aceleracion << "\nVelocidad Maxima: " << cajasDeCambios[i]->velMax << endl;
						}
						cout << "Seleccione caja de cambios: ";
						cin >> cajadc;
						while (cajadc < 1 || cajadc > cajasDeCambios.size()) {
							cout << "Caja de cambios invalida!\nSeleccione caja de cambios: ";
							cin >> cajadc;
						}
						cajadc--;
						autos[pos]->aceleracion -= cajasDeCambios[cajadc]->aceleracion;
						autos[pos]->velMax += cajasDeCambios[cajadc]->velMax;
						cout << "\nResultados de modificacion\n";
						cout << "Marca: " << autos[pos]->marca << "\nModelo: " << autos[pos]->modelo << "\nVelocidad Maxima: " << autos[pos]->velMax << "\nCaballos de fuerza: " << autos[pos]->caballosFuerza << "\nAceleracion: " << autos[pos]->aceleracion << endl;
						system("pause");
						break;
					default:
						system("cls");
						cout << "Opcion invalida!\n";
						system("pause");
						break;
					}
					break;
					case 3:
						system("cls");
						cout << "--Ordenar Autos--\n";
						cout << "Autos existentes:\n";
						for (int i = 0; i < autos.size(); i++) {
							cout << (i+1) << "\nMarca: " << autos[i]->marca << "\nModelo: " << autos[i]->modelo << "\nVelocidad Maxima: " << autos[i]->velMax << "\nCaballos de fuerza: " << autos[i]->caballosFuerza << "\nAceleracion: " << autos[i]->aceleracion << endl;
						}
						cout << "\nEspecificaciones de los autos:\n1. Velocidad Maxima\n2. Caballos de fuerza\n3. Aceleracion\nSeleccione aspecto para ordenar:\n";
						cin >> ordenar;
						while (ordenar < 1 || ordenar > 3) {
							cout << "Opcion invalida!\nSeleccione aspecto para ordenar:\n";
							cin >> ordenar;
						}
						system("cls");
						cout << "Resultados del ordenamiento\n";
						switch (ordenar) {
						case 1:
							//Ordenado del vector de carros en base a velocidad maxima
							for (int i = 0; i < autos.size(); i++) {
								for (int j = 0; j < autos.size() - 1; j++) {
									if (autos[j]->velMax < autos[j + 1]->velMax) {
										Auto* temp = autos[j];
										autos[j] = autos[j + 1];
										autos[j + 1] = temp;
									}
								}
							}
							for (int i = 0; i < autos.size(); i++) {
								cout << (i + 1) << "\nMarca: " << autos[i]->marca << "\nModelo: " << autos[i]->modelo << "\nVelocidad Maxima: " << autos[i]->velMax << "\nCaballos de fuerza: " << autos[i]->caballosFuerza << "\nAceleracion: " << autos[i]->aceleracion << endl;
							}
							break;
						case 2:
							//Ordenado del vector de carros en base a caballos de fuerza
							for (int i = 0; i < autos.size(); i++) {
								for (int j = 0; j < autos.size() - 1; j++) {
									if (autos[j]->caballosFuerza < autos[j + 1]->caballosFuerza) {
										Auto* temp = autos[j];
										autos[j] = autos[j + 1];
										autos[j + 1] = temp;
									}
								}
							}
							for (int i = 0; i < autos.size(); i++) {
								cout << (i + 1) << "\nMarca: " << autos[i]->marca << "\nModelo: " << autos[i]->modelo << "\nVelocidad Maxima: " << autos[i]->velMax << "\nCaballos de fuerza: " << autos[i]->caballosFuerza << "\nAceleracion: " << autos[i]->aceleracion << endl;
							}
							break;
						case 3:
							//Ordenado del vector de carros en base a aceleracion
							for (int i = 0; i < autos.size(); i++) {
								for (int j = 0; j < autos.size() - 1; j++) {
									if (autos[j]->aceleracion < autos[j + 1]->aceleracion) {
										Auto* temp = autos[j];
										autos[j] = autos[j + 1];
										autos[j + 1] = temp;
									}
								}
							}
							for (int i = 0; i < autos.size(); i++) {
								cout << (i + 1) << "\nMarca: " << autos[i]->marca << "\nModelo: " << autos[i]->modelo << "\nVelocidad Maxima: " << autos[i]->velMax << "\nCaballos de fuerza: " << autos[i]->caballosFuerza << "\nAceleracion: " << autos[i]->aceleracion << endl;
							}
							break;
						}
						system("pause");
						break;
					case 4:
						system("cls");
						cout << "--Carrera--\n";
						cout << "Autos existentes:\n";
						for (int i = 0; i < autos.size(); i++) {
							cout << (i + 1) << "\nMarca: " << autos[i]->marca << "\nModelo: " << autos[i]->modelo << "\nVelocidad Maxima: " << autos[i]->velMax << "\nCaballos de fuerza: " << autos[i]->caballosFuerza << "\nAceleracion: " << autos[i]->aceleracion << endl;
						}
						cout << "Seleccione el auto 1: ";
						cin >> auto1;
						cout << "Seleccione el auto 2: ";
						cin >> auto2;
						cout << "Ingrese la distancia de la carrera (en km): ";
						cin >> distancia;
						auto1--;
						auto2--;
						//se les resta 1 a las variables ya que se ingresa el valor que se ve en pantalla pero en realidad es ese valor -1.
						carrera(autos[auto1]->velMax, autos[auto2]->velMax, autos[auto1]->aceleracion, autos[auto2]->aceleracion, distancia);
						system("cls");
						break;
					case 5:
						nfs = false;
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
