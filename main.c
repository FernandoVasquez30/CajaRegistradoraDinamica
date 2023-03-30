#include "global.h"
#include "productos.h"
#include "venta.h"
#include "fecha.h"

void inventario()
{
	LIMPIAR
	int op;
	do
	{
		printf("1. Crear Producto\n");
		printf("2. Lista de Productos\n");
		printf("3. Regresar\n");
		printf("Ingresa su opcion: ");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			LIMPIAR
			crearProducto();
			break;

		case 2:
			LIMPIAR
			listaProducto();
			break;

		case 3:
			LIMPIAR
			break;
		}
	} while (op != 3);
}

int main()
{
	int op;
	LIMPIAR

	do{

		printf("1. Registrar Venta\n");
		printf("2. Inventario\n");
		printf("3. Lista de ventas\n");
		printf("4. salir\n");
		printf("Ingresa su opcion: ");
		scanf("%d", &op);

		switch (op){
		case 1:
			LIMPIAR
			registrarVenta();
			break;

		case 2:
			LIMPIAR
			inventario();
			break;

		case 3:
			LIMPIAR
			listaVentas();
			break;

		default:
			LIMPIAR
			break;
		}
	} while (op != 4);
	return 0;
}