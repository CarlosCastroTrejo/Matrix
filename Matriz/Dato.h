#pragma once
#include <iostream>
#include <string>
using namespace std;
class Dato
{
	int numero=0; // Numero que el dato tendra
	string texto; // Texto que el dato tendra
public:
	Dato();
	void llenarDato(int);
	int getNumero();
	int setNumero(int);
	string getTexto();
	void llenarDato(int, string);
	friend ostream&operator<<(ostream&, const Dato&);
	~Dato();
};

