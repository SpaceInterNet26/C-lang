#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void Svk();
void Kbl();
int main() {

	double x10 = 0;
	int r;
	double epsilon;
	printf("I. PRADINIAI DUOMENYS\nPradinis desimtainis skaicius: x_10 = ");
	scanf("%lf", &x10);
	printf("Tikslines skaiciavimo sistemos pagrindas: r = ");
	scanf("%d", &r);
	printf("Leistinoji skaiciaus konvertavimo paklaida: epsilon = ");
	scanf("%lf", &epsilon);
	float S = ceil(log((1 / epsilon)) / log(r));
	
	printf("\nII. KONVERTAVIMO REZULTATAI\nReiksminiu skaitmenu po kablelio skaicius atitinkantis uzduota konvertavimo paklaida epsilon = %.0e: s = %g", epsilon, S);
	
	printf("\nKonvertuotas skaicius: x_%d: ", r );
	Svk(x10, r);
	if (x10 != (int)x10) {
		printf(".");
		Kbl(x10, epsilon, r, (int)S);
	}
	return 0;
}


void Svk(double x10,int r) {
	int I[100];
	int D[100];
	I[0] = floor(x10);
	int i = 0;
	while (I[i] > 0) {
		i += 1;
		I[i] = floor(I[i - 1] / r);
		D[i - 1] = I[i - 1] - I[i] * r;
	}
	for (int j = i; j > 0; j--) {
		printf("%d", D[j - 1]);
	}
}

void Kbl(double x10, double epsilon, int r, int s) {
	double f[100];
	int l[100];
	double ne;
	f[0] = modf(x10, &ne);


	for (int i = 0; i < s; i++) {
		double prod = f[i] * r;
		l[i] = (int)floor(prod);       
		f[i + 1] = modf(prod, &ne);   
	}
	for (int j = 0; j < s ; j++) {
		printf("%d", l[j]);
	}
}
