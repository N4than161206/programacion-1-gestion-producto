#include <stdio.h>

int main (int argc, char *argv[]) {

    char ID[10], nombre[20];

    int stock, numVenta, numReabastecer;

    float precio, total, ganancia = 0;

    int opc;

    do{

        printf("\nSeleccione una opcion:\n");

        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Consultar producto\n");
        printf("5. Mostrar ganancias\n");
        printf("6. Salir\n");

        printf(">> ");
        scanf("%d",&opc);

        switch (opc)
        {

        case 1:

            printf("\nIngrese los datos del producto:\n");

            printf("ID: ");
            scanf("%s",ID);

            printf("Nombre: ");
            scanf("%s",nombre);

            printf("Stock: ");
            scanf("%d",&stock);

            printf("Precio: ");
            scanf("%f",&precio);

            printf("Producto registrado\n");

            break;


        case 2:

            printf("Ingrese la cantidad de producto a vender: ");
            scanf("%d",&numVenta);

            if(numVenta <= 0){
                printf("Error: la cantidad debe ser mayor que 0\n");
                break;
            }

            if(numVenta > stock){
                printf("Error: no se puede realizar la venta, no existe suficiente stock\n");
                break;
            }

            total = numVenta * precio;

            stock -= numVenta;

            ganancia += total;

            printf("El total de la venta es: %.2f\n",total);
            printf("El nuevo stock es: %d\n",stock);

            break;


        case 3:

            printf("Ingrese la cantidad de producto a reabastecer: ");
            scanf("%d",&numReabastecer);

            if(numReabastecer <= 0){
                printf("Error: la cantidad debe ser mayor que 0\n");
                break;
            }

            stock += numReabastecer;

            printf("El nuevo stock es: %d\n",stock);

            break;


        case 4:

            printf("\nID \t\t Nombre \t\t Stock \t\t Precio\n");

            printf("%s \t\t %s \t\t %d \t\t %.2f\n",
                   ID,nombre,stock,precio);

            break;


        case 5:

            printf("Total ganancias: %.2f\n",ganancia);

            break;


        case 6:

            printf("Programa finalizado.\n");

            break;


        default:

            printf("No existe la opcion\n");

            break;
        }

    }while(opc != 6);

    return 0;
}
