#include <stdio.h>
#include <string.h>

FILE *fd;
int cont = 0;

struct cabecera
{
    char codigo[20];
    char descripcion[100];
    float precio;
    int cant_ingreso;
} head[100];

void menu_registro()
{
    printf("\e[34m\n\n------- MENU DE REGISTRO DE INVENTARIO -------\e[0m\n");
    printf("[1] Crear Producto \n");
    printf("[2] Agregar Productos al Inventario\n");
    printf("[3] Mostrar Productos del Inventario\n");
    printf("[4] Eliminar Producto del inventario\n");
    printf("[5] Salir\n");
}

void crear_producto()
{
    char archivo[] = "/Users/anapaulalopez/Documents/output/programacion/prom.txt";
    int rpt, i, j;
    fd = fopen(archivo, "w");
    if (fd == NULL)
    {
        printf("ERROR al ubicar el archivo!! ");
        return;
    }

    for (j = 0; j < 100; j++)
    {
        fprintf(fd, "-");
    }
    fprintf(fd, "\n");
    fprintf(fd, "INDICE\t\tCODIGO\t\tDESCRIPCION\t\tPRECIO UNITARIO\t\t CANTIDAD\n");
    for (j = 0; j < 100; j++)
    {
        fprintf(fd, "-");
    }
    fprintf(fd, "\n");

    do
    {
    OA:
        fflush(stdin);
        printf("\n\nCodigo: ");
        gets(head[cont].codigo);
        for (i = 0; i < cont; i++)
        {
            if (strcmp(head[i].codigo, head[cont].codigo) == 0)
            {
                printf("\e[1;33mEl codigo ya existe en el inventario. Intente con un codigo diferente.\e[0m\n");
                goto OA;
            }
        }

        printf("\nDescripcion: ");
        gets(head[cont].descripcion);
        do
        {
            printf("\nPrecio Unitario: ");
            scanf("%f", &head[cont].precio);
            if (head[cont].precio <= 0)
            {
                printf("\e[1;31mEl precio no puede ser negativo o menor que cero.\e[0m\n");
                printf("Ingrese nuevamente:\n");
            }
        } while (head[cont].precio <= 0);

        do
        {
            printf("\nCantidad: ");
            scanf("%d", &head[cont].cant_ingreso);
            if (head[cont].cant_ingreso <= 0)
            {
                printf("\e[1;31mLa cantidad no puede ser negativa o menor que cero.\e[0m\n");
                printf("Ingrese nuevamente:\n");
            }
        } while (head[cont].cant_ingreso <= 0);

        fprintf(fd, "%d\t\t%s\t\t%s\t\t\t%.2f\t\t\t%d\n", cont + 1, head[cont].codigo, head[cont].descripcion, head[cont].precio, head[cont].cant_ingreso);
        fprintf(fd, "\n\n");
        cont++;
        printf("Desea ingresar mas productos al inventario: Si(1)-- No(0)-->");
        scanf("%d", &rpt);

    } while (rpt == 1);
    fclose(fd);
}

void agregar_producto()
{
    char archivo[] = "/Users/anapaulalopez/Documents/output/programacion/prom.txt";
    int i, rpt;
    fd = fopen(archivo, "a");
    if (fd == NULL)
    {
        printf("Error al ubicar el archivo !!!\n");
        return;
    }
    printf("\t::::::Agregando Productos:::::\n");
    do
    {
    AE:
        fflush(stdin);
        printf("\n\nCodigo: ");
        gets(head[cont].codigo);

        for (i = 0; i < cont; i++)
        {
            if (strcmp(head[i].codigo, head[cont].codigo) == 0)
            {
                printf("\e[1;33mEl codigo ya existe en el inventario. Intente con un codigo diferente.\e[0m\n");
                goto AE;
            }
        }

        printf("\nDescripcion: ");
        gets(head[cont].descripcion);
        do
        {
            printf("\nPrecio Unitario: ");
            scanf("%f", &head[cont].precio);
            if (head[cont].precio <= 0)
            {
                printf("\e[1;31mEl precio no puede ser negativo o menor que cero.\e[0m\n");
                printf("Ingrese nuevamente:\n");
            }
        } while (head[cont].precio <= 0);

        do
        {
            printf("\nCantidad: ");
            scanf("%d", &head[cont].cant_ingreso);
            if (head[cont].cant_ingreso <= 0)
            {
                printf("\e[1;31mLa cantidad no puede ser negativa o menor que cero.\e[0m\n");
                printf("Ingrese nuevamente:\n");
            }
        } while (head[cont].cant_ingreso <= 0);

        fprintf(fd, "%d\t\t%s\t\t%s\t\t\t%.2f\t\t\t%d\n", cont + 1, head[cont].codigo, head[cont].descripcion, head[cont].precio, head[cont].cant_ingreso);
        fprintf(fd, "\n\n");
        cont++;
        printf("Ingresar mas productos: Si(1) -- No(0) --> ");
        scanf("%d", &rpt);

    } while (rpt == 1);
    fclose(fd);
}

void mostrar_productos()
{
    int c;
    char archivo[] = "/Users/anapaulalopez/Documents/output/programacion/prom.txt";
    fd = fopen(archivo, "r");

    if (fd == NULL)
    {
        printf("\e[1;33mERROR!!, el archivo no existe todavia, para ello primero debe CREAR un producto...!!!\e[0m\n");
        return;
    }
    else
    {
        if (cont == 0)
        {
            printf("\e[1;33mNo tiene inventario para mostrar, recuerde crear un producto primero...\e[0m\n");
            return;
        }
        else
        {
            while ((c = fgetc(fd)) != EOF)
            {
                if (c == '\n')
                {
                    printf("\n");
                }
                else
                {
                    putchar(c);
                }
            }
        }
    }

    fclose(fd);
}

void eliminar_producto()
{
    char archivo[] = "/Users/anapaulalopez/Documents/output/programacion/prom.txt";
    fd = fopen(archivo, "w");
    int i, j, indice_eliminar;

    if (fd == NULL)
    {
        printf("Error al ubicar el archivo!!!\n");
        return;
    }
    else
    {
        if (cont == 0)
        {
            printf("\e[1;33mAun no tiene inventario para eliminar...\e[0m\n");
            return;
        }
        else
        {
            for (j = 0; j < 100; j++)
            {
                printf("-");
            }
            printf("\n");
            printf("INDICE\t\tCODIGO\t\tDESCRIPCION\t\tPRECIO UNITARIO\t\tCANTIDAD\n");
            for (j = 0; j < 100; j++)
            {
                printf("-");
            }
            printf("\n");

            for (i = 0; i < cont; i++)
            {
                printf("%d\t\t%s\t\t%s\t\t\t%.2f\t\t\t%d\n", i + 1, head[i].codigo, head[i].descripcion, head[i].precio, head[i].cant_ingreso);
            }
            printf("\n\n");
        OA:
            printf("Ingrese el indice del producto que desea eliminar: ");
            scanf("%d", &indice_eliminar);

            if (indice_eliminar < 1 || indice_eliminar > cont)
            {
                printf("\e[1;31mProducto con indice '%d' no encontrado en el inventario.\e[0m\n", indice_eliminar);
                goto OA;
            }

            for (i = indice_eliminar - 1; i < cont - 1; i++)
            {
                strcpy(head[i].codigo, head[i + 1].codigo);
                strcpy(head[i].descripcion, head[i + 1].descripcion);
                head[i].precio = head[i + 1].precio;
                head[i].cant_ingreso = head[i + 1].cant_ingreso;
            }
            cont--;

            for (j = 0; j < 100; j++)
            {
                fprintf(fd, "-");
            }
            fprintf(fd, "\n");
            fprintf(fd, "INDICE\t\tCODIGO\t\tDESCRIPCION\t\tPRECIO UNITARIO\t\t CANTIDAD\n");
            for (j = 0; j < 100; j++)
            {
                fprintf(fd, "-");
            }
            fprintf(fd, "\n");

            for (i = 0; i < cont; i++)
            {
                fprintf(fd, "%d\t\t%s\t\t%s\t\t\t%.2f\t\t\t%d\n", i + 1, head[i].codigo, head[i].descripcion, head[i].precio, head[i].cant_ingreso);
                fprintf(fd, "\n\n");
            }

            printf("El producto se ha eliminado correctamente.\n");
        }
    }

    fclose(fd);
}

void cargar_productos()
{
    char archivo[] = "/Users/anapaulalopez/Documents/output/programacion/prom.txt";
    fd = fopen(archivo, "r");
    if (fd == NULL)
    {
        // printf("Todavia no se ha creado un archivo...\n");
        return;
    }
    // Saltar las dos primeras líneas de encabezado y guiones
    fscanf(fd, "%*[^\n]\n");
    fscanf(fd, "%*[^\n]\n");
    fscanf(fd, "%*[^\n]\n");

    // Leer cada producto del archivo
    while (fscanf(fd, "%*d\t\t%s\t\t%s\t\t\t%f\t\t\t%d\n", head[cont].codigo, head[cont].descripcion, &head[cont].precio, &head[cont].cant_ingreso) != EOF)
    {
        cont++;
    }

    fclose(fd);
}
