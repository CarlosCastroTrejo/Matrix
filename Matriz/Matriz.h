#pragma once
#include"Dato.h"
class Matriz
{
	int N = 0; // Numero de filas de la Matriz
	int M = 0; // Numero de columnas de la Matriz
	int formaCelda = 0; // Determina si la celda tendra texto
	int tipoLlenado = 0; // Determina tipo de llenado de la Matriz
	Dato arreglo[20][20]; // Matriz 

	public:
	Matriz(int, int, int, int); // Constructor de la matriz (renglo,columna,formaCelda,tipoLlenado)
	int getN(); // Regresa la variable N (renglones)
	int getM(); // Regresa la variable M (columnas)
	friend ostream& operator<<(ostream&, const Matriz&);
	void Llenar(); // Llena todos los objetos del arreglo
	void operator+=(Matriz);
	void operator*=(Matriz);
	bool operator>(Matriz);



	~Matriz();
};

