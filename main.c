/*
    ATP 2 - PROJETO 1 - Polinômios

    Desenvolvido por:
        Kayke G. Vertu
*/
#include "poly.h"
#include <stdio.h>

int main() {
    char in1[93], in2[93];

    printf("Digite os nomes dos arquivos de entrada: ");
    scanf(" %93s %93s", in1, in2);

    // Entradas
    poly p, q, plinha, qlinha;
    p = readfile_poly(in1);
    q = readfile_poly(in2);

    // Derivação
    plinha = derivate_poly(p);
    qlinha = derivate_poly(q);

    printf("Polinômio P:\n");
    print_poly(p);
    printf("Polinômio P':\n");
    print_poly(plinha);
    
    printf("Polinômio Q:\n");
    print_poly(q);
    printf("Polinômio Q':\n");
    print_poly(qlinha);

    // Soma, subtração e produto
    poly soma, subtr, prod;
    soma = add_poly(p, q);
    subtr = subtr_poly(p, q);
    prod = prod_poly(p, q);

    printf("P + Q:\n");
    print_poly(soma);

    printf("P - Q:\n");
    print_poly(subtr);

    printf("P * Q:\n");
    print_poly(prod);

    // Liberando espaço na memória, esses polinômios não são utilizados no resto do código
    free_poly(&plinha);
    free_poly(&qlinha);
    free_poly(&soma);
    free_poly(&subtr);
    free_poly(&prod);

    // Integral definida
    double a, b, defp, defq;
    printf("Defina os limites da integral definida: ");
    scanf(" %lf %lf", &a, &b);

    defp = integrate_poly_def(p, a, b);
    defq = integrate_poly_def(q, a, b);

    printf("A integral definida de P é %lf.\n", defp);
    printf("A integral definida de Q é %lf.\n", defq);

    // Método de Newton-Raphson
    int it;
    double tol, init;

    printf("\nNewton-Raphson:\nDefina o valor de inicialização: ");
    scanf(" %lf", &init);

    do {
        printf("Defina a tolerância: ");
        scanf(" %lf", &tol);
        
        if (tol < 0) printf("Entrada inválida, tente novamente.\n");
    } while (tol < 0);

    do {
        printf("Defina o número de iterações: ");
        scanf(" %d", &it);
        
        if (it < 0) printf("Entrada inválida, tente novamente.\n");
    } while (it < 0);

    double nwtp = newton_poly(p, init, it, tol);
    double nwtq = newton_poly(q, init, it, tol);
    printf("Aplicando o método de Newton-Raphson, temos que:\n%lf é uma raiz de P.\n%lf é uma raiz de Q.\n", nwtp, nwtq);

    // Liberando espaço na memória
    free_poly(&p);
    free_poly(&q);

    return 0;
}