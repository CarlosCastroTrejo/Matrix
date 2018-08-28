#pragma once
#include"Dato.h"
class Matriz
{
	// Atributos

	// Numero de filas de la Matriz
	int N = 0; 

	// Numero de columnas de la Matriz
	int M = 0; 

	// Determina si la celda tendra texto. 1 representa que se usa parte texto y 0  representa que no se usa parte texto. 
	int formaCelda = 0; 

	// Determina tipo de llenado de la Matriz. 1 el usuario teclea todos los datos uno a uno, 2 los datos se introducen a partir de un archivo de texto y 3 los datos se alimentan por una función random. 
	int tipoLlenado = 0; 

	// Matriz 
	Dato arreglo[20][20]; 

	//Variable que acumula la suma de los enteros en los renglones especificados del Metodo Sum
	int acumrenglon;

	//Variable que acumula la suma de los enteros en las columas especificados del Metodo Sum
	int acumcolumna;

	//Arreglo tipo doble auxiliar para duplicar una columna o fila especifica 
	int arregloAux[50]; 

	// Metodos

	public:
	/* Matriz : Constructor del objeto
		Input: Entero que asigna el valor a N, entero que asigna el valor a M, entero que asigna el valor a formaCelda y entero que asigna el valor a tipoLlenado
		Output: Ninguno
	*/
	Matriz(int, int, int, int);

	/* Get N: Metodo extrae el valor de N
		Input: Ninguno
		Output: valor del atributo N
	*/
	int getN(); 
	

	/* Get M: Metodo extrae el valor de M
		Input: Ninguno
		Output: valor del atributo M
	*/
	int getM();


	/* Llenar Matriz: Metodo encargado de asignar valores a cada casilla de la Matriz
		Input: Ninguno
		Output: Ninguno
	*/
	void Llenar(); 

	/* Desplegar Diagonal: Metodo encargado de desplegar en pantalla la diagonal principal de la matriz
		Input: Ninguno
		Output: Ninguno
	*/
	void desplegarDiagonal();

	/* Consula Diagonal: Metodo encargado de verificar si la casilla en la matriz existe y devolver el valor en caso de que la casilla exista
		Input: Entero que representa la coordenada X y entero que representa la coordenada Y
		Output: Ninguno
	*/
	void consultarDatos(int, int);

	/* Modificar Celda: Metodo encargado de preguntar la coordenada a modificar, verificar que exista esa celda y finalmente modificarla
		Input: Ninguno
		Output: Ninguno
	*/
	void modificarCelda(int, int);

	/* Mostrar Orilla: Metodo encargado de mostrar todos los elementos cuya coordenada renglón sea n-1 y coordenada columna sea m-1. 
		Input: Ninguno
		Output: Ninguno
	*/
	void mostrarOrilla();

	/* Mostrar Centro: Metodo encargado de mostrar todos los elementos centros de la matriz
		Input: Ninguno
		Output: Ninguno
	*/
	void mostrarCentro();

	/* Intercambiar Elementos: Metodo encargado de intercambiar todos los elementos del renglón/columna x por los del renglón/columna y.
		Input: Ninguno
		Output: Ninguno
	*/
	void intercambiarElementos(bool,int,int);

	/* Transpuesta : Metodo encargado de modificar la matriz original y calcular su transpuesta
		Input: Ninguno
		Output: Ninguno
	*/
	void transpuesta();

	/* Suma Renglon o Columna : Metodo encargado de suma todos los numeros de cierta columna a renglon
		Input: valor booleano para referirse si es columna o renglon, valor entero del numero de la columna o renglon a sumar
		Output: valor entero que hace referencia a la suma 
	*/
	int sumaRenglonColumna(bool,int);

	/* BubbleSort: Metodo encargado de arreglar Fila o Columna de la matriz con el metodo de BubbleSort
		Input: valor booleano para referirse si es columna o renglon, valor entero del numero de la columna o renglon a sumar
		Output: Ninguno
	*/
	void bubbleSort(bool, int);

	/* Insertion Sort: Metodo encargado de arreglar Fila o Columna de la matriz con el metodo de Insertion
		Input: valor booleano para referirse si es columna o renglon, valor entero del numero de la columna o renglon a sumar
		Output: Ninguno
	*/
	void insertionSort(bool, int);

	/* QuickSort: Metodo encargado de arreglar Fila o Columna de la matriz con el metodo de recursividad de QuickSort
		Input: valor booleano para referirse si es columna o renglon, valor entero del numero de la columna o renglon a sumar
		Output: Ninguno
	*/
	void QuickSort(bool, int);

	/* QuickSort: Metodo encargado de arreglar Fila o Columna de la matriz con el metodo de recursividad de QuickSort
		Input: valor booleano para referirse si es columna o renglon, valor entero del numero de la columna o renglon a sumar
		Output: Ninguno
	*/
	void SelectionSort(bool, int);


	/* Llenar: Metodo encargado de asignar valores a cada casilla de la Matriz
		Input: Ninguno
		Output: Ninguno
	*/
	void operator+=(Matriz);

	/* Sobrecarga del operador "*=": metodo para multiplicar dos matrices sobrecargando el operador *=
	Input: Matriz por la cual se va a multiplicar
	Output: Ninguno
	*/
	void operator*=(Matriz);

	/* Sobrecarga del operador ">": metodo para que comparar dos matrices sobrecargando el operador >, se compara el tamano de la matriz
		Input: Matriz por la cual se va a comparar
		Output: valor booleano
	*/
	bool operator>(Matriz);

	/* Sobrecarga del operador "<<": metodo para imprimir sobrecargando el operador <<
		Input: ostream el cual se le asignara los datos y objeto de clase Matriz del cual se extraera la informacion
		Output: ostream
	*/
	friend ostream& operator<<(ostream&, const Matriz&);
	
	/* CambioAnterior: intercambia los datos de una casilla del arreglo arr con respecto la posicion anterior, ya sea trbajando con columnas o filas
		Input: valor booleano para referirse si es columna o renglon, valor entero del numero de la columna o renglon a sumar
		Output: Ninguno
	*/
	void CambioAnterior(bool, int, int); //(Columna?, i,j) 

	/* Rapido: Metodo encargado de implementa el algoritmo de QuickSort par ordenar  
		Input: arreglo a ordenar, valor entero de inicio desde donde se quiere ordenar, valor entero de final hasta donde se quiere ordenar) 
		Output: Ninguno
	*/
	void rapido(int arr[], int izq, int der);//(arregloAux [], 


	// Destructor
	~Matriz();
};

