#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Función para verificar si la cadena ingresada es un número entero válido (sin usar ctype.h)
int esNumeroEntero(char* cadena) {
    // Recorrer la cadena y verificar que todos los caracteres sean dígitos (0-9)
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] < '0' || cadena[i] > '9') {  // Verificar si el carácter no es un número
            if (cadena[i] != '\n') {  // Ignorar el salto de línea
                return 0; // No es un número entero
            }
        }
    }
    return 1; // Es un número entero
}

// Función para ingresar datos de productos
void ingresarDatos(char nombres[][50], float precios[], int cantidades[], int numProductos) {
    char buffer[100];
    for (int i = 0; i < numProductos; i++) {

        // Ingresar el nombre del producto
        printf("Ingrese el nombre del producto %d: ", i + 1);
        fgets(nombres[i], 50, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = '\0';  // Eliminar el salto de línea

        // Ingresar el precio del producto
        int valid = 0;
        while (!valid) {
            printf("Ingrese el precio del producto %d: ", i + 1);
            fgets(buffer, sizeof(buffer), stdin);
            if (sscanf(buffer, "%f", &precios[i]) != 1) {
                printf("Error: Ingrese un número válido para el precio.\n");
            } else if (precios[i] < 0) {
                printf("Error: El precio no puede ser negativo.\n");
            } else {
                valid = 1;
            }
        }

        // Ingresar la cantidad del producto (debe ser un número entero)
        valid = 0;
        while (!valid) {
            printf("Ingrese la cantidad del producto %d: ", i + 1);
            fgets(buffer, sizeof(buffer), stdin);
            if (!esNumeroEntero(buffer)) {
                printf("Error: Ingrese un número entero válido para la cantidad.\n");
            } else {
                sscanf(buffer, "%d", &cantidades[i]);  // Convertir a entero después de la validación
                if (cantidades[i] < 0) {
                    printf("Error: La cantidad no puede ser negativa.\n");
                } else {
                    valid = 1;  // Valor válido y entero
                }
            }
        }
    }
}

// Función para calcular el valor total del inventario considerando cantidades
float calcularTotal(float precios[], int cantidades[], int numProductos) {
    float total = 0;
    for (int i = 0; i < numProductos; i++) {
        total += precios[i] * cantidades[i];
    }
    return total;
}

// Función para calcular el promedio de precios ponderado por la cantidad
float calcularPromedio(float precios[], int cantidades[], int numProductos) {
    float total = calcularTotal(precios, cantidades, numProductos);
    int totalCantidades = 0;
    for (int i = 0; i < numProductos; i++) {
        totalCantidades += cantidades[i];
    }
    return total / totalCantidades;
}

// Función para encontrar el índice del producto más caro
int encontrarProductoMasCaro(float precios[], int numProductos) {
    int indiceMax = 0;
    for (int i = 1; i < numProductos; i++) {
        if (precios[i] > precios[indiceMax]) {
            indiceMax = i;
        }
    }
    return indiceMax;
}

// Función para encontrar el índice del producto más barato
int encontrarProductoMasBarato(float precios[], int numProductos) {
    int indiceMin = 0;
    for (int i = 1; i < numProductos; i++) {
        if (precios[i] < precios[indiceMin]) {
            indiceMin = i;
        }
    }
    return indiceMin;
}

// Función para buscar un producto por su nombre
int buscarProducto(char nombres[][50], int numProductos, char producto[]) {
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombres[i], producto) == 0) {
            return i;
        }
    }
    return -1; // Producto no encontrado
}
