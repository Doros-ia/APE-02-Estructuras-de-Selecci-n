#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int horas, minutos, segundos, cambiar;
    do {
        do {
            cout << "Ingrese las horas (0 a 23): ";
            cin >> horas;
            if (horas < 0 || horas > 23) cout << "Hora invalida.\n";
        } while (horas < 0 || horas > 23);
        do {
            cout << "Ingrese los minutos (0 a 59): ";
            cin >> minutos;
            if (minutos < 0 || minutos > 59) cout << "Minutos invalidos.\n";
        } while (minutos < 0 || minutos > 59);
        do {
            cout << "Ingrese los segundos (0 a 59): ";
            cin >> segundos;
            if (segundos < 0 || segundos > 59) cout << "Segundos invalidos.\n";
        } while (segundos < 0 || segundos > 59);
        cout << "Hora registrada: " << setfill('0') << setw(2) << horas << ":"
             << setw(2) << minutos << ":" << setw(2) << segundos << '\n';
        cout << setfill(' ');
        do {
            cout << "¿Desea cambiar la hora? (1 Si, 0 No): ";
            cin >> cambiar;
            if (cambiar != 0 && cambiar != 1) cout << "Respuesta invalida.\n";
        } while (cambiar != 0 && cambiar != 1);
    } while (cambiar == 1);
    cout << "Programa finalizado.\n";
    return 0;
}
