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
	 
	// Constructor
	Dato(); 

	//  Metodos

	/* Llenar Dato: Metodo que asigna valor al atributo numero, solo si el Dato no tiene texto
		Input: Entero que sera asignado a numero
		Output: Ninguno
		(polimorfismo)
	*/
	void llenarDato(int);

	/* Llenar Dato: Metodo que asigna valor al atributo texto y numero, solo si el Dato tiene texto y numero
		Input: Entero que sera asignado a numero y string que sera asignado a texto
		Output: Ninguno
		(polimorfismo)
	*/
	void llenarDato(int, string);

	/* Get Numero: Metodo que extrae el valor asignado al atributo numero
		Input: Ninguno
		Output: valor del atributo numero
	*/
	int getNumero();

	/* Set Numero: Metodo que asigna un valor al atributo numero
		Input: valor entero que sera asignado al atributo
		Output: valor del atributo numero modificado
	*/
	int setNumero(int);

	/* Get Texto: Metodo que extrae el valor asignado al atributo texto
		Input: Ninguno
		Output: valor del atributo texto
	*/
	string getTexto();

	/* Set Texto: Metodo que asigna un valor al atributo texto
	Input: valor string que sera asignado al atributo
	Output: valor del atributo texto modificado
	*/
	string setTexto(string);

	/* Sobrecarga del operador "<<": metodo para imprimir sobrecargando el operador <<
		Input: ostream el cual se le asignara los datos y objeto de clase Dato del cual se extraera la informacion
		Output: ostream 
	*/
	friend ostream&operator<<(ostream&, const Dato&);

	// Destructor
	~Dato();
};

