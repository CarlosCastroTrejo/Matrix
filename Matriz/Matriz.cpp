#include "Matriz.h"
#include <iostream>
#include "Dato.h"
using namespace std;

Matriz::Matriz(int n, int m, int formaCelda, int tipoLLenado)
{

	if ((n > 1 && n <= 500) && (m > 1 && m <= 500))
	{
		this->N = n;
		this->M = m;
	}
	else
	{
		cout << "Numero de renglones y/o columnas invalido, fin de ejecucion" << endl;
		exit(-1);
	}

	if (formaCelda == 1 || formaCelda == 0)
	{
		this->formaCelda = formaCelda;
	}
	else
	{
		cout << "Valor incorrecto para determinar tipo de datos de ingreso" << endl;
		exit(-1);
	}

	if (tipoLLenado == 1 || tipoLLenado == 2 || tipoLLenado == 3)
	{
		this->tipoLlenado = tipoLLenado;
	}
	else
	{
		cout << "Error en la especificacion de fuente de datos, se asume carga individual" << endl;
		this->tipoLlenado = 1;
	}
}

int Matriz::getN()
{
	return this->N;
}

int Matriz::getM()
{
	return this->M;
}

void Matriz::Llenar()
{
	switch (tipoLlenado)
	{
	case 1:
	{
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < M; y++)
			{
				if (this->formaCelda == 1) 
				{
					int temp = 0;
					string temp1;
					cout << "Ingrese el numero: ";
					cin >> temp;
					cout << "Ingrese el texto: ";
					cin >> temp1;
					arreglo[x][y].llenarDato(temp, temp1);
				}
				else 
				{
					int temp = 0;
					cout << "Ingrese el numero: ";
					cin >> temp;
					arreglo[x][y].llenarDato(temp);
				}
				cout << endl;
			}
		}

	}break;
	case 2:
	{

	}break;
	case 3:
	{

	}break;
	default:
	{

	}break;

	}

}

void Matriz::operator+=(Matriz otraMatriz) 
{
	if (this->N != otraMatriz.N || this->M != otraMatriz.M) 
	{
		cout << "Las matrices no son de tamanos iguales";
	}
	else
	{
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < M; y++)
			{
				arreglo[x][y].setNumero(otraMatriz.arreglo[x][y].getNumero());
			}
		}
	}
}

void Matriz::operator*=(Matriz otraMatriz)
{

	for (int x = 0; x < M; x++)
	{
		for (int y = 0; y < M; y++)
		{
			for (int z = 0; z < N
				; z++)
			{
				arreglo[x][y].setNumero(arreglo[x][z].getNumero() * otraMatriz.arreglo[z][y].getNumero());
			}
			
		}
	}

}

bool Matriz::operator>(Matriz otraMatriz)
{
	return (N > otraMatriz.N && M > otraMatriz.M);
}

ostream& operator<<(ostream &o, const Matriz  &ma)
{
	for (int x = 0; x < ma.N; x++)
	{
		for (int y = 0; y < ma.M; y++)
		{
			o << ma.arreglo[x][y]<<"/";
		}
		o << endl;
	}
	return o;
}



Matriz::~Matriz()
{
}


