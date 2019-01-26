#include <stdio.h>

#define N 1000

int main() {
	// Without mem_barrier
	int i = 0;
	int a[N];
	for (; i<N; i++)
		a[i]++;

	// With mem_barrier
	i=0;
	for (; i<N; i++) {
		asm (""::"m" (i));
		a[i]++;
	}
}
