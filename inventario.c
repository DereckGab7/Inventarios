#include <stdio.h>
#include <string.h>
#include "inventario.h"

int ingresarProductos(char nombres[10][50], float precios[10]) {
    int i = 0;
    char continuar = 's';

    printf("--- Ingreso de Productos (max 10) ---\n");

    while (i < 10 && (continuar == 's' || continuar == 'S')) {
        printf("Ingrese nombre del producto %d: ", i + 1);
        scanf("%49s", nombres[i]);

        printf("Ingrese precio de %s: ", nombres[i]);
        while (scanf("%f", &precios[i]) != 1 || precios[i] < 0 || precios[i] > 100)  {
            printf("Error. Ingrese un precio valido: ");
            while (getchar() != '\n');
        }

        i++;

        if (i < 10) {
            printf("¿Desea ingresar otro producto? (s/n): ");
            scanf(" %c", &continuar); 
        } else {
            printf("Se ha alcanzado el límite de 10 productos.\n");
        }
    }

    printf("Se ingresaron %d productos.\n", i);
    return i;
}

float calcularTotal(float precios[10], int numProductos) {
    float total = 0.0;
    for (int i = 0; i < numProductos; i++) {
        total += precios[i];
    }
    return total;
}

void mostrarExtremos(char nombres[10][50], float precios[10], int numProductos) {
    if (numProductos == 0) {
        printf("No hay productos para mostrar.\n");
        return;
    }

    int indiceMax = 0;
    int indiceMin = 0;
    float precioMax = precios[0];
    float precioMin = precios[0];

    for (int i = 1; i < numProductos; i++) {
        if (precios[i] > precioMax) {
            precioMax = precios[i];
            indiceMax = i;
        }
        if (precios[i] < precioMin) {
            precioMin = precios[i];
            indiceMin = i;
        }
    }

    printf("--- Productos Extremos ---\n");
    printf("Producto mas Caro: %s (Precio: $%.2f)\n", nombres[indiceMax], precioMax);
    printf("Producto mas Barato: %s (Precio: $%.2f)\n", nombres[indiceMin], precioMin);
}

float calcularPromedio(float precios[10], int numProductos) {
    if (numProductos == 0) {
        return 0.0;
    }
    return calcularTotal(precios, numProductos) / numProductos;
}

void buscarProducto(char nombres[10][50], float precios[10], int numProductos) {
    if (numProductos == 0) {
        printf("No hay productos en el inventario para buscar.\n");
        return;
    }

    char nombreBuscado[50];
    int encontrado = 0;

    printf("Ingrese el nombre del producto a buscar: ");
    scanf("%49s", nombreBuscado);

    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("-> Producto encontrado: %s, Precio: $%.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("-> Producto '%s' no encontrado en el inventario.\n", nombreBuscado);
    }
}