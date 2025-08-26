#include "analyze.h"
#include "algorithm.h"


double get_time_search(SeP f, int*x, int size, int y,int z){
double total_time=0;
int i=0;
while(i<z){
struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC,&start);
    (*f)(x,size,y);
    clock_gettime(CLOCK_MONOTONIC, &end);
double nanosec= ((end.tv_nsec-start.tv_nsec)*BILLION);
double sec2 =end.tv_sec-start.tv_sec;
double time= nanosec+sec2;
total_time = total_time+time;
i++;
}
  return total_time/z;
}

double get_time_sort(SP FP, int*x, int size, int y)
{
  double total_time=0;
  int i=0;
 while(i<y){
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    (*FP)(x,size);
    clock_gettime(CLOCK_MONOTONIC, &end);
double nanosec = ((end.tv_nsec-start.tv_nsec)*BILLION);
double sec2 = end.tv_sec-start.tv_sec;
double time= nanosec+sec2;
total_time = total_time + time;
i++;
  }
  return total_time/y;
}

//bubble sort
double BubbleSort_WC(SP fp , int * array, int SIZE, int n, const algorithm_t algo)
{
    w_case(array, SIZE, ZERO, algo);
    return get_time_sort(*fp, array, SIZE,n);    
}

double BubbleSort_BC(SP fp , int * array, int SIZE, int n, const algorithm_t algo)
{
    b_case(array, SIZE, ZERO, algo);
    return get_time_sort(*fp, array, SIZE,n);    
}

double BubbleSort_AC(SP fp , int * array, int SIZE, int n, const algorithm_t algo)
{
    a_case(array, SIZE, ZERO, algo);
    return get_time_sort(*fp, array, SIZE,n);   
 
}

//insertion sort
double insertion_sort_WC(SP fp , int * array, int SIZE, int n, const algorithm_t algo)
{
    w_case(array, SIZE, ZERO, algo);
    return get_time_sort(*fp, array, SIZE,n);    
}
double insertion_sort_BC(SP fp , int * array, int SIZE, int n, const algorithm_t algo)
{
    b_case(array, SIZE, ZERO, algo);
    return get_time_sort(*fp, array, SIZE,n);    
}
double insertion_sort_AC(SP fp , int * array, int SIZE, int n, const algorithm_t algo)
{
    a_case(array, SIZE, ZERO, algo);
    return get_time_sort(*fp, array, SIZE,n);    
}

// quick sort
double quick_sort_WC(SP fp , int * array, int SIZE, int n, const algorithm_t algo)
{
    w_case(array, SIZE, ZERO, algo);
    return get_time_sort(*fp, array, SIZE,n);    
}
double quick_sort_BC(SP fp , int * array, int SIZE, int n, const algorithm_t algo)
{
    b_case(array, SIZE, ZERO, algo);
    return get_time_sort(*fp, array, SIZE,n);    
}
double quick_sort_AC(SP fp , int * array, int SIZE, int n, const algorithm_t algo)
{
    a_case(array, SIZE, ZERO, algo);
    return get_time_sort(*fp, array, SIZE,n);    
}

//linear search
double linear_search_WC(SeP fp , int * array, int SIZE, int k, int n,const algorithm_t algo)
{
    w_case(array, SIZE, k, algo);
    return get_time_search(*fp, array, SIZE,k,n);    
}

double linear_search_AC(SeP fp , int * array, int SIZE, int k, int n,const algorithm_t algo)
{
    a_case(array, SIZE, k, algo);
    return get_time_search(*fp, array, SIZE,k,n);      
}
double linear_search_BC(SeP fp , int * array, int SIZE, int k, int n,const algorithm_t algo)
{
    b_case(array, SIZE, k, algo);
    return get_time_search(*fp, array, SIZE,k,n);    
}

//binary search
double binary_search_BC(SeP fp , int * array, int SIZE, int k, int n,const algorithm_t algo)
{
    b_case(array, SIZE, k, algo);
    return get_time_search(*fp, array, SIZE,k,n);    
}
double binary_search_AC(SeP fp , int * array, int SIZE, int k, int n,const algorithm_t algo)
{
    a_case(array, SIZE, k, algo);
    return get_time_search(*fp, array, SIZE,k,n);    
}
double binary_search_WC(SeP fp , int * array, int SIZE, int k, int n,const algorithm_t algo)
{
    w_case(array, SIZE, k, algo);
    return get_time_search(*fp, array, SIZE,k,n);    
}




void benchmark(const algorithm_t a, const case_t c, result_t* buf, int n)
{
int size = SIZE_START;
int buffert_index = ZERO;
double t= buf[buffert_index].time;
while (n > ZERO)
{
buf[buffert_index].size = size;
int* array = (int*)calloc((size * size), sizeof(int));


switch (a)
{
case bubble_sort_t:
switch (c)
{
case worst_t:
t=BubbleSort_WC(&bubble_sort,array,buf[buffert_index].size,n,a);
break;

case average_t:
t= BubbleSort_AC(&bubble_sort, array, buf[buffert_index].size, n, a);
break;

case best_t:
t= BubbleSort_BC(&bubble_sort, array, buf[buffert_index].size, n, a);
break;
}
break;

case insertion_sort_t:
switch (c)
{
case worst_t:
t= insertion_sort_WC(&insertion_sort, array, buf[buffert_index].size, n,a);
break;

case average_t:
t= insertion_sort_AC(&insertion_sort, array, buf[buffert_index].size, n,a);
break;

case best_t:
t= insertion_sort_BC(&insertion_sort, array, buf[buffert_index].size, n,a);
break;
}
break;

case quick_sort_t:
switch (c)
{
case worst_t:
t= quick_sort_WC(&quick_sort, array, buf[buffert_index].size, n,a);
break;

case average_t:
t= quick_sort_AC(&quick_sort, array, buf[buffert_index].size, n,a);
break;

case best_t:
t= quick_sort_BC(&quick_sort, array, buf[buffert_index].size, n,a);
break;
}
break;

case linear_search_t:
switch (c)
{
case worst_t:
t=linear_search_WC(&linear_search, array, buf[buffert_index].size, 5, n,a);
break;

case average_t:
t=linear_search_AC(&linear_search, array, buf[buffert_index].size, ZERO, n,a);
break;

case best_t:
t=linear_search_BC(&linear_search, array, buf[buffert_index].size, ZERO, n,a);
break;
}
break;

case binary_search_t:
switch (c)
{
case worst_t:
t=binary_search_WC(&linear_search, array, buf[buffert_index].size, ZERO, n,a);
break;

case average_t:
t=binary_search_AC(&linear_search, array, buf[buffert_index].size, ZERO, n,a);
break;

case best_t:
t=binary_search_BC(&linear_search, array, buf[buffert_index].size, ZERO, n,a);
break;
}
break;
}
buf[buffert_index].time=t;
n--;
buffert_index++;
size = size * 2;
free(array);
}
}

//Worst case
void w_case(int *x, int y, int z, const algorithm_t alg){
 int i=0, j=y-1, k=1;

switch(alg){
case bubble_sort_t:
while(i<y) {
x[i]=j;
j--;
i++;
}
break;
 
  case insertion_sort_t:
while(i<y) {
x[i]=j;
j--;
i++;
}
  break;
 
  case quick_sort_t:
  while(i<y){
 x[i]=i;
 i++;
  }
  int tmp=x[y-1];
  x[y-1]=x[0];
  x[0]=tmp;
  break;
 
  case linear_search_t:
while(i<y) {
x[i]=k;
k--;
i++;
}
  x[y-1]=z;
  break;
 
  case binary_search_t:
  while(i<y){
 x[i]=i;
 i++;
  }
  x[y-1]=z;
  break;
  }
}

//average case
void a_case(int *x, int y, int z, const algorithm_t alg){
int i=0, size=(y/2);
switch(alg){
case bubble_sort_t:

case insertion_sort_t:
while(i<size){
x[i]=i;
i++;
}


while(i>=size){
x[i]=rand()%size*2;
i--;
}
break;

case quick_sort_t:
while(i<y){
x[i]=i;
i++;
}
int tmp=x[y/4];
x[y/4]=x[y-1];
x[y-1]=tmp;
break;

case linear_search_t:
while(i<y){
x[i]=rand()%y;
i++;
}
x[y/2]=z;
break;

case binary_search_t:
while(i<y){
x[i]=i;
i++;
}

x[y-3]=z;
break;
  }
}


 
//best case
void b_case(int *x, int y, int z, const algorithm_t alg){
int i=0,j=1;
switch(alg){
case bubble_sort_t:

case insertion_sort_t:
while(i<y){
x[i]= i;
i++;
}
break;

case quick_sort_t:
while(i<y){
x[i]= i;
i++;
}
int tmp= x[y/2];
x[y/2]=x[y-1];
x[y-1]= tmp;
break;

case linear_search_t:
x[0]=z;
while(j<y){
x[j]=rand()%y;
j++;
}
break;

case binary_search_t:
while(i<y){
x[i]=i;
i++;
}
x[y/2]=z;
break;
  }
}