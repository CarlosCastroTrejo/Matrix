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
	 o << data.numero << " " << data.texto;
	 return o;
}

int Dato::getNumero() 
{

	return this->numero;
}

int Dato::setNumero(int x)
{
	this->numero += x;
	return this->numero;
}

string Dato::getTexto()
{
	return this->texto;
}

Dato::~Dato()
{
}
