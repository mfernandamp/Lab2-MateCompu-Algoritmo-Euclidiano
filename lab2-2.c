//1.- Algoritmo Euclidiano

#include <stdio.h>
#include <time.h> //Librería para medir el tiempo
#include <gmp.h> //Librería para trabajo matemático

void gcd(mpz_t a, mpz_t b);

//arcg: cantidad de parámetros contando el nombre del ejecutable que es el primer parámetro.
//argv[]: Un arreglo que contiene todos los parámetros recibidos.
//Lo hago para recibir los valores desde la consola!!!


main(int argc, char *argv[])
{
	mpz_t a, b;
	clock_t inicio, fin; // Se crea variable 'clock_t' para calcular el tiempo de ejecúción del programa.
	inicio=clock();
	mpz_init_set_str(a,argv[1],10);
	mpz_init_set_str(b,argv[2],10);
	if(mpz_cmp_ui(a, 0)<0 || mpz_cmp_ui(b,0)<0) //Condición para que los valores de n y k sean positivos!
	{	
		printf("Los valores de n y de k deben ser positivos\n");
		return 0;
	}
	if (mpz_cmp(a,b)<0) // Como es un arreglo uno se guarda en la posición 1 y el otro en la 2.Si se ingresan mal los datos, el programa lo acusará y se cerrará.
	{
		printf("El valor de a tiene que ser mayor que el de b.\n"); // Si se ingresan mal los datos, el programa lo acusará y se cerrará.
		return 0;
	}
	if (argc != 3) //Como argc es la cantidad de parámetros, si lee más de 3 estará malo (porque solo necesitamos n y k)
	{
		printf("Para ejecutar use: ./Ejecutar [valor a] [valor b] \n"); // Si se ingresan más de dos argumentos en la terminal, el programa lo acusará y se cerrará.
		return 0;
	}
	else
	{
		
		gcd(a,b); //Se manda los datos ingresados.
	}
	
	fin=clock();
	printf("El tiempo de ejecución fue de: %f \n",(fin-inicio)/(double)CLOCKS_PER_SEC); // %f es porque es un flotante!!!

	return 0; 
}

void gcd(mpz_t a, mpz_t b)
{
	mpz_t resta;
	mpz_init(resta);
	int vueltas=0;
	 while(mpz_sgn(b) != 0)  //Si b es distinto de 0, se ejecuta el ciclo while.
    {
        mpz_mod(resta, a, b);   //Se le asigna a la variable resta, el modulo entre a y b.
        mpz_set(a, b);  //Se le asigna a la variable a, el valor de la variable b.
        vueltas = vueltas +1;
        mpz_set(b, resta);  //Se le asigna a b, el valor de la variable resto.
        vueltas = vueltas + 1; //Cantidad de veces que se cambian los valores de a y b.
    }
    gmp_printf("\nEl gcd es: %Zd \n", a);   //Se muestra por consola el valor del maximo comun divisor entre a y b.
    printf("\nEl numero de veces que 'a' y/o 'b' fueron cambiados es: %d\n\n", vueltas);    //Se muestra por consola la cantidad de veces en que a y/o b fueron cambiados.mpz_sub(resto, a, b);   //Se le asigna a la variabl....e resto la resta entre a y b.
  	mpz_clear(a);   //Se borra lo almacenado en la variable a.
    mpz_clear(b);   //Se borra lo almacenado en la variable b.
    mpz_clear(resta);   //Se borra lo almacenado en la variable resto.
}