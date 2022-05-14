#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// functie ca sa verifice daca este prim sau nu
int prim(int n)
{
	// Corner cases
	if (n <= 1)
		return 0;
	if (n <= 3)
		return 1;

	// aceasta verificare este ca sa trecem direct la 5 in bucla
	if (n % 2 == 0 || n % 3 == 0)
		return 0;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return 0;

	return 1;
}

//functia care verifica daca numarul este prim circular sau nu
int primCircular(int n)
{
	// numara cifrele numarului
	int cnt = 0;
	int	a = n;
	int div;//numarul fara o cifra
	int rem;//cifra pe care vrem sa o adaugam la "div" ca sa circulam numarul

	while (a) {
		cnt++;
		a /= 10;
	}

	int num = n;
	while (prim(num)) {

		// generam urmatoarea permutare a cifrelor numarului
		// mutam ultima cifra pe prima pozitie
		rem = num % 10;
		div = num / 10;
		num = (pow(10, cnt - 1)) * rem + div;

		// daca se parcurg toate permutarile si la final reiese acelasi numar 
		// cu care am intrat iesim din bucla
		if (num == n)
			return 1;
	}

	return 0;
}

int main()
{
	int n;
	int j;
	int i;//parcurge fiecare numar de la 2 pana la n
	j = 0;//numara cate numere prime circulare avem pana la n
	FILE* f;
	FILE* g;
	f = fopen("prm.in", "rt");
	g = fopen("prm.out", "wt");

	fscanf(f, "%d", &n);

	for (i = 2; i < n; i++)
	{
		if (primCircular(i))
			j++;
	}

	fprintf(g, "%d", j);//afisarea

	fclose(f);
	fclose(g);

	return 0;
}