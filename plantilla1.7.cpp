#include <iostream>
#include <fstream>
#include <windows.h> // para SetConsoleTextAttribute() de VISUAL STUDIO
using namespace std;

const int NUM_COLORES = 3;

const int PALETA[NUM_COLORES] = {0,1,4};  // 0 = negro; 1 = azul; 4 = rojo

const int DIMENSION = 9;

typedef enum {VACIO, FIJA, RELLENO} tEstadoCasilla;

struct tCasilla {
	int numero;
	tEstadoCasilla estado;
};

typedef tCasilla tTablero[DIMENSION][DIMENSION];


// Inicializa el estado de la casilla dada a vacío 
void iniciaCasilla(tCasilla & casilla);

// Dibuja una casilla
void dibujaCasilla(const tCasilla & casilla);

// Establece el color de fondo al valor dado como argumento
void colorFondo(int color);

//Inicializa todas las casillas del tablero
void iniciaTablero(tTablero tablero); 

//Carga un tablero de fichero
bool cargarTablero(string fichero, tTablero tablero); 

// Dibuja el tablero en pantalla
void dibujarTablero(const tTablero tablero);

int main(){
	tTablero tablero;
	
	iniciaTablero(tablero);
	if (cargarTablero("sudoku1.txt", tablero))
		dibujarTablero(tablero);
	
	return 0;
}

void dibujaCasilla(const tCasilla& casilla) {
	colorFondo(PALETA[casilla.estado]);
	if (casilla.estado != VACIO) cout << casilla.numero;
	else cout << " ";
	colorFondo(0);
}

/*
Visual Studio incluye una biblioteca, Windows.h, que tiene, entre otras, rutinas para la consola. 
Una de ellas es SetConsoleTextAttribute(), que permite ajustar los colores de fondo y primer plano. 
Al invocarlo con un color para el fondo (0 = negro; 1 = azul; 4 = rojo) lo establecerá, 
y usará el blanco (15) como color de primer plano.
*/
void colorFondo(int color){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}

// Dibuja el tablero en pantalla
void dibujarTablero(const tTablero tablero) {
	//filas
	for (int i = 0; i < DIMENSION; i++) {
		if (i % 3 == 0) {
			for (int k = 0; k < DIMENSION * 3 + 3; k++)
				cout << "-";
			cout << endl;
		}

		for (int j = 0; j < DIMENSION; j++) {
			if (j % 3 == 0)
				cout << "|";
			cout << " ";
			dibujaCasilla(tablero[i][j]);
			cout << " ";
		}
		cout << "|";
		cout << endl;
	}
	for (int k = 0; k < DIMENSION * 3 + 3; k++)
		cout << "-";
	cout << endl;
}