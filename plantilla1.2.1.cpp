// Tema 1 - ejercicio 2 (plantilla)


//Constantes y tipos de datos

const int NUM_FILAS = 25;
const int NUM_COLUMNAS = 80;
const int NUM_COLORES = 5;


enum  tColor { negro, azul, verde, amarillo, rojo };

struct tPixel {
	char caracter;
	tColor color, colorFondo;
	bool parpadea;
};

typedef tPixel tPantalla[NUM_FILAS][NUM_COLUMNAS];


//Prototipos

tColor colorMasUtilizado(const tPantalla pantalla, int fila);  // Fila: 1..25
void primerParpadeante(const tPantalla pantalla, int &fila, int &columna); // Fila: 1..25 - Columna: 1..80;  0 en fila y en columna si no lo hay


string aCadena(tColor color);

int main() {   
	tPantalla pantalla;
	int fila, col;
	tColor maxColor;
	
	// Borrado de toda la pantalla
	for(int i = 0; i < NUM_FILAS; i++) 
		for(int j = 0; j < NUM_COLUMNAS; j++) {
			tPixel pixel = {' ', negro, negro, false };
			pantalla[i][j] = pixel;
		}
	

	//
	// Inicialización a datos de prueba
	//
	fila = 1;
	for( int i = 0; i < 45; i++ ){
		tPixel pixel = {' ', amarillo, verde, false };
		pantalla[fila-1][i] = pixel;
	}  // en la fila 1 (índice 0) ponemos 45 fondos verdes (con primer plano amarillo)
	
	pantalla[9][2].parpadea = true;  // este es el único parpadeante =  fila: 10 columna: 3
	
	//
	// Pruebas
	//
	maxColor = colorMasUtilizado(pantalla, fila);  // buscamos el color de fondo más usado en la fila 1 (el verde)

	cout << "El color más utilizado en la fila " << fila << " es " << aCadena(maxColor) << endl;

	
	
	primerParpadeante(pantalla, fila, col);

	if (fila == 0) 
	  cout << "No hay ningun caracter parpadeante" << endl;
	else 
	  cout << "Primer parpadeante en la fila " << fila << " y columna " << col << endl;
   
	return 0;
}



tColor colorMasUtilizado(const tPantalla pantalla, int fila) {
  // Se recibe la fila, no el índice (índice = fila-1)
  

}

void primerParpadeante(const tPantalla pantalla, int &fila, int &columna) {
   // Devuelve la fila-columna (no los índices); 0 en fila y en columna si no lo hay
   
}


string aCadena(tColor color) {
	string resultado;

	switch (color) {
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
