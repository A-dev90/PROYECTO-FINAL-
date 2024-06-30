#include <stdio.h>
#include <string.h>
#include "opciones_menu.h"

int main()
{
    cargar_productos(); 
    int opcion;
    do
    {
        menu_registro();
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            crear_producto();
            break;
        case 2:
            agregar_producto();
            break;
        case 3:
            mostrar_productos();
            break;
        case 4:
            eliminar_producto();
            break;
        case 5:
            printf("\e[32mSaliendo del programa...\e[0m");

            break;
        default:
            printf("\e[1;31mOpcion no valida. Intente de nuevo.\e[0m\n");
            break;
        }
    } while (opcion != 5);

    return 0;
}
