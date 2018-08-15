#include <iostream>
#include"Dato.h"
#include "Matriz.h"

using namespace std;

int main()
{

	Matriz miMatriz(3, 3, 0, 1);
	miMatriz.Llenar();
	cout << miMatriz;

	Matriz otra(3, 4, 0, 1);
	otra.Llenar();
	cout << miMatriz;

	system("pause");
}