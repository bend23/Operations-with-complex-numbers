#include <stdio.h>
#include <stdlib.h>
#define max_Lenght 15000

/* 
In the following code it's defined a data structure which is memorizing complex numbers.
Every complex number as in mathematics has a real part and an imaginary part. 

This code solves different types of mathematical problems with complex numbers. 
I defined some functions which are solving operations like:
printing on the terminal, adding together (+), extraction (-), multiplication (*) 

The final outcome it's saved in the same way in the data structure. 
 */

typedef struct
{
    int real;
    int imaginar;

}Complex_Number;

//FNCT TO GET DATA FROM THE KEYBOARD, MEMORY INITIALIZED DYNAMICALLY USING POINTERS
Complex_Number *read_NrComplex(int *n)
{
    Complex_Number *a = (Complex_Number *)malloc(sizeof(Complex_Number) * max_Lenght);

    printf("With how many complex numbers do you want to work:\n");
    scanf(" %d", n);

    for(int i = 0; i < *n; i++)
    {
        printf("Introduce the real part of the %d complex number:\n", i+1);
        scanf(" %d", &a[i].real);

        printf("Introduce the imaginary part of the %d complex number:\n", i+1);
        scanf(" %d", &a[i].imaginar);
    }
    return a;
}

//FUNCT FOR PRINTING
int print_NrComplex(Complex_Number *a, int n)
{
    printf("The given complex numbers are:\n");
    printf("\n");

    for(int i = 0; i < n; i++)
    {
        printf("The real part of the %d complex number is: %d\n", i+1, a[i].real);
        printf("The imaginary part of the %d complex number is: %d\n", i+1 ,a[i].imaginar);
    }

    printf("\n");
}

// (+)
Complex_Number sum_Comp(Complex_Number *a, int n)
{
    Complex_Number sum;

    sum.real = 0; sum.imaginar = 0;
    for(int i = 0; i < n; i++)
    {
        sum.real += a[i].real;
        sum.imaginar += a[i].imaginar;
    }
    return sum;
}

// (-)
Complex_Number extract_Comp(Complex_Number *a, int n)
{
    Complex_Number extract;
    extract.real = a[0].real; extract.imaginar = a[0].imaginar;

    for(int i = 1; i < n; i++){
        extract.real -= a[i].real;
        extract.imaginar -= a[i].imaginar;
    }
    return extract;
}

// (*)
Complex_Number produs2(Complex_Number x, Complex_Number y)
{
    Complex_Number produs;
    produs.real = x.real*y.real - x.imaginar*y.imaginar;
    produs.imaginar = x.real*y.imaginar + x.imaginar*y.real;

    return produs;
}

Complex_Number produs_comp(Complex_Number *a, int n)
{
    Complex_Number produs = produs2(a[0], a[1]);
    for(int i = 2; i < n; i++)
    {
        produs = produs2(produs, a[i]);
    }
    return produs;
}

int main()
{
    int n;

    //COLLECTING DATA FROM THE KEYBOARD
    Complex_Number *a = read_NrComplex(&n);
    printf("n: %d \n", n);
    print_NrComplex(a,n);

    //PRINTING THE NUMBERS
    Complex_Number sum = sum_Comp(a, n);
    if(sum.imaginar < 0)
    {
        printf("The sum of the numbers is: %d %di \n", sum.real, sum.imaginar);
    } else printf("The sum of the numbers is: %d + %di \n", sum.real, sum.imaginar);

    //EXTRACTION
    Complex_Number scad = extract_Comp(a, n);
    if(scad.imaginar < 0)
    {
        printf("The difference of the numbers is: %d %di \n", scad.real, scad.imaginar);
    } else printf("The difference of the numbers is: %d + %di \n", scad.real, scad.imaginar);

    //PRODUCT
    Complex_Number produs = produs_comp(a, n);
    if(produs.imaginar < 0)
    {
        printf("The product of the numbers is: %d %di \n", produs.real, produs.imaginar);
    } else printf("The product of the numbers is: %d + %di \n", produs.real, produs.imaginar);

    free(a);

    return 0;
}
