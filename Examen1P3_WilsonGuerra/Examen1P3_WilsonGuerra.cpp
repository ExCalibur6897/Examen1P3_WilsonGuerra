#include <iostream>
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
	string opcionn = "";
	while (true) {
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
			system("cls");
			cout << "Bienvenido a Need for Speed!\n";
			cout << "1. Agregar Auto\n2. Modificar Auto\n3. Ordenar Autos\n4. Carrera\n\nIngrese una opcion:\n";
			cin >> opcionn;
			if (opcionn == "1")
				opcion = 1;
			else if (opcionn == "2")
				opcion = 2;
			else if (opcionn == "3")
				opcion = 3;
			else if (opcionn == "4")
				opcion = 4;
			else
				opcion = 0;
			
			switch (opcion) {
			case 1:
				system("cls");
				cout << "Agregar Auto\n";
				system("pause");
				break;
			case 2:
				system("cls");
				cout << "Modificar Auto\n";
				system("pause");
				break;
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
			default:
				system("cls");
				cout << "Opcion invalida!\n";
				system("pause");
				break;
			system("pause");
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
