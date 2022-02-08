// Tema 1 - ejercicio 4 - plantilla

#include <iostream>
#include <string>
#include <ctime>
#include <locale>
using namespace std;


// Constantes
const int NUM_DEP = 6;
const int NUM_CON = 5;
const int NUM_MES = 12;

// Tipo Enumerado para los departamentos
typedef enum tDepartamentos { marketing, contabilidad, rrhh, distribucion, ingenieria, investigacion };

// Tipo Enumerado para los conceptos
typedef  enum tConceptos { salarios, suministros, mobiliario, equipamiento, otros };

// Tipo Enumerado para los meses
typedef enum tMeses {
    enero, febrero, marzo, abril, mayo, junio, julio, agosto, septiembre, octubre,
    noviembre, diciembre
};

// Tipo Array para guardar la contabilidad completa
typedef double tContabilidad[NUM_DEP][NUM_CON][NUM_MES];

// Tipo Array para guardar los gastos por meses
typedef double tGastosMes[NUM_MES];

//
// subprogramas pedidos
//

//a)	Escribir en la pantalla la suma de gastos de cada uno de los departamentos.
void muestraGastosDepartamentos(const tContabilidad contabilidad);
//b)	Escribir en la pantalla la suma de gastos por cada concepto.
void muestraGastosConceptos(const tContabilidad contabilidad);
//c)	Calcular y devolver el total de gastos de un año.
double totalGastosAnio(const tContabilidad contabilidad);
//d)	Construir y devolver un array con los gastos generados cada mes.
void gastosPorMeses(const tContabilidad contabilidad, tGastosMes gastosMes);
// e)	Encontrar el valor más alto de la tabla de gastos y devolver el departamento responsable, el tipo de gasto y el mes en que se produjo.
void maximoGasto(const tContabilidad contabilidad, double& maximo, tDepartamentos& depMax,
    tConceptos& conMax, tMeses& mesMax);

//
// subprogramas auxiliares
//
void inicializaContabilidad(tContabilidad contabilidad);
string nombreDepartamento(tDepartamentos dep);
string nombreConcepto(tConceptos con);
string nombreMes(tMeses mes);


int main() {
    // Declaración de variables
    tContabilidad contabilidad;
    

    setlocale(LC_ALL, "spanish");

    // Inicialización aleatoria de los datos de la empresa
    inicializaContabilidad(contabilidad);

    // Apartado a. Gastos por departamento.
    muestraGastosDepartamentos(contabilidad);

    // Apartado b. Gastos por concepto.
    muestraGastosConceptos(contabilidad);

    // Apartado c. Gastos totales en el año.
    

    // Apartado d. Gastos por meses en array
    

    // Apartado e. Máximo gasto y dónde se produjo
    


    return 0;
}

void inicializaContabilidad(tContabilidad contabilidad) {
    
}

void muestraGastosDepartamentos(const tContabilidad contabilidad) {
    
}

void muestraGastosConceptos(const tContabilidad contabilidad) {
    
}

double totalGastosAnio(const tContabilidad contabilidad) {
    
}

void gastosPorMeses(const tContabilidad contabilidad, tGastosMes gastosMes) {
    
}

void maximoGasto(const tContabilidad contabilidad, double& maximo, tDepartamentos& depMax, tConceptos& conMax, tMeses& mesMax) {
    
}

string nombreDepartamento(tDepartamentos dep) {
    string nombre;
    switch (dep) {
    case marketing:
        nombre = "marketing";
        break;
    case contabilidad:
        nombre = "Contabilidad";
        break;
    case rrhh:
        nombre = "RRHH";
        break;
    case distribucion:
        nombre = "Distribución";
        break;
    case ingenieria:
        nombre = "Ingeniería";
        break;
    case investigacion:
        nombre = "Investigación";
        break;
    }
    return nombre;
}

string nombreConcepto(tConceptos con) {
    string nombre;
    switch (con) {
    case salarios:
        nombre = "salarios";
        break;
    case suministros:
        nombre = "suministros";
        break;
    case mobiliario:
        nombre = "mobiliario";
        break;
    case equipamiento:
        nombre = "equipamiento";
        break;
    case otros:
        nombre = "otros";
        break;
    }
    return nombre;
}

string nombreMes(tMeses mes) {
    string nombre;
    switch (mes) {
    case enero:
        nombre = "enero";
        break;
    case febrero:
        nombre = "febrero";
        break;
    case marzo:
        nombre = "marzo";
        break;
    case abril:
        nombre = "abril";
        break;
    case mayo:
        nombre = "mayo";
        break;
    case junio:
        nombre = "junio";
        break;
    case julio:
        nombre = "julio";
        break;
    case agosto:
        nombre = "agosto";
        break;
    case septiembre:
        nombre = "septiembre";
        break;
    case octubre:
        nombre = "octubre";
        break;
    case noviembre:
        nombre = "noviembre";
        break;
    case diciembre:
        nombre = "diciembre";
        break;
    }
    return nombre;
}
