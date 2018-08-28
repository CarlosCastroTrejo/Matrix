// Estructura de Datos
// Proyecto Matriz: Se utiliza la abstraccion de datos para crear una matriz
// Carlos Emiliano Castro Trejo A01422062
// Jorge Romero Romanis A01423263

#include <iostream>
#include"Dato.h"
#include "Matriz.h"
#include <assert.h>   // Estatuto assert

using namespace std;

int main(int argc, const char * argv[])
{
	cout << "Mumero de argumentos" << argc << endl;

	for (int x = 0; x < argc; x++)
	{
		cout << argv[x] << endl;
	}

	assert(argc<6 && "El numero de argumentos es erroneo" );

//	Matriz miMatriz(stoi(argv[1]), stoi(argv[2]), stoi(argv[3]), stoi(argv[4]));
	Matriz miMatriz(4, 4, 1, 3);
	miMatriz.Llenar();
	cout << miMatriz;
	/*
	miMatriz.mostrarOrilla();
	miMatriz.mostrarCentro();
	miMatriz.intercambiarElementos(1,0,1);
	cout << miMatriz;

	miMatriz.intercambiarElementos(0, 2, 3);
	cout << miMatriz;*/

	miMatriz.bubbleSort(0, 0);
	//miMatriz.bubbleSort(0, 1);
	//miMatriz.bubbleSort(0, 2);
	cout << endl << endl;
	cout << miMatriz;

	//Matriz otraMatriz(3, 3, 0, 1);
	//otraMatriz.Llenar();
	//cout << otraMatriz;

	//miMatriz *= otraMatriz;
	/*miMatriz.desplegarDiagonal();
	miMatriz.consultarDatos(2,2);
	miMatriz.modificarCelda();
	*/
	//cout << miMatriz;


	

	system("pause");
}