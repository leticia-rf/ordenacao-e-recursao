#include <stdio.h>
#include <math.h>

double calcularPolinomio (double polinomio[], int grau, double x);
void encontrarRaizes (double a, double b, double polinomio[], double grau, double *raiz1, double *raiz2);

int main () {

    int grau = 0;
	double polinomio[15] = {0};
    double a = 0, b = 0;

    scanf ("%d", &grau);

    for (int i = 0; i <= grau; i++)
        scanf ("%lf", &polinomio[i]);
    
    scanf ("%lf %lf", &a, &b);

	if (a > b) {
		double temp = a;
        a = b;
        b = temp;
	}

	double raiz1, raiz2;

	encontrarRaizes (a, b, polinomio, grau, &raiz1, &raiz2);

	printf ("A raiz encontra-se entre %.15lf e %.15lf.\n", raiz1, raiz2);

    return 0;
}

/*
	exemplo com x^3 - x - 2:
	polinomio[] = { 1, 0, -1, -2 }
	return = -2 + x(-1 + x(0 + x(1)))  ->  x^3 -x - 2
*/
double calcularPolinomio (double polinomio[], int grau, double x) {
    if (grau == 0) return polinomio[0];
    return polinomio[grau] + x * calcularPolinomio(polinomio, grau - 1, x);
}

// metodo da bissecao
void encontrarRaizes (double a, double b, double polinomio[], double grau, double *raiz1, double *raiz2) {

	double c = a + (b - a) / 2;
	double fc = calcularPolinomio (polinomio, grau, c);

	double fa = calcularPolinomio (polinomio, grau, a);
	double fb = calcularPolinomio (polinomio, grau, b);
	
	if ((-(pow(10, -10))) <= fc && fc <= (pow(10, -10))) {
		if (fa * fc < 0) {
			*raiz1 = a;
			*raiz2 = c;
		}
		if (fb * fc < 0) {
			*raiz1 = c;
			*raiz2 = b;
		}
		return;
	}

	// se f(a) * f(c) < 0 (sinais inversos), continuar no intervalo [a, c]
	if (fa * fc < 0) 
		encontrarRaizes (a, c, polinomio, grau, raiz1, raiz2);

	// se f(b) * f(c) < 0 (sinais inversos), continuar no intervalo [c, b]
	if (fb * fc < 0) 
		encontrarRaizes (c, b, polinomio, grau, raiz1, raiz2);

}