#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Validador del numero*/
int contar_digitos(int num) {
    int count = 0;
    while(num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

//Definición del tipo de datos adecuado. 
typedef int Numero[16];

/*Función que cree un número según descripción (el usuario ingresa valor). */

void numentero (int num, Numero Numerogen)    
{

    int count;
    for (count = 0; count <= 15; count++)
    {
           Numerogen[count] = num %10;
         num/=10;
    }
        
}

/*Función que despliegue un número (según lo descrito, debe desplegar 5847 si el arreglo contiene {7, 4, 8, 5}) */

void printnumero(Numero Numerogen)
{
        int count;
        int suma = 0;
        for (count=0; count <=15 ; count ++)
        {
            int potencia = pow(10, count);
            suma = suma + Numerogen[count] * potencia;
            
        }
            printf(" El número del arreglo es: %d", suma);
}
 
/*Función que genere un nuevo número como resultado de sumar otros dos (debe usar representación dada).*/ 

void sumanumero(int num1, int num2, Numero Arrsuma)
{
    int i;
    Numero Arrnum1;
    Numero Arrnum2;
    numentero (num1, Arrnum1);
   numentero (num2, Arrnum2);
   
   for (i = 0; i <=15; i++)
   {
    Arrsuma[i] = Arrnum1[i] + Arrnum2[i];
    if (Arrsuma[i] >=10)
    {
        Arrsuma[i] = Arrsuma[i] %10;
        Arrsuma[i+1]= Arrsuma[i+1] + Arrsuma[i] /10; 
    }
    
   }
   printf("El resultado es: "); printnumero(Arrsuma);
}
/* Función que genere un nuevo número como resultado de multiplicar otro por un dígito decimal (iden). */

void multiplinumero(int num, int num2, Numero Arr) {
    numentero(num, Arr);
    int reserva = 0;
    int i;
    for (i = 15; i >= 0; i--) {
        int prod = Arr[i] * num2 + reserva;
        Arr[i] = prod % 10;
        reserva = prod / 10;
    }
    while (reserva != 0) {
        int temp = reserva % 10;
        reserva /= 10;
        Arr[--i] = temp;
    }
     printf("El resultado es: "); printnumero(Arr);
}
int main ()
{
    Numero Creado;
    int numcrear;
    int numsum1;
    int numsum2;
    Numero Arreglosumado;
    int num_mul1;
    int num_mul2;
    Numero Arreglomultiplicado;
    int opcion;

    printf("Hola, bienvenido, que función desea realizar: \n"); 
    
        while (opcion != 5)
    {
        printf("Ingrese una opción: \n");
            printf("1. Crear Arreglo: \n");
            printf("2. Imprimir Arreglo: \n");
            printf("3. Sumar Arreglos: \n");
            printf("4. Multiplicar Arreglo: \n");
            printf("5. Salir: \n");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                printf("Ingrese un número entero no negativo: \n");
                scanf("%d", &numcrear);
                if (numcrear < 0 || contar_digitos(numcrear) > 16)
                {
                    printf("Favor ingrese un número válido \n");
                }
                else
                {
                    numentero(numcrear, Creado);
                    printf("Arreglo creado exitosamente: \n");
                }
                break;

            case 2:
                if (numcrear < 0)
                {
                    printf("Favor ingrese un número para ingresarlo al arreglo:\n");
                }
                else
                {
                    printnumero(Creado);
                    printf("\n");
                }
                break;

            case 3:
                printf("Ingrese dos números por favor: ");
                scanf("%d %d", &numsum1, &numsum2);
                if (numsum1 < 0 || contar_digitos(numsum1) > 16 || numsum2 < 0 || contar_digitos(numsum2) > 16)
                {
                    printf("Ingrese 2 números válidos: \n");
                }
                else
                {
                    sumanumero(numsum1, numsum2, Arreglosumado);
                    printf("\n");
                }
                break;

            case 4:
                printf("Ingrese un número: \n");
                scanf("%d", &num_mul1);
                if (num_mul1 < 0 || contar_digitos(num_mul1) > 16)
                {
                    printf("Favor ingrese un número válido: \n");
                }
                else
                {
                    printf("Ingrese un número decimal: \n");
                    scanf("%d", &num_mul2);
                    if (num_mul2 < 0 || num_mul2 > 9)
                    {
                        printf("Ingrese un número decimal válido\n");
                    }
                    else
                    {
                        multiplinumero(num_mul1, num_mul2, Arreglomultiplicado);
                        printf("\n");
                    }
                }
                break;

            case 5:
                printf("Adiós!\n");
                break;

            default:
                printf("Opción inválida. Intente nuevamente.\n");
                break;
        }
    }
    return 0;
}
