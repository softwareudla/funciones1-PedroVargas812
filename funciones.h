#ifndef FUNCIONES_H
#define FUNCIONES_H

void ingresarDatos(char nombres[][50], float precios[], int cantidades[], int numProductos);
float calcularTotal(float precios[], int cantidades[], int numProductos);
float calcularPromedio(float precios[], int cantidades[], int numProductos);
int encontrarProductoMasCaro(float precios[], int numProductos);
int encontrarProductoMasBarato(float precios[], int numProductos);
int buscarProducto(char nombres[][50], int numProductos, char producto[]);

#endif
