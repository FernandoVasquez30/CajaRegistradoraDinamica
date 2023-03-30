#ifndef __VENTA_H__ //__VENTA_H__
#define __VENTA_H__

#include "global.h"
#include "productos.h"

struct factura{
	char fecha[11];
	char nomPersona[20];
	struct producto lproductos[100];
	float total;
	struct factura *siguiente;
};

extern struct factura *lista_facturas;

void eliminarBasura();
void registrarVenta();
void listaVentas();

#endif //__FECHA_H__