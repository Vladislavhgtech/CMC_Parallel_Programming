#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


static inline double f(unsigned long long int index) {

	return pow(index, 3) / (pow(index, 5) + sin(pow(2, index)));
}

double sum(unsigned long long int N) {
	double SUM = 0;
#pragma loop count min(16)
	for (unsigned long long int n = 1; n <= N; ++n) {
		SUM += f(n);
	}
	return SUM;
}

int main(int argc, char* argv[]) {
	unsigned long long int N = argc > 1 ? atol(argv[1]) : 1000;

	printf("sum %lld = ", N);
	clock_t time = clock();
	double SUM;
	SUM = sum(N);
	printf("%lf\n", SUM);
	time = clock() - time;
	printf("evaluation time: %lf\n", (double)time / CLOCKS_PER_SEC);
	return 0;
}