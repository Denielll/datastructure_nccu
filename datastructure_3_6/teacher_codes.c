#include <stdio.h>
#include <math.h>

int Factorial(int n) {
	int ans = 1;
	int mul = 2;

	while (mul <= n) {
		ans = ans * mul;
		mul = mul + 1;
	}

	return ans;
}

int IsPrime(int n) {
	int factor = 2;

	while (factor <= sqrt(n)) {
		/*if n%factor is equal to 0,
		then return 0
		(false, not a prime)*/
		if (n % factor == 0) {
			return 0;
		}
		factor = factor + 1;
	}

	return 1;
}

int NextPrime(int n) {
	for (int i = n + 1; ;i = i + 1) {
		if (IsPrime(i) == 1) {
			return i;
		}
	}
}

double DistToOrig(int x, int y) {
	return sqrt(x*x + y*y);
}

int GetHeight(int r, int x) {
	return sqrt(r*r - x*x);
}

double PI1(int r) {
	double area = 0;

	for (int x = 0; x <= r; x = x + 1) {
		int y = GetHeight(r, x);
		area = area + y;
	}


	return 4.0*area / (r*r);
}

double PI2(int k) {
	double sum = 0;

	for (double i = 1; i <= k; i++) {
		sum = sum + 1.0 / (i*i);
	}

	return sqrt(6.0 * sum);
}

double PI3(int k) {
	double pi = 0;

	for (int i = 1; i <= k; i++) {
		if (i % 2 == 0) {
			pi -= 4.0 / (2.0*(double)i - 1.0);
		}
		else {
			pi += 4.0 / (2.0*(double)i - 1.0);
		}
	}

	return pi;
}

double PI4(int k) {
	double pi = 3;

	for (int i = 1; i <= k; i++) {
		double first = 2.0*(double)i;
		if (i % 2 == 0) {
			pi -= 4.0 / (first*(first + 1)*(first + 2));
		}
		else {
			pi += 4.0 / (first*(first + 1)*(first + 2));
		}
	}

	return pi;
}






int main() {
	for (int i = 1; i <= 10000; i++) {
		printf("Pi = %f %f %f %.20f\n", PI1(i), PI2(i), PI3(i), PI4(i));
	}
	getchar();


	/*int prime = 2;
	for (int i = 1; i <= 100; i = i+1) {
	printf("the %dth prime is %d\n", i, prime);
	prime = NextPrime(prime);
	}
	getchar();*/



	/*int n = 2;

	while (n <= 100) {
	if (IsPrime(n) == 1) {
	printf("%d is a prime number\n", n);
	}
	else {
	printf("%d is NOT a prime number\n", n);
	}
	n = n+1; //n++;
	getchar();
	}*/



	/*int n = 1;

	while (n <= 20) {
	printf("%d! = %d\n", n, Factorial(n));
	n = n + 1;
	}*/

	getchar();
	return 0;
}