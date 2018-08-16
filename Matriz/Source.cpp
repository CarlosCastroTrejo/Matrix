#include <iostream>
#include"Dato.h"
#include "Matriz.h"

using namespace std;

int main()
{

	Matriz miMatriz(3, 3, 0, 1);
	miMatriz.Llenar();
	cout << miMatriz;
	miMatriz.diagonal();
	miMatriz.consultarDatos(5,6);

	

	system("pause");
}