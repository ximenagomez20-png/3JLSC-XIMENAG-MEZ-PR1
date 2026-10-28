// 3JLSC-XIMENAGÓMEZ-PR1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>

using namespace std;

struct Nodo {
	char dato;
	Nodo* siguiente;
	Nodo* anterior;
};

// Recorre la lista desde la cabeza hacia la cola
// Muestra tambien la direccion de memoria de cada nodo y sus enlaces 
void ImprimirLista(Nodo* cabeza) {
	Nodo* actual = cabeza;
	while (actual != nullptr) {
		cout << "Dato: " << actual->dato
			<< " | Direccion: " << actual
			<< " | Anterior: " << actual->anterior
			<< " | Siguiente: " << actual->siguiente << endl;
		actual = actual->siguiente;
	}
	cout << endl;
}

// Recorre la lista desde la cola hacia la cabeza (usando el apuntador anterior)
void ImprimirListaReversa(Nodo* cola) {
	Nodo* actual = cola;
	while (actual != nullptr) {
		cout << "Dato: " << actual->dato
			<< " | Direccion: " << actual
			<< " | Anterior: " << actual->anterior
			<< " | Siguiente: " << actual->siguiente << endl;
		actual = actual->anterior;
	}
	cout << endl;
}

void BorrarLista(Nodo*& cabeza, Nodo*& cola) {
	int contador = 0;
	while (cabeza != nullptr) {
		Nodo* siguiente = cabeza->siguiente;
		contador++;
		// Se imprime antes de delete: despues el nodo ya no existe
		cout << "Elemento borrado " << contador
			<< " | Dato: " << cabeza->dato
			<< " | Direccion: " << cabeza << endl;
		delete cabeza;
		cabeza = siguiente;
	}
	cout << "Total de elementos borrados: " << contador << endl; 
	cola = nullptr;
}

// Agrega un nodo al final; mantener la cola evita recorrer toda la lista
void agregarNodo(Nodo*& cabeza, Nodo*& cola, int valor) {
	Nodo* nuevoNodo = new Nodo;
	nuevoNodo->dato = valor;
	nuevoNodo->siguiente = nullptr;
	nuevoNodo->anterior = nullptr;

	if (cabeza == nullptr) {
		cabeza = nuevoNodo;
		cola = nuevoNodo;
	}
	else {
		cola->siguiente = nuevoNodo;
		nuevoNodo->anterior = cola;
		cola = nuevoNodo;
	}
}


int main()
{
	cout << "Actividad / Examen Practico 1 - Lista Doblemente Enlazada\n";
	Nodo* cabeza = nullptr;
	Nodo* cola = nullptr;
	int opcion;
	const int tamanolista = 6;

	do {
		cout << "\n____Menu principal____";
		cout << "1. Capturar elementos"
		cout << "2. Imprimir lista de Inicio a Fin\n";
		cout << "3. Imprimir lista de Fin a Inicio\n";
		cout << "4. Borrar lista\n";
		cout << "5. salir\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;

		switch (opcion) {
		    case 1:
				cout << "\nCapturar" << tamanolista << "elementos:\n";
				for (int i = 0; i < tamanolista; i++) {
					char valor;
					cout << "Ingrese el caracter " << i + 1 << ": ";
					cin >> valor;
					agregarNodo(cabeza, cola, valor);
				}
				cout << "Elemento ingresado con exito\n";
				break;

		case 2:
			cout << "\nImprimiendo lista de Inicio a Fin: " << endl;
			ImprimirLista(cabeza);
			break;
		case 3:
			cout << "\nImprimiendo lista de Fin a Inicio: " << endl;
			ImprimirListaReversa(cola);
			break;
		case 4:
			cout << "\nBorrando lista de caracteres: " << endl;
			BorrarLista(cabeza, cola);
			break;
		case 5: 
			cout << "\nSaliendo del programa..." << endl;
			break;
		default: 
			cout << "\nOpcion no valida. Intente de nuevo";
			break;
		}
	} while (opcion != 5);

	cout << "\nEXAMEN PRACTICO 1" << endl;

	return 0;
}