#include "Dato.h"
#include <iostream>
#include <string>
using namespace std;


Dato::Dato()
{
}

void Dato::llenarDato(int numero)
{
	this->numero = numero;
}

void Dato::llenarDato(int numero,string texto)
{
	this->numero = numero;
	this->texto = texto;
}

 ostream&operator<<(ostream& o, const Dato& data) 
{
	 // Se le asigna a la variable 'o' de tipo ostream el numero y texto del objeto Dato
	 o << data.numero << " " << data.texto;
	 return o;
}

int Dato::getNumero() 
{

	return this->numero;
}

int Dato::setNumero(int nuevoNumero)
{
	this->numero = nuevoNumero;
	return this->numero;
}

string Dato::getTexto()
{
	return this->texto;
}

string Dato::setTexto(string nuevoTexto)
{
	this->texto = nuevoTexto;
	return this->texto;
}

Dato::~Dato()
{
}
