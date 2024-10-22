#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTOS 10

int main() {
    char nombres[MAX_PRODUCTOS][50];
    float precios[MAX_PRODUCTOS];
    int cantidades[MAX_PRODUCTOS];
    int numProductos;
    char buffer[100];  // Para leer entradas usando fgets

    // Solicitar y validar el número de productos
    do {
        printf("Ingrese el numero de productos (maximo %d): ", MAX_PRODUCTOS);
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &numProductos);

        if (numProductos > MAX_PRODUCTOS || numProductos <= 0) {
            printf("Error: Numero invalido de productos. Debe ser entre 1 y %d.\n", MAX_PRODUCTOS);
        }
    } while (numProductos > MAX_PRODUCTOS || numProductos <= 0);

    // Ingresar datos de los productos
    ingresarDatos(nombres, precios, cantidades, numProductos);

    // Mostrar los datos de los productos en formato de tabla
    printf("\nLista de productos:\n");
    printf("%-20s %-10s %-10s\n", "Producto", "Precio", "Cantidad");
    for (int i = 0; i < numProductos; i++) {
        printf("%-20s %-10.2f %-10d\n", nombres[i], precios[i], cantidades[i]);
    }

    // Calcular y mostrar el valor total del inventario
    float total = calcularTotal(precios, cantidades, numProductos);
    printf("\nEl valor total del inventario es: %.2f\n", total);

    // Calcular y mostrar el precio promedio ponderado por cantidad
    float promedio = calcularPromedio(precios, cantidades, numProductos);
    printf("El precio promedio ponderado de los productos es: %.2f\n", promedio);

    // Encontrar y mostrar el producto más caro
    int indiceCaro = encontrarProductoMasCaro(precios, numProductos);
    printf("El producto mas caro es %s con un precio de %.2f\n", nombres[indiceCaro], precios[indiceCaro]);

    // Encontrar y mostrar el producto más barato
    int indiceBarato = encontrarProductoMasBarato(precios, numProductos);
    printf("El producto mas barato es %s con un precio de %.2f\n", nombres[indiceBarato], precios[indiceBarato]);

    // Buscar un producto por su nombre
    char productoBuscado[50];
    char buscarOtra;

    do {
        printf("\nIngrese el nombre del producto a buscar: ");
        fgets(productoBuscado, sizeof(productoBuscado), stdin);
        productoBuscado[strcspn(productoBuscado, "\n")] = '\0';  // Eliminar el salto de línea residual

        int indiceBuscado = buscarProducto(nombres, numProductos, productoBuscado);

        if (indiceBuscado != -1) {
            printf("El precio del producto %s es %.2f\n", productoBuscado, precios[indiceBuscado]);
        } else {
            printf("Producto no encontrado.\n");
        }

        // Preguntar si desea buscar otro producto
        printf("\n¿Desea buscar otro producto? (s/n): ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, " %c", &buscarOtra);

    } while (buscarOtra == 's' || buscarOtra == 'S');

    return 0;
}
