#ifndef ANALYZE_H
#define ANALYZE_H
#include<stdbool.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE_START 512
#define ITERATIONS 4
#define ZERO 0
#define FIVE 5
#define BILLION 1e-9

// algorithm_t defines different algorithms
typedef enum {
	bubble_sort_t,
	insertion_sort_t,
	quick_sort_t,
	linear_search_t,
	binary_search_t
} algorithm_t;

// case_t defines different cases
typedef enum {
	best_t,
	worst_t,
	average_t,
} case_t;

// result_t defines a timed measurement for a given array size
typedef struct {
	int size;
	double time;
} result_t;

// benchmark benchmarks an algorithm a for a specific case c, writing n results
// to the result buffer buf
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n);

//definierar pointer till sorteringsfunktionerna
//kan behöva ändras(nästan kopia)
typedef bool(*SeP)(const int*, int, int);

//definierar pointer till sökfunktionerna
//kan behöva ändras (nästan kopia)
typedef void(*SP)(int *, int);

//skapar en array x av längden y på best case
void b_case(int *x, int y, int z, const algorithm_t alg);
 
//skapar en array x av längden y på en average case
void w_case(int *x, int y, int z, const algorithm_t alg);

//skapar en array x av längden y på en average case
void a_case(int *x, int y, int z, const algorithm_t alg);

double get_time_search(SeP f, int* a, int size, int v,int n);
#endif

double get_time_sort(SP FP, int* a, int size,int n);

 
