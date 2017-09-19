// 1103.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

typedef struct vector {

	int a;
	int b;
	int c;

};

void enterVector(vector * pvector) {

	int a = 0; int b = 0; int c = 0;

	printf("\nDie 3 Koordinaten des Vektors eingeben (mit Leeraste getrennt): ");
	scanf_s("%d %d %d", &a, &b, &c);
	
	*pvector = { a,b,c };

}

int calcScalar(vector x, vector y) {

	int scalar = (x.a * y.a) + (x.b * y.b) + (x.c * y.c);

	return scalar;
}

vector calcVector(vector x, vector y) {

	vector product = { (x.b*y.c - x.c*y.b), (x.c*y.a - x.a*y.c), (x.a*y.b - x.b*y.a) };

	return product;
}

vector addVectors(vector x, vector y) {

	vector sum = { (x.a + y.a), (x.b + y.b), (x.c + y.c) };

	return sum;
}

vector subtractVectors(vector x, vector y) {

	vector difference = { (x.a - y.a), (x.b - y.b), (x.c - y.c) };

	return difference;
}

void showMenu() {
	
	// Menu
	printf("\nMENU\n");
	printf("--------------------------\n");
	printf("1. Vektordaten eingeben\n");
	printf("2. Skalarprodukt berechnen\n");
	printf("3. Vektorprodukt berechnen\n");
	printf("4. Vektoren addieren\n");
	printf("5. Vektoren subtrahieren\n");
	printf("6. Vektorkoordinaten zeigen\n");
	printf("9. Dieses Menu zeigen\n");
	printf("0. Ende\n");
}

int main(void)
{
	//Declaration & definition
	
	int wahl = 0;

	bool loop = true;

	vector x; vector y;

	x = y = { 0,0,0 };
	

	vector * px = &x;
	vector * py = &y;

	// start

	showMenu();

	//operations
	while (loop) {
	
			printf("\nDeine Wahl: ");
			scanf_s("%d", &wahl);
	
			switch (wahl) {

			case 1: // enter two three-dimensional vectors
				
				printf("\nVektor x\n");
				printf("--------\n");
				enterVector(px);

				printf("\nVektor y\n");
				printf("--------\n");
				enterVector(py);

				break;

			case 2: // scalar product

				printf("\nDas Skalarprodukt von [%d, %d, %d] und [%d, %d, %d] ist %d.\n", x, y, calcScalar(x, y));

				break;

			case 3: // vector product

				printf("\nDas Vektorprodukt von [%d, %d, %d] und [%d, %d, %d] ist [%d, %d, %d].\n", x, y, calcVector(x, y));

				break;

			case 4: // add vectors

				printf("\nDie Vektorsumme von [%d, %d, %d] und [%d, %d, %d] ist [%d, %d, %d].\n", x, y, addVectors(x, y));

				break;

			case 5: // subtract vectors

				printf("\nDie Vektordifferenz von [%d, %d, %d] und [%d, %d, %d] ist [%d, %d, %d].\n", x, y, subtractVectors(x, y));

				break;

			case 6: // show vectors
				
				printf("\nVektor x: [%d, %d, %d]\n", x);
				
				printf("\nVektor y: [%d, %d, %d]\n", y);

				break;

			case 9: // show menu again

				showMenu();

				break;

			case 0:
				loop = false;
				break;

			default:
				break;

			}

	}
	return 0;
}

