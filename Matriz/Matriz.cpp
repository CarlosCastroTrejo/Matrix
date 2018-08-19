#include "Matriz.h"
#include <iostream>
#include "Dato.h"
#include <assert.h>   // Estatuto assert
#include<time.h>
#include<fstream>
using namespace std;

Matriz::Matriz(int n, int m, int formaCelda, int tipoLLenado)
{
	assert((n > 1 && n <= 500) && (m > 1 && m <= 500) && "Numero de renglones y/o columnas invalido, fin de ejecucion");
	assert(formaCelda == 1 || formaCelda == 0 && "Valor incorrecto para determinar tipo de datos de ingreso");

	this->N = n;
	this->M = m;
	this->formaCelda = formaCelda;

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
		string dato;
		ifstream archivo;
		archivo.open("llenarDatos.csv");

		int x = 0, y = 0;
		if (archivo.is_open())
		{
			while (!archivo.eof())
			{
				getline(archivo, dato);
				if (formaCelda == 0)
				{
					while (dato.length() > 0)
					{
						arreglo[x][y].setNumero(stoi(dato.substr(0, dato.find(','))));
						dato.erase(0, dato.find(',') + 1);
						if (dato.length() == 1)
						{
							y++;
							arreglo[x][y].setNumero(stoi(dato.substr(0, 1)));
							dato.erase(0, 1);
						}
						y++;
					}
					if (y > M + 1)
					{
						assert(0 && "El numero de columnas es erroneo");
					}
					y = 0;

					x++;
					if (x > N)
					{
						assert(0 && "El numero de renglones es erroneo");
					}
				
				}
				else 
				{
					while (dato.length() > 0)
					{
						arreglo[x][y].setNumero(stoi(dato.substr(0, dato.find(','))));
						dato.erase(0, dato.find(',') + 1);
						arreglo[x][y].setTexto(dato.substr(0, dato.find(',')));
						dato.erase(0, dato.find(',') + 1);
						if (y == M-1)
						{
							dato.erase(0, dato.length());
						}
						y++;
					}
					if (y > M )
					{
						assert(0 && "El numero de columnas es erroneo");
					}
					y = 0;
					x++;	
					if (x > N)
					{
						assert(0 && "El numero de renglones es erroneo");
					}
				}
			}
			archivo.close();
		}
		else
		{
			cout << "Archivo inexistente o faltan permisos para abrirlo" << endl;
		}
	}break;
	case 3:
	{
		srand(time(NULL));
		char arregloCaracteres[]{"abcdefghijklmnopqrstuvwxyz"};
		
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < M; y++)
			{
				if (this->formaCelda == 1) //Contiene texto
				{
					int numeroRandom = rand() % 1000;
					int caracterRandom=0;
					string palabraRandom;
					for (int x = 0; x < 5; x++) 
					{
						caracterRandom = rand() % (sizeof(arregloCaracteres) - 1);
						palabraRandom += arregloCaracteres[caracterRandom];
					}
					
					arreglo[x][y].llenarDato(numeroRandom, palabraRandom);
				}
				else
				{
					int temp = rand() % 1000;
					arreglo[x][y].llenarDato(temp);
				}
			}
		}


	}break;
	default:
	{

	}break;

	}

}

void Matriz::desplegarDiagonal()
{
	cout << endl;
	for (int x = 0; x < N; x++)
	{
		for (int space = 0; space < x; space++)
		{
			cout << "  ";
		}
		for (int y = 0; y < M; y++)
		{
			if (x == y)
			{
				cout << arreglo[x][y];
			}
		}
		cout << endl;
	}
}

void Matriz::modificarCelda(int tempX,int tempY)
{
	

	assert(tempX <= N-1 && tempX>= 0 && "La matriz no tiene el numero de fila que quieres acceder\n");
	assert(tempX <= M-1 && tempY >= 0 && "La matriz no tiene el numero de fila que quieres acceder\n");
	if (formaCelda == 0)
	{
		int tempNumero = 0;
		cout << endl << "Ingresa el nuevo numero de la casilla: ";
		cin >> tempNumero;
		arreglo[tempX][tempY].setNumero(tempNumero);
	}
	else 
	{
		int tempNumero = 0;
		string tempTexto;
		cout << endl << "Ingresa el nuevo numero de la casilla: ";
		cin >> tempNumero;
		cout << endl << "Ingresa el nuevo texto de la casilla: ";
		cin >> tempTexto;
		arreglo[tempX][tempY].setNumero(tempNumero);
		arreglo[tempX][tempY].setTexto(tempTexto);
	}
}

void Matriz::consultarDatos(int x, int y)
{
	cout << endl;
	assert(x <= N-1 && x>=0 && "La matriz no tiene el numero de fila que quieres acceder\n");
	assert(y <= M-1 && y >= 0 && "La matriz no tiene el numero de fila que quieres acceder\n");

	cout << arreglo[x-1][y-1];
}

void Matriz::mostrarOrilla() 
{
	cout << endl;
	for (int x = 0; x < N; x++) 
	{
		for (int y = 0; y < N; y++)
		{
			if (x == 0 || x == N - 1 || y == 0 || y == M - 1) 
			{
				cout << arreglo[x][y];
			}
			else 
			{
				cout << "   ";
			}
		}
		cout << endl;
	}
}

void Matriz::mostrarCentro()
{
	cout << endl;
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			if (x == 0 || x == N - 1 || y == 0 || y == M - 1)
			{
				cout << "   ";
			}
			else
			{
				cout << arreglo[x][y];
			}
		}
		cout << endl;
	}
}

void Matriz::intercambiarElementos(bool eleccion,int nueva,int vieja)
{
	cout << endl;
	
	int temporal = 0;

	if (eleccion) 
	{

		assert(vieja < M && "El numero de columna no existe");
		assert(nueva < M && "El numero de columna no existe");

		for (int x = 0; x < M; x++) 
		{
			temporal = arreglo[x][vieja].getNumero();
			arreglo[x][vieja].setNumero(arreglo[x][nueva].getNumero());
			arreglo[x][nueva].setNumero(temporal);
		}

	}
	else if (!eleccion) 
	{

		assert(vieja < N && "El numero de columna no existe");
		assert(nueva < N && "El numero de columna no existe");

		for (int x = 0; x < N; x++)
		{
			temporal = arreglo[vieja][x].getNumero();
			arreglo[vieja][x].setNumero(arreglo[nueva][x].getNumero());
			arreglo[nueva][x].setNumero(temporal);
		}

	}
}

void Matriz::transpuesta() 
{
	Dato aux[50][50];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			aux[j][i] = arreglo[i][j];
		}
	}
	int auxInt = N;
	N = M;
	M = auxInt;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arreglo[i][j] = aux[i][j];
		}
	}

}

int Matriz::sumaRenglonColumna(bool fila, int numeroDeFilaOColumna) {
	if (fila) {
		acumrenglon = 0;
		for (int j = 0; j < M; j++) {
			acumrenglon += arreglo[numeroDeFilaOColumna][j].getNumero();
		}
		return acumrenglon;
	}
	else {
		acumcolumna = 0;
		for (int i = 0; i < N; i++) {
			acumcolumna += arreglo[i][numeroDeFilaOColumna].getNumero();
		}
		return acumcolumna;
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
				arreglo[x][y].setNumero(arreglo[x][y].getNumero()+otraMatriz.arreglo[x][y].getNumero());
			}
		}
	}
}

void Matriz::operator*=(Matriz otraMatriz)
{
	Matriz temporal = otraMatriz;
	cout << endl;
	int resultado = 0;
	for (int x = 0; x < N; x++)
	{
		resultado = 0;
		for (int y = 0; y < M; y++)
		{
			resultado = 0;
			for (int z = 0; z < N; z++)
			{
				resultado+=arreglo[x][z].getNumero() * otraMatriz.arreglo[z][y].getNumero();
			}
			cout << endl;
			temporal.arreglo[x][y].setNumero(resultado);
			resultado = 0;
		}
	}

	for (int x = 0; x < N; x++) 
	{
		for (int y = 0; y < M; y++)
		{
			arreglo[x][y].setNumero(temporal.arreglo[x][y].getNumero());
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


