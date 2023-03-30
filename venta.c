#include "venta.h"
#include "fecha.h"

struct factura *lista_facturas = NULL;

void eliminarBasura()
{
    struct factura *actual = lista_facturas;
    struct factura *anterior = NULL;

    while (actual != NULL && actual->lproductos->precio != 0 && actual->lproductos->precio > 0)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual != NULL){
        if (anterior == NULL){
            lista_facturas = actual->siguiente;
        }else{
            anterior->siguiente = actual->siguiente;
        }
        free(actual);
    }
}

void registrarVenta()
{
    int i = 1;
    if (lista_productos != NULL){

        i = 0;
        char fechaH[11];
        char nombre[22];
        int cantidad;
        int codigo;
        char respuesta;
        int cont = 0;
        int existe = 0;

        struct factura *nueva_factura = malloc(sizeof(struct factura));
        
        fecha(fechaH);
        strcpy(nueva_factura->fecha, fechaH);

        fflush(stdin);
        printf("Ingrese su nombre:");
        gets(nueva_factura->nomPersona);
        if (strcmp(nueva_factura->nomPersona, "") == 0)
        {
            printf("No debe estar vacio\n");
            PAUSE
            LIMPIAR
            return;
        }

        nueva_factura->total = 0;

        do{
            do{
                int operacion = 0;

                printf("---PRODUCTOS DISPONIBLES---\n");
                listaProducto();

                printf("Ingrese el ID del producto:");
                scanf("%d", &codigo);

                struct producto *actual = lista_productos;

                while (actual != NULL)
                {
                    if (actual->id == codigo && codigo != 0)
                    {
                        printf("%s - $%.f - %d\n", actual->nombre, actual->precio, actual->cantidad);
                        printf("Ingresa la cantidad a llevar:");
                        scanf("%d", &cantidad);
                        while (cantidad > actual->cantidad)
                        {
                            printf("Cantidad insuficiente, hay disponible %d de %s.\n\n", actual->cantidad, actual->nombre);
                            printf("Ingresa la cantidad que quieres comprar:");
                            scanf("%d", cantidad);
                        }
                        actual->cantidad = actual->cantidad - cantidad;

                        strcpy(nueva_factura->lproductos[cont].nombre, actual->nombre);
                        nueva_factura->lproductos[cont].id = actual->id;
                        nueva_factura->lproductos[cont].precio = actual->precio;
                        nueva_factura->lproductos[cont].cantidad = cantidad;
                        operacion = actual->precio * cantidad;
                        nueva_factura->total = nueva_factura->total + operacion;
                        existe = 1;
                    }
                    actual = actual->siguiente;
                }
                if (existe == 0)
                {
                    existe = 3;
                }
            } while (nueva_factura->total == 0);

            fflush(stdin);
            printf("quieres comprar otro producto? [s/n]: ");
            cont++;
            scanf("%c", &respuesta);
        } while (respuesta == 'S' || respuesta == 's');

        nueva_factura->siguiente = lista_facturas;
        lista_facturas = nueva_factura;
    }
    if (i == 1)
    {
        LIMPIAR
        printf("No hay Productos a la venta...\n");
    }
    PAUSE
    LIMPIAR
    return;
}

void listaVentas()
{
        int i = 1;
        if (lista_facturas != NULL)
        {
            i = 0;
            eliminarBasura();
            LIMPIAR
            int cont = 0;
            struct factura *actual = lista_facturas;
            while (actual != NULL)
            {
            int x = 0;
            cont++;
            printf("Venta # %d - Cliente: %s - Fecha: %s\n", cont, actual->nomPersona, actual->fecha);
            do
            {
                printf("\tProducto #%d: %s, Cantidad: %d, Precio Unitario: %.f\n", actual->lproductos[x].id, actual->lproductos[x].nombre, actual->lproductos[x].cantidad, actual->lproductos[x].precio);
                x++;
            } while (strlen(actual->lproductos[x].nombre) != 0);
            printf("\t-----------------------------");
            printf("\n\tPrecio Total A Pagar: %.f\n", actual->total);
            printf("\t-----------------------------\n");
            actual = actual->siguiente;
            }
        }
        if (i == 1)
        {
            LIMPIAR
            printf("No hay ninguna venta...");
        }
        getch();
        LIMPIAR
        return;
}