#pragma once
#include <iostream>
#include <string>
using namespace std;
class Dato
{
	// Atributos
	int numero=0; // Numero que el dato tendra
	string texto; // Texto que el dato tendra

public:
	Dato(); // Constructor vacio

	/* Llenar Dato: Metodo que asigna valor al atributo numero, solo si el Dato no tiene texto
		Input: Valor entero que sera asignado a numero
		Output: Ninguno
	*/
	void llenarDato(int);

	/* Llenar Dato: Metodo que asigna valor al atributo numero, solo si el Dato no tiene texto
	Input: Valor entero que sera asignado a numero
	Output: Ninguno
	*/
	void llenarDato(int, string);

	int getNumero();
	int setNumero(int);
	string getTexto();
	friend ostream&operator<<(ostream&, const Dato&);
	~Dato();
};

