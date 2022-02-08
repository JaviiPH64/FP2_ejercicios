// Tema 1 - ejercicio 2

// solución con dimensiones variables de fila y columna

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//Tipos de datos

const int NUM_FILAS = 25;
const int NUM_COLUMNAS = 80;
const int NUM_COLORES = 5;

typedef enum  { negro, azul, verde, amarillo, rojo } tColor;

typedef struct {
	char caracter;
	tColor color, colorFondo;
	bool parpadea;
} tPixel;

typedef tPixel tRejilla[NUM_FILAS][NUM_COLUMNAS];

typedef struct{
	tRejilla rejilla;
	int numFilas, numColumnas;
} tPantalla;

typedef int tNumVecesColor[NUM_COLORES];

//Prototipos

tColor colorMasUtilizado(const tPantalla pantalla, int fila);  // Fila: 1..25
void primerParpadeante(const tPantalla pantalla, int &fila, int &columna); // Fila: 1..25 - Columna: 1..80

string aCadena(tColor color);

int main() {
	tPantalla pantalla;
	int fila, col;
	tColor maxColor;
	
	do{
		cout << "Dime el numero de filas" << endl;
		cin >> pantalla.numFilas;
	}while (pantalla.numFilas < 1 || pantalla.numFilas > NUM_FILAS);

	do{
		cout << "Dime el numero de columnas" << endl;
		cin >> pantalla.numColumnas;
	}while (pantalla.numColumnas < 1 || pantalla.numColumnas > NUM_COLUMNAS);

	// Borrado de toda la pantalla
	for(int i = 0; i < pantalla.numFilas; i++) 
		for(int j = 0; j < pantalla.numColumnas; j++) {
			tPixel pixel = {' ', negro, negro, false };
			pantalla.rejilla[i][j] = pixel;
		}
	

	//
	// Inicialización a datos de prueba
	//
	fila = 1;
	for( int i = 0; i < (pantalla.numColumnas/2 + 1); i++ ){
		tPixel pixel = {' ', amarillo, verde, false };
		pantalla.rejilla[fila-1][i] = pixel;
	}  // en la fila 1 (índice 0) ponemos pantalla.numColumnas/2 + 1 fondos verdes (con primer plano amarillo)
	
	pantalla.rejilla[0][pantalla.numColumnas-1].parpadea = true;  // el único parpadeante es el extremo superior derecho
	
	//
	// Pruebas
	//
	maxColor = colorMasUtilizado(pantalla, fila);  // buscamos el color de fondo más usado en la fila 1 (el verde)

	cout << "El color mas utilizado en la fila " << fila << " es " << aCadena(maxColor) << endl;

	
	
	primerParpadeante(pantalla, fila, col);

	if (fila == 0) 
	  cout << "No hay ningun caracter parpadeante" << endl;
	else 
	  cout << "Primer parpadeante en la fila " << fila << " y columna " << col << endl;
   
	
	return 0;
}

tColor colorMasUtilizado(const tPantalla pantalla, int fila) {
  
}

void primerParpadeante(const tPantalla pantalla, int &fila, int &columna) {
   
}

string aCadena(tColor color) {
	string resultado;
	
	switch(color) {
		case negro:
			resultado = "negro";
			break;
		case azul:
			resultado = "azul";
			break;
		case verde:
			resultado = "verde";
			break;
		case amarillo:
			resultado = "amarillo";
			break;
		case rojo:
			resultado = "rojo";
			break;
		default:
			resultado = "Error!";
			break;
	}

	return resultado;
}
