#include <iostream>
#include <stdlib.h> // Para borrar pantalla
#include <string>
#include <vector> // Para usar el vector de clientes

using namespace std;

class Cliente {
private:
    float balance;  // balance/saldo
    string nombre;
    string iD;
    string direccion;
    string correo;

public:
    // Constructor por defecto (sin argumentos)
    Cliente() : balance(0.0f), nombre(""), iD(""), direccion(""), correo("") {}

    // Constructor con argumentos para inicializar los datos del cliente
    Cliente(float balanceInicial, string nombreCliente, string idCliente, string direccionCliente, string correoCliente) {
        balance = balanceInicial;
        nombre = nombreCliente;
        iD = idCliente;
        direccion = direccionCliente;
        correo = correoCliente;
    }

    // Métodos para establecer (set) y obtener (get) el balance
    void setBalance(float nuevoBalance) {
        balance = nuevoBalance;
    }

    float getBalance() {
        return balance;
    }

    // Métodos para establecer y obtener el nombre
    void setNombre(string nuevoNombre) {
        nombre = nuevoNombre;
    }

    string getNombre() {
        return nombre;
    }

    // Métodos para establecer y obtener el ID
    void setId(string nuevoId) {
        iD = nuevoId;
    }

    string getId() {
        return iD;
    }

    // Métodos para establecer y obtener la dirección
    void setDireccion(string nuevaDireccion) {
        direccion = nuevaDireccion;
    }

    string getDireccion() {
        return direccion;
    }

    // Métodos para establecer y obtener el correo
    void setCorreo(string nuevoCorreo) {
        correo = nuevoCorreo;
    }

    string getCorreo() {
        return correo;
    }

    // Método para depositar dinero en la cuenta
    void depositar(float deposito) {
        balance += deposito;
    }

    // Método para retirar dinero de la cuenta
    void retirar(float retiro) {
        balance -= retiro;
    }

    // Método para mostrar la información del cliente y su cuenta
    void consultar() {
        cout << "Nombre: " << nombre << endl;
        cout << "El ID: " << iD << endl;
        cout << "Balance: " << balance << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Correo: " << correo << endl;
    }
};

// Función para realizar las acciones del menú sobre un cliente específico
void realizarAccion(int opcion, Cliente& cliente) {
    float cantidad;

    if (opcion == 1) { // Depositar
        cout << "Ingrese la cantidad a depositar: ";
        cin >> cantidad;
        if (cantidad > 0) {
            cliente.depositar(cantidad);
            cout << "Deposito realizado con éxito." << endl;
        } else {
            cout << "La cantidad a depositar debe ser mayor que cero." << endl;
        }
    } else if (opcion == 2) { // Retirar
        cout << "Ingrese la cantidad a retirar: ";
        cin >> cantidad;
        if (cantidad > 0 && cantidad <= cliente.getBalance()) {
            cliente.retirar(cantidad);
            cout << "Retiro realizado con éxito." << endl;
        } else if (cantidad <= 0) {
            cout << "La cantidad a retirar debe ser mayor que cero." << endl;
        } else {
            cout << "Fondos insuficientes." << endl;
        }
    } else if (opcion == 3) { // Consultar
        cliente.consultar();
    } else {
        cout << "Opción inválida." << endl;
    }

    cout << "Presione cualquier tecla para continuar...";
    cin.get(); // Consume el salto de línea anterior
    cin.get(); // Espera a que el usuario presione una tecla
    system("cls"); // Limpia la pantalla (Windows)
    // system("clear"); // Limpia la pantalla (Linux/macOS)
}

int main() {
    vector<Cliente> clientes; // <--- 1. Declaramos un vector llamado 'clientes' para guardar objetos de la clase Cliente
    int opcionMenu;

    do {
        cout << "\t\tSistema Bancario" << endl;
        cout << "1) Agregar nuevo cliente." << endl;
        cout << "2) Seleccionar cliente existente." << endl;
        cout << "3) Salir." << endl;
        cout << "Seleccione una opción: ";
        cin >> opcionMenu;

        system("cls"); // Limpia la pantalla

        if (opcionMenu == 1) {
            // --- 2. Lógica para agregar un nuevo cliente ---
            float balanceInicial;
            string nombreCliente, idCliente, direccionCliente, correoCliente;

            cout << "Ingrese el nombre del cliente: ";
            getline(cin >> ws, nombreCliente);

            cout << "Ingrese el ID del cliente: ";
            getline(cin >> ws, idCliente);

            cout << "Ingrese la dirección del cliente: ";
            getline(cin >> ws, direccionCliente);

            cout << "Ingrese el correo electrónico del cliente: ";
            getline(cin >> ws, correoCliente);

            cout << "Ingrese el saldo inicial de la cuenta: ";
            cin >> balanceInicial;

            // --- 3. Creamos un nuevo objeto Cliente con los datos ingresados ---
            Cliente nuevoCliente(balanceInicial, nombreCliente, idCliente, direccionCliente, correoCliente);

            // --- 4. Agregamos el nuevo cliente al vector 'clientes' usando push_back() ---
            clientes.push_back(nuevoCliente);

            cout << "Cliente agregado con éxito." << endl;
            cout << "Presione cualquier tecla para continuar...";
            cin.get();
            cin.get();
            system("cls");
        } else if (opcionMenu == 2) {
            // --- 5. Lógica para seleccionar un cliente existente ---
            if (clientes.empty()) {
                cout << "No hay clientes registrados." << endl;
                cout << "Presione cualquier tecla para continuar...";
                cin.get();
                cin.get();
                system("cls");
                continue; // Volvemos al inicio del bucle do-while
            }

            cout << "Lista de clientes:" << endl;
            // --- 6. Mostramos la lista de clientes con un índice ---
            for (int i = 0; i < clientes.size(); ++i) {
                cout << i + 1 << ") " << clientes[i].getNombre() << " (ID: " << clientes[i].getId() << ")" << endl;
            }

            int indiceCliente;
            cout << "Seleccione el número del cliente: ";
            cin >> indiceCliente;

            if (indiceCliente >= 1 && indiceCliente <= clientes.size()) {
                // --- 7. Accedemos al cliente seleccionado usando el índice (restamos 1 porque el vector es base 0) ---
                Cliente& clienteSeleccionado = clientes[indiceCliente - 1];

                int opcionAccion;
                do {
                    cout << "\n\t\tAcciones del Cliente" << endl;
                    cout << "1) Depositar efectivo." << endl;
                    cout << "2) Retirar dinero." << endl;
                    cout << "3) Consultar estado de cuenta." << endl;
                    cout << "4) Volver al menú principal." << endl;
                    cout << "Seleccione una opción: ";
                    cin >> opcionAccion;

                    system("cls");

                    // --- 8. Llamamos a la función realizarAccion para el cliente seleccionado ---
                    realizarAccion(opcionAccion, clienteSeleccionado);

                } while (opcionAccion != 4);
            } else {
                cout << "Número de cliente inválido." << endl;
                cout << "Presione cualquier tecla para continuar...";
                cin.get();
                cin.get();
                system("cls");
            }
        } else if (opcionMenu == 3) {
            cout << "Gracias por usar el sistema bancario." << endl;
        } else {
            cout << "Opción inválida." << endl;
            cout << "Presione cualquier tecla para continuar...";
            cin.get();
            cin.get();
            system("cls");
        }

    } while (opcionMenu != 3);

    return 0;
}