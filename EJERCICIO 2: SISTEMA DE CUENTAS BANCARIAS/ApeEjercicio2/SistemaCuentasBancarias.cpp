#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main() {
    string dni, numeroCuenta, tipoCuenta, numeroActual, tipoActual;
    string cuenta1 = "", cuenta2 = "", cuenta3 = "";
    string tipo1 = "", tipo2 = "", tipo3 = "";
    int cantidadCuentas, i, tipo, cuentaSeleccionada, destino, opcion;
    double saldoInicial, saldoActual = 0, saldoDestino = 0, monto;
    double saldo1 = 0, saldo2 = 0, saldo3 = 0;
    // Se registra el DNI y se valida que no quede vacio.
    cout << "Ingrese el DNI del cliente: "; getline(cin, dni);
    while (dni.empty()) { cout << "DNI vacio. Ingrese nuevamente: "; getline(cin, dni); }
    do {
        cout << "¿Cuantas cuentas desea crear? (1 a 3): "; cin >> cantidadCuentas;
    } while (cantidadCuentas < 1 || cantidadCuentas > 3);
    // Se crean hasta tres cuentas usando variables simples, sin arreglos.
    for (i = 1; i <= cantidadCuentas; i++) {
        cin.ignore(10000, '\n');
        cout << "Numero de la cuenta " << i << ": "; getline(cin, numeroCuenta);
        while (numeroCuenta.empty()) { cout << "Numero vacio. Ingrese nuevamente: "; getline(cin, numeroCuenta); }
        do { cout << "Tipo (1 Ahorros, 2 Corriente): "; cin >> tipo; }
        while (tipo != 1 && tipo != 2);
        tipoCuenta = tipo == 1 ? "Ahorros" : "Corriente";
        do { cout << "Saldo inicial: $ "; cin >> saldoInicial; }
        while (saldoInicial < 0);
        switch (i) {
            case 1: cuenta1 = numeroCuenta; tipo1 = tipoCuenta; saldo1 = saldoInicial; break;
            case 2: cuenta2 = numeroCuenta; tipo2 = tipoCuenta; saldo2 = saldoInicial; break;
            case 3: cuenta3 = numeroCuenta; tipo3 = tipoCuenta; saldo3 = saldoInicial; break;
        }
    }
    do { cout << "Seleccione una cuenta (1 a " << cantidadCuentas << "): "; cin >> cuentaSeleccionada; }
    while (cuentaSeleccionada < 1 || cuentaSeleccionada > cantidadCuentas);
    // El menu se repite hasta que se elija la opcion 6.
    do {
        switch (cuentaSeleccionada) {
            case 1: numeroActual = cuenta1; tipoActual = tipo1; saldoActual = saldo1; break;
            case 2: numeroActual = cuenta2; tipoActual = tipo2; saldoActual = saldo2; break;
            case 3: numeroActual = cuenta3; tipoActual = tipo3; saldoActual = saldo3; break;
        }
        cout << "\n--- MENU BANCARIO ---\nCuenta seleccionada: " << numeroActual << '\n';
        cout << "1. Ver atributos\n2. Enviar dinero\n3. Recibir dinero\n";
        cout << "4. Transferir entre cuentas\n5. Seleccionar otra cuenta\n6. Salir\nOpcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "DNI: " << dni << "\nNumero: " << numeroActual << "\nTipo: " << tipoActual;
                cout << fixed << setprecision(2) << "\nSaldo: $" << saldoActual << '\n';
                break;
            case 2:
                do { cout << "Monto a enviar: $ "; cin >> monto; }
                while (monto <= 0 || monto > saldoActual);
                saldoActual -= monto;
                if (cuentaSeleccionada == 1) saldo1 = saldoActual;
                else if (cuentaSeleccionada == 2) saldo2 = saldoActual;
                else saldo3 = saldoActual;
                cout << "Envio realizado. Saldo: $" << saldoActual << '\n';
                break;
            case 3:
                do { cout << "Monto a recibir: $ "; cin >> monto; } while (monto <= 0);
                saldoActual += monto;
                if (cuentaSeleccionada == 1) saldo1 = saldoActual;
                else if (cuentaSeleccionada == 2) saldo2 = saldoActual;
                else saldo3 = saldoActual;
                cout << "Dinero recibido. Saldo: $" << saldoActual << '\n';
                break;
            case 4:
                // Se resta al origen y se suma el mismo monto al destino.
                if (cantidadCuentas == 1) cout << "No existe otra cuenta para transferir.\n";
                else {
                    do { cout << "Cuenta destino: "; cin >> destino; }
                    while (destino < 1 || destino > cantidadCuentas || destino == cuentaSeleccionada);
                    do { cout << "Monto a transferir: $ "; cin >> monto; }
                    while (monto <= 0 || monto > saldoActual);
                    if (destino == 1) saldoDestino = saldo1;
                    else if (destino == 2) saldoDestino = saldo2;
                    else saldoDestino = saldo3;
                    saldoActual -= monto; saldoDestino += monto;
                    if (cuentaSeleccionada == 1) saldo1 = saldoActual;
                    else if (cuentaSeleccionada == 2) saldo2 = saldoActual;
                    else saldo3 = saldoActual;
                    if (destino == 1) saldo1 = saldoDestino;
                    else if (destino == 2) saldo2 = saldoDestino;
                    else saldo3 = saldoDestino;
                    cout << "Transferencia realizada. Saldo origen: $" << saldoActual << '\n';
                }
                break;
            case 5:
                do { cout << "Seleccione una cuenta: "; cin >> cuentaSeleccionada; }
                while (cuentaSeleccionada < 1 || cuentaSeleccionada > cantidadCuentas);
                break;
            case 6: cout << "Sistema finalizado.\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 6);
    return 0;
}
