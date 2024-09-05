#include<iostream>
#include <string>
#include <vector>
using namespace std;
/*Preguntas del examen
Pregunta 1: Templates
Tienda es una empresa que se encarga de la venta de productos de alimentos, esta empresa se encarga de diferentes productos, se debe codificar las ventas de los productos, se necesita ingresar 5 atributos a una clase, los siguientes atributos son: ID, producto, tipo de producto(1: importado, 2: nacional), stock, id_empleado.
Desarrollar una aplicación que permita utilizar templates con clases, las funciones que puede realizar son las siguientes:
- Registrar 5 productos de manera aleatoria donde contienen los siguientes atributos: ID(int), producto(string), tipo de producto(int), stock(int), id_empleado(int) y precio(float).
- Mostrar los productos que son de tipo nacional
- Mosstrar que productos tienen un precio entre 20.00 y 100.00
- Mostrar los productos donde el ID es un numero impar.

Pregunta 2: Lambdas y recursividad
Escribir un programa utilizando expresiones lambdas(a,b) y recursividad (C)
a. Ingresar numero de 6 digitos enteros que permita descomponerlo en dos partes, la descomposicion de ser en tres digitos, por ejemplo: 654321 -> 654 - 321, se tiene que verificar cual es el numero mayor de las dos partes
b. Ingresar un numero entero, donde se permita calcular el numero factorial, el numero debe ser mayor a 0.
c. Desarrollar un algoritmo con recursividad, se debe ingresar un numero entero por teclado y que permita indicar si es un numero primo.

Pregunta 3: Listas
Escribir un programa en C++ para diseñar y crear una lista simple enlazada de numeros enteros. La lista debe permitir:
- Agregar al final nuevos elementos a la lista simple enlazada, donde permite el ingreso de elementos en el rango de 5 a 30.
- Mostrar los elementos impares de la lista simple enlazada
- Eliminar elemento de la lista simple enlazada de acuerdo a numero entero ingresado por teclado
- Obtener la cantidad de elementos que son menores a 20 de la lista simple enlazada
En la solucion del diseño de la lista se debe usar Templates. No debe usar STL. No debe usar libreria list.
Se debe crear un menu para poder utilizar las funciones mencionadas

*/

//Pregunta 3: Listas
template<class T>
class List {
private:
	T data;
	List* next;
	List* head;
	List* tail;
public:
	List() {
		head = NULL;
		tail = NULL;
	}
	void add(T data) {
		if(data<5 || data>30) return;
		List* newNode = new List();
		newNode->data = data;
		newNode->next = NULL;
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	void showImpar() {
		List* temp = head;
		while (temp != NULL) {
			if (temp->data % 2 != 0) {
				cout << temp->data << " ";
			}
			temp = temp->next;
		}
		cout << endl;
	}
	void deleteElement(T data) {
		List* temp = head;
		List* prev = NULL;
		while (temp != NULL) {
			if (temp->data == data) {
				if (prev == NULL) {
					head = temp->next;
					delete temp;
					return;
				}
				else {
					prev->next = temp->next;
					delete temp;
					return;
				}
			}
			prev = temp;
			temp = temp->next;
		}
	}
	int countLessThan20() {
		List* temp = head;
		int count = 0;
		while (temp != NULL) {
			if (temp->data < 20) {
				count++;
			}
			temp = temp->next;
		}
		return count;
	}
	void showList() {
		List* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	~List() {
		List* temp = head;
		while (temp != NULL) {
			head = head->next;
			delete temp;
			temp = head;
		}
	}

};


//Pregunta 1: Templates
template<class T>
class Tienda {
private:
	T ID;
	string producto;
	int tipoProducto;
	int stock;
	int id_empleado;
	float precio;
	vector<Tienda> productos;
public:
	Tienda() {}
	//Registrar productos
	void registrarProducto(T ID, string producto, int tipoProducto, int stock, int id_empleado, float precio) {
		//Añadir productos al vector tienda
		Tienda p;
		p.ID = ID;
		
	}
	void mostrarNacional() {


		if (tipoProducto == 2) {
			cout << "ID: " << ID << " Producto: " << producto << " Tipo: Nacional" << " Stock: " << stock << " ID Empleado: " << id_empleado << " Precio: " << precio << endl;
		}
	}
	void mostrarPrecio() {
		if (precio >= 20.00 && precio <= 100.00) {
			cout << "ID: " << ID << " Producto: " << producto << " Tipo: Nacional" << " Stock: " << stock << " ID Empleado: " << id_empleado << " Precio: " << precio << endl;
		}
	}
	void mostrarImpar() {
		if (ID % 2 != 0) {
			cout << "ID: " << ID << " Producto: " << producto << " Tipo: Nacional" << " Stock: " << stock << " ID Empleado: " << id_empleado << " Precio: " << precio << endl;
		}
	}
};



//Pregunta 2.a:
int descomponer() {
	//generar numero aleatorio de 6 digitos
	int n = 100000 + rand() % 900000;
	//int n;
	//cout<<"Ingrese un numero de 6 digitos: ";
	//cin>>n;
	if (n < 100000 || n>999999) {
		cout << "El numero ingresado no es de 6 digitos" << endl;
		return 0;
	}
	int a = n / 1000;
	int b = n % 1000;
	cout << a << " - " << b << endl;
	int a1, a2, a3, b1, b2, b3;
	a1 = a / 100;
	a2 = (a % 100) / 10;
	a3 = a % 10;
	b1 = b / 100;
	b2 = (b % 100) / 10;
	b3 = b % 10;
	//Numero mayor de A
	int mayorA = a1;
	if (a2 > mayorA) mayorA = a2;
	if (a3 > mayorA) mayorA = a3;
	//Numero mayor de B
	int mayorB = b1;
	if (b2 > mayorB) mayorB = b2;
	if (b3 > mayorB) mayorB = b3;
	cout << "El numero mayor de A es: " << mayorA << endl;
	cout << "El numero mayor de B es: " << mayorB << endl;
	return 0;
}

//Pregunta 2.b: usando lambdas sin recursividad

void factorial() {
	int n;
	cout << "Ingrese un numero entero mayor a 0: ";
	cin >> n;
	if (n <= 0) {
		cout << "El numero ingresado no es mayor a 0" << endl;
		return;
	}
	auto fact = [](int n) {
		int f = 1;
		for (int i = 1; i <= n; i++) {
			f *= i;
		}
		return f;
	};
	cout << "El factorial de " << n << " es: " << fact(n) << endl;
}

//Pregunta 2.c: usando recursividad
bool esPrimo(int n, int i = 2) {
	if (n <= 2) return (n == 2) ? true : false;
	if (n % i == 0) return false;
	if (i * i > n) return true;
	return esPrimo(n, i + 1);
}

int main() {
	//descomponer();
	//int n;
	//cout << "Ingrese un numero entero: ";
	//cin >> n;
	//cout<<esPrimo(n);

	//Prueba lista
//Menu lista
	List<int> lista;
	int opcion;
	do {
		cout << "Menu" << endl;
		cout << "1. Agregar elemento" << endl;
		cout << "2. Mostrar impares" << endl;
		cout << "3. Eliminar elemento" << endl;
		cout << "4. Contar menores a 20" << endl;
		cout << "5. Mostrar lista" << endl;
		cout << "6. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			int n;
			cout << "Ingrese un numero: ";
			cin >> n;
			lista.add(n);
			break;
		case 2:
			lista.showImpar();
			break;
		case 3:
			int n1;
			cout << "Ingrese un numero a eliminar: ";
			cin >> n1;
			lista.deleteElement(n1);
			break;
		case 4:
			cout << "Cantidad de elementos menores a 20: " << lista.countLessThan20() << endl;
			break;
		case 5:
			lista.showList();
			break;
		}
	} while (opcion != 6);

	return 0;
}