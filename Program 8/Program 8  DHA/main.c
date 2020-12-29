#include <stdio.h>
#include<math.h>

// Function to compute a^m mod n
// int compute(int a, int m, int n)
// {
// 	int r;
// 	int y = 1;

// 	while (m > 0)
// 	{
// 		r = m % 2;

// 		// fast exponention
// 		if (r == 1)
// 			y = (y*a) % n;
// 		a = a*a % n;

// 		m = m / 2;
// 	}

// 	return y;
// }
long long int compute(long long int a, long long int b,
                                     long long int P)
{ 
    if (b == 1)
        return a;
 
    else
        return (((long long int)pow(a, b)) % P);
}
 
// C program to demonstrate Diffie-Hellman algorithm
int main()
{
	int p ;
	printf("Enter modulus value:");
	scanf("%d",&p);	
		// modulus
	int g ;		// base
	printf("\nEnter Base Value:");
	scanf("%d",&g);

	int a, b;	// a - Alice's Secret Key, b - Bob's Secret Key.
	int A, B;	// A - Alice's Public Key, B - Bob's Public Key

	// choose secret integer for Alice's Pivate Key (only known to Alice)
	// a = 4;		// or use rand()
printf("\nEnter Alice's Secret Key:");
scanf("%d",&a);
	// Calculate Alice's Public Key (Alice will send A to Bob)
	A = compute(g, a, p);

	// choose secret integer for Bob's Pivate Key (only known to Bob)
	// b = 3;		// or use rand()
printf("\nEnter Bob's Secret Key");
scanf("%d",&b);
	// Calculate Bob's Public Key (Bob will send B to Alice)
	B = compute(g, b, p);

	// Alice and Bob Exchanges their Public Key A & B with each other

	// Find Secret key
	int keyA = compute(B, a, p);
	int keyB = compute(A, b, p);

	printf("\nAlice's Secret Key is %d\nBob's Secret Key is %d\n", keyA, keyB);

	return 0;
}
