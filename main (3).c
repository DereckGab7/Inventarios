#include <stdio.h>
#include "inventario.h" 

int main() {
    char nombres[10][50];
    float precios[10];
    int numProductos = 0;
    int opcion;

    printf("Bienvenido al Sistema de Gestion de Inventario (Max 10 productos)\n");

    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Ingresar productos\n");
        printf("2. Calcular precio total del inventario\n");
        printf("3. Mostrar producto mas caro y mas barato\n");
        printf("4. Calcular precio promedio\n");
        printf("5. Buscar producto por nombre\n");
        printf("6. Salir\n");
        printf("------------------------\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Error: Ingrese solo numeros.\n");
            while (getchar() != '\n'); 
            opcion = 0; 
        }

        switch (opcion) {
            case 1:
                numProductos = ingresarProductos(nombres, precios);
                break;
            
            case 2: 
                if (numProductos == 0) {
                    printf("Inventario vacio. Ingrese productos primero (Opcion 1).\n");
                } else {
                    float total = calcularTotal(precios, numProductos);
                    printf("El precio total del inventario es: $%.2f\n", total);
                }
                break;

            case 3: 
                if (numProductos == 0) {
                    printf("Inventario vacio. Ingrese productos primero (Opcion 1).\n");
                } else {
                    mostrarExtremos(nombres, precios, numProductos);
                }
                break;

            case 4: 
                if (numProductos == 0) {
                    printf("Inventario vacio. Ingrese productos primero (Opcion 1).\n");
                } else {
                    float promedio = calcularPromedio(precios, numProductos);
                    printf("El precio promedio de los productos es: $%.2f\n", promedio);
                }
                break;

            case 5: 
                if (numProductos == 0) {
                    printf("Inventario vacio. Ingrese productos primero (Opcion 1).\n");
                } else {
                    buscarProducto(nombres, precios, numProductos);
                }
                break;

            case 6:
                printf("Saliendo del programa... Adios.\n");
                break;

            default:
                printf("Opcion no valida. Por favor, intente de nuevo.\n");
                break;
        }

    } while (opcion != 6);

    return 0;
}