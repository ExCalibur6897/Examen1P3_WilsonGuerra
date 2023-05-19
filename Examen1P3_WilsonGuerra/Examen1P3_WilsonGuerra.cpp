#include <iostream>

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
