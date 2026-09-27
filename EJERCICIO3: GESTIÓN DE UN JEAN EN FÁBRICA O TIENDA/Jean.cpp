#include <iostream> 
#include <iomanip> 
#include <string> 
using namespace std; 
int main() { 
    string codigo, color, talla, estadoTela; 
    int respuestaTenido, cantidadTenidos, cantidadBotones, opcionEstado, opcion; 
    double precio, humedad; 
    bool fueTenido; 
    // Se registran y validan los datos del jean. 
    cout << "Codigo del jean: "; getline(cin, codigo); 
    while (codigo.empty()) { 
        cout << "El codigo no puede estar vacio. Ingrese nuevamente: "; 
        getline(cin, codigo); 
    } 
    cout << "Color: "; getline(cin, color); 
    while (color.empty()) { 
        cout << "El color no puede estar vacio. Ingrese nuevamente: "; 
        getline(cin, color); 
    } 
    cout << "Talla: "; getline(cin, talla); 
    while (talla.empty()) { 
        cout << "La talla no puede estar vacia. Ingrese nuevamente: "; 
        getline(cin, talla); 
    } 
    do { 
        cout << "¿Fue tenido? (1 Si, 0 No): "; cin >> respuestaTenido; 
        if (respuestaTenido != 0 && respuestaTenido != 1) cout << "Respuesta invalida.\n"; 
    } while (respuestaTenido != 0 && respuestaTenido != 1); 
    fueTenido = respuestaTenido == 1; 
    if (fueTenido) { 
        do { 
            cout << "Cantidad de tenidos (mayor que 0): "; cin >> cantidadTenidos; 
            if (cantidadTenidos <= 0) cout << "Cantidad invalida.\n"; 
        } while (cantidadTenidos <= 0); 
    } else cantidadTenidos = 0; 
    do { 
        cout << "Precio (mayor o igual que 0): $ "; cin >> precio; 
        if (precio < 0) cout << "Precio invalido.\n"; 
    } while (precio < 0); 
    do { 
        cout << "Cantidad de botones (0 o mas): "; cin >> cantidadBotones; 
        if (cantidadBotones < 0) cout << "Cantidad invalida.\n"; 
    } while (cantidadBotones < 0); 
    do { 
        cout << "Humedad del jean (0 a 100): "; cin >> humedad; 
        if (humedad < 0 || humedad > 100) cout << "Humedad invalida.\n"; 
    } while (humedad < 0 || humedad > 100); 
    do { 
        cout << "Estado de la tela (1 Buena, 2 Regular, 3 Danada): "; cin >> opcionEstado; 
        if (opcionEstado < 1 || opcionEstado > 3) cout << "Estado invalido.\n"; 
    } while (opcionEstado < 1 || opcionEstado > 3); 
    if (opcionEstado == 1) estadoTela = "Buena"; 
    else if (opcionEstado == 2) estadoTela = "Regular"; 
    else estadoTela = "Danada"; 
    // Toda la lógica está en main, sin clases ni funciones adicionales. 
    do { 
        cout << "\n--- GESTION DEL JEAN ---\n"; 
        cout << "1. Mostrar datos\n2. Lavar jean\n3. Secar jean\n4. Salir"; 
        cout << "\nSeleccione una opcion: "; cin >> opcion; 
        switch (opcion) { 
            case 1: 
                cout << "\n--- DATOS DEL JEAN ---\n"; 
                cout << "Codigo: " << codigo << "\nColor: " << color << "\nTalla: " << talla; 
                cout << "\nFue tenido: " << (fueTenido ? "Si" : "No"); 
                cout << "\nCantidad de tenidos: " << cantidadTenidos; 
                cout << fixed << setprecision(2) << "\nPrecio: $" << precio; 
                cout << "\nCantidad de botones: " << cantidadBotones; 
                cout << "\nHumedad: " << humedad << "%\nEstado de la tela: " << estadoTela << '\n'; 
                break; 
            case 2: 
                if (cantidadTenidos > 0) { 
                    cantidadTenidos--; 
                    if (cantidadTenidos == 0) fueTenido = false; 
                    cout << "Lavado realizado.\n"; 
                } else cout << "No quedan tenidos por disminuir.\n"; 
                cout << "Cantidad de tenidos: " << cantidadTenidos << '\n'; 
                break; 
            case 3: 
                if (humedad > 0) { 
                    humedad -= 10; 
                    if (humedad < 0) humedad = 0; 
                    cout << "Secado realizado.\n"; 
                } else cout << "El jean ya esta seco.\n"; 
                cout << fixed << setprecision(2) << "Humedad actual: " << humedad << "%\n"; 
                break; 
            case 4: 
                cout << "Programa finalizado.\n"; 
                break; 
            default: 
                cout << "Opcion invalida.\n"; 
        } 
    } while (opcion != 4); 
    return 0; 
}
