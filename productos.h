#ifndef __PRODUCTO_H__ //__PRODUCTO_H__
#define __PRODUCTO_H__
#include "global.h"

struct producto{
	int id;
	char nombre[20];
	float precio;
	int cantidad;
	struct producto *siguiente;
};

extern struct producto *lista_productos;

void crearProducto();
void eliminarProducto();
void listaProducto();

#endif //__PRODUCTO_H__