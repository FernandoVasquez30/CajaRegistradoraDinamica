#include "productos.h"

struct producto *lista_productos = NULL;

void crearProducto(){
	LIMPIAR
	
	char nombre[20];
	float precio;
	struct producto *nuevo_producto = malloc(sizeof(struct producto));
	
	fflush(stdin);
	printf("Ingrese el nombre del producto:");
	gets(nombre);
	if (strcmp(nombre,"") == 0){
        printf("No debe estar vacio\n");
        PAUSE
        LIMPIAR
        return;
    }

	struct producto *actual = lista_productos;
	
	int id = 1;
	while(actual != NULL){
		id++;
		if (strcmp(actual->nombre,nombre)==0){
			printf("el producto ya existe\n");
			PAUSE
            LIMPIAR
            return;
		}
		actual = actual->siguiente;
	}
	
	nuevo_producto->id = id;
	strcpy(nuevo_producto->nombre,nombre);
	printf("ingresa el precio del producto:");
	scanf("%f",&precio);
	if(precio == 0){
		printf("El 0 no es valido.\n");
		PAUSE
		LIMPIAR
		return;
	}else if(precio < 0){
		printf("Ingresastes un negativo, vuelve a intentarlo\n");
		PAUSE
		LIMPIAR
		return;
	}

	nuevo_producto->precio = precio;
	printf("ingresa la cantidad: ");
	scanf("%d",&nuevo_producto->cantidad);
	if(nuevo_producto->cantidad == 0){
        printf("El 0 no es valido.\n");
		PAUSE
		LIMPIAR
		return;
	}else if(nuevo_producto->cantidad < 0){
        printf("Ingresastes un negativo, vuelve a intentarlo\n");
		PAUSE
		LIMPIAR
		return;
	}

	nuevo_producto->siguiente = lista_productos;
	lista_productos = nuevo_producto;
	LIMPIAR
	return;
}

void eliminarProducto(){
    struct producto *actual = lista_productos;
    struct producto *anterior = NULL;

    while (actual != NULL && actual->cantidad != 0 && actual->cantidad > 0) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual != NULL) {
        if (anterior == NULL) {
            lista_productos = actual->siguiente;
        } else {
            anterior->siguiente = actual->siguiente;
        }
            free(actual);
        }
}

void listaProducto(){
		int i = 1;
		if (lista_productos != NULL){
			i = 0;

			eliminarProducto();
			struct producto *actual = lista_productos;
			while (actual != NULL){
			printf("%d - %s - $%.f - %d\n", actual->id, actual->nombre, actual->precio, actual->cantidad);
			actual = actual->siguiente;
			}
		}
		if (i == 1){
			LIMPIAR
			printf("No hay productos en el inventario...\n");
		}
	getch();
    LIMPIAR
    return;
}
