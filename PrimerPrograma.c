#include <stdio.h>
#include <stdlib.h>

//1. Diseñe un algoritmo que determine si un número es o no es “Par negativo”
char esParNegativo(int num1)
{
    char result ='F';
    if (num1 %2 == 0 && num1<0)
    {
         result ='V';
        
    }
        return result;
}

//2. Cree una función que diga si la división entre dos números es exacta.
char esExacto(int num1, int num2)
{
    char result = 'F';
    if (num1 % num2 == 0 || num2 % num1 == 0)
    {
        result ='V';
    }
       return result;  
}

//3. Cree una función que diga si un número a es múltiplo de un número b.
char EsMultiplo(int num1, int num2)
{
    char result = 'F';
    if (esExacto(num1,num2)=='V')
    {
    result='V';
    }
}

/*5. Escriba un programa que pida el año actual y un año cualquiera y que escriba cuántos años 
han pasado desde ese año o cuántos años faltan para llegar a ese año */

void Years (int y1, int y2)
{
    if (y1>y2)
    {
        printf("Entre %d y %d han pasado %d años\n",y1, y2, y1-y2);
    }
        else
    {
      printf(" Faltan %d años para llegar al año %d\n", y2-y1, y2);
    } 

}

/*6. Cree función TipoTriangulo(L1,L2,L3), que determine si forman un triángulo es:
        equilátero (si tiene tres lados iguales),
        isósceles (si tiene dos lados iguales)
            escaleno (si tiene tres lados desiguales).*/

void   tipoTriangulo(int L1, int L2, int L3)
{
    if ((L1 == L2)&&(L2==L3))
    {
        printf("Es un triangulo equilatero");
    }
    else
    {
        if ((L1==L2)||(L1==L3)||(L2==L3))
          {
             printf("Es triangulo isosceles");
          }      
            else {
                printf("Es triangulo escaleno");
            }
    }
}

// Main que ejecuta las funciones anteriores

int main()
{
    int a=0,b=0;
    printf("Introduzca un numero: \n"); scanf("%d", &a);
    if (esParNegativo(a)=='V')
       {
         printf("%d Es par negativo\n",a);
       }
        else {
        
            printf("%d No es par negativo\n\n", a);
            }
    printf("Introduce un segundo número\n"); scanf("%d", &b);
    if(esExacto(a,b)=='V')
    {
    printf("%d y %d son multiplos\n", a,b);
    }

    int ano1=0, ano2=0;
    printf("Introduzca dos años:\n"); scanf("%d %d", &ano1, &ano2);
    Years(ano1,ano2);

    int lado1=0,lado2=0,lado3=0;
    printf("Introduzca las 3 medidas del triangulo: \n"); scanf("%d %d %d", &lado1, &lado2, &lado3);
    tipoTriangulo(lado1,lado2,lado3);

}
    
